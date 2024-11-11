
typedef struct numero{
    int valor;
}Numero;

typedef struct elemento* Lista;

Lista* cria_lista(); 
void libera_lista(Lista* li); 
int insere_lista_final(Lista* li, Numero number); 
int insere_lista_inicio(Lista* li, Numero number); 
int insere_lista_pos(Lista* li, int pos, Numero number); 
int remove_lista_inicio(Lista* li); 
int remove_lista_final(Lista* li); 
int tamanho_lista(Lista* li); 
int lista_vazia(Lista* li); 
int lista_cheia(Lista* li); 
void imprime_lista(Lista* li); 
int consulta_lista_pos(Lista* li, int pos, Numero *number); 