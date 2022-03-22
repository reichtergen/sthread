#include <stdio.h>

#ifdef _WIN32
    #include <synchapi.h> // for Sleep()
#else
    #include <unistd.h>
    #define Sleep() sleep()
#endif


#include "sthread.h"


void func1(void *args) {

    for (size_t i = 0; i < 10; i++)
    {
        printf("%s\n", args);
        Sleep(1000);
    }
    
}

void func2(void *args) {

    for (size_t i = 0; i < 10; i++)
    {
        printf("%s\n", args);
        Sleep(2000);
    }
    
}

int main(void) {

    sthread_t thread1, thread2;

    create_thread(&thread1, func1, (char*)"A--thread 1");
    create_thread(&thread2, func2, (char*)"B--thread 2");

    printf("Waiting threads!\n\n");

    /* optional */
    wait_thread(&thread1);
    wait_thread(&thread2);  

    printf("\nDestroy threads!\n");

    destroy_thread(&thread1);
    destroy_thread(&thread2);

    return 0;
}