#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main() {
    
    ListaEstatica *lista = inicializar_lista();
    if (lista == NULL) {
        printf("Erro ao inicializar a lista.\n");
        return 1;
    }

    int valores_final[] = {10, 20, 30};
    if (inserir_n_final(lista, valores_final, 3) == 0) {
        printf("Inseridos 3 elementos no final: 10, 20, 30\n");
    } else {
        printf("Falha ao inserir elementos no final.\n");
    }

    int valores_inicio[] = {5, 15};
    if (inserir_n_inicio(lista, valores_inicio, 2) == 0) {
        printf("Inseridos 2 elementos no inicio: 5, 15\n");
    } else {
        printf("Falha ao inserir elementos no inicio.\n");
    }

    int posicoes_consulta[] = {0, 2, 4};  
    int valores_consulta[3];
    if (acessar_n_elementos(lista, posicoes_consulta, 3, valores_consulta) == 0) {
        printf("Valores nas posicoes 0, 2 e 4: ");
        for (int i = 0; i < 3; i++) {
            printf("%d ", valores_consulta[i]);
        }
        printf("\n");
    } else {
        printf("Falha ao consultar elementos.\n");
    }

    printf("Estado atual da lista: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");

    free(lista);

    return 0;
}
