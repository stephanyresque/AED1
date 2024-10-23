#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct elemento{
    Aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }

    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }

        free(fi);
    }
}

int consulta_Fila(Fila* fi, Aluno *al){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }

    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, Aluno al){
    if(fi == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;
    }else{
        fi->final->prox = no;
    }

    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }

    if(fi->inicio == NULL){
        return 0;
    }

    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){ //fila ficou vazia
        fi->final == NULL;
    }
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL){
        return 1;
    }

    if(fi->inicio == NULL){
        return 1;
    }

    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f | %.2f | %.2f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}




