#include "res_handler.h"
#include "constants.h"

#define PADDING 200 // Space to be allocated for header info in server response

char *construct_error_response(
        const char *status,
        const char *error_msg,
        const char *version,
        int *content_length) {
    char *response = malloc(PADDING * sizeof(char));

    if (response == NULL) {
        memory_error();
    }

    int response_length = snprintf(response,
                                   PADDING,
                                   "%s %s %s", version, status, error_msg);

    *content_length = response_length;

    return response;
}

char *assign_type(char *type) {
    char *content_type = malloc(CONTENT_TYPE_LENGTH * sizeof(char));

    if (content_type == NULL) {
        memory_error();
    }

    // Check for either one of html, txt, png,
    // gif, jpg, ico, css, js file extensions.
    if (strcmp(type, HTML) == 0) {
        strcpy(content_type, html_type);
    } else if (strcmp(type, TXT) == 0) {
        strcpy(content_type, txt_type);
    } else if (strcmp(type, PNG) == 0) {
        strcpy(content_type, png_type);
    } else if (strcmp(type, GIF) == 0) {
        strcpy(content_type, gif_type);
    } else if (strcmp(type, JPG) == 0) {
        strcpy(content_type, jpg_type);
    } else if (strcmp(type, ICO) == 0) {
        strcpy(content_type, icon_type);
    } else if (strcmp(type, CSS) == 0) {
        strcpy(content_type, css_type);
    } else if (strcmp(type, JS) == 0) {
        strcpy(content_type, js_type);
    } else {
        strcpy(content_type, octet_type);
    }

    return content_type;
}