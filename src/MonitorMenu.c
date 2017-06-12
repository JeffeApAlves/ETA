/**
 * @file MonitorMenu.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Menu Monitoramento
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
#include "MainForm.h"
#include "BR_pt.h"
#include "Container.h"
#include "MonitorMenu.h"

TMenu*	pMonitorMenu=NULL;

/**
 * Cria o menu monitoramento e seus itens com seus respectivos eventos onenter
 *
 * @param left,top posicao do menu na tela 
 * @public
*/
void createMonitorMenu(int left,int top)
{
	const TOnEnter events[]= {enterI0_mMonitor,enterI1_mMonitor,enterI2_mMonitor};
		
	createVerticalMenu(pMonitorMenu,events,left,top,ITEMS_MONITOR_MENU);
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private 
*/
static int enterI0_mMonitor()
{
	if(pMainForm==NULL)
		pMainForm = constructMainForm();

	setVisibilityOfForm(pMainForm,1);
	
	hideMenu(pMonitorMenu);

	setFocusMenu(pMainMenu);		
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 *@private 
*/
static int enterI1_mMonitor()
{
	setVisibilityOfForm(pMainForm,0);
	
	hideMenu(pMonitorMenu);
	
	setFocusMenu(pMainMenu);		
}
//------------------------------------------------------------------------------------------------------

/**
 * Evento do item que foi passado como paramentro na criacao do menu
 * @private 
*/
static int enterI2_mMonitor()
{
	hideMenu(pMonitorMenu);
	
	setFocusMenu(pMainMenu);
}
//-----------------------------------------------------------------------------------------------------
