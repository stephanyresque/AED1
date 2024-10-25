typedef struct numero{
    int valor;
}Numero;

typedef struct elemento* Lista;

Lista* cria_lista();//
void libera_lista(Lista *li);//
int inserir_lista_inicio(Lista *li, Numero number);//
int inserir_lista_final(Lista *li, Numero number);//
int inserir_lista_pos(Lista *li, int pos, Numero number);//
int tamanho_lista(Lista *li);//
int remover_inicio(Lista *li, int n_numeros);//
int remover_final(Lista *li, int n_numeros);//
void imprimir_lista(Lista *li);//