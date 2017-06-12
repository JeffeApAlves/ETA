#ifndef MISC_H
#define MISC_H

#include "Type.h"

/**@public Funcoes*/
int getLargerItem(char* str[],int size);
void floatToString(TText* out,float valor);
float calcPercentual(float valor,TScale* scale);
int anyKey(void);

#endif
