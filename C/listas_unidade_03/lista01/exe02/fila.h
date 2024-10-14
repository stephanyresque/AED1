#define MAX 100
#define CHAVE_BASE 0

typedef struct fila Fila;

typedef struct{

    int valor;
    int chave;
}Numero;

Fila* cria_fila();
void libera_fila(Fila *filha);
int tamanho_fila(Fila *filha);
int fila_cheia(Fila *filha);
int fila_vazia(Fila *filha);
int inserir_fila(Fila *filha, Numero number);
int remove_fila(Fila *filha);
int consulta_primeiro_fila(Fila *filha, Numero *number);
void imprimir_fila(Fila *filha);