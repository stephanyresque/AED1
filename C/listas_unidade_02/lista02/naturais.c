#include <stdio.h>
#include <stdlib.h>
#include "naturais.h"

struct conjunto{
    int *numeros;
    int cardinalidade;
    int capacidade;
};

Conjunto* criaConjunto(){
    Conjunto *nat;

    nat = (Conjunto*)calloc(1,sizeof(Conjunto));

    if(nat==NULL){
        printf("Erro ao criar conjunto.\n");
        return NULL;
    }else{
        nat->numeros = NULL;
        nat->cardinalidade = 0;
        nat->capacidade = 0;
        return nat;
    }
}

int conjuntoVazio(Conjunto *nat){

    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALSE;
    }
    if(nat->cardinalidade == 0){
        printf("Conjunto vazio.\n");
        return TRUE;
    }else{
        printf("Conjunto nao vazio.\n");
        return FALSE;
    }
}

int insereElementoConjunto(int x, Conjunto *nat){

    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALHA;
    }

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            printf("Elemento ja existe.\n");
            return FALHA;
        }
    }

    if(nat->cardinalidade == nat->capacidade){
        int novaCapacidade;

        if(nat->capacidade = 0){
            novaCapacidade = 1;
        }else{
            novaCapacidade = 2 * nat->capacidade;
        }

        int *novosNumeros;

        novosNumeros = (int*)realloc(nat->numeros, novaCapacidade * sizeof(int));

        if(novosNumeros == NULL){
            printf("Erro ao realocar o conjunto.\n");
            return FALHA;
        }
        nat->numeros = novosNumeros;
        nat->capacidade = novaCapacidade;
    }

    nat->numeros[nat->cardinalidade++] = x;
    printf("Elemento adicionado com sucesso.\n");
    return SUCESSO;
}

int excluirElementoConjunto(int x, Conjunto *nat){
    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALHA;
    }

    int indice = -1;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            indice = i;
            break;
        }
    }

    if(indice == -1){
        printf("O elemento nao existe.\n");
        return FALHA;
    }

    for(int i = indice; i < nat->cardinalidade - 1; i++){
        nat->numeros[i] = nat->numeros[i+1];
    }

    nat->cardinalidade--;

    printf("Elemento excluido com sucesso.\n");
    return SUCESSO;
}

int tamanhoConjunto(Conjunto *nat){

    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALHA;
    }
    printf("Tamanho do conjunto/cardinalidade: %d\n", nat->cardinalidade);
    return nat->cardinalidade;
}

int maior(int x, Conjunto *nat){

    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALHA;
    }

    if(nat->cardinalidade == 0){
        printf("Conjunto vazio.\n");
        return 0;
    }
    int total = 0;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] > x){
            total++;
        }
    }

    if(total == nat->cardinalidade){
        printf("Todos os elementos do conjunto sao maiores que x.\n");
        return 0;
    }else{
        printf("Maiores que %d: %d\n", x, total);
        return total;
    }
}

int menor(int x, Conjunto *nat){

    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALHA;
    }

    if(nat->cardinalidade == 0){
        printf("Conjunto vazio.\n");
        return 0;
    }

    int total = 0;

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] < x){
            total++;
        }
    }

    if(total == nat->cardinalidade){
        printf("Todos os elementos do conjunto sao menores que x.\n");
        return 0;
    }else{
        printf("Menores que %d: %d\n", x, total);
        return total;
    }

}

int pertenceConjunto(int x, Conjunto *nat){

    if(nat == NULL){
        printf("O conjunto nao foi criado ainda.\n");
        return FALHA;
    }

    for(int i = 0; i < nat->cardinalidade; i++){
        if(nat->numeros[i] == x){
            printf("%d pertence ao conjunto.\n", x);
            return TRUE;
        }
    }
    printf("%d nao pertence ao conjunto.\n", x);
    return FALSE;
}

int conjuntosIdenticos(Conjunto *nat1,Conjunto *nat2){

    if((nat1 == NULL) || (nat2 == NULL)){
        printf("Um ou ambos os conjuntos nao foram criados ainda.\n");
        return FALHA;
    }


    if(nat1->cardinalidade != nat2->cardinalidade){
        printf("Os conjuntos nao sao identicos.\n");
        return FALSE;
    }
    int verificador = 0;

    for(int i = 0; i <nat1->cardinalidade; i++){
        for(int j = 0; j < nat2->cardinalidade; j++){
            if(nat1->numeros[i] = nat2->numeros[j]){
                verificador++;
            }
        }
    }

    if(verificador == nat1->cardinalidade){
        printf("Os conjuntos sao identicos.\n");
        return TRUE;
    }else{
        printf("Os conjuntos nao sao identicos.\n");
        return FALSE;
    }
}

int subconjunto(Conjunto *nat1, Conjunto *nat2){

    if((nat1 == NULL) || (nat2 == NULL)){
        printf("Um ou ambos os conjuntos nao foram criados ainda.\n");
        return FALHA;
    }

    int verificador = 0;

    for(int i = 0; i <nat2->cardinalidade; i++){
        for(int j = 0; j < nat1->cardinalidade; j++){
            if(nat2->numeros[i] = nat1->numeros[j]){
                verificador++;
            }
        }
    }

    if(verificador == nat1->cardinalidade){
        printf("C1 eh um subconjunto de C2.\n");
        return TRUE;
    }else{
        printf("C1 nao eh um subconjunto de C2.\n");
        return FALSE;
    }
}

void destruirConjunto(Conjunto **nat){
    if(*nat == NULL){
        printf("Conjunto nao existe.\n");
        
    }else{
        free((*nat)->numeros);
        free(*nat);
        *nat = NULL; 
        printf("Conjunto destruido.\n");
           
    }
}

// void menu(){

//     while(1==1){
//         int resp;

//         printf("CONJUNTO DOS NATURAIS\n");
//         printf("---------------------------------\n");
//         printf("[1] Criar um conjunto vazio.\n");
//         printf("[2] Verificar se o conjunto eh vazio.\n");
//         printf("[3] Inserir elementos.\n");
//         printf("[4] Excluir elementos do conjunto.\n");
//         printf("[5] Cardinalidade do conjunto.\n");
//         printf("[6] Verificar se x eh maior.\n");
//         printf("[7] Verificar se x eh menor.\n");
//         printf("[8] Verificar se x pertence ao conjunto.\n");
//         printf("[9] Verificar se os conjuntos sao iguais.\n");
//         printf("[10] Verificar se C1 eh subconjunto de C2.\n");
//         printf("[11] Destruir conjunto.\n");
//         printf("[0] Sair.\n");


//         printf("Selecione: ");
//         scanf("%d", &resp);

//         switch (resp)
//         {
//         case 1:
//             Conjunto *nat;
//             nat = criaConjunto();
//             break;
//         case 2:
//             conjuntoVazio(nat);
//             break;
//         case 3:
//             int x;
//             printf("Informe o elemento a ser inserido: \n");
//             scanf("%d", &x);
//             insereElementoConjunto(x, nat);
//             break;
//         case 4:
//             int y;
//             printf("Informe o elemento a ser excluido: \n");
//             scanf("%d", &y);
//             excluirElementoConjunto(y, nat);
//             break;
//         case 5:
//             tamanhoConjunto(nat);
//             break;
//         case 6:
//             int z;
//             printf("Informe o elemento: \n");
//             scanf("%d", &z);
//             maior(z, nat);
//             break;
//         case 7:
//             int w;
//             printf("Informe o elemento: \n");
//             scanf("%d", &w);
//             menor(w, nat);
//             break;
//         case 8:
//             int t;
//             printf("Informe o elemento: \n");
//             scanf("%d", &t);
//             pertenceConjunto(t, nat);
//             break;
//         case 11:
//             destruirConjunto(&nat);
        
//         }

//         if(resp == 0){
//             break;
//         }
//     }
// }


