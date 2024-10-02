#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[25];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa cria_pessoa(){
    Pessoa p;

    printf("\nDigite o nome e a data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
};

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d", p.nome, p.data.dia, p.data.mes, p.data.ano);
};

// função push (empilhar):
No* push(No *topo){
    No *novo = malloc(sizeof(No));
    
    if(novo == NULL){
        printf("\nErro ao alocar memoria...\n");
        return NULL;
    }else{
        novo->p = cria_pessoa();
        novo->proximo = topo;
        return novo;
    }
};

int main(){

    No *topo = NULL;
    int opcao;

    do{
        printf("\n0 - sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            topo = push(topo);
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!!!\n");
            break;
        }
    }while(opcao != 0);
    
    

    return 0;
}