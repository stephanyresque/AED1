#define MAX 100

typedef struct fila Fila;

typedef struct{
    char nome[50];
    int matricula;
    float media;
}Aluno;

Fila *cria_fila();
int fila_vazia(Fila *filha);
int fila_cheia(Fila *filha);
int inserir_elemento(Fila *filha, Aluno aluno);
int tamanho_fila(Fila *filha);
int remover_elemento(Fila *filha);
void mostrar_elemento(Fila *filha, int posicao);
void imprimir_fila(Fila *filha);
int consulta_final(Fila *filha, Aluno *aluno);
int consulta_inicio(Fila *filha, Aluno *aluno);
void liberar_fila(Fila *filha);
