#ifndef OS_UTILS_H
#define OS_UTILS_H
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    FAIL = -1,
    OK = 0,
} return_value; 

__attribute ((visibility("default"))) char *os_strdup(char *src);

#ifdef __cplusplus
}
#endif
#endif
