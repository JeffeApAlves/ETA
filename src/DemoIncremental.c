/**
 * @file DemoIncremental.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Implementa a interface de comunicacao e simula comunicacao retornando incremental no object value
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
#include "DemoIncremental.h"

const TDAInterface	iDemoIncremental = {

									.init=initDemoIncremental,
									.deInit=deInitDemoIncremental,
									.comunic=comunicDemoIncremental,
									.getAll=getAllDemoIncremental,
									.getId = getIdDemoIncremental
								};


/**
 *
 * @private
*/
static TInterface getIdDemoIncremental()
{
	return INTERFACE_SIM_INCR;
}
//---------------------------------------------------------------------------------------------------------------

/**
 *
 * @private
*/
static int initDemoIncremental()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 *
 * @private
*/
static int deInitDemoIncremental()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 *
 * @private
*/
static int comunicDemoIncremental()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 *
 * @public
*/
static int getAllDemoIncremental(TValueObjectDA* const out)
{
	if(out!=NULL){

		out->Dispenser.Cloro		= getDemoIncrementalDispenserCloro();
		out->Dispenser.Coagulante	= getDemoIncrementalDispenserCoagulante();
		out->Dispenser.Floculante	= getDemoIncrementalDispenserFloculante();
		out->Dispenser.pH			= getDemoIncrementalDispenserPH();

		out->Sensor.FlowIn		= getDemoIncrementalFlowIn();
		out->Sensor.FlowOut		= getDemoIncrementalFlowOut();
		out->Sensor.FlowOil		= getDemoIncrementalFlowOil();

		out->Tank.Chemical		= getDemoIncrementalTankChemical();
		out->Tank.In			= getDemoIncrementalTankIn();
		out->Tank.Out			= getDemoIncrementalTankOut();
		out->Tank.SeparatorOil	= getDemoIncrementalTankSeparatorOil();

		out->Pump.Main			= getDemoIncrementalPumpMain();
		out->Valve.Out			= getDemoIncrementalValve();
	}

	return 0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 *
 * @public
*/
const TDAInterface* getInterfaceDemoIncremental()
{
	return	&iDemoIncremental;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalDispenserCloro()
{
	static int  i = 0;

	i++;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalDispenserCoagulante()
{
	static int  i = 0;

	i++;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalDispenserFloculante()
{
	static int  i = 0;

	i++;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalDispenserPH()
{
	static int  i = 0;

	i++;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalFlowIn()
{
	static float  i = 0;

	i+=0.1;

	return i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalFlowOut()
{
	static float  i = 0;

	i+=0.1;

	return i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalFlowOil()
{
	static float  i = 0;

	i+=0.1;

	return i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalTankChemical()
{
	static int  i = 0;

	i+=50;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalTankIn()
{
	static int  i = 0;

	i+=5;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalTankOut()
{
	static int  i = 0;

	i+=20;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoIncrementalTankSeparatorOil()
{
	static int  i = 0;

	i+=15;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static int getDemoIncrementalPumpMain()
{
	return 0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static int getDemoIncrementalValve()
{
	return 0;
}
//---------------------------------------------------------------------------------------------------------------
