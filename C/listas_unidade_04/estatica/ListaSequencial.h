#define MAX 100  

typedef struct {
    int dados[MAX]; 
    int tamanho;     
} ListaEstatica;

ListaEstatica* inicializar_lista();
int lista_vazia(ListaEstatica *lista);
int lista_cheia(ListaEstatica *lista);
int inserir_n_final(ListaEstatica *lista, int valores[], int n);
int inserir_n_inicio(ListaEstatica *lista, int valores[], int n);
int remover_final(ListaEstatica *lista);
int acessar_n_elementos(ListaEstatica *lista, int posicoes[], int n, int valores[]);


