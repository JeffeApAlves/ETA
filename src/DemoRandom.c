/**
 * @file DemoRandom.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Implementa a interface de comunicacao e simula comunicacao retornando valores randomicos no object value
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
#include "DemoRandom.h"

const TDAInterface	iDemoRandom = {
									.init=initDemoRandom,
									.deInit=deInitDemoRandom,
									.comunic=comunicDemoRandom,
									.getAll=getAllDemoRandom,
									.getId = getIdDemoRandom
								};


static TInterface getIdDemoRandom()
{
	return INTERFACE_SIM_RANDOM;
}
//---------------------------------------------------------------------------------------------------------------

static int initDemoRandom()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

static int deInitDemoRandom()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

static int comunicDemoRandom()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

static int getAllDemoRandom(TValueObjectDA* const out)
{
	if(out!=NULL){

		out->Dispenser.Cloro		= getDemoRandomDispenserCloro();
		out->Dispenser.Coagulante	= getDemoRandomDispenserCoagulante();
		out->Dispenser.Floculante	= getDemoRandomDispenserFloculante();
		out->Dispenser.pH			= getDemoRandomDispenserPH();

		out->Sensor.FlowIn		= getDemoRandomFlowIn();
		out->Sensor.FlowOut		= getDemoRandomFlowOut();
		out->Sensor.FlowOil		= getDemoRandomFlowOil();

		out->Tank.Chemical		= getDemoRandomTankChemical();
		out->Tank.In			= getDemoRandomTankIn();
		out->Tank.Out			= getDemoRandomTankOut();
		out->Tank.SeparatorOil	= getDemoRandomTankSeparatorOil();

		out->Pump.Main			= getDemoRandomPumpMain();
		out->Valve.Out			= getDemoRandomValve();
	}

	return 0;
}
//---------------------------------------------------------------------------------------------------------------

const TDAInterface* getInterfaceDemoRandom()
{
	return	&iDemoRandom;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomDispenserCloro()
{
	int  i= rand()%100;

	return (float)i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomDispenserCoagulante()
{
	int  i= rand()%100;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomDispenserFloculante()
{
	int  i= rand()%10+20;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomDispenserPH()
{
	int  i= rand()%20+80;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomFlowIn()
{
	int  i= rand()%5;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomFlowOut()
{
	int  i= rand()%5;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomFlowOil()
{
	int  i= rand()%5;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomTankChemical()
{
	int  i= rand()%10000;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomTankIn()
{
	int  i= rand()%2000;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomTankOut()
{
	int  i= rand()%2000;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getDemoRandomTankSeparatorOil()
{
	int  i= rand()%2000;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static int getDemoRandomPumpMain()
{
	int  i= rand()%2000;

	return i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static int getDemoRandomValve()
{
	int  i= rand()%2000;

	return i;
}
//---------------------------------------------------------------------------------------------------------------
