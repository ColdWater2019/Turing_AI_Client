#include "os_mutex.h"
#include <sys/types.h>
#ifdef GNU_GCC
#include <pthread.h>
typedef pthread_mutex_t os_mutex;
#else
typedef * os_mutex;
#endif
os_mutex_handle_t os_mutex_create() {
    os_mutex_handle_t mutex = (os_mutex_handle_t)os_calloc(1,sizeof(os_mutex));
    if(mutex) {
#ifdef GNU_GCC
        pthread_mutex_init(mutex,PTHREAD_PRIO_NONE);
#endif 
        return mutex; 
    }
}

int os_mutex_lock(os_mutex_handle_t self) {
#ifdef GNU_GCC
	pthread_mutex_t* mutex = (pthread_mutex_t*)self;
    pthread_mutex_lock(self);
#endif 
}

int os_mutex_unlock(os_mutex_handle_t self) {
#ifdef GNU_GCC
	pthread_mutex_t* mutex = (pthread_mutex_t*)self;
    pthread_mutex_unlock(self);
#endif 
}

void os_mutex_destroy(os_mutex_handle_t self) {
    if(self) {
#ifdef GNU_GCC
	    pthread_mutex_t* mutex = (pthread_mutex_t*)self;
        pthread_mutex_destroy(self);
#endif 
        os_free(self);
    }
}


