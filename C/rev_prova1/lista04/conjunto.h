typedef struct naturais Naturais;

Naturais* criaconjunto();
int conjuntovazio(Naturais *nat);
int inserirelemento(int x, Naturais *nat);
int excluirelemento(int x, Naturais *nat);
int cardinalidade(Naturais *nat);
int maior(int x, Naturais *nat);
int menor(int x, Naturais *nat);
int pertenceConjunto(int x, Naturais *nat);
int conjuntosIdenticos(Naturais *nat1,Naturais *nat2);
int subconjunto(Naturais *nat1, Naturais *nat2);
void destruirconjunto(Naturais **nat);
