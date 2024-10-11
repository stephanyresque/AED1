#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void menu() {
    printf("\n=== Menu da Pilha ===\n");
    printf("1. Inserir elemento (push)\n");
    printf("2. Remover elemento (pop)\n");
    printf("3. Mostrar elemento do topo\n");
    printf("4. Verificar tamanho da pilha\n");
    printf("5. Verificar se a pilha esta cheia\n");
    printf("6. Verificar se a pilha esta vazia\n");
    printf("7. Imprimir pilha\n");
    printf("8. Sair\n");
    printf("=====================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Pilha *minha_pilha = cria_pilha();
    if (minha_pilha == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 1;
    }

    int opcao;
    Numero num;
    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                printf("Digite o valor: ");
                scanf("%d", &num.valor);
                printf("Digite a chave: ");
                scanf("%d", &num.chave);
                if (push(minha_pilha, num)) {
                    printf("Elemento inserido com sucesso!\n");
                } else {
                    printf("Erro: Pilha cheia ou nao alocada.\n");
                }
                break;

            case 2:
                
                if (pop(minha_pilha)) {
                    printf("Elemento removido com sucesso!\n");
                } else {
                    printf("Erro: Pilha vazia ou nao alocada.\n");
                }
                break;

            case 3:
                
                if (topo_pilha(minha_pilha, &num)) {
                    printf("Topo da pilha: Chave = %d, Valor = %d\n", num.chave, num.valor);
                } else {
                    printf("Erro: Pilha vazia ou nao alocada.\n");
                }
                break;

            case 4:
                
                printf("Tamanho da pilha: %d\n", tamanho_pilha(minha_pilha));
                break;

            case 5:
                
                if (pilha_cheia(minha_pilha)) {
                    printf("A pilha esta cheia.\n");
                } else {
                    printf("A pilha nao esta cheia.\n");
                }
                break;

            case 6:
                
                if (pilha_vazia(minha_pilha)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia.\n");
                }
                break;

            case 7:
                
                imprimir_pilha(minha_pilha);
                break;

            case 8:
                
                printf("Saindo...\n");
                libera_pilha(minha_pilha);
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 8);

    return 0;
}
