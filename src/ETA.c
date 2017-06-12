/**
 * @file ETA.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Controler da camada de negocio
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
#include "DataAcquisition.h"
#include "ETA.h"

/**
 * Funcao chamada pela Thread responsavel pela camada de dominio para execucao das tasks
 * @public
*/
void processTasksOfDomain(void)
{
	setFlowSensorIn(		getFlowIn());
	setFlowSensorOut(		getFlowOut());
	setFlowSensorOil(		getFlowOil());
	
	setDispenserCloro(		getDispenserCloro());
	setDispenserPH(			getDispenserPH());
	setDispenserFloculante(	getDispenserFloculante());
	setDispenserCoagulante(	getDispenserCoagulante());
	
	setLevelOilSeparator( getTankSeparatorOil());
	setLevelTankOut(		getTankOut());
	setLevelTankIn(			getTankIn());
	setLevelTankChemical(	getTankChemical());		
}
//-------------------------------------------------------------------------------------------------------------

/**
 * Inicializa as Entidades do dominio
 * @public
*/
void initEntities(void)
{
	initValve();
	initPump();
	initFlowSensor();
	initTanks();
	initDispenser();
}
//-------------------------------------------------------------------------------------------------------------
