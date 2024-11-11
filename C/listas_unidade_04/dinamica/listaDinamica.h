typedef struct No {
    int dado;            
    struct No *proximo;  
} No;

typedef struct {
    No *inicio;   
    int tamanho;  
} ListaDinamica;

ListaDinamica* inicializar_lista();
int lista_vazia(ListaDinamica *lista);
int inserir_n_final(ListaDinamica *lista, int valores[], int n);
int inserir_n_inicio(ListaDinamica *lista, int valores[], int n);
int remover_final(ListaDinamica *lista);
int acessar_n_elementos(ListaDinamica *lista, int posicoes[], int n, int valores[]);
void liberar_lista(ListaDinamica *lista);


