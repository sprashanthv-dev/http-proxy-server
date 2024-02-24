#ifndef DNS_CACHE_H
#define DNS_CACHE_H

#include <stdio.h>
#include <netdb.h>
#include <stdbool.h>
#include <arpa/inet.h>

#define IP_ADDR_SIZE 16

struct hostname_ip_map {
    char hostname[50];
    char ip_addr[20];
};

struct hostname_ip_map* load_host_ip_mappings(char *path, char *mode, size_t *num);

char *get_ip_for_hostname(const char *host_name, const struct hostname_ip_map* map, size_t num);

struct addrinfo* build_server_info(const char *ip_addr, int port_no);

bool update_dns_cache_file(const char *host_name, const char *ip_addr);

#endif //DNS_CACHE_H
