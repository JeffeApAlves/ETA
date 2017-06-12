#ifndef DISPLAY_H
#define DISPLAY_H

#include <curses.h>
#include <panel.h>

#include "BR_pt.h"
#include "Type.h"

#define	LEN_MAX_BARGRAPH	20


typedef struct{
	
	int		Left,Top;
	
	TText Label[MAX_TEXT_LEN];
	TText Unidade[MAX_TEXT_LEN];
	
	TText Text[MAX_TEXT_LEN];	
	TText Min[MAX_TEXT_LEN];
	TText Max[MAX_TEXT_LEN];
				
	WINDOW*		pWindow;
	PANEL*		pPanel;	
	
	int			Id;
	
	TPercentual	Percentual;
	
} TDisplay;

/**@private*/
static void initDisplay(TDisplay* d);
static void drawDisplay(TDisplay* d);
static void createWindowDisplay(TDisplay* d);

/**@public Funcoes*/
TDisplay* constructDisplay(int left,int top);
void destrutorDisplay(TDisplay* d);
void hideDisp(TDisplay* d);
void updateDisp(TDisplay* d);
void setDispLabel(TDisplay* d,TText* str);
void setDispUnidade(TDisplay* d,TText* str);
void showDisp(TDisplay* d);
void setDispMax(TDisplay* d,float valor);
void setDispMin(TDisplay* d,float valor);
void setDispText(TDisplay* d,float valor);
void setDispInfo(TDisplay* d,  TText* label, TText* unidade, float valor,TScale scale);
void setDispPercentual(TDisplay* d,TPercentual valor);

#endif
