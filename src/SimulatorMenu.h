#ifndef SIMULATOR_MENU_H
#define SIMULATOR_MENU_H

#include "Menu.h"

/**@private*/
static void enterI0_mSimulator(void);
static void enterI1_mSimulator(void);
static void enterI2_mSimulator(void);
static void enterI3_mSimulator(void);

/**@public Funcoes*/
void createSimulatorMenu(int left,int top);

/**@public Variaveis*/
extern TMenu*	pSimulatorMenu;

#endif
