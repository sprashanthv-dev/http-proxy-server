#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "constants.h"
#include "dir_ops.h"
#include "utils.h"
#include "error_utils.h"

char **parse_path(char *full_path) {
    // Find index of the last occurence of "/" in the path
    size_t len = strlen(full_path);

    int index = find_last_occurence(full_path, SLASH_CHAR);

    if (index != -1) {

        char **path_info = malloc(2 * sizeof (char *));

        if (path_info == NULL) {
            memory_error();
        }

        char dir_name[NAME_SIZE];
        char file_name[NAME_SIZE];

        strncpy(dir_name, full_path, index);
        dir_name[index] = NULL_TERMINATOR;

        // Indicates root document (usually index.html)
        if (index + 1 == len) {
            strcpy(file_name, ROOT_FILE);
        } else {
            int size = (int) (len - index);
            strncpy(file_name, full_path + index + 1, size);
            file_name[size] = NULL_TERMINATOR;
        }

        path_info[0] = malloc(strlen(dir_name) + 1);
        path_info[1] = malloc(strlen(file_name) + 1);

        if (path_info[0] == NULL || path_info[1] == NULL) {
            memory_error();
        }

        strcpy(path_info[0], dir_name);
        strcpy(path_info[1], file_name);

        return path_info;
    }

    return NULL;
}

char *get_full_path(const char *dir_name, const char *file_name) {
    size_t len = strlen(dir_name) + strlen(SLASH) + strlen(file_name) + 1;

    char *full_path = malloc(len * sizeof (char));

    if (full_path == NULL) {
        memory_error();
    }

    strcpy(full_path, dir_name);
    strcat(full_path, SLASH);
    strcat(full_path, file_name);

    return full_path;
}

bool create_directory(char *dir_name) {
    bool doesExist = does_dir_exist(dir_name);

    if (!doesExist) {
        int result = mkdir(dir_name, DIR_PERMISSIONS);

        if (result < 0) {
            printf("Error in creating the directory ...\n");
            return false;
        }
    }

    return true;
}

bool does_dir_exist(char *dir_name) {
    DIR *directory = opendir(dir_name);

    if (directory != NULL) {
        closedir(directory);
        return true;
    } else {
        if (ENOENT == errno) {
            printf("Directory %s does not exist\n", dir_name);
        } else  {
            printf("Error in opening the directory %s\n", dir_name);
        }

        return false;
    }
}