
typedef struct aluno{
    int matricula;
    char nome[50];
    float n1,n2,n3;
}Aluno;

typedef struct elemento* Lista;

Lista* cria_lista(); //
void libera_lista(Lista* li); //
int insere_lista_final(Lista* li, Aluno al); //
int insere_lista_inicio(Lista* li, Aluno al); //
int insere_lista_pos(Lista* li, int pos, Aluno al); //
int remove_lista(Lista* li, int mat); //
int remove_lista_inicio(Lista* li); //
int remove_lista_final(Lista* li); //
int tamanho_lista(Lista* li); //
int lista_vazia(Lista* li); //
int lista_cheia(Lista* li); //
void imprime_lista(Lista* li); //
int consulta_lista_mat(Lista* li, int mat, Aluno *al); //
int consulta_lista_pos(Lista* li, int pos, Aluno *al); //