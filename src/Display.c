/**
 * @file Display.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Componente display
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
#include "Misc.h"
#include "Display.h"

/**
 * Contrtutor: Cria um display na tela na posicao left,top
*/
TDisplay* constructDisplay(int left,int top)
{
	TDisplay* 	d = registerDisplay();

	initDisplay(d);

	d->Left		= left;
	d->Top		= top;

	createWindowDisplay(d);

	return d;
}
//------------------------------------------------------------------------------------------------------

/**
 * Destrutor: Exclui display
*/
void destrutorDisplay(TDisplay* d)
{
	if(d!=NULL)	{

		delwin( d->pWindow );

		unregisterDisplay(d);
	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Inicializa variavei do display
 *@private
*/
static void initDisplay(TDisplay* d)
{
	if(d!=NULL){

		d->pWindow	= NULL;
		d->pPanel	= NULL;

		d->Percentual = 0;
		setDispLabel(d,"");
		setDispText(d,0.0);
		setDispUnidade(d,"");
		setDispMin(d,0.0);
		setDispMax(d,0.0);
	}
}
//------------------------------------------------------------------------------------------------------

/**
	Desenha o display
*/
static void drawDisplay(TDisplay* d)
{
	int row,col;

	box(d->pWindow, 0 , 0 );

	getmaxyx( d->pWindow, row, col );

	mvwprintw(d->pWindow, 0 , 1,FORMAT_LABEL, d->Label );
	mvwprintw(d->pWindow, 2 , 1,FORMAT_VAL, d->Text );
	mvwprintw(d->pWindow, 0 , col-strlen(d->Unidade)-3 ,FORMAT_UNIT,d->Unidade );
	mvwprintw(d->pWindow, 5 , 1,FORMAT_MIN, d->Min );
	mvwprintw(d->pWindow, 5 , col-strlen(d->Max)-3,FORMAT_MAX, d->Max );

	drawBarGraph(d,d->Percentual);
}
//------------------------------------------------------------------------------------------------------

/**
	Cria janela e painel do display
*/
static void createWindowDisplay(TDisplay* d)
{
	if(d!=NULL && d->pWindow==NULL){

		d->pWindow	= newwin((LINES-2)/4.0,	 COLS /4.0, d->Top, d->Left);
		d->pPanel	= new_panel(d->pWindow);
	}
}
//---------------------------------------------------------------------------------------------------

/**
	Funcao chamada na Thread que cuida da atualizacao da tela
*/
void updateDisp(TDisplay* d)
{
//    if(d!=NULL && panel_hidden(d->pPanel)==TRUE	){

		drawDisplay(d);
//    }
}
//---------------------------------------------------------------------------------------------------

inline void setDispLabel(TDisplay* d,TText* str)
{
	if(d!=NULL)
		strcpy(d->Label,str);
}
//---------------------------------------------------------------------------------------------------

inline void setDispUnidade(TDisplay* d,TText* str)
{
	if(d!=NULL)
		strcpy(d->Unidade,str);
}
//---------------------------------------------------------------------------------------------------

inline void hideDisp(TDisplay* d)
{
	if(d!=NULL)
		hide_panel (d->pPanel);
}
//---------------------------------------------------------------------------------------------------

inline void showDisp(TDisplay* d)
{
	if(d!=NULL){

		show_panel (d->pPanel);
	}
}
//---------------------------------------------------------------------------------------------------

void drawBarGraph(TDisplay* d,int qt)
{
	int i;

	int fill = qt * (LEN_MAX_BARGRAPH/100.0);

	for(i=0;i<LEN_MAX_BARGRAPH;i++)
		mvwaddch(d->pWindow, 6, 2+i, i<fill? 178: 196);
}
//---------------------------------------------------------------------------------------------------

void setDispInfo(TDisplay* d, TText* label, TText* unidade, float valor,TScale scale)
{
	if(d!=NULL){

		setDispLabel(d,label);
		setDispUnidade(d,unidade);
		setDispMin(d,scale.Min);
		setDispMax(d,scale.Max);
		setDispText(d,valor);
	}
}
//----------------------------------------------------------------------------------------------------------------

inline void setDispText(TDisplay* d,float valor)
{
	if(d!=NULL)
		floatToString(d->Text,valor);
}
//---------------------------------------------------------------------------------------------------

inline void setDispMin(TDisplay* d,float valor)
{
	if(d!=NULL)
		floatToString(d->Min,valor);
}
//---------------------------------------------------------------------------------------------------

inline void setDispMax(TDisplay* d,float valor)
{
	if(d!=NULL)
		floatToString(d->Max,valor);
}
//---------------------------------------------------------------------------------------------------

inline void setDispPercentual(TDisplay* d,TPercentual valor)
{
	if(d!=NULL)
		d->Percentual = valor;
}
//---------------------------------------------------------------------------------------------------
