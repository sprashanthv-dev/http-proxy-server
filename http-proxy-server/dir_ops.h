#ifndef DIR_OPS_H
#define DIR_OPS_H

#include <stdbool.h>
#include <dirent.h>
#include <errno.h>

#define NAME_SIZE 200

// Return directory path and file path
// from a fully qualified path name
char** parse_path(char *path);

char *get_full_path(const char *dir_name, const char *file_name);

// Create a directory
bool create_directory(char *dir_name);

// Check if directory exists
bool does_dir_exist(char *dir_name);

#endif //DIR_OPS_H
