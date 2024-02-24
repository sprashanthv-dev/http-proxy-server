#ifndef CONSTANTS_H
#define CONSTANTS_H

#define AI_FAMILY AF_INET
#define SOCK_TYPE SOCK_STREAM
#define AI_PROTOCOL IPPROTO_TCP

#define METHOD_ERROR "METHOD_ERROR"
#define HOST_ERROR "HOST_ERROR"
#define BLACKLISTED_RESOURCE "BLACKLISTED_DOMAIN"

#define BAD_REQUEST "400"
#define FORBIDDEN "403"
#define NOT_FOUND "404"

#define REFERER_HEADER "Referer"
#define NO_REFERER "No Referer Header"
#define REFERER_OFFSET 2

#define BAD_REQUEST_MSG "Bad Request"
#define FORBIDDEN_MSG "Forbidden"
#define NOT_FOUND_MSG "Not Found"

#define DNS_CACHE_FILE "host_ip.txt"
#define BLACKLIST_FILE "blacklist.txt"
#define ROOT_FILE "index.html"

#define DIR_PERMISSIONS 0777
#define CONTENT_TYPE_LENGTH 30

#define SPACE " "
#define COLON ":"
#define COLON_SPACE ": "
#define NEWLINE '\n'
#define PERIOD '.'
#define NEWLINE_STR "\n"

#define NULL_TERMINATOR '\0'
#define COMMA ","
#define SLASH "/"
#define SLASH_CHAR '/'
#define DOUBLE_SLASH "//"
#define HTTP_PREFIX "http://"

#endif
