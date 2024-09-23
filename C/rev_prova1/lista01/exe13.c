#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct departamento{
    char nome_d[25];
    int n_funcionarios;
    int anos_exist;
}Departamento;

typedef struct funcionario{
    char nome_f[25];
    int matricula;
    int anos_trab;
    Departamento dp[50];
}Funcionario;

int main(){

    int k_func, i;

    printf("Informe quantos funcionarios: ");
    scanf("%d", &k_func);

    Funcionario fp[k_func];

    for(i=0;i<k_func;i++){
        printf("Nome funcionario: ");
        fflush(stdin);
        fgets(fp[i].nome_f,25,stdin);
        printf("Matricula: ");
        scanf("%d", &fp[i].matricula);
        printf("Anos trabalhados: ");
        scanf("%d", &fp[i].anos_trab);

        system("cls");

        printf("-----Departamento-----\n");
        printf("Nome departamento: ");
        fflush(stdin);
        fgets(fp[i].dp[i].nome_d,25,stdin);
        printf("Quantidade de funcionarios: ");
        scanf("%d", &fp[i].dp[i].n_funcionarios);
        printf("Anos de existencia: ");
        scanf("%d", &fp[i].dp[i].anos_exist);

        system("cls");
    }

    system("cls");

    for(i=0;i<k_func;i++){
        printf("--------DADOS--------\n");
        printf("Nome funcionario: %s", fp[i].nome_f);
        printf("Matricula: %d\n", fp[i].matricula);
        printf("Anos trabalhados: %d\n", fp[i].anos_trab);
        if(fp[i].anos_trab >= 30){
            printf("Ja pode solicitar aposentadoria.\n");
        }
        printf("Nome departamento: %s", fp[i].dp[i].nome_d);
        printf("Quantidade de funcionarios: %d\n", fp[i].dp[i].n_funcionarios);
        printf("Anos de existencia: %d\n", fp[i].dp[i].anos_exist);
    }


    return 0;
}