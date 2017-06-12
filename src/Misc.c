/**
 * @file
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Funcoes de uso gerais
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#ifndef WIN32
#include <termios.h>
#endif // WIN32
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "BR_pt.h"
#include "Misc.h"

/**
 * Retorna o tammnho do maior Caption entre os itens de uma lista
 * @public
 * @param str Referencia da lista
 * @param size Quantidade itens
*/
int getLargerItem(char* str[],int size)
{
 	int temp,ret_len=0,i;

	for( i=0; i<size; i++ ) {

		if(str[i]!=NULL){

			temp = strlen (str[i]);

			if(ret_len<temp){

				ret_len = temp;
			}
		}
	}

 	return ret_len;
}
//---------------------------------------------------------------------------------------------------

/**
 * Converte um float em string
 * @public
*/
void floatToString(TText* out,float valor)
{
	TText str[MAX_TEXT_LEN];\
	sprintf(str,FORMAT_DISP,valor);\
	strcpy(out,str);
}
//---------------------------------------------------------------------------------------------------------------------------------

/**
 * Calcula o percentual do valor em relacao a uma escala
 * @public
*/
float calcPercentual(float valor,TScale *scale)
{
	float out=0.0;

	if(scale!=NULL){

		if((scale->Max-scale->Min)!=0.0)
			out = ((100.0*valor)/(scale->Max-scale->Min));
	}
	return out;
}
//---------------------------------------------------------------------------------------------------------------------------------

/**
 * Verifica se alguma tecla foi pressionada
 * @public
*/
int anyKey(void)
{
#ifdef WIN32
    return kbhit();
#else
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF){

        ungetc(ch, stdin);
        return 1;
    }

    return 0;
#endif // WIN32
}
//---------------------------------------------------------------------------------------------------------------------------------
