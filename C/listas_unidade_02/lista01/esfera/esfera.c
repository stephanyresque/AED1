#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"
#include <math.h>

struct esfera{
    float raio;
    float area;
    float volume;
};

Esfera* create(float raio){
    Esfera *esfera_user;

    esfera_user = (Esfera*)calloc(1, sizeof(Esfera));

    esfera_user->raio = raio;
    esfera_user->area = 4*3.14*pow(raio,2);
    esfera_user->volume = (4/3) * 3.14 * pow(raio, 3);

    return esfera_user;
}

float raio(Esfera *esfera_user){
    printf("Raio: %.2f\n", esfera_user->raio);
    return esfera_user->raio;
}
float area(Esfera *esfera_user){
    printf("Area: %.2f\n", esfera_user->area);
    return esfera_user->area;
}
float volume(Esfera *esfera_user){
    printf("Volume: %.2f\n", esfera_user->volume);
    return esfera_user->volume;
}