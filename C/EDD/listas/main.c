#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void menu() {
    printf("------ MENU ------\n");
    printf("1. Criar lista\n");
    printf("2. Inserir aluno no inicio\n");
    printf("3. Inserir aluno no final\n");
    printf("4. Inserir aluno em uma posicao\n");
    printf("5. Consultar aluno pela posicao\n");
    printf("6. Consultar aluno pela matricula\n");
    printf("7. Remover aluno pela matricula\n");
    printf("8. Remover aluno do inicio\n");
    printf("9. Remover aluno do final\n");
    printf("10. Imprimir lista\n");
    printf("11. Exibir tamanho da lista\n");
    printf("12. Verificar se a lista esta vazia\n");
    printf("0. Sair\n");
    printf("------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Lista* li = NULL;
    int opcao, pos, mat;
    Aluno al;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                li = cria_lista();
                if (li != NULL) {
                    printf("Lista criada com sucesso!\n");
                } else {
                    printf("Erro ao criar lista.\n");
                }
                break;

            case 2:
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite o nome: ");
                getchar();  // Limpar o buffer do teclado
                fgets(al.nome, 30, stdin);
                al.nome[strcspn(al.nome, "\n")] = '\0';  // Remover o \n inserido pelo fgets
                printf("Digite as tres notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                if (insere_lista_inicio(li, al)) {
                    printf("Aluno inserido no inicio!\n");
                } else {
                    printf("Erro ao inserir aluno.\n");
                }
                break;

            case 3:
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite o nome: ");
                getchar();  // Limpar o buffer do teclado
                fgets(al.nome, 30, stdin);
                al.nome[strcspn(al.nome, "\n")] = '\0';  // Remover o \n inserido pelo fgets
                printf("Digite as tres notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                if (insere_lista_final(li, al)) {
                    printf("Aluno inserido no final!\n");
                } else {
                    printf("Erro ao inserir aluno.\n");
                }
                break;

            case 4:
                printf("Digite a posicao para inserir o aluno: ");
                scanf("%d", &pos);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite o nome: ");
                getchar();  // Limpar o buffer do teclado
                fgets(al.nome, 30, stdin);
                al.nome[strcspn(al.nome, "\n")] = '\0';  // Remover o \n inserido pelo fgets
                printf("Digite as tres notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                if (insere_lista_pos(li, pos, al)) {
                    printf("Aluno inserido na posicao %d!\n", pos);
                } else {
                    printf("Erro ao inserir aluno na posicao.\n");
                }
                break;

            case 5:
                printf("Digite a posicao a ser consultada: ");
                scanf("%d", &pos);
                if (consulta_lista_pos(li, pos, &al)) {
                    printf("Aluno encontrado na posicao %d:\n", pos);
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("Notas: %.2f %.2f %.2f\n", al.n1, al.n2, al.n3);
                } else {
                    printf("Aluno nao encontrado na posicao %d.\n", pos);
                }
                break;

            case 6:
                printf("Digite a matricula a ser consultada: ");
                scanf("%d", &mat);
                if (consulta_lista_mat(li, mat, &al)) {
                    printf("Aluno com matricula %d encontrado:\n", mat);
                    printf("Nome: %s\n", al.nome);
                    printf("Notas: %.2f %.2f %.2f\n", al.n1, al.n2, al.n3);
                } else {
                    printf("Aluno com matricula %d nao encontrado.\n", mat);
                }
                break;

            case 7:
                printf("Digite a matricula do aluno a ser removido: ");
                scanf("%d", &mat);
                if (remove_lista(li, mat)) {
                    printf("Aluno com matricula %d removido com sucesso!\n", mat);
                } else {
                    printf("Erro ao remover aluno com matricula %d.\n", mat);
                }
                break;

            case 8:
                if (remove_lista_inicio(li)) {
                    printf("Aluno removido do inicio com sucesso!\n");
                } else {
                    printf("Erro ao remover aluno do inicio.\n");
                }
                break;

            case 9:
                if (remove_lista_final(li)) {
                    printf("Aluno removido do final com sucesso!\n");
                } else {
                    printf("Erro ao remover aluno do final.\n");
                }
                break;

            case 10:
                imprime_lista(li);
                break;

            case 11:
                printf("Tamanho da lista: %d\n", tamanho_lista(li));
                break;

            case 12:
                if (lista_vazia(li)) {
                    printf("A lista esta vazia.\n");
                } else {
                    printf("A lista contem elementos.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                libera_lista(li);
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
