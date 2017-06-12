/**
 * @file SimulatorMenu.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Menu de simulacoes
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

#include "MainMenu.h"
#include "DataAcquisition.h"
#include "SimulatorMenu.h"
#include "BR_pt.h"

TMenu*	pSimulatorMenu=NULL;

/**
 * Cria menu simulacao com seus itens e respectivos eventos
 *
 * @param left,top posicao do menu na tela
 * @return pSimulatorMenu Referencia do menu criado
 * @public
*/
void createSimulatorMenu(int left,int top)
{
	TOnEnter events[]= {enterI0_mSimulator,enterI1_mSimulator,enterI2_mSimulator,enterI3_mSimulator};

	createVerticalMenu(pSimulatorMenu,events,left,top,ITEMS_SIMULATION_MENU);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static void enterI0_mSimulator(void)
{
	setAppStatus(APP_RUNNING_SIMULATION);

	setInterface(INTERFACE_SIM_RANDOM);

	hideMenu(pSimulatorMenu);

	setFocusMenu(pMainMenu);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static void enterI1_mSimulator(void)
{
	setAppStatus(APP_RUNNING_SIMULATION);

	setInterface(INTERFACE_SIM_INCR);

	hideMenu(pSimulatorMenu);

	setFocusMenu(pMainMenu);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static void enterI2_mSimulator(void)
{
	setAppStatus(APP_MEASUREMENT);

	setInterface(INTERFACE_RBPI3);

	hideMenu(pSimulatorMenu);

	setFocusMenu(pMainMenu);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static void enterI3_mSimulator(void)
{
	hideMenu(pSimulatorMenu);

	setFocusMenu(pMainMenu);
}
//------------------------------------------------------------------------------------------------------
