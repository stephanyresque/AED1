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