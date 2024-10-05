#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
    
    Fila *minha_fila;
    Aluno aluno;
    int opcao, posicao, resultado;

    minha_fila = cria_fila();

    do{
        printf("\n1 - Inserir aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Consultar aluno por posicao\n");
        printf("4 - Consultar aluno ao final da fila\n");
        printf("5 - Consultar aluno no inicio da fila\n");
        printf("6 - Consultar tamanho da fila\n");
        printf("7 - Imprimir pilha\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            if(fila_cheia(minha_fila)){

                printf("Fila cheia.\n");
            }else{
                printf("Informe os dados do aluno: \n");
                printf("Nome: ");
                fflush(stdin);
                fgets(aluno.nome,25,stdin);
                printf("Matricula: ");
                scanf("%d", &aluno.matricula);
                printf("Media: ");
                scanf("%f", &aluno.media);

                inserir_elemento(minha_fila, aluno);
            }
            break;
        case 2:

            if(remover_elemento(minha_fila)){

                printf("Elemento removido com sucesso.\n");
            }else{

                printf("Erro ao remover aluno da fila.\n");
            }
            break;
        case 3:

            printf("Insira a posicao: ");
            scanf("%d", &posicao);

            mostrar_elemento(minha_fila, posicao);
            break;
        case 4:

            if(consulta_final(minha_fila, &aluno)){
                printf("Nome: %s", aluno.nome);
                printf("Matricula: %d\n", aluno.matricula);
                printf("Media: %.2f\n", aluno.media);
            }else{

                printf("Erro ao consultar final da fila.\n");
            }
            break;
        case 5:

            if(consulta_inicio(minha_fila, &aluno)){
                printf("Nome: %s", aluno.nome);
                printf("Matricula: %d\n", aluno.matricula);
                printf("Media: %.2f\n", aluno.media);
            }else{

                printf("Erro ao consultar final da fila.\n");
            }
            break;
        case 6:

            resultado = tamanho_fila(minha_fila);

            if(resultado != 0){

                printf("Tamanho atual da fila: %d\n", resultado);
            }else{

                printf("Fila nao criada ainda.\n");
            }
            break;
        case 7:

            imprimir_fila(minha_fila);
            break;
        case 8:

            printf("Saindo...\n");
            break;
        default:

            printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 8);
    
    liberar_fila(minha_fila);
    
    return 0;
}