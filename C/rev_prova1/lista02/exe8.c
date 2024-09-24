// Faça um programa que leia um valor inteiro N não negativo. Se o valor de N for inválido, o
// usuário deverá digitar outro até que ele seja válido (ou seja, positivo). Em seguida, leia um vetor
// V contendo N posições de inteiros, em que cada valor deverá ser maior ou igual a 2. Esse vetor
// deverá ser alocado dinamicamente

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, valor;
    int *vet;

    n = 0;

    while(n <= 0){
        printf("Informe n: ");
        scanf("%d", &n);
    }

    system("cls");

    vet = (int *)calloc(n, sizeof(int));

    for(i=0;i<n;i++){
        printf("[%d]: ", i);
        scanf("%d", &valor);

        if(valor >= 2){
            vet[i] = valor;
        }else{
            vet[i] = 0;
        }
    }

    system("cls");

    for(i=0;i<n;i++){
        printf("[%d]: %d\n", i, vet[i]);

    }

    return 0;
}