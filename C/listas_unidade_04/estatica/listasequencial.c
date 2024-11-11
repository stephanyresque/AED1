#include <stdio.h>
#include <stdlib.h>
#include "listasequencial.h"

struct lista{
    int tamanho;
    Numero number[MAX];
};

Lista *cria_lista(){

    Lista *listinha;

    listinha = (Lista*)malloc(sizeof(Lista));
    if(listinha == NULL){
        
        exit(1);
    }

    listinha->tamanho = 0;

    return listinha;
}

void liberar_lista(Lista *listinha){
    free(listinha);
}

int tamanho_lista(Lista *listinha){

    if(listinha == NULL){

        return 0;
    }

    return listinha->tamanho;
}

int lista_vazia(Lista *listinha){

    if(listinha == NULL){

        return 0;
    }

    if(listinha->tamanho == 0){

        return 1;
    }

    return 0;
}

int lista_cheia(Lista *listinha){

    if(listinha == NULL){

        return 0;
    }

    if(listinha->tamanho == MAX){

        return 1;
    }

    return 0;
}

int inserir_inicio(Lista *listinha, Numero number){

    if(listinha == NULL || listinha->tamanho == MAX){

        return 0;
    }

    int i;
    for(i = listinha->tamanho; i > 0; i--){

        listinha->number[i] = listinha->number[i-1];
    }

    listinha->number[0] = number;
    listinha->tamanho++;
    return 1;
}

int inserir_meio(Lista *listinha, Numero number, int pos){

    if(listinha == NULL || listinha->tamanho == MAX){

        return 0;
    }

    if(pos < 0 || pos > listinha->tamanho){

        return 0;
    }

    int i;
    for(i = listinha->tamanho; i > pos; i--){

        listinha->number[i] = listinha->number[i - 1];
    }

    listinha->number[pos] = number;
    listinha->tamanho++;
    return 1;
}

int inserir_fim(Lista *listinha, Numero number){

    if(listinha == NULL || listinha->tamanho == MAX){

        return 0;
    }

    listinha->number[listinha->tamanho] = number;
    listinha->tamanho++;
    return 1;
}

int remover_inicio(Lista *listinha){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }

    int i;
    for(i=0; i < listinha->tamanho - 1; i++){

        listinha->number[i] = listinha->number[i + 1];
    }

    listinha->tamanho--;
    return 1;
}

int remover_meio(Lista *listinha, int pos){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }

    if(pos < 0 || pos >= listinha->tamanho){

        return 0;
    }

    int i;
    for(i = pos; i < listinha->tamanho - 1; i++){

        listinha->number[i] = listinha->number[i + 1];
    }

    listinha->tamanho--;
    return 1;
}

int remover_final(Lista *listinha){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }

    listinha->tamanho--;
    return 1;
}


int consulta_por_indice(Lista *listinha, Numero *number,int indice){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }

    if(indice < 0 || indice >= listinha->tamanho){

        return 0;
    }

    *number = listinha->number[indice];

    return 0;
}

void imprimir_lista(Lista *listinha){

    if(listinha == NULL || listinha->tamanho == 0){

        printf("A lista está vazia ou não existe.\n");
        return;
    }

    int i;
    for (i = 0; i < listinha->tamanho; i++) {
        printf("Valor: %d\n", 
             listinha->number[i].valor);
    }
}











