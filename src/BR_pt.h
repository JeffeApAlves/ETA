/**
 * @BR_pt.h
 * @authors Jefferson Alves
 * @authors Rogerio Benites
 * @date 04.04.2017
 * @brief Textos em Portugues
 * de agua 
 * 
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see https://pdcurses.sourceforge.io/doc/PDCurses.txt
 * @see https://fossies.org/dox/PDCurses-3.4/index.html
 * @see https://pdcurses.sourceforge.io/
 * @see https://www.stack.nl/~dimitri/doxygen/manual/commands.html
 * @see https://www.gnu.org/prep/standards/html_node/Writing-C.html Code Style
 * @see https://pt.wikipedia.org/wiki/Biblioteca_padr%C3%A3o_do_C 
  */
  
#ifndef _BR_PT_H
#define _BR_PT_H

#define	ITEMS_SIMULATION_MENU	"Randomica", "Incremental","Parar","Voltar"
#define	ITEMS_CONFIG_MENU		"Unidades", "RaspBerry PI3", "Voltar"
#define	ITEMS_MAIN_MENU			"Monitoramento", "Simulacao", "Configuracao", "Sair"
#define	ITEMS_MONITOR_MENU		"Iniciar", "Parar", "Voltar"

#define	TEXT_CLORO				(TText*)"Cloro"
#define	TEXT_PH					(TText*)"pH"
#define	TEXT_FLOCULANTE			(TText*)"Floculante"
#define	TEXT_COAGULANTE			(TText*)"Coagulante"

#define	TEXT_FLOW_IN			(TText*)"Vazao(IN)"
#define	TEXT_FLOW_OUT			(TText*)"Vazao(OUT)"
#define	TEXT_FLOW_OIL			(TText*)"Vazao(OLEO)"

#define	TEXT_TANK_SOW			(TText*)"T. (Sep-Oleo)"
#define	TEXT_TANK_OUT			(TText*)"T. (Out)"
#define	TEXT_TANK_IN			(TText*)"T. (In)"
#define	TEXT_TANK_CHEMICAL		(TText*)"T. (Quimico)"

#define	TEXT_PUMP				(TText*)"Bomba"
#define	TEXT_VALVE_OUT			(TText*)"Valvula(Out)"

#define	FORMAT_DISP				"%5.1f"
#define	FORMAT_LABEL			"%s"
#define	FORMAT_VAL				"V: %s"
#define	FORMAT_MIN				"%s"
#define	FORMAT_MAX				"%s"
#define	FORMAT_UNIT				"[%s]"

#define	UNIT_FLOW				(TText*)"m3/s"
#define	UNIT_VOLUME_ML			(TText*)"ml"
#define	UNIT_VOLUME				(TText*)"L"
#define	UNIT_BINARIO			(TText*)"I/O"
#define	UNIT_PERCENTUAL			(TText*)"%"
#endif
