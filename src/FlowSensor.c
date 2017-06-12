/**
 * @file FlowSensor.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Entidade Fluxo
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
#include "FlowSensor.h"

TFlowSensor	FlowSensorIn,FlowSensorOut,FlowSensorOil;


void initFlowSensor(void)
{
	TScale scale = {.Max = 5,.Min = 0};
	
	setFlowSensor(&FlowSensorIn, TEXT_FLOW_IN,	UNIT_FLOW,scale);
	setFlowSensor(&FlowSensorOut,TEXT_FLOW_OUT,	UNIT_FLOW,scale);
	setFlowSensor(&FlowSensorOil,TEXT_FLOW_OIL,	UNIT_FLOW,scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setFlowSensorIn(float val)
{
	FlowSensorIn.Valor		= val;
	FlowSensorIn.Percentual	= calcPercentual(FlowSensorIn.Valor,&FlowSensorIn.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setFlowSensorOut(float val)
{
	FlowSensorOut.Valor = val;
	FlowSensorOut.Percentual	= calcPercentual(FlowSensorOut.Valor,&FlowSensorOut.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
inline void setFlowSensorOil(float val)
{
	FlowSensorOil.Valor			= val;
	FlowSensorOil.Percentual	= calcPercentual(FlowSensorOil.Valor,&FlowSensorOil.Scale);
}
//---------------------------------------------------------------------------------------------------------

/**
 * gets and sets
 * @public
*/
void setFlowSensor(TFlowSensor* out,TText title[],TText unit[],TScale scale)
{
	strcpy(out->Label,		title);
	strcpy(out->Unidade,	unit);
	out->Scale	= scale;
	out->Percentual = calcPercentual(out->Valor,&out->Scale);
}
//--------------------------------------------------------------------------------------------------------------------
