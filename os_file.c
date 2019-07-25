#include "os_file.h"
#include <stdio.h>
#include <fcntl.h>
typedef FILE os_file;
os_file_handle_t os_fopen(const char * path, const char * mode) {
    return fopen(path,mode);  
}
int os_fclose(os_file_handle_t file) {
    return fclose(file);
}
size_t os_fread(void *buffer, size_t size, size_t count, os_file_handle_t stream) {
    return fread(buffer,size,count,(FILE*)stream);
}
void *os_fwrite(const void* buffer, size_t size, size_t count, os_file_handle_t stream) {
    return fwrite(buffer,size,count,(FILE*)stream);
}


