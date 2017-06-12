#ifndef PUMP_H
#define PUMP_H

#include "Type.h"

typedef struct{
	
	TText			Label[MAX_TEXT_LEN];	
	TText			Unidade[MAX_TEXT_LEN];	
	TScale			Scale;
	TSensorStatus	Status;	
	
}TPump;


/**@public Funcoes*/
void initPump(void);

/**@public Variaveis*/
extern TPump Pump;

#endif
