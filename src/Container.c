/**
 * @file Container.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Container para "objetos" do TUI
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#include "Container.h"

TContainer Container;

/**
 * Incializa o container
 *@public
*/
void initContainer(void)
{
	int i;

	for(i=0;i<MAX_ENTITIES;i++){

		Container.Menus[i]		=NULL;
		Container.Displays[i]	=NULL;
		Container.Forms[i]		=NULL;
	}

	Container.CurrentMenu	= NULL;
	Container.CountMenus	= 0;
	Container.CountDisplays	= 0;
	Container.CountForms	= 0;
}
//----------------------------------------------------------------------------------------------------

/**
 * Funcao chamada pela Thread responsavel pelo TUI para execucao das tasks
 *@public
*/
void processTasksOfTUI(void)
{
	updateAllEntities();

	refresh();

	update_panels();

	doupdate();
}
//---------------------------------------------------------------------------------------------------

/**
 *Exclui todos as entidades do TUI
 *@public
*/
void deleteAllTuiEntities(void)
{
	int i;

	for(i=0;i<Container.CountMenus;i++)
		destrutorMenu(Container.Menus[i]);

	for(i=0;i<Container.CountForms;i++)
		destrutorMainForm(Container.Forms[i]);

	for(i=0;i<Container.CountDisplays;i++)
		destrutorDisplay(Container.Displays[i]);
}
//------------------------------------------------------------------------------------------------------

/**
 *Atualiza todas as entidades do TUI
 * Processa eventos relacionados ao Menu
 * Processa eventos relacionados ao Display
 * Processa eventos relacionados ao Form
 * @private
*/
static void updateAllEntities(void)
{
	int i;

	for(i=0;i<Container.CountMenus;i++)
		updateMenu(Container.Menus[i]);

	for(i=0;i<Container.CountDisplays;i++)
		updateDisp(Container.Displays[i]);

	for(i=0;i<Container.CountForms;i++)
		updateForm(Container.Forms[i]);
}
//---------------------------------------------------------------------------------------------------

/**
 *Haibilita a entrada do teclado para a janela do menu
 *@public
*/
void setFocusMenu(TMenu* m)
{
	if(m!=NULL){

		if(Container.CurrentMenu!=NULL)
			Container.CurrentMenu->Focused = 0;

		Container.CurrentMenu = m;

		showMenu(m);
		setFocus(m);
    }
}
//---------------------------------------------------------------------------------------------------

/**
 *
 *@public
*/
TMenu* registerMenu(void)
{
	TMenu* menu = NEW_OBJ(TMenu);

	if(menu!=NULL){

		menu->Id =Container.CountMenus;
		Container.Menus[Container.CountMenus] = menu;
		Container.CountMenus++;
	}

	return menu;
}
//---------------------------------------------------------------------------------------------------

/**
 *
 *@public
*/
void unregisterMenu(TMenu* menu)
{
	if(menu!=NULL){

		Container.CountMenus--;
		Container.Menus[menu->Id] = NULL;
		DELETE_OBJ(menu);
	}
}
//---------------------------------------------------------------------------------------------------

/**
 *
 *@public
*/
TDisplay* registerDisplay(void)
{
	TDisplay* disp = NEW_OBJ(TDisplay);

	if(disp!=NULL){

		disp->Id = Container.CountDisplays;
		Container.Displays[Container.CountDisplays] = disp;
		Container.CountDisplays++;
	}

	return disp;
}
//---------------------------------------------------------------------------------------------------

/**
 *
 *@public
*/
void unregisterDisplay(TDisplay* disp)
{
	if(disp!=NULL){

		Container.CountDisplays--;
		Container.Displays[disp->Id] = NULL;
		DELETE_OBJ(disp);
	}
}
//---------------------------------------------------------------------------------------------------

/**
 *
 *@public
*/
TMainForm* registerForm(void)
{
	TMainForm* form = NEW_OBJ(TMainForm);

	if(form!=NULL){

		form->Id = Container.CountForms;
		Container.Forms[Container.CountForms] = form;
		Container.CountForms++;
	}

	return form;
}
//---------------------------------------------------------------------------------------------------

/**
 *
 *@public
*/
void unregisterForm(TMainForm* form)
{
	if(form!=NULL){

		Container.CountDisplays--;
		Container.Forms[form->Id] = NULL;
		DELETE_OBJ(form);
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Configura a visiilidade do Form na tela
 * @todo Melhorar criando painel para o formulario e manipualndo o proprio
 * @param show Se o valor for 0 oculta o form na tela show diferente de 0 entao mostra
 * @param f Referencia do formulario que se desja manipular
*/
void setVisibilityOfForm(TMainForm* f,int show)
{
	int i;

	if(f!=NULL){

		for(i=0;i<Container.CountDisplays;i++){

			if(show){
				showDisp(Container.Displays[i]);
			}else{
				hideDisp(Container.Displays[i]);
			}
		}
	}
}
//-----------------------------------------s----------------------------------------------------------
