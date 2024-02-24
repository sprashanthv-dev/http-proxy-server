#include <stdio.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>

#include "proxy.h"
#include "error_utils.h"
#include "websocket.h"
#include "utils.h"
#include "constants.h"
#include "req_handler.h"
#include "res_handler.h"
#include "dns_cache.h"
#include "page_cache.h"
#include "file_ops.h"

#define BACKLOG 10
#define MAX_SIZE 2048
#define CHUNK_SIZE 2048

bool isAlive = true;

size_t entries = 0;
struct hostname_ip_map *host_ip_map = NULL;

void end_program() {
    isAlive = false;
}

void send_recv_error_msg(char *msg, ssize_t bytes_count) {

    if (bytes_count < 0) {
        error(msg);
    }
}

void send_error_response(const char *status, const char *msg, const char *version, int client_fd) {
    char *cli_response = NULL;
    int response_size = 0;

    cli_response = construct_error_response(status,msg,version,&response_size);
    ssize_t bytes_sent = send(client_fd, cli_response, response_size, 0);

    send_recv_error_msg("Proxy -> Socket send:  ", bytes_sent);
    printf("Sent %zd bytes to client \n", bytes_sent);
}

void refresh_dns_cache_file(const char *filename) {
    printf("Updating dns_cache file due to call from %s\n", filename);

    size_t new_entries = 0;
    host_ip_map = load_host_ip_mappings(DNS_CACHE_FILE, "r", &new_entries);
    entries = new_entries;

    printf("Updated Entries value %ld\n", entries);
    printf("////////////////////////////////\n");
}

// int client_fd, void *client_fd_ptr

//TODO: Check if race conditions occur while accessing the DNS_CACHE file
void *handle_client_connection(void *client_fd_ptr) {
    ssize_t bytes_sent, bytes_received;

    char buffer[MAX_SIZE];
    char server_resp[CHUNK_SIZE];

    memset(&buffer, 0, sizeof(buffer));
    memset(&server_resp, 0, sizeof(server_resp));

    printf("Handling incoming connection ...\n");
    printf("Current Thread ID: %lu \n", pthread_self());

    int client_fd = (*(int *) client_fd_ptr);
    free(client_fd_ptr);

    printf("---------------------\n");

    // Receive client request
    bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);

    printf("Received %zd bytes from the client\n", bytes_received);
    printf("Received byte contents %s\n", buffer);

    send_recv_error_msg("Proxy - Socket recv(): ", bytes_received);

    if (bytes_received > 0) {
        // Null terminate
        buffer[bytes_received + 1] = '\0';

        // Send response back to client
        int total_lines = 0;
        char **tokens = split_string(buffer, "\r\n", &total_lines);

        printf("Total lines in client request %d\n ", total_lines);

        struct parsed_request formatted_req = parse_request(buffer, total_lines);

        // Returns either IP address (or) METHOD_ERROR (or) HOST_ERROR
        char *validated_req = validate_request(&formatted_req, host_ip_map, entries);
        printf("Validated Req %s\n", validated_req);

        if (strcmp(validated_req, METHOD_ERROR) == 0) {
            send_error_response(BAD_REQUEST, BAD_REQUEST_MSG, formatted_req.version, client_fd);
        } else if (strcmp(validated_req, HOST_ERROR) == 0) {
            send_error_response(NOT_FOUND, NOT_FOUND_MSG, formatted_req.version, client_fd);
        } else if (strcmp(validated_req, BLACKLISTED_RESOURCE) == 0) {
            send_error_response(FORBIDDEN, FORBIDDEN_MSG, formatted_req.version, client_fd);
        }
        else {
            // Once request is validated, forward it from proxy to the server

            // Get remote server information
            struct addrinfo *server_info = get_server_info(formatted_req.host, formatted_req.port, host_ip_map, entries);

            size_t cached_cont_len = 0;

            // char *cached_content = read_from_proxy_cache(&formatted_req, &cached_cont_len);

            // if (cached_content != NULL) {
            //     printf("Resource %s already available in proxy cache \n", formatted_req.resource);

            //     int response_size = cached_cont_len > 0 ? (int) cached_cont_len + 200 : 200;
            //     char *response = malloc(response_size * sizeof (char));

            //     char *type = get_file_extension(formatted_req.resource);
            //     char *content_type = assign_type(type);

            //     int header_length = snprintf(response,
            //                                  response_size,
            //                                  "%s 200 OK\r\n Content-Type: %s\r\n Content-Length: %d\r\n\r\n", formatted_req.version,
            //                                  content_type, (int) cached_cont_len);

            //     // Copy actual file contents after the header information
            //     memcpy(response + header_length, cached_content, cached_cont_len);

            //     // Store the total bytes to be sent back to the client
            //     int total_bytes = header_length + (int) cached_cont_len;

            //     int res_bytes = send(client_fd, response, total_bytes, 0);
            //     send_recv_error_msg("Proxy -> client response: ", res_bytes);

            //     printf("Sent %d bytes to client\n", res_bytes);

            //     free(content_type);
            //     free(type);
            //     free(cached_content);
            //     free(response);
            // } 
            
            // else {
                // Create a new TCP connection through sockets
                int server_sockfd = create_socket(server_info);

                // Attempt to connect to the remote server through the socket
                int connect_val = connect(server_sockfd, server_info->ai_addr, server_info->ai_addrlen);

                if (connect_val < 0) {
                    perror("Error connecting to remote server: ");
                    error(gai_strerror(connect_val));
                }

                bytes_sent = send(server_sockfd, buffer, sizeof(buffer), 0);
                send_recv_error_msg("Proxy to Server Socket send:  ", bytes_sent);

                ssize_t bytes_recv;

                printf("-----------------------------------------------\n");
                printf("Requested resource %s\n", formatted_req.resource);
                printf("Requested host %s\n", formatted_req.host);
                printf("-----------------------------------------------\n");

                // Receive response from server for the send() call in chunks of 1024 bytes
                while ((bytes_recv = recv(server_sockfd, server_resp, CHUNK_SIZE, 0)) > 0) {

                    // Null terminate the server chunk response
                    server_resp[bytes_recv] = NULL_TERMINATOR;

                    // Find the end of response headers
                    int resp_headers = find_substring_index(server_resp, "\r\n\r\n");
                    resp_headers = resp_headers < 0 ? 0 : resp_headers;

                    char *contents= server_resp + resp_headers;

                    write_to_proxy_cache(&formatted_req, contents, resp_headers);
                    send_recv_error_msg("Proxy to client response: ", bytes_sent);

                    bytes_sent = send(client_fd, server_resp, bytes_recv, 0);
                    memset(&server_resp, 0, sizeof(server_resp));
                }

                free(server_info);
                free(validated_req);
                shutdown(server_sockfd, SHUT_RDWR);
            // }
        }

        free(tokens);

        // Close the client connection
        shutdown(client_fd, SHUT_RDWR);
    }

    // Clear the buffer to receive next message
    memset(&buffer, 0, sizeof(buffer));

    return NULL;
}

int main(int argc, char **argv) {

    int sock_fd = -1, bind_val, listen_val;
    int client_fd;

    struct sockaddr_in client_info;
    struct addrinfo *result;
    socklen_t client_len;

    // TODO: Modify this once timeout value is added for cache implementation
    if (argc < 2) {
        error("Usage: ./proxy <port_number>\n");
    }

    result = get_server_info(NULL, argv[1], host_ip_map, entries);

    if (result != NULL) {
        sock_fd = create_socket(result);
    }

    bind_val = bind(sock_fd, result->ai_addr, result->ai_addrlen);

    if (bind_val < 0) {
        error("Proxy -> Socket bind: ");
    }

    listen_val = listen(sock_fd, BACKLOG);

    if (listen_val < 0) {
        error("Proxy -> Socket listen: ");
    }

    // TODO: Check how often this function is to be called to retrieve the latest mappings
    host_ip_map = load_host_ip_mappings(DNS_CACHE_FILE, "r", &entries);

    printf("--------------------------------------\n");

    while (isAlive) {

        pthread_t thread;

        // Terminate the proxy server if Ctrl + C is pressed
        signal(SIGINT, end_program);

        client_len = sizeof(client_info);

        // Accept the client connection
        client_fd = accept(sock_fd,
                           (struct sockaddr *) &client_info,
                           &client_len);

        if (client_fd < 0) {
            error("Proxy -> Socket Accept: ");
        }

        int *thread_id = malloc(sizeof (int));
        *thread_id = client_fd;

//      handle_client_connection(client_fd);

        pthread_create(&thread, NULL, handle_client_connection, thread_id);
    }

    // Clean up addrinfo struct to prevent memory leaks
    free(result);
//  free(host_ip_map);

    // If Ctrl + C is pressed, clean up the socket gracefully
    shutdown(sock_fd, SHUT_RDWR);
    return 0;
}
