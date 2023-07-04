#ifndef NUMCOMPLEX_H
#define NUMCOMPLEX_H

typedef struct ponto Ponto;

Ponto* numCreate(float, float);
void numDelete(Ponto*);
float sumComplex(Ponto*, Ponto*);
float diffComplex(Ponto*, Ponto*);

#endif