// Header file containing prototypes related to web sockets
#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <netdb.h>
#include <arpa/inet.h>

#include "dns_cache.h"

// Return server info
struct addrinfo *get_server_info(const char *name, char *port_no, const struct hostname_ip_map *map, size_t num);

// Create and return the socket descriptor
int create_socket(struct addrinfo *result);

// Return host information by host name
struct hostent *get_host_info(const char *hostname);

#endif
