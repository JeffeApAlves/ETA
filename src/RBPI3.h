#ifndef DA_RBPI3_H
#define DA_RBPI3_H

#include  "InterfaceDA.h"

/**@private*/
static int getRBPI3PumpMain();
static float getRBPI3TankSeparatorOil();
static float getRBPI3TankOut();
static float getRBPI3TankIn();
static float getRBPI3TankChemical();
static float getRBPI3FlowOil();
static float getRBPI3FlowOut();
static float getRBPI3FlowIn();
static float getRBPI3DispenserPH();
static float getRBPI3DispenserFloculante();
static float getRBPI3DispenserCoagulante();
static float getRBPI3DispenserCloro();
static int getRBPI3Valve();
static TInterface getIdRBPI3();

//interface
static int getAllRBPI3(TValueObjectDA* const out);
static int initRBPI3();
static int deInitRBPI3();
static int comunicRBPI3();

/**@public Funcoes*/
const TDAInterface* getInterfaceRBPI3();

#endif
