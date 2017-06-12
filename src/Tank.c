/**
 * @file Tank.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Entidade Tank
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */


#include "Misc.h"
#include "BR_pt.h"
#include "string.h"
#include "Tank.h"

TTank	OilSeparator,TankOut,TankIn,TankChemical;

void initTanks(void)
{
	TScale scale = {.Max = 1000,.Min = 0};

	setLevel(&OilSeparator,	TEXT_TANK_SOW,			UNIT_VOLUME,scale);
	setLevel(&TankOut,		TEXT_TANK_OUT,			UNIT_VOLUME,scale);
	setLevel(&TankIn,		TEXT_TANK_IN,			UNIT_VOLUME,scale);
	setLevel(&TankChemical,	TEXT_TANK_CHEMICAL,		UNIT_VOLUME,scale);
}
//--------------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
void setLevel(TTank* out,TText title[],TText unit[],TScale scale)
{
	strcpy(out->Label,		title);
	strcpy(out->Unidade,	unit);
	out->Scale	= scale;

	out->Percentual = calcPercentual(out->Valor,&out->Scale);
}
//--------------------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setLevelOilSeparator(float val)
{
	OilSeparator.Valor		= val;
	OilSeparator.Percentual	= calcPercentual(OilSeparator.Valor,&OilSeparator.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setLevelTankOut(float val)
{
	TankOut.Valor		= val;
	TankOut.Percentual	= calcPercentual(TankOut.Valor,&TankOut.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setLevelTankIn(float val)
{
	TankIn.Valor		= val;
	TankIn.Percentual	= calcPercentual(TankIn.Valor,&TankIn.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setLevelTankChemical(float val)
{
	TankChemical.Valor		= val;
	TankChemical.Percentual	= calcPercentual(TankChemical.Valor,&TankChemical.Scale);
}
//---------------------------------------------------------------------------------------------------------
