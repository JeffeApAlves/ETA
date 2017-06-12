/**
 * @file App.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Funcoes para manipulacao da maquina de estado do SW
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

#include "App.h"

/**
 * Status do SW foi declarado como static para manter a visibilidade restrita ao modulo App.c.
 * Toda a aplicacao ira manipula-la atraves das funcoes gets and sets desse modulo
 * @see TStatusApp
 * @private
*/
static TStatusApp StatusApp = APP_STARTING;

/**
 * SW em modo medicao
 * @public
*/
 void setMeasurementApp(void)
{
	StatusApp = APP_MEASUREMENT;
}
//------------------------------------------------------------------------------------------------------------------------

/**
 * Define o status do SW
 * @public
*/
 void setAppStatus(TStatusApp sts_app)
{
	StatusApp = sts_app;
}
//------------------------------------------------------------------------------------------------------------------------

/**
 * Retorna status do SW
 * @public
*/
 TStatusApp getAppStatus(void)
{
	return StatusApp;
}
//------------------------------------------------------------------------------------------------------------------------

/**
 * Retorna se a aplicacao esta rodando
 * @public
*/
 int isRunningApp(void)
{
	return StatusApp != APP_REQUEST_CLOSE && StatusApp != APP_CLOSING && StatusApp != APP_CLOSED;
}
//------------------------------------------------------------------------------------------------------------------------
