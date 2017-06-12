/**
 * @file MainMenu.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief  Menu principal com seus repectivos eventos para cada item
 *
 *
 * @see Menu.c
 * @see BR_pt.h Textos dos itens do menu
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#include "SimulatorMenu.h"
#include "MonitorMenu.h"
#include "ConfigMenu.h"
#include "BR_pt.h"
#include "Container.h"
#include "MainMenu.h"

TMenu*	pMainMenu=NULL;

/**
 * Cria o menu principal e seus itens com seus respectivos eventos onenter
 * @param left,top posicao do menu na tela
 * @public
*/
void createMainMenu(int left,int top)
{
	const TOnEnter events[]= {enterI0_mMain,enterI1_mMain,enterI2_mMain,enterI3_mMain};

	createHorizontalMenu(pMainMenu,events,left,top,ITEMS_MAIN_MENU );
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static int enterI0_mMain()
{
	createMonitorMenu(GRID(0,0));

	setFocusMenu(pMonitorMenu);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static int enterI1_mMain()
{
	createSimulatorMenu(GRID(1,0));

	setFocusMenu(pSimulatorMenu);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static int enterI2_mMain()
{
	createConfigurationMenu(GRID(2,0));

	setFocusMenu(pConfigMenu);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static int enterI3_mMain()
{
	setAppStatus(APP_REQUEST_CLOSE);
}
//------------------------------------------------------------------------------------------------------
