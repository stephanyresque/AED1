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
