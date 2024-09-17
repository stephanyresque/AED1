#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"


struct complexo{
    int i2;
    float x_real;
    float y_img;
    float z;
};

Complexo* create(float x, float y){
    Complexo *num;

    num = (Complexo*)calloc(1, sizeof(Complexo));

    num->i2 = -1;
    num->x_real = x;
    num->y_img = y;
    num->z = num->x_real + (num->y_img * num->i2);

    return num;
}

void destroy(Complexo **num){
    if (*num != NULL){
        free(*num);
        *num = NULL; 
        printf("Numero destruido.\n");   
    }else{
        printf("Erro...\n");
    }
    
}

float soma_complexo(Complexo *num1, Complexo *num2){
    printf("A soma dos complexos eh %.2f\n", (num1->z + num2->z));
    return (num1->z + num2->z);
}

float subtrai_complexo(Complexo *num1, Complexo *num2){
    printf("A subtracao dos complexos eh %.2f\n", (num1->z - num2->z));
    return (num1->z - num2->z);
}

float multiplica_complexo(Complexo *num1, Complexo *num2){
    printf("A multiplicacao dos complexos eh %.2f\n", (num1->z * num2->z));
    return (num1->z * num2->z);
}