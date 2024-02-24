#include "error_utils.h"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void memory_error() {
    error("Memory allocation failed: ");
}