#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct
{
    int matricula;
    char nome[25];
}Aluno;
*/

int main()
{
/*
    Aluno *a;

    for(int i=0; i<2;i++)
    {
        printf("Informe a matricula do aluno: ");
        scanf("%d", &(a[i].matricula));
        printf("Matricula: %d\n", a[i].matricula);
        fflush(stdin);
        printf("Informe o nome do aluno: ");
        fgets(a[i].nome, 25, stdin);
        printf("Aluno: %s", a[i].nome);
    }
*/

/*
    int *pt, numero;

    pt = &numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("numero apontado: %d\n", *pt);
    printf("seu endereco: %d\n", pt);
*/
/*
    int *pt, vet[3];

    pt = vet;

    for(int i=0;i<3;i++)
    {
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &vet[i]);
    }

    for(int i=0;i<3;i++)
    {
        printf("numero: %d\n", *(pt+i));
    }


//pt[i] = *(pt+i)
*/

int vet[3] = {1,2,3}; //vetores são ponteiros!

    for(int i=0;i<3;i++)
    {
        printf("numero: %d\n", *(vet+i));
    }
    return 0;
}





