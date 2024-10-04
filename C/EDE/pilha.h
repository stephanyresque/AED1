#define TAMANHO_MAXIMO  100

typedef struct pilha Pilha;

typedef struct{
    char nome[50];
    int matricula;
    float media;
}Aluno;

Pilha* cria_pilha();
void libera_pilha(Pilha *pilhinha);
int tamanho_pilha(Pilha *pilhinha);
int pilha_vazia(Pilha *pilhinha);
int pilha_cheia(Pilha *pilhinha);
int consulta_topo_pilha(Pilha *pilhinha, Aluno *aluno);
int inserir_elemento(Pilha *pilhinha, Aluno aluno);
int remove_elemento(Pilha *pilhinha);
void imprime_pilha();
