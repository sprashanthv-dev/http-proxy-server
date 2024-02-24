#include <string.h>
#include <sys/socket.h>

#include "proxy.h"
#include "constants.h"
#include "error_utils.h"
#include "websocket.h"

// Returns a string version of the ip address from the struct addrinfo
char* get_ip_from_addrinfo(struct addrinfo *result) {
    struct sockaddr_in *ip = (struct sockaddr_in *) result->ai_addr;

    char *ip_addr = malloc(INET_ADDRSTRLEN);

    if (ip_addr == NULL) {
        memory_error();
    }

    inet_ntop(AI_FAMILY, &(ip->sin_addr), ip_addr, INET_ADDRSTRLEN);

    return ip_addr;
}

struct addrinfo *get_server_info(const char *name, char *port_no, const struct hostname_ip_map *map, size_t num) {
    struct addrinfo hints, *result = NULL;
    int status;

    // Reset the structure to avoid garbage values
    memset(&hints, 0, sizeof hints);

    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP Socket

    // Fetch server related info
    // If host name is NULL, it indicates connection between client
    // and proxy. In this case always perform a DNS resolution.
    if (name == NULL) {
        status = getaddrinfo(name, port_no, &hints, &result);
        printf("Status from getaddrinfo %d\n", status);
    } else {
        // Check if host name is present in the host_ip cache file
        char *ip_addr = get_ip_for_hostname(name, map, num);

        // If ip addr is not found in cache file, resolve it as
        // usual with a call to getaddrinfo()
        if (strcmp(ip_addr, NOT_FOUND_MSG) == 0) {

            printf("For host name %s, resolving through DNS\n", name);

            status = getaddrinfo(name, port_no, &hints, &result);

            // Check for errors
            if (status != 0) {
                error(gai_strerror(status));
            }

            printf("Writing to dns cache file from websocket.c\n");

            char *ipv4_addr = get_ip_from_addrinfo(result);
            update_dns_cache_file(name, ipv4_addr);

            free(ipv4_addr);

            // Update the mappings
            refresh_dns_cache_file("websocket.c");
        } else {
            printf("For host name %s, picking from cache the ip addr is %s\n", name, ip_addr);

            int port_number = atoi(port_no);
            result = build_server_info(ip_addr, port_number);
        }

        free(ip_addr);
    }

    return result;
}

int create_socket(struct addrinfo *result) {

    int sock_fd = socket(result->ai_family,
                         result->ai_socktype,
                         result->ai_protocol);

    int opt_val = 1;

    if (sock_fd < 0) {
        error("Socket creation error: ");
    }

    // Configure the created socket with additional options
    setsockopt(sock_fd,
               SOL_SOCKET,
               SO_REUSEADDR,
               (const void *) &opt_val,
               sizeof(int));

    return sock_fd;
}

struct hostent *get_host_info(const char *hostname) {
    struct hostent *host_info = gethostbyname(hostname);
    return host_info;
}