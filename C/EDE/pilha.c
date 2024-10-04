#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
    int qtd;
    Aluno dados[TAMANHO_MAXIMO];

};

Pilha* cria_pilha(){
    Pilha *pilhinha;

    pilhinha = (Pilha*)malloc(sizeof(Pilha));

    if(pilhinha != NULL){
        pilhinha->qtd = 0;
    }else{
        exit(1);
    }

    return pilhinha;
}

void libera_pilha(Pilha *pilinha){
    free(pilinha);
}

int tamanho_pilha(Pilha *pilhinha){

    if(pilhinha == NULL){

        return -1;
    }else{

        return pilhinha->qtd;
    }

}

int pilha_vazia(Pilha *pilhinha){

    if(pilhinha == NULL){
        
        return -1;
    }

    if(pilhinha->qtd == 0){

        return 1;
    }else{

        return 0;
    }
}

int pilha_cheia(Pilha *pilhinha){

    if(pilhinha == NULL){
        
        return -1;
    }

    if(pilhinha->qtd == TAMANHO_MAXIMO){

        return 1;
    }else{

        return 0;
    }
}

int consulta_topo_pilha(Pilha *pilhinha, Aluno *aluno){ //passagem por referência! (prints)

    if(pilhinha == NULL || pilhinha->qtd == 0){
        
        return -1;
    }

    *aluno = pilhinha->dados[pilhinha->qtd - 1];

    return 1;
}

int inserir_elemento(Pilha *pilhinha, Aluno aluno){ //passagem por valor! 

    if(pilhinha == NULL || pilhinha->qtd==TAMANHO_MAXIMO){
        
        return 0;
    }
    else{
        pilhinha->dados[pilhinha->qtd] = aluno;
        pilhinha->qtd++;
        return 1;
    }

}

int remove_elemento(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->qtd== 0){
        
        return 0;
    }
    
    pilhinha->qtd--;
    return 1;
}




