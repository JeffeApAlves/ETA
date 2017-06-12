#ifndef VALVE_H
#define VALVE_H

#include "Type.h"

typedef struct{
	
	TText			Label[MAX_TEXT_LEN];
	TText			Unidade[MAX_TEXT_LEN];
	TScale			Scale;
	TSensorStatus	Status;
}TValve;


/**@public*/
void initValve(void);
extern TValve	ValveOut;

#endif

