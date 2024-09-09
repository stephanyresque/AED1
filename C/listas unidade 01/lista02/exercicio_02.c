#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float A1;
    float B1;
    float A2;
    float B2;

}Coordenadas;

int main()
{
    Coordenadas plano;
    float distancia;

    printf("Informe a primeira posicao (x,y): ");
    scanf("%f %f", &plano.A1, &plano.B1);
    printf("Informe a segunda posicao (x,y): ");
    scanf("%f %f", &plano.A2, &plano.B2);

    distancia = sqrt( ((plano.A1 - plano.A2)*(plano.A1 - plano.A2)) + ((plano.B1 - plano.B2)*(plano.B1 - plano.B2)) );
    printf("A distancia eh %.2f", distancia);

    return 0;
}
