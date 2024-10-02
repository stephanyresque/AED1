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

//função desempilhar
No* pop(No **topo){ //como eu quero alterar o conteúdo do meu topo, preciso passar o endereço de memória da minha variável, se não apenas uma cópia será feita.
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        // Você está dizendo: "o ponteiro remover agora vai apontar para o mesmo lugar que *topo está apontando" — ou seja, remover e *topo estão apontando para o mesmo nó no topo da pilha.
        return remover;
    }else{
        printf("\nPilha vazia\n");
        return NULL;
    }
    
};



int main(){

    No *remover;
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
            remover = pop(&topo);

            if(remover != NULL){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);
            }else{
                printf("\nSem no a remover...\n");
            }
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

// Topo -> [João] -> [Maria] -> NULL
// Topo -> [Maria] -> NULL