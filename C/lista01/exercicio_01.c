#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char logradouro[25];
    int numero;
    char bairro[25];
    char complemento[25];
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

    return 0;
}
