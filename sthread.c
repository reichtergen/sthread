#include "sthread.h"



void create_thread(sthread_t * th, void (*thread_function)(void*), void * args)  {

    #ifdef _WIN32
        th->thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_function, args, 0, NULL);
    #else
        pthread_create(&th->thread, NULL, (void*)thread_function, args);
    #endif   

}

void wait_thread(sthread_t * th) {

    #ifdef _WIN32
        WaitForSingleObject(th->thread, 0xFFFFFFFF);
    #else
        pthread_join(th->thread, NULL);
    #endif   
}

void terminate_thread(sthread_t * th) {

    #ifdef _WIN32
        TerminateThread(th->thread, 0);
        CloseHandle(th->thread);
        th->thread = NULL;
    #else
        pthread_cancel(th->thread);
        //th->thread = 0;
    #endif   
}

void destroy_thread(sthread_t * th) {
    #ifdef _WIN32
        CloseHandle(th->thread);
        th->thread = NULL;
    #else
        //th->thread = 0;
    #endif   
}