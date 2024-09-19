#include <stdio.h>
#include <stdlib.h>
#include "naturais.h"

int main(){

    void exibeMenu();
    int opcao, elemento;
    Conjunto *nat1 = NULL;
    Conjunto *nat2 = NULL;

    do{

        exibeMenu();
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            if(nat1 != NULL){
                printf("O conjunto ja existe.\n");
            }else{
                nat1 = criaConjunto();
            }
            break;

            case 2:
            if(nat2 != NULL){
                printf("O conjunto ja existe.\n");
            }else{
                nat2 = criaConjunto();
            }
            break;

            case 3:
            if(nat1 != NULL){
                conjuntoVazio(nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 4:
            if(nat1 != NULL){
                printf("Digite o elemento a ser inserido no conjunto 1: ");
                scanf("%d", &elemento);
                insereElementoConjunto(elemento, nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 5:
            if(nat2 != NULL){
                printf("Digite o elemento a ser inserido no conjunto 2: ");
                scanf("%d", &elemento);
                insereElementoConjunto(elemento, nat2);
            }else{
                printf("Conjunto 2 nao foi criado.\n");
            }
            break;

            case 6:
            if(nat1 != NULL){
                printf("Digite o elemento a ser excluido no conjunto 1: ");
                scanf("%d", &elemento);
                excluirElementoConjunto(elemento, nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 7:
            if(nat1 != NULL){
                tamanhoConjunto(nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 8:
            if(nat1 != NULL){
                printf("Digite o elemento a ser comparado com o conjunto 1: ");
                scanf("%d", &elemento);
                maior(elemento, nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 9:
            if(nat1 != NULL){
                printf("Digite o elemento a ser comparado com o conjunto 1: ");
                scanf("%d", &elemento);
                menor(elemento, nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 10:
            if(nat1 != NULL){
                printf("Digite o elemento a ser verificado no conjunto 1: ");
                scanf("%d", &elemento);
                pertenceConjunto(elemento, nat1);
            }else{
                printf("Conjunto 1 nao foi criado.\n");
            }
            break;

            case 11:
            if(nat1 != NULL && nat2 != NULL){
                conjuntosIdenticos(nat1, nat2);
            }else{
                printf("Ambos os conjuntos precisam ser criados primeiro!\n");
            }
            break;

            case 12:
            if(nat1 != NULL && nat2 != NULL){
                subconjunto(nat1, nat2);
            }else{
                printf("Ambos os conjuntos precisam ser criados primeiro!\n");
            }
            break;

            case 13:
            if(nat1 != NULL && nat2 != NULL){
                destruirConjunto(&nat1);
                destruirConjunto(&nat2);
            }else{
                printf("Ambos os conjuntos precisam ser criados primeiro!\n");
            }
            break;

            case 0:
            printf("Saindo...\n");
            break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;

        }

    }while (opcao != 0);

    if (nat1 != NULL) {
        destruirConjunto(&nat1);
    }
    if (nat2 != NULL) {
        destruirConjunto(&nat2);
    }

    return 0;
}

void exibeMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Criar conjunto 1\n");
    printf("2. Criar conjunto 2\n");
    printf("3. Verificar se o conjunto 1 está vazio\n");
    printf("4. Inserir elemento no conjunto 1\n");
    printf("5. Inserir elemento no conjunto 2\n");
    printf("6. Excluir elemento do conjunto 1\n");
    printf("7. Verificar tamanho do conjunto 1\n");
    printf("8. Verificar se elemento eh maior no conjunto 1\n");
    printf("9. Verificar se elemento eh menor no conjunto 1\n");
    printf("10. Vericar se elemento pertence ao conjunto 1\n");
    printf("11. Comparar se dois conjuntos sao identicos\n");
    printf("12. Verificar se conjunto 1 eh subconjunto de conjunto 2\n");
    printf("13. Destruir conjuntos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}