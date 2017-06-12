#ifndef CONTAINER_H
#define CONTAINER_H

#include "Menu.h"
#include "Display.h"
#include "MainForm.h"
#include "Macro.h"

#define MAX_ENTITIES	20

typedef struct{
	
	TMenu* 		Menus[MAX_ENTITIES];
	TDisplay* 	Displays[MAX_ENTITIES];
	TMainForm* 	Forms[MAX_ENTITIES];
	
	TMenu*		CurrentMenu;

	int			CountMenus;
	int			CountDisplays;
	int			CountForms;	
	
} TContainer;

/**@private*/
static void updateAllEntities(void);

/**@public*/
void processTasksOfTUI(void);
void deleteAllTuiEntities(void);
void setFocusMenu(TMenu* m);
void unregisterDisplay(TDisplay* disp);
TDisplay* registerDisplay(void);
void unregisterMenu(TMenu* menu);
TMenu* registerMenu(void);
void unregisterForm(TMainForm* form);
TMainForm* registerForm(void);
void initContainer(void);
void setVisibilityOfForm(TMainForm* f,int show);

#endif
