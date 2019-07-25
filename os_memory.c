#include "os_memory.h"

void *os_malloc(size_t size) {
    return malloc(size);
}

void os_free(void *ptr) {
    free(ptr);
}

void *os_calloc(size_t nmemb, size_t size) {
    return calloc(nmemb,size);
}

void *os_realloc(void *ptr, size_t size) {
    return realloc(ptr,size);
}


