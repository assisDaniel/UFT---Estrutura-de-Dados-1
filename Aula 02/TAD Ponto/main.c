#include <stdio.h>
#include "TPonto.h"

int main(void){
    TPonto *p1= TPonto_create(2.5, 3.33333);
    TPonto *p2= TPonto_create(5.7485, 0.11111);
    TPonto_print(p1);
    TPonto_print(p2);

    printf("\n Distancia euclidiana: %f", TPonto_dist(p1, p2));
    printf("\n");
    TPonto_set(p1, 1.0, 2.0);
    TPonto_print(p1);

    // Pra tentar fzr na semana! FUNÇÃO GET.
    //Olhar o replit pra saber oq fzr.

    /* float x,y;
       TPonto_get(p2, &x, &y);
       printf("\nValores de x e y resgatados: %f, %f\n", x, y);  */
    
}