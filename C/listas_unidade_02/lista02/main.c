#include <stdio.h>
#include <stdlib.h>
#include "naturais.h"

int main(){

    Conjunto *nat;

    nat = criaConjunto();

    conjuntoVazio(nat);

    insereElementoConjunto(1, nat);
    insereElementoConjunto(2, nat);
    insereElementoConjunto(3, nat);
    insereElementoConjunto(4, nat);
    insereElementoConjunto(5, nat);
    insereElementoConjunto(6, nat);


    excluirElementoConjunto(6, nat);

    tamanhoConjunto(nat);

    maior(3, nat);

    menor(3, nat);

    pertenceConjunto(5, nat);



    return 0;
}