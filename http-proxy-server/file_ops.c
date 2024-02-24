#include "file_ops.h"
#include "constants.h"
#include "utils.h"

FILE *open_file(char path[], char mode[]) {
    FILE *fptr = fopen(path, mode);

    if (fptr == NULL) {
        printf("Error in opening the file located at: %s\n", path);
    } else {
        printf("File located at path %s opened successfully \n", path);
    }

    printf("***********************************\n");

    return fptr;
}

char *read_file(FILE *fptr, size_t *total_bytes) {
    long fsize;
    size_t file_bytes;

    char *contents = NULL;
    char error_msg[ERROR_MSG_SIZE];

    if (fptr != NULL) {
        // Move file ptr to end of file
        fseek(fptr, 0, SEEK_END);

        // Determine file size
        fsize = ftell(fptr);

        // Reset file pointer to the beginning of the file
        rewind(fptr);

        // Allocate memory to store file contents
        contents = malloc(sizeof(char) * fsize);

        if (contents == NULL) {
            memory_error();
        }

        printf("File contains %ld bytes\n ", fsize);

        // Read file contents one byte at a time
        file_bytes = fread(contents, 1, fsize, fptr);

        printf("Is end of file %d\n", feof(fptr));

        // Not all bytes could be read from the file
        if (file_bytes != fsize) {
            *total_bytes = -2; // Denotes that the file was not read completely

            snprintf(error_msg,
                     sizeof (error_msg),
                     "Error in reading file, only read %ld bytes out of total %ld bytes\n",
                     file_bytes, fsize);

            error(error_msg);
        } else {
            // Record total bytes present in the file
            *total_bytes = file_bytes;
        }

        fclose(fptr);
    } else {
        // File does not exist (or) memory related issues
        *total_bytes = -1;
    }

    return contents;
}

bool write_to_file(char *name, char *mode, char *contents, int offset) {
    FILE *fptr = open_file(name, mode);

    printf("Writing to file .. %s\n", name);

    if (fptr != NULL) {
        int skipPattern = offset > 0 ? 4 : 0;
        size_t incoming_bytes = strlen(contents);

        printf("Incoming bytes %ld\n", incoming_bytes);

//      size_t bytes_written = fwrite(contents, sizeof (char), incoming_bytes, fptr);
        size_t bytes_written = fwrite(contents + skipPattern, sizeof (char), incoming_bytes, fptr);

        // Check if the write operation was successful
        if (incoming_bytes != bytes_written) {
            printf("Error in writing to the file, only %ld bytes written out of total %ld bytes\n", bytes_written, incoming_bytes);
            fclose(fptr);
            return false;
        }

        fclose(fptr);
        return true;
    }

    printf("Error in writing to the file %s\n", name);
    fclose(fptr);
    return false;
}

int get_no_of_lines(FILE *fptr) {
    int lines = 0;
    int ch;

    while((ch = getc(fptr)) != EOF) {
        if (ch == NEWLINE) {
            lines++;
        }
    }

    return lines;
}

char *get_file_extension(char *path) {
    char *type = malloc(5 * sizeof(char));

    if (type == NULL) {
        memory_error();
    }

    int index = 0;

    // Get the index where "." appears in the file path
    int position = find_last_occurence(path, PERIOD);

    // Get the file extension
    for (int i = position + 1; path[i] != '\0'; i++) {
        type[index] = path[i];
        index++;
    }

    // Null terminate the buffer
    type[index + 1] = '\0';

    return type;
}

bool is_image_file(char *ext) {

    if (strcmp(ext, "png") == 0 ||
        strcmp(ext, "gif") == 0 ||
        strcmp(ext, "jpg")  == 0||
        strcmp(ext, "ico")  == 0) {
        return true;
    }

    return false;
}