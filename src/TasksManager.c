/**
 * @file TasksManager.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Gerenciador de tasks atraves de Threads
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 * @see http://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html
 */

#include "Container.h"
#include "DataAcquisition.h"
#include "ETA.h"

#include "TasksManager.h"


pthread_t	ThreadFrontEnd,
			ThreadDomain,
			ThreadDataAcquisition;

/**
 * Instancia todas as Threads do sistema que serao responsaveis por todo o processo
 *
 * ThreadFrontEnd: Responsavel pelo Front End (TUI)
 * ThreadDomain: Responsavel pelos tasks do domain
 * ThreadDataAcquisition: Responsavel pela aquisicao de dados
 * @public
*/
void initThreads(void)
{
	pthread_create(&ThreadFrontEnd,NULL,execTasksFrontEnd,NULL);
	pthread_create(&ThreadDomain,NULL,execTasksDomain,NULL);
	pthread_create(&ThreadDataAcquisition,NULL,execTasksDataAcquisition,NULL);
}
//-----------------------------------------------------------------------------------------------------------------

/**
 * Finaliza todas as Threads
 * @public
 * @todo Melhorar
*/
void deInitThreads(void)
{
	pthread_cancel(ThreadFrontEnd);
	pthread_cancel(ThreadDomain);
	pthread_cancel(ThreadDataAcquisition);
}
//-----------------------------------------------------------------------------------------------------------------

/**
 * Thread responsavel pela execucao de tarefas relacionadas ao Front end (TUI) (View Layer).
 * @private
*/
static void* execTasksFrontEnd(void* data)
{
	do{
		processTasksOfTUI();
		sleep_ms(TIME_OF_FRONT_END);

	}while(1);
}
//-----------------------------------------------------------------------------------------------------------------

/**
 * Thread responsavel pela execucao de tarefas relacionadas ao negocio  (Domain Layer).
 * @private
*/
static void* execTasksDomain(void* data)
{
	do{
		processTasksOfDomain();
		sleep_ms(TIME_OF_DOMAIN);

	}while(1);
}
//-----------------------------------------------------------------------------------------------------------------

/**
 * Thread responsavel pela execucao de tarefas relacionadas a aquisicao de dados /comunicacao (Data Layer).
 * @private
*/
static void* execTasksDataAcquisition(void* data)
{
	do{
		processTasksOfDataAcquisition();
		sleep_ms(TIME_OF_DA);

	}while(1);
}
//-----------------------------------------------------------------------------------------------------------------

/**
 * Suspende a execucao da thread por um determinado  empo
 * cross-platform sleep function
 * @public
 * @param milliseconds Tempo em que a Thread ficara suspensa em milesegundo
*/
void sleep_ms(int milliseconds)
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}
//---------------------------------------------------------------------------------------------------------------------------------
