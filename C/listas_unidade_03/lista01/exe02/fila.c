#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    int tamanho;
    Numero number[MAX];
};

Fila* cria_fila(){

    Fila *filha;

    filha = (Fila*)malloc(sizeof(Fila));
    if(filha == NULL){

        exit(1);
    }

    filha->tamanho = 0;
    int i;
    for(i=0;i<MAX;i++){
        filha->number[i].chave = CHAVE_BASE;
    }

    return filha;
}

void libera_fila(Fila *filha){

    if(filha == NULL){
        exit(1);
    }

    free(filha);
}

int tamanho_fila(Fila *filha){

    if(filha == NULL){

        exit(1);
    }

    return filha->tamanho;
}

int fila_cheia(Fila *filha){

    if(filha == NULL){

        return 0;
    }
    if(filha->tamanho == MAX){
        
        return 1;
    }

    return 0;
}


int fila_vazia(Fila *filha){

    if(filha == NULL){

        return 0;
    }

    if(filha->tamanho == 0){

        return 1;
    }

    return 0;
}

int inserir_fila(Fila *filha, Numero number){

    if(filha == NULL || filha->tamanho == MAX){

        return 0;
    }

    filha->number[filha->tamanho] = number;
    filha->tamanho++;
    return 1;
}

int remove_fila(Fila *filha){

    if(filha == NULL || filha->tamanho == 0){

        return 0;
    }

    int i;
    for(i=0; i < filha->tamanho - 1; i ++){
        filha->number[i] = filha->number[i+1];
    }

    filha->tamanho--;
    return 1;
}

int consulta_primeiro_fila(Fila *filha, Numero *number){

    if(filha == NULL || filha->tamanho == 0){

        return 0;
    }

    *number = filha->number[0];

    return 1;
}

void imprimir_fila(Fila *filha){
    if(filha == NULL || filha->tamanho == 0){

        printf("Fila nao exite.\n");
        exit(1);
    }

    int i;
    for(i=0; i < filha->tamanho; i++){
        printf("Elemento %d;\n", i);
        printf("Chave: %d\n", filha->number[i].chave);
        printf("Numero: %d\n", filha->number[i].valor);
    }
}



