#include <stdlib.h>
#include <stdio.h>

#include "proxy.h"
#include "utils.h"
#include "req_handler.h"
#include "constants.h"
#include "websocket.h"
#include "blacklist.h"

// TODO: Look into message body field of the struct if it is needed
struct parsed_request parse_request(char *request, int total_lines) {
    struct parsed_request formatted_request;
    memset(&formatted_request, 0, sizeof(formatted_request));

    // Extract m out of n total lines only if m <= n
    // TODO: Check if the below line is needed
    // int no_of_lines = total_lines >= LINES_TO_EXTRACT ? LINES_TO_EXTRACT : total_lines;

    char **lines = get_n_lines(request, total_lines);

    int referer_index = find_substr_index_in_array(lines,total_lines,REFERER_HEADER);

    int req_info = 0;
    int host_info = 0;

    if (lines[0] != NULL) {
        char **requested_resource = split_string(lines[0], SPACE, &req_info);

        // Indicates first line of client request is valid
        // TODO: Check if handling invalid first line requests is necessary
        if (req_info == 3) {
            // Request method
            strcpy(formatted_request.method, requested_resource[0]);

            // Requested resource
            strcpy(formatted_request.resource, requested_resource[1]);

            // Http version
            strcpy(formatted_request.version, requested_resource[2]);

            free(requested_resource);
        }
    }

    if (lines[1] != NULL) {
        char **host_details = split_string(lines[1], COLON_SPACE, &host_info);

        if (host_details[1] != NULL) {

            // Host
            strcpy(formatted_request.host, host_details[1]);

            // Indicates that no port was specified in the
            // client request for the requested resource
            if (host_info < 3) {
                strcpy(formatted_request.port, DEFAULT_SERVER_PORT);
            } else {
                strcpy(formatted_request.port, host_details[2]);
            }

            free(host_details);
        }
    }

    // If referer header was present in the client request
    // store it as part of our parsed_request struct type
    if (referer_index != -1) {
        char *referer_header = lines[referer_index];
        int count = 0;

        // [Referer, http, //netsys.cs.colorado.edu/]
        char **referer_details = split_string(referer_header, COLON, &count);

        if (referer_details[2] != NULL) {
            int referer_domain = find_substring_index(referer_details[2], DOUBLE_SLASH);

            if (referer_domain != -1) {
                int offset = referer_domain + REFERER_OFFSET;
                int referer_len = (int) (strlen(referer_details[2]) - offset) + 1;

                char referer[referer_len];
                strncpy(referer, referer_details[2] + offset, referer_len);

                referer[referer_len] = '\0';

                strcpy(formatted_request.referer, referer);
            }
        }

        free(referer_details);
    } else {
        strcpy(formatted_request.referer, NO_REFERER);
    }

    free(lines);

    return formatted_request;
}

/**
 *
 * @param request
 * @return
 * Ip address of resolved host name -> If request is valid
 * METHOD_ERROR -> If request method is not GET
 * HOST_ERROR -> If domain name could not be resolved to an IP address
 */
char *validate_request(struct parsed_request *request, const struct hostname_ip_map* map, size_t num) {
    printf("Host name inside validate_request %s\n", request->host);

    if (strcmp(request->method, GET_METHOD) != 0) {
        return METHOD_ERROR;
    }

    if (isIPOrDomainBlacklisted(request->host)) {
        return BLACKLISTED_RESOURCE;
    }

    // Before resolving host name through gethostbyname(), check
    // if the hostname is present in our hostname ip cache file
    char *ip_addr = get_ip_for_hostname(request->host, map, num);

    // Ip address was not found in the map
    if (strcmp(ip_addr, NOT_FOUND_MSG) == 0) {
        printf("Ip_addr is not found, calling get_host_info \n");
        struct hostent *host_info = get_host_info(request->host);

        if (host_info == NULL) {
            return HOST_ERROR;
        }

        // Assumption: If provided hostname resolves to multiple
        // IP addresses only the first IP address will be picked.
        char *raw_ip = host_info->h_addr_list[0];
        char *ip_address = inet_ntoa(*(struct in_addr *) raw_ip);
        char *final_ip = malloc(strlen(ip_address) * sizeof (char ));

        strcpy(final_ip, ip_address);

        printf("Writing to dns cache file from req_handler.c\n");

        // Update the hostname ip pair in the dns_cache file
        update_dns_cache_file(request->host, final_ip);

        // Update the mappings
        refresh_dns_cache_file("req_handler.c");

        return final_ip;
    }

    printf("Ip_addr retrieved from cache %s\n", ip_addr);

    return ip_addr;
}