#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main()
{
    float d;
    Ponto *p, *q;
    int a, b;

    p = pto_cria(10, 21);
    q = pto_cria(7, 25);
    pto_acessa(p, &a,&b);
    d = pto_distancia(p, q);
    pto_atribui(100, 200);

    printf("Distancia entre os pontos eh %f", d);

    pto_libera()

    return 0;
}
