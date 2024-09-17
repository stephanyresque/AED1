#include <stdio.h>
#include <stdlib.h>
#include "cilindro.h"

int main()
{
    Cilindro *meu_cilindro;

    meu_cilindro = create(10, 5);

    altura(meu_cilindro);
    raio(meu_cilindro);
    area(meu_cilindro);
    volume(meu_cilindro);
    
    return 0;
}