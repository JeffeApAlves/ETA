/**
 * @file
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 08.04.2017
 * @brief Entidade Valvula
 *
 *
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 */

#include <string.h>
#include "Misc.h"
#include "BR_pt.h"
#include "Valve.h"

TValve			ValveOut;

void initValve(void)
{
	strcpy(ValveOut.Label,		TEXT_VALVE_OUT);
	strcpy(ValveOut.Unidade,	UNIT_BINARIO);
}
//---------------------------------------------------------------------------------------------------
