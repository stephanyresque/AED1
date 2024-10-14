#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista *lista = cria_lista();
    Numero numero;
    int opcao, chave, posicao, resultado;

    do {
        printf("\n=== MENU DE OPÇOES ===\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Inserir no meio\n");
        printf("4. Remover do inicio\n");
        printf("5. Remover do meio\n");
        printf("6. Remover do fim\n");
        printf("7. Consultar por chave\n");
        printf("8. Consultar por indice\n");
        printf("9. Imprimir lista\n");
        printf("10. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &numero.valor);
                printf("Digite a chave: ");
                scanf("%d", &numero.chave);
                if (inserir_inicio(lista, numero)) {
                    printf("Numero inserido no inicio com sucesso!\n");
                } else {
                    printf("Erro ao inserir no inicio.\n");
                }
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &numero.valor);
                printf("Digite a chave: ");
                scanf("%d", &numero.chave);
                if (inserir_fim(lista, numero)) {
                    printf("Numero inserido no fim com sucesso!\n");
                } else {
                    printf("Erro ao inserir no fim.\n");
                }
                break;

            case 3:
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                printf("Digite o valor: ");
                scanf("%d", &numero.valor);
                printf("Digite a chave: ");
                scanf("%d", &numero.chave);
                if (inserir_meio(lista, numero, posicao)) {
                    printf("Numero inserido na posicao %d com sucesso!\n", posicao);
                } else {
                    printf("Erro ao inserir no meio.\n");
                }
                break;

            case 4:
                if (remover_inicio(lista)) {
                    printf("Numero removido do inicio com sucesso!\n");
                } else {
                    printf("Erro ao remover do inicio.\n");
                }
                break;

            case 5:
                printf("Digite a posicao para remover: ");
                scanf("%d", &posicao);
                if (remover_meio(lista, posicao)) {
                    printf("Numero removido da posicao %d com sucesso!\n", posicao);
                } else {
                    printf("Erro ao remover do meio.\n");
                }
                break;

            case 6:
                if (remover_final(lista)) {
                    printf("Numero removido do fim com sucesso!\n");
                } else {
                    printf("Erro ao remover do fim.\n");
                }
                break;

            case 7:
                printf("Digite a chave para consultar: ");
                scanf("%d", &chave);
                resultado = consulta_por_chave(lista, &numero, chave);
                if (resultado) {
                    printf("Numero encontrado: Chave = %d, Valor = %d\n", numero.chave, numero.valor);
                } else {
                    printf("Chave nao encontrada.\n");
                }
                break;

            case 8:
                printf("Digite o indice para consultar: ");
                scanf("%d", &posicao);
                resultado = consulta_por_indice(lista, &numero, posicao);
                if (resultado) {
                    printf("Numero encontrado: Chave = %d, Valor = %d\n", numero.chave, numero.valor);
                } else {
                    printf("Indice fora de alcance.\n");
                }
                break;

            case 9:
                imprimir_lista(lista);
                break;

            case 10:
                liberar_lista(lista);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 10);

    return 0;
}
