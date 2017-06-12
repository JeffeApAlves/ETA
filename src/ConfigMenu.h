#ifndef CONFIG_MENU_H
#define CONFIG_MENU_H

#include "Menu.h"

/**@private*/
static int enterI0_mConfig();
static int enterI1_mConfig();
static int enterI2_mConfig();

/**@public*/
void createConfigurationMenu(int left,int top);

/**@public Variaveis*/
extern TMenu*	pConfigMenu;

#endif
