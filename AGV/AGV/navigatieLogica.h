#ifndef NAVIGATIELOGICA_H_INCLUDED
#define NAVIGATIELOGICA_H_INCLUDED

#include "main.h"

void vooruit(void);
void stop(void);
void rechtdoor(void);
void rechtdoorAnd(void);
void achteruit(void);
void rechtsom(void);
void linksom(void);
void metingPadbreedte(void);
int ramping(int originalValue , int value);

void kwartslagDraaienRechts(void);
void kwartslagDraaienLinks(void);
void Pirouette(void);
void Pirouette2(void);
void calibrate(void);
void ongecontroleerdAchteruit(void);
void ongecontroleerdVooruit(void);
void ongecontroleerdVooruit2(void);
void kleinBeetjeVooruit(void);
void kleinBeetjeAchteruit(void);
void minderBeetjeVooruit(void);
void grootBeetjeVooruit(void);

#endif // NAVIGATIELOGICA_H_INCLUDED
