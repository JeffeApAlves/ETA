#ifndef FLOW_SENSOR_H
#define FLOW_SENSOR_H

#include "Type.h"

typedef struct{
	
	TText			Label[MAX_TEXT_LEN];		
	TText 			Unidade[MAX_TEXT_LEN];
	
	TSensorStatus	Status;
	TFlow			Valor;
	TPercentual		Percentual;
	TScale			Scale;	
		
}TFlowSensor;


/**@public Funcoes*/
void initFlowSensor(void);
void setFlowSensorOil(float val);
void setFlowSensorOut(float val);
void setFlowSensorIn(float val);
void setFlowSensor(TFlowSensor* out,TText title[],TText unit[],TScale scale);

extern TFlowSensor	FlowSensorIn,FlowSensorOut,FlowSensorOil;

#endif

