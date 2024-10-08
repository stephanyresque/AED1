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
        // Como isso funciona? O campo "proximo" do novo nó vai apontar para o antigo topo da pilha. Isso garante que o novo nó se torne o topo e o antigo topo fique logo abaixo dele na pilha.
        // Se a pilha estava vazia (ou seja, topo era NULL), o campo proximo do novo nó também será NULL, indicando que este é o único elemento na pilha.
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
// Antes de Maria ser empilhada, a pilha está assim:
// Pilha (vazia)

// Depois de Maria ser empilhada:
// Topo -> [Maria, 01/01/1990] -> NULL

// Agora, se você empilhar outra pessoa (por exemplo, "João" nascido em 02/02/1992):
// Topo -> [João, 02/02/1992] -> [Maria, 01/01/1990] -> NULL