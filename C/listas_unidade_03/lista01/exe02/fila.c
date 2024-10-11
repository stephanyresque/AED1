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

    if(filha == NULL || filha->tamanho != MAX){

        return 0;
    }

    return 1;
}


int fila_vazia(Fila *filha){

    if(filha == NULL || filha->tamanho != 0){

        return 0;
    }

    return 1;
}

int inserir_fila(Fila *filha){

    if(filha == NULL || filha->tamanho != 0){

        return 0;
    }
}
