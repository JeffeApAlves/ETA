#ifndef DEMO_RANDOM_H
#define DEMO_RANDOM_H

#include  "InterfaceDA.h"

/**@private*/
static int getDemoRandomPumpMain();
static float getDemoRandomTankSeparatorOil();
static float getDemoRandomTankOut();
static float getDemoRandomTankIn();
static float getDemoRandomTankChemical();
static float getDemoRandomFlowOil();
static float getDemoRandomFlowOut();
static float getDemoRandomFlowIn();
static float getDemoRandomDispenserPH();
static float getDemoRandomDispenserFloculante();
static float getDemoRandomDispenserCoagulante();
static float getDemoRandomDispenserCloro();
static int getDemoRandomValve();

//interface
static int getAllDemoRandom(TValueObjectDA* const out);
static int initDemoRandom();
static int deInitDemoRandom();
static int comunicDemoRandom();
static TInterface getIdDemoRandom();

/**@public Funcoes*/
const TDAInterface* getInterfaceDemoRandom();

#endif
