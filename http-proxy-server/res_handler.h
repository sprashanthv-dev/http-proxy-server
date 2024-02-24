#ifndef RES_HANDLER_H
#define RES_HANDLER_H

#include <stdio.h>
#include <string.h>
#include "content_type.h"
#include "error_utils.h"

char *construct_error_response(
        const char* status,
        const char* error_msg,
        const char* version,
        int *content_length);

char *assign_type(char *type);

#endif //RES_HANDLER_H
