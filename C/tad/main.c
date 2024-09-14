#include <stdio.h>
#include "vector.h"

int main()
{
    FloatVector *vet;

    vet = create(10);

    append(vet, 1);
    append(vet, 2);
    append(vet, 3);

    print(vet);

    destroy(&vet);


    return 0;
}