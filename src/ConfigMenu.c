/**
 * @file ConfigMenu.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Menu Configuracao criado utilizando o componente menu
 *
 * @see Menu.c
 * @see BR_pt.h Textos dos itens do menu
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */


#include "MainMenu.h"
#include "Container.h"
#include "DataAcquisition.h"
#include "BR_pt.h"
#include "ConfigMenu.h"

TMenu*	pConfigMenu = NULL;

/**
 * Cria o Menu Configuracao e seus itens com seus respectivos eventos onenter
 * @param left,top posicao do menu na tela
 * @public
*/
void createConfigurationMenu(int left,int top)
{
	const TOnEnter events[]= {enterI0_mConfig,enterI1_mConfig,enterI2_mConfig};

	createVerticalMenu(pConfigMenu,events,left,top,ITEMS_CONFIG_MENU);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @todo Implementar a configuracao de unidade
 * @private
*/
static int enterI0_mConfig()
{
	hideMenu(pConfigMenu);

	setFocusMenu(pMainMenu);

	return 0;
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static int enterI1_mConfig()
{
	setInterface(INTERFACE_RBPI3);

	hideMenu(pConfigMenu);

	setFocusMenu(pMainMenu);

	return 0;
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private
*/
static int enterI2_mConfig()
{
	hideMenu(pConfigMenu);

	setFocusMenu(pMainMenu);

	return 0;
}
//------------------------------------------------------------------------------------------------------
