/**
 * @file MainForm.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief  Formulario principal Ajustar a tela do terminal para 100 colunas x 35 linhas e fonte Courier New
 * 
 * 
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#include "Valve.h"
#include "Pump.h"
#include "Tank.h"
#include "FlowSensor.h"
#include "Dispenser.h"
#include "MainForm.h"
#include "Container.h"

TMainForm*	pMainForm=NULL;

/**
 * Contrutor
*/
TMainForm* constructMainForm(void)
{
	TMainForm* mainform = registerForm();
	
	createDisplays(mainform);
	
	setLabels(mainform);
	
	return mainform;
}
//----------------------------------------------------------------------------------------------------------------

/**
 * Destrutor
*/
static void createDisplays(TMainForm* mf)
{
	mf->FlowSensorIn		= constructDisplay(GRID(1,0));
	mf->FlowSensorOut		= constructDisplay(GRID(2,0));
	mf->FlowSensorOil		= constructDisplay(GRID(3,0));

	mf->DispenserCoagulante	= constructDisplay(GRID(0,1));
	mf->DispenserCloro		= constructDisplay(GRID(1,1));
	mf->DispenserFloculante	= constructDisplay(GRID(2,1));
	mf->DispenserPH			= constructDisplay(GRID(3,1));

	mf->OilSeparetor		= constructDisplay(GRID(0,2));
	mf->TankOut				= constructDisplay(GRID(1,2));
	mf->TankIn				= constructDisplay(GRID(2,2));
	mf->TankChemical		= constructDisplay(GRID(3,2));
		
	mf->Pump				= constructDisplay(GRID(0,3));
	mf->Valve				= constructDisplay(GRID(3,3));
	
}
//----------------------------------------------------------------------------------------------------------------

/**
 *
*/
void destrutorMainForm(TMainForm* mf)
{
	if(mf!=NULL){
		unregisterForm(mf);			
	}
}
//----------------------------------------------------------------------------------------------------------------

/**
 *
*/
void setLabels(TMainForm* mf)
{
	setDispInfo(mf->FlowSensorIn,		FlowSensorIn.Label,
										FlowSensorIn.Unidade,
										FlowSensorIn.Valor,
										FlowSensorIn.Scale);

	setDispInfo(mf->FlowSensorOut,		FlowSensorOut.Label,
										FlowSensorOut.Unidade,
										FlowSensorOut.Valor,
										FlowSensorOut.Scale);												

	setDispInfo(mf->FlowSensorOil,		FlowSensorOil.Label,
										FlowSensorOil.Unidade,
										FlowSensorOil.Valor,
										FlowSensorOil.Scale);	

	setDispInfo(mf->DispenserCoagulante,DispenserCoagulante.Label,
										DispenserCoagulante.Unidade,
										DispenserCoagulante.Valor,
										DispenserCoagulante.Scale);

	setDispInfo(mf->DispenserCloro,		DispenserCloro.Label,
										DispenserCloro.Unidade,
										DispenserCloro.Valor,
										DispenserCloro.Scale);

	setDispInfo(mf->DispenserFloculante,	DispenserFloculante.Label,
										DispenserFloculante.Unidade,
										DispenserFloculante.Valor,
										DispenserFloculante.Scale);

	setDispInfo(mf->DispenserCloro,		DispenserCloro.Label,
										DispenserCloro.Unidade,
										DispenserCloro.Valor,
										DispenserCloro.Scale);

	setDispInfo(mf->DispenserPH,		DispenserPH.Label,
										DispenserPH.Unidade,
										DispenserPH.Valor,
										DispenserPH.Scale);
												
	setDispInfo(mf->OilSeparetor,		OilSeparator.Label,
										OilSeparator.Unidade,
										OilSeparator.Valor,
										OilSeparator.Scale);	
												
	setDispInfo(mf->TankOut,			TankOut.Label,
										TankOut.Unidade,
										TankOut.Valor,
										TankOut.Scale);


	setDispInfo(mf->TankIn,				TankIn.Label,
										TankIn.Unidade,
										TankIn.Valor,
										TankIn.Scale);
												

	setDispInfo(mf->TankChemical,		TankChemical.Label,
										TankChemical.Unidade,
										TankChemical.Valor,
										TankChemical.Scale);
												
	setDispInfo(mf->Pump,				Pump.Label,
										Pump.Unidade,
										0,
										Pump.Scale);																								

	setDispInfo(mf->Valve,				ValveOut.Label,
										ValveOut.Unidade,
										0,
										ValveOut.Scale);																								
}
//----------------------------------------------------------------------------------------------------------------

/**
 *
*/
void updateForm(TMainForm* mf)
{
	setDispText(mf->FlowSensorIn,FlowSensorIn.Valor);
	setDispPercentual(mf->FlowSensorIn,FlowSensorIn.Percentual);	
	
	setDispText(mf->FlowSensorOut,FlowSensorOut.Valor);
	setDispPercentual(mf->FlowSensorOut,FlowSensorOut.Percentual);	
	
	setDispText(mf->FlowSensorOil,FlowSensorOil.Valor);
	setDispPercentual(mf->FlowSensorOil,FlowSensorOil.Percentual);	
	
	setDispText(mf->DispenserCoagulante,DispenserCoagulante.Valor);
	setDispPercentual(mf->DispenserCoagulante,DispenserCoagulante.Percentual);	
	
	setDispText(mf->DispenserCloro,DispenserCloro.Valor);
	setDispPercentual(mf->DispenserCloro,DispenserCloro.Percentual);
	
	setDispText(mf->DispenserFloculante,DispenserFloculante.Valor);
	setDispPercentual(mf->DispenserFloculante,DispenserFloculante.Percentual);	
	
	setDispText(mf->DispenserPH,DispenserPH.Valor);
	setDispPercentual(mf->DispenserPH,DispenserPH.Percentual);	
	
	setDispText(mf->OilSeparetor,OilSeparator.Valor);
	setDispPercentual(mf->OilSeparetor,OilSeparator.Percentual);	
		
	setDispText(mf->TankOut,TankOut.Valor);
	setDispPercentual(mf->TankOut,TankOut.Percentual);	
		
	setDispText(mf->TankIn,TankIn.Valor);
	setDispPercentual(mf->TankIn,TankIn.Percentual);	
		
	setDispText(mf->TankChemical,TankChemical.Valor);
	setDispPercentual(mf->TankChemical,TankChemical.Percentual);	
			
	setDispText(mf->Pump,Pump.Status);
	setDispText(mf->Valve,ValveOut.Status);		
}
//----------------------------------------------------------------------------------------------------------------
