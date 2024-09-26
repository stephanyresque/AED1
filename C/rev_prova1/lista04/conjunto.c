#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

struct naturais{
    int *numeros;
    int cardinalidade;
    int capacidade;
};

Naturais* criaconjunto(){
    Naturais* nat;

    nat = (Naturais*)calloc(1, sizeof(Naturais));

    if(nat == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    nat->capacidade = 0;
    nat->cardinalidade = 0;
    nat->numeros = NULL;

    return nat;
}

int conjuntovazio(Naturais *nat){

    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }
    if(nat->numeros == NULL){
        printf("Conjunto vazio.\n");
        return 1;
    }else{
        printf("Conjunto nao vazio.\n");
        return 0;
    }

}

int inserirelemento(int x, Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            printf("O elemento ja existe no conjunto.\n");
            return 0;
        }
    }

    if(nat->capacidade == nat->cardinalidade){
        int nova_capacidade;

        if(nat->capacidade == 0){
            nova_capacidade = 1;
        }else{
            nova_capacidade = 2 * nat->capacidade;
        }

        int *novos_numeros;

        novos_numeros = (int*)realloc(nat->numeros, nova_capacidade * sizeof(int));
        

    }



}

