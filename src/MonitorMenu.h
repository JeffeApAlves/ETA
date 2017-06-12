#ifndef MONITOR_MENU_H
#define MONITOR_MENU_H

#include "Menu.h"

/**@private*/
static int enterI0_mMonitor();
static int enterI1_mMonitor();
static int enterI2_mMonitor();

/**@public*/
void createMonitorMenu(int left,int top);

/**@public Variaveis*/
extern TMenu*	pMonitorMenu;
#endif
