
typedef struct conjunto Conjunto;

#define TRUE 1
#define FALSE 0
#define SUCESSO 1
#define FALHA 0

Conjunto* criaConjunto();
int conjuntoVazio(Conjunto *nat);
int insereElementoConjunto(int x, Conjunto *nat);
int excluirElementoConjunto(int x, Conjunto *nat);
int tamanhoConjunto(Conjunto *nat);
int maior(int x, Conjunto *nat);
int menor(int x, Conjunto *nat);
int pertenceConjunto(int x, Conjunto *nat);
int conjuntosIdenticos(Conjunto *nat1,Conjunto *nat2);
int subconjunto(Conjunto *nat1, Conjunto *nat2);
void destruirConjunto(Conjunto **nat);

// void menu();

