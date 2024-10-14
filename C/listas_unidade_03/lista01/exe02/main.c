#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila *fila = cria_fila();
    Numero numero;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir na fila\n");
        printf("2. Remover da fila\n");
        printf("3. Consultar o primeiro elemento da fila\n");
        printf("4. Tamanho da fila\n");
        printf("5. Imprimir fila\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (fila_cheia(fila)) {
                    printf("Erro: a fila está cheia.\n");
                } else {
                    printf("Digite o valor: ");
                    scanf("%d", &numero.valor);
                    printf("Digite a chave: ");
                    scanf("%d", &numero.chave);
                    if (inserir_fila(fila, numero)) {
                        printf("Numero inserido com sucesso!\n");
                    } else {
                        printf("Erro ao inserir o numero na fila.\n");
                    }
                }
                break;

            case 2:
                if (remove_fila(fila)) {
                    printf("Numero removido com sucesso!\n");
                } else {
                    printf("Erro: a fila está vazia ou não existe.\n");
                }
                break;

            case 3:
                if (consulta_primeiro_fila(fila, &numero)) {
                    printf("Primeiro elemento da fila:\n");
                    printf("Chave: %d\n", numero.chave);
                    printf("Valor: %d\n", numero.valor);
                } else {
                    printf("Erro: a fila está vazia ou não existe.\n");
                }
                break;

            case 4:
                printf("Tamanho atual da fila: %d\n", tamanho_fila(fila));
                break;

            case 5:
                imprimir_fila(fila);
                break;

            case 6:
                libera_fila(fila);
                printf("Fila liberada e saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}
