#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[25];
    float nota1, nota2, nota3;
    int matricula;

}Aluno;

int main()
{
    Aluno dados;

    printf("tamanho estrutura: %d\n", sizeof(dados));

    printf("Nome do aluno: ");
    fgets(dados.nome,25,stdin);
    printf("Notas: ");
    scanf("%f %f %f", &dados.nota1, &dados.nota2, &dados.nota3);
    printf("Matricula: ");
    scanf("%d", &dados.matricula);

    printf("tamanho estrutura: %d", sizeof(dados));

    return 0;
}
