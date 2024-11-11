#include "listaDinamica.h"
#include <stdlib.h>
#include <stdio.h>

ListaDinamica* inicializar_lista() {
    ListaDinamica *lista = (ListaDinamica*) malloc(sizeof(ListaDinamica));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

int lista_vazia(ListaDinamica *lista) {
    return lista->inicio == NULL;
}

int inserir_n_final(ListaDinamica *lista, int valores[], int n) {
    for (int i = 0; i < n; i++) {
        No *novo = (No*) malloc(sizeof(No));
        if (novo == NULL) return -1;  
        novo->dado = valores[i];
        novo->proximo = NULL;
        
        if (lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            No *aux = lista->inicio;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        lista->tamanho++;
    }
    return 0;
}

int inserir_n_inicio(ListaDinamica *lista, int valores[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        No *novo = (No*) malloc(sizeof(No));
        if (novo == NULL) return -1; 
        novo->dado = valores[i];
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tamanho++;
    }
    return 0;
}

int remover_final(ListaDinamica *lista) {
    if (lista_vazia(lista)) return -1;  

    No *anterior = NULL, *atual = lista->inicio;
    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (anterior != NULL) {
        anterior->proximo = NULL;
    } else {
        lista->inicio = NULL;
    }
    free(atual);
    lista->tamanho--;
    return 0;
}

int acessar_n_elementos(ListaDinamica *lista, int posicoes[], int n, int valores[]) {
    for (int i = 0; i < n; i++) {
        int posicao = posicoes[i];
        if (posicao < 0 || posicao >= lista->tamanho) return -1;  

        No *aux = lista->inicio;
        for (int j = 0; j < posicao; j++) {
            aux = aux->proximo;
        }
        valores[i] = aux->dado;
    }
    return 0;
}

void liberar_lista(ListaDinamica *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}
