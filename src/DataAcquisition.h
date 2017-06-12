#ifndef DATA_ACQ_H
#define DATA_ACQ_H


/**@public Funcoes*/

void processTasksOfDataAcquisition(void);
void setInterface(TInterface ninterface);

inline float getDispenserCloro();
inline float getDispenserCoagulante();
inline float getDispenserFloculante();
inline float getDispenserPH();

inline float getFlowIn();
inline float getFlowOut();
inline float getFlowOil();

inline float getTankChemical();
inline float getTankIn();
inline float getTankOut();
inline float getTankSeparatorOil();

inline int getPumpMain();
inline int getValve();

#endif
