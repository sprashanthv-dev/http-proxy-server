#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "error_utils.h"

#define ERROR_MSG_SIZE 150
#define LINE_SIZE 200

FILE *open_file(char path[], char mode[]);

char *read_file(FILE *fptr, size_t *total_bytes);

bool write_to_file(char *name, char *mode, char *contents, int offset);

int get_no_of_lines(FILE *fptr);

char* get_file_extension(char *path);

bool is_image_file(char *ext);

#endif // FILE_OPS_H
