#ifndef DEMO_INCREMENTAL_H
#define DEMO_INCREMENTAL_H

#include  "InterfaceDA.h"

// private
static int getDemoIncrementalPumpMain();
static float getDemoIncrementalTankSeparatorOil();
static float getDemoIncrementalTankOut();
static float getDemoIncrementalTankIn();
static float getDemoIncrementalTankChemical();
static float getDemoIncrementalFlowOil();
static float getDemoIncrementalFlowOut();
static float getDemoIncrementalFlowIn();
static float getDemoIncrementalDispenserPH();
static float getDemoIncrementalDispenserFloculante();
static float getDemoIncrementalDispenserCoagulante();
static float getDemoIncrementalDispenserCloro();
static int getDemoIncrementalValve();

//interface
static int getAllDemoIncremental(TValueObjectDA* const out);
static int initDemoIncremental();
static int deInitDemoIncremental();
static int comunicDemoIncremental();
static TInterface getIdDemoIncremental();

/**@public Funcoes*/
const TDAInterface* getInterfaceDemoIncremental();

#endif
