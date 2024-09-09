#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[25];
    char cargo[25];
    float salario_base;
    int cpf;
    char departamento[25];
    float salario_ajustado;

}Funcionarios;

int main()
{
   Funcionarios dados[25];
   int i;

   printf("Coleta de dados\n");

   for(i=0;i<2;i++)
   {
       printf("Nome: ");
       fgets(dados[i].nome,25,stdin);
       printf("Cargo: ");
       fgets(dados[i].cargo,25,stdin);
       printf("Salario base: ");
       scanf("%f", &dados[i].salario_base);

       if( strcmp(dados[i].cargo, "Assistente") == 0)
       {
           dados[i].salario_ajustado = dados[i].salario_base * 1.05;
       }else if( strcmp(dados[i].cargo, "Supervisor") == 0 )
       {
           dados[i].salario_ajustado = dados[i].salario_base * 1.10;
       }else if( strcmp(dados[i].cargo, "Gerente") == 0 )
       {
           dados[i].salario_ajustado = dados[i].salario_base * 1.15;
       }else
       {
           dados[i].salario_ajustado = dados[i].salario_base * 1.02;
       }

       printf("CPF: ");
       scanf("%d", &dados[i].cpf);
       printf("Departamento: ");
       fflush(stdin);
       fgets(dados[i].departamento,25,stdin);

   }

    system("cls");
    printf("Dados funcionarios\n");

    for(i=0;i<2;i++)
    {
        printf("NOME: %s", dados[i].nome);
        printf("CARGO: %s", dados[i].cargo);
        printf("SALARIO BASE: %.2f\n", dados[i].salario_base);
        printf("SALARIO AJUSTADO: %.2f\n", dados[i].salario_ajustado);
        printf("CPF: %d\n", dados[i].cpf);
        printf("DEPARTAMENTO: %s", dados[i].departamento);
        printf("--------------------------------------\n");
    }

    return 0;
}
