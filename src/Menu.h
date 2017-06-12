#ifndef MENU_H
#define MENU_H

#include <curses.h>
#include <panel.h>
#include "Type.h"
#include "Macro.h"

#define MAX_ITEM		    20
#define	MARGEN_TEXT_TOP		1
#define	MARGEN_TEXT_LEFT	1

#define H_MENU_HOR	    	((2* MARGEN_TEXT_TOP)+1)
#define W_MENU_HOR	    	COLS
#define H_MENU_VER	    	((2 * MARGEN_TEXT_TOP) + m->Count)
#define W_MENU_VER	    	(COLS/4.0)                          //todo quantidade de colunas da tela em 4 partes


/**Ponteiros para as funcoes de eventos*/
typedef	int	(*TOnSelect)();
typedef	int	(*TOnEnter)();

/** Estrutura do item do menu*/
typedef struct{

	TText		Text[MAX_TEXT_LEN];
	TStatusItem	Status;
	int			Id;
	TOnEnter	OnEnter;
	TOnSelect	OnSelect;
}TItem;

/** Estrutura do menu*/
typedef struct{

	int			Left,Top;
	int			Focused;
	int			Count;
	int			Id;
	int			ItemSelected;
	TItem*		pItens[MAX_ITEM];
	WINDOW*		pWindow;
	PANEL*		pPanel;
	TStyle		Style;

} TMenu;

/** @private Funcoes*/
static void initMenu(TMenu* m);
static void createWindowMenu(TMenu* m);
static void drawMenu(TMenu *m);
static void printItemItem(TMenu *m,int i,bool selected);
static void executeOnEnter(TMenu* m);
static void addItem(TMenu *m,TText *str,TOnEnter onenter,TOnSelect onselect);
static void addItemList(TMenu* m,TText* itens[],const TOnEnter events[],int size);
static void deleteItem(TMenu* m,int index);

/** @public Funcoes*/
void destrutorMenu(TMenu* m);
TMenu* constructMenu(int left, int top,TText* itens[],const TOnEnter events[],int size,TStyle	style);
void setOnEnter(TMenu* m,int index_item,TOnEnter func);
void setOnSelect(TMenu* m,int index_item,TOnSelect func);
void setFocus(TMenu* m);
void priorItem(TMenu *m);
void nextItem(TMenu *m);
void hideMenu(TMenu *m);
void showMenu(TMenu *m);
void updateMenu(TMenu *m);

#endif
