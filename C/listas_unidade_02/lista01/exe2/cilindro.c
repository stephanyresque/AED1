#include <stdio.h>
#include <stdlib.h>
#include "cilindro.h"
#include <math.h>

struct cilindro{
    float raio, altura;
    float volume;
    float area;
};

Cilindro* create(float altura,float raio){
    Cilindro *cilindro_usuario;

    cilindro_usuario = (Cilindro*)calloc(1, sizeof(Cilindro));

    cilindro_usuario->altura = altura;
    cilindro_usuario->raio = raio;
    cilindro_usuario->area =  2*3.14*raio*(raio + altura);
    cilindro_usuario->volume = 3.14 * pow(raio,2) * altura;

    return cilindro_usuario;
}

float altura(Cilindro *cilindro_usuario){
    printf("Altura: %.2f\n", cilindro_usuario->altura);
    return cilindro_usuario->altura;
}
float raio(Cilindro *cilindro_usuario){
    printf("Raio: %.2f\n", cilindro_usuario->raio);
    return cilindro_usuario->raio;
}
float area(Cilindro *cilindro_usuario){
    printf("Area: %.2f\n", cilindro_usuario->area);
    return cilindro_usuario->area;
}
float volume(Cilindro *cilindro_usuario){
    printf("Volume: %.2f\n", cilindro_usuario->volume);
    return cilindro_usuario->volume;
}
