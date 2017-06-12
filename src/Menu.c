/**
 * @file Menu.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Componente menu criado utilizando a lib Pdcurses
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#include <string.h>
#include "Container.h"
#include "Misc.h"
#include "Menu.h"

/**
 * Contrtutor: Cria um menu com os itens da lista
 * @param itens Itens da lista
 * @param events eventos de cada item em respectiva ordem
 * @param size quantidade de itens
 * @param style define o estilo do menu horizontal ou vertical @see Type.h
 * @param left,top posicao do menu na tela
 * @return referencia do menu criado
 * @public
*/
TMenu* constructMenu(int left, int top,TText* itens[],const TOnEnter events[],int size,TStyle	style)
{
	TMenu* 	m	= registerMenu();

	initMenu(m);

	m->Left		= left;
	m->Top		= top;
	m->Style	= style;

	addItemList(m,itens,events,size);

	createWindowMenu(m);

	drawMenu(m);

	return m;
}
//------------------------------------------------------------------------------------------------------

/**
 * Destrutor: Libera toda a memoria alocado dinamicamente e exclui da lista do Container
 * @param m Referencia do menu que se deseja excluir
 * @public
*/
void destrutorMenu(TMenu* m)
{
	int i;

	if(m!=NULL)	{

		for(i = 0;i<m->Count;i++)
			DELETE_OBJ(m->pItens[i]);

		delwin( m->pWindow );

		unregisterMenu(m);

	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Inicializa as variaveis da estrutura do menu
 * @private
*/
static void initMenu(TMenu* m)
{
	int i;

	if(m!=NULL){

		m->pWindow		= NULL;
		m->pPanel		= NULL;
		m->Count		= 0;
		m->ItemSelected	= 0;
		m->Focused		= 0;
		for(i=0; i<MAX_ITEM ; i++){
			m->pItens[i] = NULL;
		}

		m->Style = VERTICAL;
	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Adiciona um lista de itens no menu
 * @private
*/
static void addItemList(TMenu* m,TText* itens[],const TOnEnter events[],int size)
{
	int i;

	if(itens!=NULL){

		for(i=0;i<size;i++){

			if(m->Count<MAX_ITEM-1){

				addItem(m,itens[i],events[i],NULL);
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Adiciona um item no menu
 * @public
*/
void addItem(TMenu* m,TText *str,TOnEnter onenter,TOnSelect onselect)
{
	if(m->Count < MAX_ITEM - 1){

		TItem* 	item = NEW_OBJ(TItem);

		strcpy(item->Text,str);

		item->Id		= m->Count;			//melhorar

		m->pItens[m->Count] = item;

		item->Status	= ENABLED;

		setOnEnter(m,item->Id,onenter);

		setOnSelect(m,item->Id,onselect);

		m->Count++;
	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Exclui item
 * @private
*/
static void deleteItem(TMenu* m,int index)
{
	if(m!=NULL){

		DELETE_OBJ(m->pItens[index]);

		m->pItens[index] = NULL;

		m->Count--;
	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Desenha o menu completo box + itens
 * Imprime todos os itens e seleciona o item atraves do valor do Index
 * @private
*/
static void drawMenu(TMenu* m)
{
    int i;

//   	box(m->pWindow,186,205);
   	box(m->pWindow,0,0);

	for(i=0; i<m->Count; i++ ) {

		printItemItem(m,i,i==m->ItemSelected);
	}
}
//------------------------------------------------------------------------------------------------------

/**
 * Set ponteiro do evento OnEnter
 * @public
*/
void setOnEnter(TMenu* m,int index_item,TOnEnter func)
{
	if(m!=NULL){

		m->pItens[index_item]->OnEnter = func;
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Set o ponteiro do evento onselect
 * @public
*/
void setOnSelect(TMenu* m,int index_item,TOnSelect func)
{
	if(m!=NULL){

		m->pItens[index_item]->OnSelect = func;
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Executa o evento onEnter
 * @private
*/
static void executeOnEnter(TMenu* m)
{
	if(m!=NULL && m->pItens[m->ItemSelected]->OnEnter!=NULL){

		m->pItens[m->ItemSelected]->OnEnter();
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Habilita a entrada do teclado para a janela do menu
 * @public
*/
void setFocus(TMenu* m)
{
	if(m!=NULL && m->pWindow!=NULL){

		m->Focused		= 1;

    	keypad( m->pWindow, TRUE );
    }
}
//---------------------------------------------------------------------------------------------------

/**
 * Imprime item do menu se selected for true item estara selecionado
 * @private
*/
static void printItemItem(TMenu *m,int i,bool selected)
{
	if( selected )
		wattron(m->pWindow, A_STANDOUT );
	else
		wattroff(m->pWindow, A_STANDOUT );

	if(m->Style == VERTICAL){
		mvwprintw(m->pWindow, MARGEN_TEXT_TOP + i,MARGEN_TEXT_LEFT, "%s", m->pItens[i]->Text );
	}else{
		mvwprintw(m->pWindow, MARGEN_TEXT_TOP ,MARGEN_TEXT_LEFT+(i*(COLS/m->Count)), "%s", m->pItens[i]->Text );
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Seleciona o item anterior do menu
 * @public
*/
void priorItem(TMenu *m)
{
	if(m!=NULL){

		m->ItemSelected = (m->ItemSelected-1 < 0)		?	m->Count-1: m->ItemSelected-1;
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Seleciona o item seguinte do menu
 * @public
*/
void nextItem(TMenu *m)
{
	if(m!=NULL){

		m->ItemSelected = (m->ItemSelected+1 > m->Count-1)	?	0: m->ItemSelected+1;
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Oculta o menu
 * @public
*/
void hideMenu(TMenu *m)
{
	if(m!=NULL){

		hide_panel (m->pPanel);
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Mostra o menu
 * @public
*/
void showMenu(TMenu *m)
{
	if(m!=NULL){

		show_panel (m->pPanel);
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Desenha a janela do menu
 * Cria a janela autosize em funcao do maior caption
 * @private
*/
static void createWindowMenu(TMenu* m)
{
	if(m!=NULL && m->pWindow==NULL){

		if(m->Style == VERTICAL){

			m->pWindow	= newwin(H_MENU_VER, W_MENU_VER , m->Top, m->Left);
		}
		else
		{
			m->pWindow	= newwin(H_MENU_HOR, W_MENU_HOR , m->Top, m->Left);
		}

		m->pPanel	= new_panel(m->pWindow);
	}
}
//---------------------------------------------------------------------------------------------------

/**
 * Funcao chamada na Thread que cuida da atualizacao da tela e processamento de eventos.
 * @remark Apenas os itens sao atualizados quando um otao e precionado o box nao.
 * @public
*/
void updateMenu(TMenu *m)
{
    int ch,i;

	if(m!=NULL && m->Focused==1 /*&& panel_hidden(m->pPanel)==TRUE*/){


        if(anyKey()){

            wtimeout(m->pWindow,1);

			ch = wgetch(m->pWindow);

			switch( ch ) {

				case KEY_UP:
				case KEY_LEFT:	priorItem(m);		break;
				case KEY_DOWN:
				case KEY_RIGHT:	nextItem(m);		break;
				case 0x0A:		executeOnEnter(m);	break;	//ENTER
			}

			for(i=0; i<m->Count; i++ ) {

				printItemItem(m,i,i==m->ItemSelected);
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------
