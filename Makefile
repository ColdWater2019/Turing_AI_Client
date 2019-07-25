LOCAL_CFLAGS 	:= -rdynamic -g -O2 
LOCAL_CFLAGS  += -I./ -DGNU_GCC 
LOCAL_LDFLAGS += -Wl,-rpath,../
LOCAL_LDFLAGS +=  -lpthread -lm 


CFLAGS += $(LOCAL_CFLAGS)

turing_ai:  aes.o cJSON.o aiwifi.o os_memory.o os_log.o os_stream.o os_queue.o os_mutex.o os_semaphore.o os_thread.o os_file.o 
	$(CC) -o $@ $^ $(CFLAGS) $(LOCAL_LDFLAGS) 

clean:
	rm -f turing_ai 
	rm -f *.o
