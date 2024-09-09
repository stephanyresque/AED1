#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float pontoX, pontoY;

}Coordenadas;

int main()
{
    Coordenadas ponto;
    float distancia;

    printf("Informe o ponto no plano cartesiano:\n");
    printf("(X): ");
    scanf("%f", &ponto.pontoX);
    printf("(Y): ");
    scanf("%f", &ponto.pontoY);

    distancia = sqrt( (ponto.pontoX*ponto.pontoX) + (ponto.pontoY*ponto.pontoY) );

    printf("Distancia ate a origem: %.2f", distancia);

    return 0;
}
