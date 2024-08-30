#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome_dep[25];
    int quant_func;
    int anos_exist;

}Departamento;

typedef struct
{
    char nome[25];
    int matricula;
    int anos_trabalhados;
    Departamento dpt[10];

}Funcionario;

int main()
{
    Funcionario fp[10];
    int F;
    printf("Insira a quantidade de funcionarios: ");
    scanf("%d", &F);

    for(int i = 0; i < F; i++)
    {
        fflush(stdin);
        printf("Nome funcionario: ");
        fgets(fp[i].nome, 25, stdin);
        printf("Sua matricula: ");
        scanf("%d", &fp[i].matricula);
        printf("Anos trabalhados: ");
        scanf("%d", &fp[i].anos_trabalhados);
        printf("Departamento\n");

        fflush(stdin);
        printf("Nome: ");
        fgets(fp[i].dpt[i].nome_dep, 25, stdin);
        printf("Quantidade de funcionarios: ");
        scanf("%d", &fp[i].dpt[i].quant_func);
        printf("Anos de existencia: ");
        scanf("%d", &fp[i].dpt[i].anos_exist);

    }
    system("cls");
    printf("Funcionarios e departamentos\n");
    for(int i = 0; i < F; i++)
    {
        printf("Nome: %s", fp[i].nome);
        printf("Matricula: %d\n", fp[i].matricula);
        printf("Anos trabalhados: %d\n", fp[i].anos_trabalhados);
        printf("Departamento: %s", fp[i].dpt[i].nome_dep);
        printf("Quantidade de funcionarios: %d\n", fp[i].dpt[i].quant_func);
        printf("Anos de existencia: %d\n", fp[i].dpt[i].anos_exist);
    }


    return 0;
}
