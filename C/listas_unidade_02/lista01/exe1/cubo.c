#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

struct cubo{
    float lado;
    float area;
    float volume;
};

Cubo* create(float lados){
    Cubo *cubo_usuario;

    cubo_usuario = (Cubo*)calloc(1,sizeof(Cubo));

    cubo_usuario->lado = lados;
    cubo_usuario->area = 6 * (pow(lados,2));
    cubo_usuario->volume = pow(lados,3);

    return cubo_usuario;
}

float area(const Cubo *cubo_usuario){
    printf("A area do seu cubo eh %.2f u.d.", cubo_usuario->area);
    return cubo_usuario->area;
}

float volume(const Cubo *cubo_usuario){
    printf("O volume do seu cubo eh %.2f u.d.", cubo_usuario->volume);
    return cubo_usuario->volume;
}

float lados(const Cubo *cubo_usuario){
    printf("Os lados do seu cubo tem medida de %.2f u.d.", cubo_usuario->lado);
    return cubo_usuario->lado;
}