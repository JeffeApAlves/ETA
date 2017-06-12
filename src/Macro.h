#ifndef MACRO_H
#define MACRO_H

#include "Menu.h"           // altura do menu usado na macro grid
#include <stdlib.h>			// malloc and free

#ifdef WIN32
#define CLEAR_SCREEN    "cls"
#else
#define CLEAR_SCREEN    "clear"
#endif // WIN32

/**
* Cria dinamicamente um objeto do tipo type
*/
#define	NEW_OBJ(type)\
				(type*)(malloc(sizeof(type)))
//---------------------------------------------------------------------------------------------------------------------------------

/**
 * Exclui dinamicamente um objeto
*/
#define	DELETE_OBJ(obj)\
					if(obj!=NULL)\
						free(obj)
//---------------------------------------------------------------------------------------------------------------------------------

/**
 * Cria um menu vertical a partir de uma lista
*/
#define	createVerticalMenu(menu,events,left,top,args...)\
							if(menu==NULL){\
								TText* itens[] ={args};\
								int size = (int)( sizeof(itens) / sizeof(itens[0]) );\
								menu = constructMenu(left,top,itens,events,size,VERTICAL);}

//---------------------------------------------------------------------------------------------------------------------------------

/**
 * Cria um menu horizontal a partir de uma lista
*/
#define	createHorizontalMenu(menu,events,left,top,args...)\
							if(menu==NULL){\
								TText* itens[]={args};\
								int size = (int)( sizeof(itens) / sizeof(itens[0]) );\
								menu = constructMenu(left,top,itens,events,size,HORIZONTAL);}
//---------------------------------------------------------------------------------------------------------------------------------

/**
 * grid para o formulario principal divide a area em 4 x 4 espacas iguais para criacao das janelas
 * a constante 3 e para descontar o espaco gaso no menu principa Horizontal
 * @todo Criar define para a altura do menu horizontal
*/
#define GRID(l,t)	(int)(l*(COLS/4.0)),(int)(t*((LINES-2)/4.0))+H_MENU_HOR
//---------------------------------------------------------------------------------------------------------------------------------


#endif
