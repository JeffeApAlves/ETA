/**
 * @file RBPI3.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Implementa a interface de comunicacao para o HW da RaspBery PI3
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
#include "RBPI3.h"

const TDAInterface	iRBPI3 = {
									.init=initRBPI3,
									.deInit=deInitRBPI3,
									.comunic=comunicRBPI3,
									.getAll=getAllRBPI3,
									.getId = getIdRBPI3
								};

static TInterface getIdRBPI3()
{
	return INTERFACE_RBPI3;
}
//---------------------------------------------------------------------------------------------------------------

static int initRBPI3()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

static int deInitRBPI3()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

static int comunicRBPI3()
{
	return	0;
}
//---------------------------------------------------------------------------------------------------------------

static int getAllRBPI3(TValueObjectDA* const out)
{
	if(out!=NULL){

		out->Dispenser.Cloro		= getRBPI3DispenserCloro();
		out->Dispenser.Coagulante	= getRBPI3DispenserCoagulante();
		out->Dispenser.Floculante	= getRBPI3DispenserFloculante();
		out->Dispenser.pH			= getRBPI3DispenserPH();

		out->Sensor.FlowIn		= getRBPI3FlowIn();
		out->Sensor.FlowOut		= getRBPI3FlowOut();
		out->Sensor.FlowOil		= getRBPI3FlowOil();

		out->Tank.Chemical		= getRBPI3TankChemical();
		out->Tank.In			= getRBPI3TankIn();
		out->Tank.Out			= getRBPI3TankOut();
		out->Tank.SeparatorOil	= getRBPI3TankSeparatorOil();

		out->Pump.Main			= getRBPI3PumpMain();
		out->Valve.Out			= getRBPI3Valve();
	}

	return 0;
}
//---------------------------------------------------------------------------------------------------------------

const TDAInterface* getInterfaceRBPI3()
{
	return	&iRBPI3;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3DispenserCloro()
{
	int  i= rand()%10+50;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3DispenserCoagulante()
{
	int  i= rand()%10+50;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3DispenserFloculante()
{
	int  i= rand()%10+50;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3DispenserPH()
{
	int  i= rand()%10+50;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3FlowIn()
{
	int  i= rand()%2;

	return (float) i+1.0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3FlowOut()
{
	int  i= rand()%2;

	return (float) i+2.0;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3FlowOil()
{
	int  i= rand()%2;

	return (float) i+3;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3TankChemical()
{
	int  i= rand()%50+500;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3TankIn()
{
	int  i= rand()%50+500;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3TankOut()
{
	int  i= rand()%50+500;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static float getRBPI3TankSeparatorOil()
{
	int  i= rand()%50+500;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static int getRBPI3PumpMain()
{
	int  i= rand()%50+50;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @private
*/
static int getRBPI3Valve()
{
	int  i= rand()%50+50;

	return (float) i;
}
//---------------------------------------------------------------------------------------------------------------
