#ifndef BLACKLIST_H
#define BLACKLIST_H

#include <stdbool.h>
#include <arpa/inet.h>

bool isIPOrDomainBlacklisted(const char *end_point);

// Check if the provided string is a valid IPv4 address
bool isValidIPv4Address(const char *ip);

#endif //BLACKLIST_H
