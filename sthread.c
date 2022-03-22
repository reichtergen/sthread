#include "sthread.h"

#ifdef _WIN32
    #include <processthreadsapi.h>
    #include <synchapi.h>
    #include <handleapi.h>
#else
    #include <pthread.h>
#endif

typedef struct sthread_t {

    #ifdef _WIN32
        HANDLE thread;
    #else
        pthread_t thread;
    #endif
} sthread_t;


void create_thread(sthread_t * th, void (*thread_function)(void*), void * args)  {

    #ifdef _WIN32
        th->thread = CreateThread(NULL, 0, thread_function, args, 0, NULL);
    #else
        pthread_create( th->thread, NULL, thread_function, args);
    #endif   

}

void wait_thread(sthread_t * th) {

    #ifdef _WIN32
        WaitForSingleObject(th->thread, 0xFFFFFFFF);
    #else
        pthread_join( th->thread, NULL);
    #endif   
}

void terminate_thread(sthread_t * th) {

    #ifdef _WIN32
        TerminateThread(th->thread, 0);
        CloseHandle(th->thread);
        th->thread = NULL;
    #else
        pthread_cancel(th->thread);
        th->thread = NULL;
    #endif   
}

void destroy_thread(sthread_t * th) {
    #ifdef _WIN32
        CloseHandle(th->thread);
        th->thread = NULL;
    #else
        th->thread = NULL;
    #endif   
}