#ifndef OS_FILE_H
#define OS_FILE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
typedef struct os_file* os_file_handle_t;
__attribute ((visibility("default"))) os_file_handle_t os_fopen(const char * path, const char * mode);
__attribute ((visibility("default"))) int os_fclose(os_file_handle_t file);
__attribute ((visibility("default"))) size_t os_fread(void *buffer, size_t size, size_t count, os_file_handle_t stream);
__attribute ((visibility("default"))) void *os_fwrite(const void* buffer, size_t size, size_t count, os_file_handle_t stream);

#ifdef __cplusplus
}
#endif
#endif
