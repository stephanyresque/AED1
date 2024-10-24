#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct elemento{
    Aluno dados;
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

int consulta_lista_pos(Lista* li, int pos, Aluno *al){
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
        *al = no->dados;
        return 1;
    }

}

int consulta_lista_mat(Lista* li, int mat, Aluno *al){
    if(li == NULL){
        return 0;
    }

    Elem *no = (*li);
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }

}

int insere_lista_final(Lista* li, Aluno al){
    if(li == NULL){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
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

int insere_lista_inicio(Lista* li, Aluno al){
    if(li == NULL){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    (*li) = no;
    
    return 1;
}

int insere_lista_pos(Lista* li, int pos, Aluno al){ // A->B->C
    if(li == NULL || pos <= 0){
        return 0;
    }

    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }

    no->dados = al;
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

int remove_lista(Lista* li, int mat){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){ //lista vazia
        return 0;
    }

    Elem *ant, *no = (*li);
    while( no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }

    if(no == NULL){ //matrícula não encontrada
        return 0;
    }

    if(no == (*li)){
        (*li) = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
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
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL){
        return;
    }

    Elem *no = (*li);
    while( no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f | %.2f | %.2f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
