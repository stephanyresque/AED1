typedef struct aluno{
    int matricula;
    char nome[50];
    float n1,n2,n3;
}Aluno;

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, Aluno *al);
int insere_Fila(Fila* fi, Aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);