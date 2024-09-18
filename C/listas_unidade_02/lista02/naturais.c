#include <stdio.h>
#include <stdlib.h>
#include "naturais.h"

struct conjunto{
    int *numeros;
    int cardinalidade;
    int capacidade;
};

Conjunto* criaConjunto(){
    Conjunto *nat;

    nat = (Conjunto*)calloc(1,sizeof(Conjunto));

    if(nat==NULL){
        return NULL;
    }else{
        nat->numeros = NULL;
        nat->cardinalidade = 0;
        nat->capacidade = 0;
        return nat;
    }
}

int conjuntoVazio(Conjunto *nat){
    if(nat->cardinalidade == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

int insereElementoConjunto(int x, Conjunto *nat){

    if(nat == NULL){
        return FALHA;
    }

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            return FALHA;
        }
    }

    if(nat->cardinalidade == nat->capacidade){
        int novaCapacidade;

        if(nat->capacidade = 0){
            novaCapacidade = 1;
        }else{
            novaCapacidade = 2 * nat->capacidade;
        }

        int *novosNumeros = (int*)realloc(nat->numeros, novaCapacidade * sizeof(int));
        if(novosNumeros == NULL){
            return FALHA;
        }
        nat->numeros = novosNumeros;
        nat->capacidade = novaCapacidade;
    }

    nat->numeros[nat->capacidade++] = x;
    return SUCESSO;
}

int excluirElementoConjunto(int x, Conjunto *nat){
    if(nat == NULL){
        return FALHA;
    }

    int indice = -1;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            indice = i;
            break;
        }
    }

    if(indice == -1){
        return FALHA;
    }

    for(int i = indice; i < nat->cardinalidade - 1; i++){
        nat->numeros[i] = nat->numeros[i+1];
    }

    nat->cardinalidade--;

    return SUCESSO;
}

int tamanhoConjunto(Conjunto *nat){
    return nat->cardinalidade;
}

int maior(int x, Conjunto *nat){

    if(nat->cardinalidade == 0){
        printf("Conjunto vazio.\n");
        return 0;
    }
    int total = 0;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] > x){
            total++;
        }
    }

    if(total == nat->cardinalidade){
        printf("Todos os elementos do conjunto sao maiores que x.\n");
        return 0;
    }else{
        return total;
    }
}

int menor(int x, Conjunto *nat){

    if(nat->cardinalidade == 0){
        printf("Conjunto vazio.\n");
        return 0;
    }

    int total = 0;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] < x){
            total++;
        }
    }

    if(total == nat->cardinalidade){
        printf("Todos os elementos do conjunto sao menores que x.\n");
        return 0;
    }else{
        return total;
    }

}

int pertenceConjunto(int x, Conjunto *nat){

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            return TRUE;
        }
    }

    return FALSE;
}

int conjuntosIdenticos(Conjunto *nat1,Conjunto *nat2){

    if(nat1->cardinalidade != nat2->cardinalidade){
        return FALSE;
    }
    int verificador = 0;

    for(int i = 0; i <nat1->cardinalidade; i++){
        for(int j = 0; j < nat2->cardinalidade; j++){
            if(nat1->numeros[i] = nat2->numeros[j]){
                verificador++;
            }
        }
    }

    if(verificador == nat1->cardinalidade){
        return TRUE;
    }else{
        return FALSE;
    }
}

int subconjunto(Conjunto *nat1, Conjunto *nat2){
    int verificador = 0;

    for(int i = 0; i <nat2->cardinalidade; i++){
        for(int j = 0; j < nat1->cardinalidade; j++){
            if(nat2->numeros[i] = nat1->numeros[j]){
                verificador++;
            }
        }
    }

    if(verificador == nat1->cardinalidade){
        return TRUE;
    }else{
        return FALSE;
    }
}




