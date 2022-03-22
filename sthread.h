#ifndef STHREAD_H
#define STHREAD_H

typedef void* HANDLE;

typedef struct sthread_t {

    #ifdef _WIN32
        HANDLE thread;
    #else
        pthread_t thread;
    #endif
} sthread_t;


void create_thread(sthread_t * th, void (*thread_function)(void*), void * args);
void wait_thread(sthread_t * th);
void terminate_thread(sthread_t * th);
void destroy_thread(sthread_t * th);

#endif