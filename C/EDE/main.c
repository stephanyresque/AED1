#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){

    Pilha *minha_pilha;
    Aluno aluno;

    minha_pilha = cria_pilha();
    int opcao;

    do{
        printf("\n1 - Inserir aluno (push)\n");
        printf("2 - Remover aluno (pop)\n");
        printf("3 - Consultar aluno no topo\n");
        printf("4 - Imprimir pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if(pilha_cheia(minha_pilha)){
                printf("Pilha cheia!\n");
            }else{
                printf("Nome do aluno: ");
                fflush(stdin);
                fgets(aluno.nome,25,stdin);
                printf("Matricula: ");
                scanf("%d", &aluno.matricula);
                printf("Media: ");
                scanf("%f", &aluno.media);

                push(minha_pilha, aluno);
            }
            break;
        case 2:
            if(pop(minha_pilha)){
                printf("Aluno removido com sucesso!\n");
            }else{
                printf("Erro ao remover aluno.\n");
            }
            break;
        case 3:
            if(consulta_topo_pilha(minha_pilha, &aluno)){
                printf("Nome: %s", aluno.nome);
                printf("Matricula: %d\n", aluno.matricula);
                printf("Media: %.2f\n", aluno.media);
            }else{
                printf("Erro ao consultar topo da pilha.\n");
            }
            break;
        case 4:

            imprime_pilha(minha_pilha);
            break;
        case 5:

            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }

    }while(opcao != 5);

    libera_pilha(minha_pilha);

    return 0;
}