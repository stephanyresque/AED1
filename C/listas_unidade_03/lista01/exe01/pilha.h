#define MAX 100
#define CHAVE_BASE 0

typedef struct pilha Pilha;

typedef struct{

    int valor;
    int chave;
}Numero;

Pilha *cria_pilha();
void libera_pilha(Pilha *pilhinha);
int tamanho_pilha(Pilha *pilhinha);
int pilha_cheia(Pilha *pilhinha);
int pilha_vazia(Pilha *pilhinha);
int push(Pilha *pilhinha, Numero number);
int pop(Pilha *pilhinha);
int topo_pilha(Pilha *pilhinha, Numero *number);
void imprimir_pilha(Pilha *pilhinha);