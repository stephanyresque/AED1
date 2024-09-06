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
/*
int main()
{

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
/*
int vet[3] = {1,2,3}; //vetores são ponteiros!

    for(int i=0;i<3;i++)
    {
        printf("numero: %d\n", *(vet+i));
    }
*/
//    int i;
//    printf("%d", sizeof(i));

//sizeof, calloc, malloc, realloc e free
/*
    int *pt;

    pt = calloc(4, sizeof(int));

    if(pt == NULL)
    {
        printf("Erro de alocacao de memoria");
        exit(1);
    }else
    {
        printf("Memoria alocada com sucesso");
    }
*/
/*
    int *vet, tam;

    printf("Qual tamanho do vetor: ");
    scanf("%d", &tam);

    vet = calloc(tam, sizeof(int));

    if(vet == NULL)
    {
        printf("Erro de alocacao de memoria");
        exit(1);
    }else
    {
        printf("Memoria alocada com sucesso");
    }



    return 0;
}

*/

int main()
{
    char letra = 'a';
    char *pt1 = &letra;
    char **pt2 = &pt1;
    char ***pt3 = &pt2;

    printf("%c\n", *pt1);
    printf("%c\n", **pt2);
    printf("%c\n", ***pt3);
    printf("--------------\n");
    printf("%d\n", pt3);
    printf("%d\n", *pt3);
    printf("%d\n", **pt3);
    printf("%c\n", ***pt3);



    return 0;
}


