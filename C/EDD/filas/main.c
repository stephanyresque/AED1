#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void menu() {
    printf("\n---------- MENU ----------\n");
    printf("1. Criar fila\n");
    printf("2. Liberar fila\n");
    printf("3. Inserir aluno\n");
    printf("4. Remover aluno\n");
    printf("5. Consultar aluno na frente da fila\n");
    printf("6. Verificar tamanho da fila\n");
    printf("7. Verificar se a fila esta cheia\n");
    printf("8. Verificar se a fila esta vazia\n");
    printf("9. Imprimir fila\n");
    printf("0. Sair\n");
    printf("---------------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila* fi = NULL;
    Aluno al;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado após o scanf

        switch(opcao) {
            case 1:
                fi = cria_Fila();
                if (fi != NULL) {
                    printf("Fila criada com sucesso!\n");
                } else {
                    printf("Erro ao criar a fila!\n");
                }
                break;

            case 2:
                libera_Fila(fi);
                fi = NULL;
                printf("Fila liberada!\n");
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

                if(insere_Fila(fi, al)) {
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir aluno!\n");
                }
                break;

            case 4:
                if(remove_Fila(fi)) {
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Erro ao remover aluno (fila vazia ou nao criada)!\n");
                }
                break;

            case 5:
                if(consulta_Fila(fi, &al)) {
                    printf("Aluno na frente da fila:\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("Notas: %.2f | %.2f | %.2f\n", al.n1, al.n2, al.n3);
                } else {
                    printf("Erro ao consultar aluno (fila vazia ou nao criada)!\n");
                }
                break;

            case 6:
                printf("Tamanho da fila: %d\n", tamanho_Fila(fi));
                break;

            case 7:
                if(Fila_cheia(fi)) {
                    printf("Fila cheia!\n");
                } else {
                    printf("Fila nao esta cheia!\n");
                }
                break;

            case 8:
                if(Fila_vazia(fi)) {
                    printf("Fila esta vazia!\n");
                } else {
                    printf("Fila nao esta vazia!\n");
                }
                break;

            case 9:
                printf("Imprimindo a fila:\n");
                imprime_Fila(fi);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while(opcao != 0);

    if(fi != NULL) {
        libera_Fila(fi);
    }

    return 0;
}
