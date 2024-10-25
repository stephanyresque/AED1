#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct elemento{
    Aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha *pi;

    pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi == NULL){
        exit(1);
    }
    *pi = NULL;

    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem *no;
        while((*pi) != NULL){
            no = (*pi);
            (*pi) = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, Aluno *al){
    if(pi == NULL){
        return 0;
    }
    if((*pi) == NULL){
        return 0;
    }

    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, Aluno al){
    if(pi == NULL){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->dados = al;
    no->prox = (*pi);
    (*pi) = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL){
        return 0;
    }
    if((*pi) == NULL){
        return 0;
    }

    Elem *no = (*pi);
    (*pi) = no->prox;
    free(no);

    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL){
        return 0;
    }
    int c = 0;
    Elem *no = (*pi);
    while( no != NULL){
        c++;
        no = no->prox;
    }

    return c;
}

int Pilha_cheia(Pilha* pi){
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 1;
    }
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL){
        return 1;
    }

    if((*pi) == NULL){
        return 1;
    }

    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL){
        return;
    }
    Elem *no = (*pi);
    while(no != NULL){
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s", no->dados.nome);
        printf("Notas: %.2f | %.2f | %.2f\n", no->dados.n1, no->dados.n2,no->dados.n3);
        printf("---------------------\n");
        no = no->prox;
    }
}


