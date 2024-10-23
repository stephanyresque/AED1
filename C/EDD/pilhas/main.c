#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void menu(){
    printf("\n---------- MENU ----------\n");
    printf("1. Criar pilha\n");
    printf("2. Liberar pilha\n");
    printf("3. Inserir aluno\n");
    printf("4. Remover aluno\n");
    printf("5. Consultar topo da pilha\n");
    printf("6. Verificar tamanho da pilha\n");
    printf("7. Verificar se pilha esta cheia\n");
    printf("8. Verificar se pilha esta vazia\n");
    printf("9. Imprimir pilha\n");
    printf("0. Sair\n");
    printf("---------------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Pilha* pi = NULL;
    Aluno al;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();  

        switch(opcao) {
            case 1:
                pi = cria_Pilha();
                printf("Pilha criada com sucesso!\n");
                break;

            case 2:
                libera_Pilha(pi);
                pi = NULL;
                printf("Pilha liberada!\n");
                break;

            case 3:
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                getchar();
                printf("Digite o nome: ");
                fgets(al.nome, 50, stdin);
                printf("Digite a primeira nota: ");
                scanf("%f", &al.n1);
                printf("Digite a segunda nota: ");
                scanf("%f", &al.n2);
                printf("Digite a terceira nota: ");
                scanf("%f", &al.n3);
                if(insere_Pilha(pi, al)) {
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir aluno!\n");
                }
                break;

            case 4:
                if(remove_Pilha(pi)) {
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Erro ao remover aluno (pilha vazia ou nao criada)!\n");
                }
                break;

            case 5:
                if(consulta_topo_Pilha(pi, &al)) {
                    printf("Topo da pilha:\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s", al.nome);
                    printf("Notas: %.2f | %.2f | %.2f\n", al.n1, al.n2, al.n3);
                } else {
                    printf("Erro ao consultar topo (pilha vazia ou nao criada)!\n");
                }
                break;

            case 6:
                printf("Tamanho da pilha: %d\n", tamanho_Pilha(pi));
                break;

            case 7:
                if(Pilha_cheia(pi)) {
                    printf("Pilha cheia!\n");
                } else {
                    printf("Pilha nao esta cheia!\n");
                }
                break;

            case 8:
                if(Pilha_vazia(pi)) {
                    printf("Pilha esta vazia!\n");
                } else {
                    printf("Pilha nao esta vazia!\n");
                }
                break;

            case 9:
                printf("Imprimindo a pilha:\n");
                imprime_Pilha(pi);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while(opcao != 0);

    if(pi != NULL) {
        libera_Pilha(pi);
    }

    return 0;
}
