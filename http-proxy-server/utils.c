#include <string.h>

#include "utils.h"
#include "error_utils.h"

int count_char_occurence(const char *str, const char *ch) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == *ch) {
            count++;
        }
    }

    return count;
}

char **split_string(const char *str, const char *delimiter, int *count) {
    int buffer_size = count_char_occurence(str, delimiter) + 1;
    *count = buffer_size;

    int counter = 0;

    // 1-D array of strings
    char **strs = malloc(buffer_size * sizeof(char *));

    // Store a copy of the input string to avoid direct
    // modification to the original input.
    char *str_copy = strdup(str);
    char *part;

    if (strs == NULL || str_copy == NULL) {
        memory_error();
    }

    // Get each token in the input string based
    // on the provided delimiter
    part = strtok(str_copy, delimiter);

    // Process each token
    while (part != NULL && counter < buffer_size) {
        strs[counter] = strdup(part);
        part = strtok(NULL, delimiter); // Get the next token
        counter++;
    }

    return strs;
}

char **get_n_lines(const char *buf, int n) {
    int count = 0;

    // Tokenize incoming client request based on \r\n
    char **tokens = split_string(buf, "\r\n", &count);

    return tokens;
}

int find_substring_index(const char *str, const char *pattern) {
    int index = -1;

    const char *result = strstr(str, pattern);

    if (result != NULL) {
        index = (int) (result - str);
    }

    return index;
}

int find_substr_index_in_array(char **arr, int entries, const char *pattern) {
    int result = -1;

    for (int i = 0; i < entries; i++) {
        const char *item = arr[i];

        if (item != NULL) {
            int idx = find_substring_index(item, pattern);

            if (idx != -1) {
                result = i;
                break;
            }
        }
    }

    return result;
}

int find_last_occurence(const char *str, char ch) {
    int index = -1;

    const char *pos = strrchr(str, ch);

    if (pos != NULL) {
        index = (int) (pos - str);
    } else {
        error("Strrchr has returned NULL: ");
    }

    return index;
}


