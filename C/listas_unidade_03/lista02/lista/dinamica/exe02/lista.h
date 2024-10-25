typedef struct numero
{
    int valor;
}Numero;

typedef struct elemento* Lista;

Lista* cria_lista();//
void libera_lista(Lista *li);//
int inserir_inicio(Lista *li, Numero number);//
int inserir_final(Lista *li, Numero number);//
int inserir_pos(Lista *li, int pos,Numero number);//
void imprime_lista(Lista *li);//