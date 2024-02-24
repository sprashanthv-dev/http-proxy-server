#include "constants.h"
#include "page_cache.h"
#include "utils.h"
#include "file_ops.h"
#include "dir_ops.h"

// Checks if the requested resource is the remote
// server's root document (index.html) or not
bool is_root_document(struct parsed_request *req) {
    size_t len = strlen(HTTP_PREFIX) + strlen(req->host) + strlen(SLASH) + 1;
    char resource[len];

    strcpy(resource, HTTP_PREFIX);
    strcat(resource, req->host);
    strcat(resource, SLASH);

    if (strcmp(resource, req->resource) == 0 && strcmp(req->referer, NO_REFERER) == 0) {
        return true;
    }

    return false;
}

// Checks if the requested resource is a resource
// belonging to a subdomain of the root document
bool is_subdomain_resource(struct parsed_request *req) {

    // haystack (str) - req.resource, needle (pattern) - req.host
    int index = find_substring_index(req->resource, req->host);

    if (index != -1 && !is_root_document(req)) {
        return true;
    }

    return false;
}

bool write_to_proxy_cache(struct parsed_request *req, char *contents, int offset) {

    // Get the dir name and file name from the requested resource
    char **path_info = parse_path(req->resource);

    if (path_info != NULL) {
        char *dir_name = path_info[0];
        char *file_name = path_info[1];

        // Calculate md5 hash of dir_name
        char *dir_name_hash = calculate_md5_hash(dir_name);

        // Create directory with dir_name
        bool create_dir = create_directory(dir_name_hash);

        if (create_dir) {
            // Call open_file() with file_name in append mode
            char *full_path = get_full_path(dir_name_hash, file_name);
            char *file_ext = get_file_extension(file_name);

            bool is_image = is_image_file(file_ext);
            char *file_mode = is_image ? "ab" : "a";

            printf("File mode: %s\n", file_mode);

            // Write file contents using write_to_file() in append mode
            bool result = write_to_file(full_path, file_mode, contents, offset);

            if (result) {
                printf("Contents written to %s successfully\n", file_name);
            } else {
                printf("Error in writing file contents to %s\n", file_name);
            }

            free(full_path);
            free(file_ext);
        }

        free(dir_name_hash);
    }

    free(path_info);

    return true;
}

char *read_from_proxy_cache(struct parsed_request *req, size_t *bytes) {

    printf("Requested resource %s\n", req->resource);

    char **path_info = parse_path(req->resource);

    if (path_info != NULL) {
        char *dir_name = path_info[0];
        char *file_name = path_info[1];

        printf("Dir name %s\n", dir_name);
        printf("File name %s\n", file_name);

        // Calculate md5 hash of dir_name
        char *dir_name_hash = calculate_md5_hash(dir_name);
        char *full_path = get_full_path(dir_name_hash, file_name);
        char *file_ext = get_file_extension(file_name);

        bool is_image = is_image_file(file_ext);
        char *file_mode = is_image ? "ab" : "a";

        FILE *fptr = open_file(full_path, file_mode);

        if (fptr != NULL) {
            size_t total_bytes = 0;
            char* file_contents = read_file(fptr, &total_bytes);

            *bytes = total_bytes;
            return file_contents;
        }

        free(file_ext);
        free(dir_name_hash);
        free(path_info);
        free(full_path);

        return NULL;
    } else {
        memory_error();
    }

    return NULL;
}

char *calculate_md5_hash(const char *str) {
    MD5_CTX md5_ctx;
    unsigned char md5_digest[MD5_DIGEST_LENGTH];

    // Each byte is represented by 2 hex characters
    char *md5_hash = malloc((MD5_DIGEST_LENGTH * 2) + 1);

    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, str, strlen(str));
    MD5_Final(md5_digest, &md5_ctx);

    if (md5_hash == NULL) {
        memory_error();
    }

    // Copy the generated hash to the final result
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5_hash[i * 2], "%02x", (unsigned int) md5_digest[i]);
    }

    return md5_hash;
}