#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <pthread.h>

#define		TIME_OF_FRONT_END		200
#define		TIME_OF_DOMAIN			200
#define		TIME_OF_DA				200

//#ifdef WIN32
//#define sleep(t) Sleep(t)
//#endif // WIN32


/**@private*/
static void* execTasksFrontEnd(void* data);
static void* execTasksDataAcquisition(void* data);
static void* execTasksDomain(void* data);

/**@public Funcoes*/
void initThreads(void);
void sleep_ms(int milliseconds);

#endif

