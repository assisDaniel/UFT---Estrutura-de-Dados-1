#ifndef NUMRACIONAIS_H
#define NUMRACIONAIS_H
#include <stdbool.h>

typedef struct ponto Ponto;

Ponto* createNum(int, int);
Ponto* sumNum(Ponto*, Ponto*);
Ponto* multNum(Ponto*, Ponto*);
bool equal(Ponto*, Ponto*);
void numPrint(Ponto*);

#endif