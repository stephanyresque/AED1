#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int push(Pilha *pilhinha, Aluno aluno){ //passagem por valor! 

    if(pilhinha == NULL || pilhinha->qtd==TAMANHO_MAXIMO){
        
        return 0;
    }
    else{
        pilhinha->dados[pilhinha->qtd] = aluno;
        pilhinha->qtd++;
        return 1;
    }

}

int pop(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->qtd== 0){
        
        return 0;
    }
    
    pilhinha->qtd--;
    return 1;
}

void imprime_pilha(Pilha *pilhinha){

    if(pilhinha == NULL || pilhinha->qtd == 0){
        
        printf("Pilha nao criada ou vazia..\n");
        exit(1);
    }

    int i;

    printf("------ DADOS PILHA ------\n");
    for(i=0;i<pilhinha->qtd;i++){
        printf("Dado %d:\n", i);
        printf("Nome: %s", pilhinha->dados[i].nome);
        printf("Matricula: %d\n", pilhinha->dados[i].matricula);
        printf("Media do aluno: %.2f\n", pilhinha->dados[i].media);
        printf("\n");
    }
}




