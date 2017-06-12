#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Menu.h"

/**@private*/
static int enterI0_mMain();
static int enterI1_mMain();
static int enterI2_mMain();
static int enterI3_mMain();

/**@public Funcoes*/
void createMainMenu(int left,int top);

/**@public Variaveis*/
extern TMenu*	pMainMenu;

#endif
