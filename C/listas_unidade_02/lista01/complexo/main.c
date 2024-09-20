#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

int main(){

    Complexo *numero1, *numero2;

    numero1 = create(10, 5);
    numero2 = create(8, 6);

    soma_complexo(numero1, numero2);
    subtrai_complexo(numero1, numero2);
    multiplica_complexo(numero1, numero2);

    destroy(&numero1);
    destroy(&numero2);

    return 0;
}