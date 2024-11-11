#define MAX 100

typedef struct lista Lista;

typedef struct{
    int valor;
}Numero;

Lista *cria_lista();
void liberar_lista(Lista *listinha);
int tamanho_lista(Lista *listinha);
int lista_vazia(Lista *listinha);
int lista_cheia(Lista *listinha);
int inserir_inicio(Lista *listinha, Numero number);
int inserir_fim(Lista *listinha, Numero number);
int inserir_meio(Lista *listinha, Numero number, int pos);
int remover_inicio(Lista *listinha);
int remover_meio(Lista *listinha, int pos);
int remover_final(Lista *listinha);
int consulta_por_indice(Lista *listinha, Numero *number,int indice);
void imprimir_lista(Lista *listinha);
