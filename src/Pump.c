/**
 * @file Pump.c
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Entidade Bomba
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
#include "Pump.h"

TPump			Pump;

void initPump(void)
{
	strcpy(Pump.Label,		TEXT_PUMP);
	strcpy(Pump.Unidade,	UNIT_BINARIO);	
}
//------------------------------------------------------------------------------------------------------------------------
