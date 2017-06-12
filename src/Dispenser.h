#ifndef Dispenser_H
#define Dispenser_H

#include "Type.h"

typedef struct{
	
	TText Label[MAX_TEXT_LEN];		
	TText Unidade[MAX_TEXT_LEN];

	TSensorStatus	Status;
	TDose			Valor;
	TPercentual		Percentual;
	TScale			Scale;	

}TDispenser;


/**@public Funcoes*/
void initDispenser(void);
void setDispenserCoagulante(float val);
void setDispenserFloculante(float val);
void setDispenserPH(float val);
void setDispenserCloro(float val);
void setDispenser(TDispenser* out,TText title[],TText unit[],TScale scale);

/**@public Variaveis*/
extern TDispenser		DispenserPH,DispenserCloro,DispenserFloculante,DispenserCoagulante;

#endif
