#include "ListaSequencial.h"
#include <stdlib.h>

ListaEstatica* inicializar_lista() {
    ListaEstatica *lista = (ListaEstatica*) malloc(sizeof(ListaEstatica));
    if (lista != NULL) {
        lista->tamanho = 0;
    }
    return lista;
}

int lista_vazia(ListaEstatica *lista) {
    return lista->tamanho == 0;
}

int lista_cheia(ListaEstatica *lista) {
    return lista->tamanho == MAX;
}

int inserir_n_final(ListaEstatica *lista, int valores[], int n) {
    if (lista->tamanho + n > MAX) {
        return -1;  
    }
    for (int i = 0; i < n; i++) {
        lista->dados[lista->tamanho] = valores[i];
        lista->tamanho++;
    }
    return 0;  
}

int inserir_n_inicio(ListaEstatica *lista, int valores[], int n) {
    if (lista->tamanho + n > MAX) {
        return -1;  
    }

    for (int i = lista->tamanho - 1; i >= 0; i--) {
        lista->dados[i + n] = lista->dados[i];
    }
   
    for (int i = 0; i < n; i++) {
        lista->dados[i] = valores[i];
    }
    lista->tamanho += n;
    return 0;  
}

int remover_final(ListaEstatica *lista) {
    if (lista_vazia(lista)) {
        return -1;  
    }
    lista->tamanho--;
    return 0;  
}

int acessar_n_elementos(ListaEstatica *lista, int posicoes[], int n, int valores[]) {
    for (int i = 0; i < n; i++) {
        int posicao = posicoes[i];
        if (posicao < 0 || posicao >= lista->tamanho) {
            return -1;  
        }
        valores[i] = lista->dados[posicao];
    }
    return 0;  
}
