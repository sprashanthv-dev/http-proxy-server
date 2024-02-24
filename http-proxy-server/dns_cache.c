#include "dns_cache.h"

#include "file_ops.h"
#include "constants.h"
#include "utils.h"

struct hostname_ip_map* load_host_ip_mappings(char *path, char *mode, size_t *num) {
    FILE *fptr = open_file(path, mode);

    if (fptr != NULL) {

        int entries = get_no_of_lines(fptr);

        printf("Number of lines in the cache file %d\n", entries);

        int idx = 0;

        *num = entries;

        struct hostname_ip_map* host_ip_map = malloc(entries * sizeof (struct hostname_ip_map));

        if (host_ip_map == NULL) {
            memory_error();
        }

        char entry[LINE_SIZE];
        fseek(fptr, 0, SEEK_END);
        rewind(fptr);

        // Process entries line by line
        while (fgets(entry, sizeof (entry), fptr) != NULL) {
            size_t line_size = strlen(entry);

            // Null terminate the last character to avoid \n in the current line
            entry[line_size - 1] = NULL_TERMINATOR;

            printf("Entry %s\n", entry);


            int total_entries = 0;

            // Split the current line based on comma
            char **items = split_string(entry, COMMA, &total_entries);

            // Store the hostname, ip address pair in the struct
            strcpy(host_ip_map[idx].hostname, items[0]);
            strcpy(host_ip_map[idx].ip_addr, items[1]);

            idx++;

            free(items);
        }

        return host_ip_map;
    }

    return NULL;
}

// Checks if the hostname is present in the struct hostname_ip_map
char *get_ip_for_hostname(const char *host_name, const struct hostname_ip_map* map, size_t num) {
    char *ip = malloc(IP_ADDR_SIZE * sizeof (char));
    int is_found = 0;

    if (map != NULL) {
        for (size_t i = 0; i < num; i++) {
            if (strcmp(host_name, map[i].hostname) == 0) {
                strcpy(ip, map[i].ip_addr);
                is_found = 1;
                break;
            }
        }
    }

    if (!is_found) strcpy(ip, NOT_FOUND_MSG);

    return ip;
}

// Builds the addrinfo struct required by connect() to the requested remote server
struct addrinfo* build_server_info(const char *ip_addr, int port_no) {
    struct addrinfo *server_info = malloc(sizeof(struct addrinfo));

    if (server_info == NULL) {
        memory_error();
    }

    // Reset the structure to avoid garbage values
    memset(server_info, 0, sizeof (struct addrinfo));

    server_info->ai_family = AI_FAMILY;
    server_info->ai_socktype = SOCK_TYPE;
    server_info->ai_protocol = AI_PROTOCOL;

    // Allocate a struct of type sockaddr_in to store the ip_addr of the remote server
    struct sockaddr_in *ipv4_addr = malloc(sizeof (struct sockaddr_in));

    if (ipv4_addr == NULL) {
        free(server_info);
        memory_error();
        return NULL;
    }

    // Reset the structure
    memset(ipv4_addr, 0, sizeof (struct sockaddr_in));

    ipv4_addr->sin_family = AF_INET;
    ipv4_addr->sin_port = htons(port_no);

    // Convert the string representation of IP address to binary and
    // store it in the sin_addr field of sockaddr_in struct type
    in_addr_t ipv4_binary_form = inet_addr(ip_addr);

    if (ipv4_binary_form == INADDR_NONE) {
        error("Failed to convert the IP address to binary form");
    } else {
        ipv4_addr->sin_addr.s_addr = ipv4_binary_form;
    }

    server_info->ai_addr = (struct sockaddr*) ipv4_addr;
    server_info->ai_addrlen = sizeof (struct sockaddr_in);

    return server_info;
}

char *concatenate_host_ip(const char *host, const char *ip) {
    size_t result_len = strlen(host) + strlen(COMMA) + strlen(NEWLINE_STR) + strlen(ip) + 1;

    char *host_ip = malloc(result_len * sizeof (char));

    if (host_ip == NULL) {
        memory_error();
    }

    strcpy(host_ip, host);
    strcat(host_ip, COMMA);
    strcat(host_ip, ip);
    strcat(host_ip, NEWLINE_STR);

    return host_ip;
}

bool update_dns_cache_file(const char *host_name, const char *ip_addr) {
    char *contents = concatenate_host_ip(host_name, ip_addr);
    bool result = write_to_file(DNS_CACHE_FILE, "a", contents, 0);

    free(contents);

    return result;
}
