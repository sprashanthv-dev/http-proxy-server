#ifndef REQ_HANDLER_H
#define REQ_HANDLER_H

#include <string.h>
#include <stdbool.h>

#include "dns_cache.h"

#define LINES_TO_EXTRACT 2
#define DEFAULT_SERVER_PORT "80"
#define GET_METHOD "GET"

struct parsed_request {
    char method[10];
    char resource[100];
    char host[50];
    char referer[75];
    char port[10];
    char version[10];
    char message_body[1024];
};

struct parsed_request parse_request(char *request, int total_lines);

char* validate_request(struct parsed_request *request, const struct hostname_ip_map* map, size_t num);

#endif //REQ_HANDLER_H
