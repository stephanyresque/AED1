#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
    Numero number;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista *li;

    li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        (*li) = NULL;
    }

    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        Elem *no;
        while( (*li) != NULL){
            no = (*li);
            (*li) = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int inserir_inicio(Lista *li, Numero number){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->number = number;
    no->prox = (*li);
    no->ant = NULL;

    if((*li) != NULL){
        (*li)->ant = no;
    }
    (*li) = no;

    return 1;
}

int inserir_final(Lista *li, Numero number){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->number = number;
    no->prox = NULL;

    if((*li) == NULL){
        no->ant = NULL;
        (*li) = no;
    }else{
        Elem *aux = (*li);
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = no;
        no->ant = aux;
    }

    return 1;
}

int inserir_pos(Lista *li, int pos,Numero number){
    if(li == NULL || pos <= 0){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->number = number;

    if(pos == 1){
        no->prox = (*li);
        no->ant = NULL;
        if (*li != NULL) {
            (*li)->ant = no;
        }
        (*li) = no;

        return 1;
    }

    Elem *aux = (*li);
    int i = 1;
    while(aux != NULL && i < pos - 1){
        aux = aux->prox;
        i++;
    }

    if(aux == NULL){
        return 0;
    }

    no->prox = aux->prox;
    no->ant = aux;

    
}

void imprime_lista(Lista *li) {
    if (li == NULL || (*li) == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Elem *no = (*li);
    while (no != NULL) {
        printf("%d ", no->number.valor);
        no = no->prox;
    }
    printf("\n");
}
