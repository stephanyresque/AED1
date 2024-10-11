#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int tamanho;
    Numero number[MAX];
};

Pilha *cria_pilha(){

    Pilha *pilhinha;

    pilhinha = (Pilha*)malloc(sizeof(Pilha));
    if(pilhinha == NULL){

        exit(1);
    }

    pilhinha->tamanho = 0;
    
    int i;
    for(i=0; i < MAX; i++){
        pilhinha->number[i].chave = CHAVE_BASE;
    }

    return pilhinha;

}

void libera_pilha(Pilha *pilhinha){

    if(pilhinha == NULL){

        exit(1);
    }

    free(pilhinha);
}

int tamanho_pilha(Pilha *pilhinha){

    if(pilhinha == NULL){

        return 0;
    }

    return pilhinha->tamanho;
}

int pilha_cheia(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->tamanho != MAX){

        return 0;
    }

    return 1;
}

int pilha_vazia(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->tamanho != 0){

        return 0;
    }

    return 1;
}

int push(Pilha *pilhinha, Numero number){

    if(pilhinha == NULL || pilhinha->tamanho == MAX){

        return 0;
    }

    pilhinha->number[pilhinha->tamanho] = number;
    pilhinha->tamanho++;

    return 1;
}

int pop(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->tamanho == 0){

        return 0;
    }

    pilhinha->tamanho--;
    return 1;
}

int topo_pilha(Pilha *pilhinha, Numero *number){

    if(pilhinha == NULL || pilhinha->tamanho == 0){

        return 0;
    }

    *number = pilhinha->number[pilhinha->tamanho - 1];

    return 1;
}

void imprimir_pilha(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->tamanho == 0){

        exit(1);
    }

    printf("Dados da pilha\n");

    int i;
    for(i=0; i < pilhinha->tamanho; i++){

        printf("Elemento %d\n", i+1);
        printf("Chave: %d\n", pilhinha->number[i].chave);
        printf("Valor: %d\n", pilhinha->number[i].valor);
        printf("\n");
    }

}





