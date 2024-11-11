#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

struct elemento{
    Numero dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista *li;

    li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista* li){
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

int consulta_lista_pos(Lista* li, int pos, Numero *number){
    if(li == NULL || pos <= 0){
        return 0;
    }

    Elem *no = (*li);
    int i = 1;
    while( no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if(no == NULL){
        return 0;
    }else{
        *number = no->dados;
        return 1;
    }

}

int insere_lista_final(Lista* li, Numero number){
    if(li == NULL){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = number;
    no->prox = NULL;

    if((*li) == NULL){ //lista vazia
        (*li) = no;
    }else{
        Elem *aux;
        aux = (*li);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
    
}

int insere_lista_inicio(Lista* li, Numero number){
    if(li == NULL){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = number;
    no->prox = (*li);
    (*li) = no;
    
    return 1;
}

int insere_lista_pos(Lista* li, int pos, Numero number){ // A->B->C
    if(li == NULL || pos <= 0){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->dados = number;
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

    if( aux == NULL){
        return 0;
    }

    no->prox = aux->prox;
    aux->prox = no;

    return 1;

}

int remove_lista_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    Elem *no = (*li);
    (*li) = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    Elem *ant, *no = (*li);
    while( no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if( no == (*li)){
        (*li) = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL){
        return 0;
    }

    int c = 0;
    Elem *no = (*li);
    while( no != NULL){
        no = no->prox;
        c++;
    }

    return c;
}

int lista_vazia(Lista* li){
    if(li == NULL){
        return 1;
    }

    if((*li) == NULL){
        return 1;
    }

    return 0;
}

int lista_cheia(Lista* li){
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 1;
    }

    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL){
        return;
    }

    Elem *no = (*li);
    while( no != NULL){
        printf("Valor: %d\n",no->dados.valor);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
