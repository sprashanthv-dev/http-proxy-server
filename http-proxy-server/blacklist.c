#include "blacklist.h"
#include "file_ops.h"
#include "constants.h"
#include "utils.h"

bool isValidIPv4Address(const char *ip) {
    struct sockaddr_in sock_addr;

    int isValid = inet_pton(AI_FAMILY, ip, &(sock_addr.sin_addr));
    return isValid != 0;
}

bool isIPOrDomainBlacklisted(const char *end_point) {
    FILE *fptr = open_file(BLACKLIST_FILE, "r");

    if (fptr == NULL) {
        memory_error();
    }

    size_t total_bytes = 0;
    char *file_contents = read_file(fptr, &total_bytes);

    // Indicates no errors were encountered in reading the file contents
    if (total_bytes > 0) {
        int parts = 0;

        char **items = split_string(file_contents, COMMA, &parts);

        bool isEndPointAnIP = isValidIPv4Address(end_point);
        printf("Is end point an IP address %d\n", isEndPointAnIP);

        // If it is an IP address, perform an exact match
        if (isEndPointAnIP) {

            for (int i = 0; i < parts; i++) {
                if (strcmp(items[i], end_point) == 0) {
                    free(items);
                    return true;
                }
            }

            free(items);

            return false;
        }

        printf("Endpoint is a domain ...\n");

        // Either a domain or subdomain, hence perform a contains match
        for (int i = 0; i < parts; i++) {

            if (strstr(items[i], end_point) != NULL) {
                free(items);
                return true;
            }
        }

        free(items);
        free(file_contents);
    }

    return false;
}