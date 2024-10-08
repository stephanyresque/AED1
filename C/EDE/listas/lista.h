#define MAX 100
#define CHAVE_BASE 0

typedef struct lista Lista;

typedef struct{
    int chave;
    char nome[50];
    int matricula;
}Aluno;

Lista *criar_lista();
int tamanho_lista(Lista *listinha);
int busca_por_chave(Lista *listinha, int chave, Aluno *aluno);
int busca_por_posicao(Lista *listinha, int posicao, Aluno *aluno);
int inserir_antes_chave(Lista *listinha, int chave, Aluno aluno);
int inserir_depois_chave(Lista *listinha, int chave, Aluno aluno);
int inserir_inicio(Lista *listinha, Aluno aluno);
int inserir_final(Lista *listinha, Aluno aluno);
int remover_por_chave(Lista *listinha, int chave);
int remover_por_posicao(Lista *listinha, int posicao);
int inverter_lista(Lista *listinha);
int concatenar(Lista *lista1, Lista *lista2);
int comparar_listas(Lista *lista1, Lista *lista2);
void imprimir_lista(Lista *listinha);
void liberar_lista(Lista *listinha);
