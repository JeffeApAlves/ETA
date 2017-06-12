/**
 * @file DataAcquisition.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Manipulador da interface de comunicacao
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#include <stdlib.h>
#include "InterfaceDA.h"
#include "DemoRandom.h"
#include "DemoIncremental.h"
#include "RBPI3.h"
#include "DataAcquisition.h"

/**
 * Ponteiro que sera utilizado para armazenar a referencia da interface ativa
 * @private
*/
static TDAInterface *iDataAcquisition = NULL;

/**
 * Object value utilizado como saida dos decodificadores de cada possivel hardware ou protocolo
 * @private
*/
static TValueObjectDA DataAcquisition;

/**
 * Seleciona a interface(Hardware) de comunicacao em tempo de execucao
 * @param ninterface id da interface a ser configurada para uso
 * @public
*/
void setInterface(TInterface ninterface)
{
	switch (ninterface){

		case INTERFACE_RBPI3:		iDataAcquisition = getInterfaceRBPI3(); 			break;
		case INTERFACE_SIM_RANDOM:	iDataAcquisition = getInterfaceDemoRandom();		break;
		case INTERFACE_SIM_INCR:	iDataAcquisition = getInterfaceDemoIncremental();	break;
		default:					iDataAcquisition = NULL; break;
	}

	if(iDataAcquisition!=NULL) iDataAcquisition->init();
}
//--------------------------------------------------------------------------------------------------------------

/**
 * Funcao que sera chamada pela Thread responsavel pela comunicacao para execucao das tarefas
 * @public
*/
void processTasksOfDataAcquisition(void)
{
	if(iDataAcquisition!=NULL){

		iDataAcquisition->comunic();
		iDataAcquisition->getAll(&DataAcquisition);
	}
}
//--------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getDispenserCloro()
{
	return DataAcquisition.Dispenser.Cloro;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getDispenserCoagulante()
{
	return DataAcquisition.Dispenser.Coagulante;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getDispenserFloculante()
{
	return DataAcquisition.Dispenser.Floculante;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
 float getDispenserPH()
{
	return DataAcquisition.Dispenser.pH;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getFlowIn()
{
	return DataAcquisition.Sensor.FlowIn;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
 float getFlowOut()
{
	return DataAcquisition.Sensor.FlowOut;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getFlowOil()
{
	return DataAcquisition.Sensor.FlowOil;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getTankChemical()
{
	return DataAcquisition.Tank.Chemical;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getTankIn()
{
	return DataAcquisition.Tank.In;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getTankOut()
{
	return DataAcquisition.Tank.Out;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
float getTankSeparatorOil()
{
	return DataAcquisition.Tank.SeparatorOil;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
int getPumpMain()
{
	return DataAcquisition.Pump.Main;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
int getValve()
{
	return DataAcquisition.Valve.Out;
}
//---------------------------------------------------------------------------------------------------------------
