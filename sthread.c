#include "sthread.h"

#ifdef _WIN32
    #include <processthreadsapi.h>
    #include <synchapi.h>
    #include <handleapi.h>
#else
    #include <pthread.h>
#endif