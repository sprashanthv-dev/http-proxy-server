#ifndef UTILS_H
#define UTILS_H

char **split_string(const char *str, const char *delimiter, int *parts);

char **get_n_lines(const char *buffer, int n);

int find_substring_index(const char *str, const char *pattern);

int find_substr_index_in_array(char **arr, int entries, const char *pattern);

int find_last_occurence(const char *str, char ch);

#endif //UTILS_H
