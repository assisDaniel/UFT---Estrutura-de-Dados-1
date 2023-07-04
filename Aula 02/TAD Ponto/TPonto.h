#ifndef TPONTO_H
#define TPONTO_H

typedef struct ponto TPonto;

TPonto *TPonto_create(float, float);
void TPonto_print(TPonto *);
float TPonto_dist(TPonto*, TPonto*);
void TPonto_set(TPonto*, float, float);
void TPonto_get(TPonto*, float*, float*);

#endif