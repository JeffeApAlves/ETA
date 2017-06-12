/**
 * @file Dispenser.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Entidade dosador
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
#include "Dispenser.h"

TDispenser		DispenserPH,DispenserCloro,DispenserFloculante,DispenserCoagulante;

/**
 *
 * @public
*/
void initDispenser(void)
{
	TScale scale = {.Max = 100,.Min = 0};
	
	setDispenser(&DispenserCloro,		TEXT_CLORO,		UNIT_VOLUME_ML,scale);
	setDispenser(&DispenserPH,			TEXT_PH,		UNIT_VOLUME_ML,scale);
	setDispenser(&DispenserFloculante,	TEXT_FLOCULANTE,UNIT_VOLUME_ML,scale);
	setDispenser(&DispenserCoagulante,	TEXT_COAGULANTE,UNIT_VOLUME_ML,scale);			
}
//--------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setDispenserCloro(float val)
{
	DispenserCloro.Valor		= val;
	DispenserCloro.Percentual	= calcPercentual(DispenserCloro.Valor,&DispenserCloro.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setDispenserPH(float val)
{
	DispenserPH.Valor		= val;
	DispenserPH.Percentual	= calcPercentual(val,&DispenserCloro.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setDispenserFloculante(float val)
{
	DispenserFloculante.Valor		= val;
	DispenserFloculante.Percentual	= calcPercentual(val,&DispenserFloculante.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setDispenserCoagulante(float val)
{
	DispenserCoagulante.Valor		= val;
	DispenserCoagulante.Percentual	= calcPercentual(val,&DispenserCoagulante.Scale);	
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
void setDispenser(TDispenser* out,TText title[],TText unit[],TScale scale)
{
	strcpy(out->Label,		title);
	strcpy(out->Unidade,	unit);
	out->Scale	= scale;
	
	out->Percentual = calcPercentual(out->Valor,&out->Scale);
}
//--------------------------------------------------------------------------------------------------------------------
