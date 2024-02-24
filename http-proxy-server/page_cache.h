#ifndef PAGE_CACHE_H
#define PAGE_CACHE_H

#include "req_handler.h"
#include <stdbool.h>
#include <openssl/md5.h>

bool is_root_document(struct parsed_request *req);

bool is_subdomain_resource(struct parsed_request *req);

bool write_to_proxy_cache(struct parsed_request *req, char *contents, int offset);

char *read_from_proxy_cache(struct parsed_request *req, size_t *bytes);

char *calculate_md5_hash(const char *str);

#endif //PAGE_CACHE_H
