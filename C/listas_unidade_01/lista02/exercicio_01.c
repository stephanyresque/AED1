#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char logradouro[25];
    int numero;
    char bairro[25];
    char complemento[50];
    int cep;
    char cidade[25];
    char estado[25];

}Endereco;

typedef struct
{
    char nome[25];
    int idade;
    Endereco dados;

}Pessoa;

int main()
{
    Pessoa pessoa;

    printf("Informe seu nome: ");
    fgets(pessoa.nome,25,stdin);
    printf("Sua idade: ");
    scanf("%d", &pessoa.idade);
    if(pessoa.idade >= 120 || pessoa.idade <=0)
    {
        printf("Idade invalida\n");
        pessoa.idade = 0;
    }
    fflush(stdin);
    system("cls");
    printf("Dados de endereco\n");
    printf("Logradouro: ");
    fgets(pessoa.dados.logradouro,25,stdin);
    printf("Numero: ");
    scanf("%d", &pessoa.dados.numero);
    fflush(stdin);
    printf("Bairro: ");
    fgets(pessoa.dados.bairro,25,stdin);
    printf("CEP: ");
    scanf("%d", &pessoa.dados.cep);
    printf("Estado: ");
    fflush(stdin);
    fgets(pessoa.dados.estado,25,stdin);
    printf("Cidade: ");
    fgets(pessoa.dados.cidade,25,stdin);
    printf("Complemento: ");
    fgets(pessoa.dados.complemento,50,stdin);

    system("cls");

    printf("DADOS %s", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Seu endereco\n");
    printf("Logradouro: %s", pessoa.dados.logradouro);
    printf("Numero: %d\n", pessoa.dados.numero);
    printf("Bairro: %s", pessoa.dados.bairro);
    printf("CEP: %d\n", pessoa.dados.cep);
    printf("Estado: %s", pessoa.dados.estado);
    printf("Cidade: %s", pessoa.dados.cidade);
    printf("Complemento: %s", pessoa.dados.complemento);


    return 0;
}
