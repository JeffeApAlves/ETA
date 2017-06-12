/**
 * @file main.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 04.04.2017
 * @brief Software para gerenciamento de processo automatizado de estacoes de tratamento
 * de agua
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 * @see https://www.stack.nl/~dimitri/doxygen/manual/commands.html
 * @see https://www.gnu.org/prep/standards/html_node/Writing-C.html Code Style
 * @see https://pt.wikipedia.org/wiki/Biblioteca_padr%C3%A3o_do_C
  */

#include <curses.h>
#include "MainMenu.h"
#include "Container.h"
#include "TasksManager.h"
#include "App.h"
#include <stdio.h>

/**@private Funcoes*/
static void startApp(void);
static void runApp(void);
static void closeApp(void);


/**
 * O SW eh inicializado pela a funcao startApp(void) fica em loop continuo dentro da runApp(void) enquantoas Threads sao executadas para
 * finalizar o SW set o StatusApp para APP_REQUEST_CLOSE atraves da funcao serStstusApp(void) entao o SW e finalizo executando a funcao
 * closeApp
 * @see App.c
 * @see TasksManagers.c
*/
int main(int argc, char *argv[])
{
	startApp();

	runApp();

	closeApp();

	return getAppStatus();
}
//-----------------------------------------------------------------------------------------------------------------

/**
 * Seta o status do SW para APP_STARTING e comeca a executar o startup do SW incializando todas as variaveis e video ao
 * finalizar o status do SW e alterado para APP_STARTED
 * @see App.c
 * @private
*/
static void startApp(void)
{
	setAppStatus(APP_STARTING);	/**APP_STARTING SW em inicializacao*/

	initContainer();			/**Inicializa o container do TUI;*/

	initEntities();				/**Inicializa as entidades do dominio Valvula / Bombas*/

	initscr();					/**Inicializa modo TUI*/

//    resizeterm(35, 100);       /**Tamanho da Tela*/

//    resize_term(35, 100);       /**Tamanho da Tela*/

	clear();					/**Limpa a tela*/

	refresh();					/**Atualiza a tela*/

	curs_set( 0 );				/**Oculta o cursor*/

	noecho();					/**Disable echo de caracteres na tela*/

	cbreak ();					/**Sem buffer de entra (cada caracter digitado eh enviado imediatamente)*/

	createMainMenu(0,0);		/**Cria menu principal no top da tela*/

	setFocusMenu(pMainMenu);	/**Configura foco no menu principal*/

	initThreads();				/**Inicializa as Threads*/

	setAppStatus(APP_STARTED);	/** APP_STARTED =SW inicializado*/
}
//------------------------------------------------------------------------------------------------------------------------

/**
 * Apos o termino da inicializacao do software feita pela funcao startApp(void) a task principal ficara neste loop infinito enquanto as
 * Threads executam todo o processos.
 * Para finalizar o SW e necessario alterar o status da aplicacao para APP_REQUEST_CLOSE atraves da funcao setAppStatus(TStatusApp sts_app)
 * o loop sera interronpido e se iniciara o shutdown do SW atraves da funcao closeApp(void)
 *
 * @see TasksManager.c
 * @see App.c
 * @private
 *
*/
static void runApp(void)
{
	setAppStatus(APP_RUNNING);	//** SW rodando*/

	while(isRunningApp()){

       sleep_ms(TIME_OF_APP);

// !!!!!!Threads are running  !!!!!!!!!!!!!!!

	}

//	Bye !!! Bye !!! See you !!! Iniciara o shutdows do SW ;-)
}
//------------------------------------------------------------------------------------------------------------------------

/**
 * Finalizacao do software altera o status da aplicacao para APP_CLOSE e comeca a fazer o shutdown do SW excluindo todos as
 * variaveis alocadas dinamicamente, finalizando as Threads e fechando o modo TUI.
 *
 * @private
*/
static void closeApp(void)
{
	setAppStatus(APP_CLOSING);		// iniciara o shutdown do SW

	deInitThreads();

	deleteAllTuiEntities();

	endwin();

	system(CLEAR_SCREEN);

	setAppStatus(APP_CLOSED);		// Finalizado o shutdown do SW
}
//------------------------------------------------------------------------------------------------------------------------
