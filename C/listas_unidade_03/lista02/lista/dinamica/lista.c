#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
    Numero number;
    struct elemento *prox;
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

int inserir_lista_inicio(Lista *li, Numero number){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
     no->number = number;
     no->prox = (*li);
     (*li) = no;

     return 1;
}

int inserir_lista_final(Lista *li, Numero number){
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
        (*li) = no;
    }else{
        Elem *aux = (*li);

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
}

int inserir_lista_pos(Lista *li, int pos, Numero number){
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
        (*li) = no;

        return 1;
    }

    Elem *aux = (*li);
    int i = 1;
    while( aux != NULL && i < pos - 1){
        aux = aux->prox;
        i++;
    }

    if(aux == NULL){
        return 0;
    }

    no->prox = aux->prox;
    aux->prox = no;

    return 1;

}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    int count = 0;
    Elem *no = (*li);

    while( no != NULL){
        no = no->prox;
        count++;
    }

    return count;
}

int remover_inicio(Lista *li, int n_numeros){
    if(li == NULL || (*li) == NULL){
        return 0;
    }

    if(tamanho_lista(li) < n_numeros){
        return 0;
    }

    Elem *no;
    int count = 1;
    while(count <= n_numeros){
        no = (*li);
        (*li) = (*li)->prox;
        free(no);
        count++;
    }

    return 1;
}

int remover_final(Lista *li, int n_numeros){
    if(li == NULL || (*li) == NULL){
        return 0;
    }

    if(tamanho_lista(li) < n_numeros){
        return 0;
    }

    if(tamanho_lista(li) == n_numeros){
        libera_lista(li);
        return 1;
    }

    int pos;
    pos = tamanho_lista(li) - n_numeros; //posição de partida para remoção

    Elem *atual = (*li);
    for (int i = 1; i < pos; i++) {
        atual = atual->prox; //pega o elemento anterior ao que será removido
    }

    Elem *aux;
    while(atual->prox != NULL){
        aux = atual->prox;
        atual->prox = aux->prox;
        free(aux);
    }

    return 1;
}

void imprimir_lista(Lista *li){
    if(li == NULL){
        return;
    }

    Elem *no = (*li);
    while( no != NULL){
        printf("%d | ", no->number.valor);
        no = no->prox;
    }
}




