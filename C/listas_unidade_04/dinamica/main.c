#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"

int main() {
    // Inicializa a lista
    ListaDinamica *lista = inicializar_lista();
    if (lista == NULL) {
        printf("Erro ao inicializar a lista.\n");
        return 1;
    }

    // Teste: Inserir 3 elementos no final
    int valores_final[] = {10, 20, 30};
    if (inserir_n_final(lista, valores_final, 3) == 0) {
        printf("Inseridos 3 elementos no final: 10, 20, 30\n");
    } else {
        printf("Falha ao inserir elementos no final.\n");
    }

    // Teste: Inserir 2 elementos no início
    int valores_inicio[] = {5, 15};
    if (inserir_n_inicio(lista, valores_inicio, 2) == 0) {
        printf("Inseridos 2 elementos no início: 5, 15\n");
    } else {
        printf("Falha ao inserir elementos no início.\n");
    }

    // Teste: Consultar 3 elementos em posições específicas
    int posicoes_consulta[] = {0, 2, 4};  // Posições para consultar
    int valores_consulta[3];
    if (acessar_n_elementos(lista, posicoes_consulta, 3, valores_consulta) == 0) {
        printf("Valores nas posições 0, 2 e 4: ");
        for (int i = 0; i < 3; i++) {
            printf("%d ", valores_consulta[i]);
        }
        printf("\n");
    } else {
        printf("Falha ao consultar elementos.\n");
    }

    // Exibe o estado final da lista
    printf("Estado atual da lista: ");
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");

    // Libera a memória da lista
    liberar_lista(lista);

    return 0;
}
