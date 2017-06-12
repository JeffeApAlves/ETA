#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include "Type.h"

typedef struct{
	
	TText Label[MAX_TEXT_LEN];		
	TText Unidade[MAX_TEXT_LEN];
		
	TSensorStatus	Status;
	TVolume			Valor;
	TPercentual		Percentual;
	TScale			Scale;
	
}TTank;


/**@public Funcoes*/
void initTanks(void);
void setLevelTankChemical(float val);
void setLevelTankIn(float val);
void setLevelTankOut(float val);
void setLevelOilSeparator(float val);
void setLevel(TTank* out,TText title[],TText unit[],TScale scale);

extern TTank	OilSeparator,TankOut,TankIn,TankChemical;

#endif
