#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

struct naturais{
    int *numeros;
    int cardinalidade;
    int capacidade;
};

Naturais* criaconjunto(){
    Naturais* nat;

    nat = (Naturais*)calloc(1, sizeof(Naturais));

    if(nat == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    nat->capacidade = 0;
    nat->cardinalidade = 0;
    nat->numeros = NULL;

    return nat;
}

int conjuntovazio(Naturais *nat){

    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }
    if(nat->cardinalidade == 0){
        printf("Conjunto vazio.\n");
        return 1;
    }else{
        printf("Conjunto nao vazio.\n");
        return 0;
    }

}

int inserirelemento(int x, Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            printf("O elemento ja existe no conjunto.\n");
            return 0;
        }
    }

    if(nat->capacidade == nat->cardinalidade){
        int nova_capacidade;

        if(nat->capacidade == 0){
            nova_capacidade = 1;
        }else{
            nova_capacidade = 2 * nat->capacidade;
        }

        int *novos_numeros;

        novos_numeros = (int*)realloc(nat->numeros, nova_capacidade * sizeof(int));

        nat->numeros = novos_numeros;
        nat->capacidade = nova_capacidade;
        
    }

    nat->cardinalidade++;
    nat->numeros[nat->cardinalidade] = x;
    printf("Elemento adicionado com sucesso!\n");
    return 1;

}

int excluirelemento(int x, Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    int indice_teste = -1;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            indice_teste = i;
            break;
        }
    }

    if(indice_teste == -1){
        printf("O elemento nao existe.\n");
        return 0;
    }

    for(int i = indice_teste; i < nat->cardinalidade - 1; i++){
        nat->numeros[i] = nat->numeros[i+1];
    }

    nat->cardinalidade--;

    printf("Elemento excluido com sucesso!\n");
    return 1;

}

int cardinalidade(Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    printf("Tamanho do conjunto eh %d\n", nat->cardinalidade);
    return nat->cardinalidade;
}

int maior(int x, Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    int maiores = 0;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] < x){
            maiores++;
        }
    }

    if(maiores == nat->cardinalidade){
        printf("%d eh maior que todos os elementos do conjunto.\n", x);
        return maiores;
    }else{
        printf("%d eh maior que %d elementos do conjunto.\n", x, maiores);
        return maiores;
    }

}

int menor(int x, Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    int menores = 0;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] > x){
            menores++;
        }
    }

    if(menores == nat->cardinalidade){
        printf("%d eh menor que todos os elementos do conjunto.\n", x);
        return menores;
    }else{
        printf("%d eh menor que %d elementos do conjunto.\n", x, menores);
        return menores;
    }

}

int pertenceConjunto(int x, Naturais *nat){
    if(nat == NULL){
        printf("Conjunto nao criado ainda.\n");
        return 0;
    }

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            printf("%d pertence ao conjunto.\n", x);
            return 1;
        }
    }

    printf("%d nao pertence ao conjunto.\n", x);
    return 0;
}

int conjuntosIdenticos(Naturais *nat1,Naturais *nat2){
    if(nat1 == NULL || nat2 == NULL){
        printf("Conjuntos nao criados ainda.\n");
        return 0;
    }

    if(nat1->cardinalidade != nat2->cardinalidade){
        printf("Conjunto nao identicos.\n");
        return 0;
    }

    int iguais = 0;

    for(int i = 0; i < nat1->cardinalidade; i++){
        for(int j = 0; j < nat2->cardinalidade; j++){
            if(nat1->numeros[i] == nat2->numeros[j]){
                iguais++;
            }
        }
    }

    if(iguais == nat1->cardinalidade){
        printf("Os conjuntos sao identicos!\n");
        return 1;
    }else{
        printf("Conjuntos NAO identicos.\n");
        return 0;
    }

}

int subconjunto(Naturais *nat1, Naturais *nat2){
    if(nat1 == NULL || nat2 == NULL){
        printf("Conjuntos nao criados ainda.\n");
        return 0;
    }

    int iguais = 0;

    for(int i = 0; i < nat1->cardinalidade; i++){
        for(int j = 0; j < nat2->cardinalidade; j++){
            if(nat1->numeros[i] == nat2->numeros[j]){
                iguais++;
            }
        }
    }

    if(iguais == nat2->cardinalidade){
        printf("Conjunto C2 eh subconjunto de C1!\n");
        return 1;
    }else{
        printf("Conjunto C2 nao eh subconjunto de C1.\n");
        return 0;
    }
}

void destruirconjunto(Naturais **nat){
    if(*nat == NULL){
        printf("Conjuntos nao criados ainda.\n");
    }else{
        free((*nat)->numeros);
        free(*nat);
        *nat = NULL;
        printf("Conjunto destruido.\n");
    }
}





