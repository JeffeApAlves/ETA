#ifndef INTERFACE_ACQ_H
#define INTERFACE_ACQ_H

#include "Type.h"

/**
 *Object value para retorno dos valores 
*/
typedef struct{
	
	struct {
	
		float	FlowIn,
				FlowOut,
				FlowOil;
	}Sensor;

	struct {
		
		float	Coagulante,
				Cloro,
				pH,
				Floculante;
	}Dispenser;

	struct{
	
		float		Out,
					In,
					Chemical,
					SeparatorOil;
			
			}Tank;
	
	struct{
		
		int Main;
	
			}Pump;

	struct{
		
		int Out;
	
			}Valve;	
	
}TValueObjectDA;

/**
 *Ponteiros da interface comunicacao
*/
typedef	float		(*TGetDAfloat)();
typedef	int			(*TGetDAInt)();
typedef	int			(*TInit)();
typedef	int			(*TGetAll)(TValueObjectDA* const);
typedef	int			(*TDeInit)();
typedef	int			(*TComunic)();
typedef	TInterface	(*TGetId)();

// interface 
typedef struct{
	
	TInit			init;
	TGetAll			getAll;
	TDeInit			deInit;
	TComunic		comunic;
	TComunic		getId;		
		
} TDAInterface;

#endif
