#include "os_thread.h"
#include <pthread.h>
#ifdef GNU_GCC
typedef pthread_t os_thread;
#else
typedef * os_thread;
#endif
os_thread_handle_t os_thread_create(os_thread_cfg_t *cfg) {
   os_thread_handle_t thread = (os_thread_handle_t)os_calloc(1,sizeof(os_thread));
   if(thread) {
#ifdef GNU_GCC
       pthread_create(thread,0,cfg->run,cfg->args);
#endif
   }
}

void os_thread_exit(os_thread_handle_t self) {
    os_thread* thread = self;
    if(self) {
#ifdef GNU_GCC
       pthread_join(*thread,NULL);
#endif
       os_free(self);
    }
}


