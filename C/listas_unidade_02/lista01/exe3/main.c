#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"

int main()
{
    Esfera *minha_esfera;

    minha_esfera = create(5);

    raio(minha_esfera);
    area(minha_esfera);
    volume(minha_esfera);

    return 0;
}