#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include "Display.h"
#include "Macro.h"

typedef struct{

	int	Id;
	
	TDisplay* FlowSensorIn;
	TDisplay* FlowSensorOut;	
	TDisplay* FlowSensorOil;		
	
	TDisplay* DispenserCoagulante;
	TDisplay* DispenserCloro;
	TDisplay* DispenserFloculante;
	TDisplay* DispenserPH;
	
	TDisplay* OilSeparetor;		
	TDisplay* TankOut;
	TDisplay* TankIn;	
	TDisplay* TankChemical;
		
	TDisplay* Pump;
	TDisplay* Valve;			
	
} TMainForm;

/**@private*/
static void createDisplays(TMainForm* mf);

/**@public Funcoes*/
void destrutorMainForm(TMainForm* mf);
void setLabels(TMainForm* mf);
TMainForm* constructMainForm(void);
void updateForm(TMainForm* mf);
void showForm(TMainForm* f,int show);

extern TMainForm*	pMainForm;
#endif
