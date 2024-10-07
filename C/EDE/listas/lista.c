#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    Aluno dados[MAX];
    int tamanho;
};

Lista *criar_lista(){
    
    Lista *listinha;

    listinha = (Lista *)malloc(sizeof(Lista));

    if(listinha == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }else{
        int i;

        for(i=0;i<MAX;i++){
            listinha->dados[i].chave = CHAVE_BASE;
        }

        listinha->tamanho = 0;
    }

    return listinha;

}

int tamanho_lista(Lista *listinha){
    if(listinha == NULL){

        return 0;
    }else{

        return listinha->tamanho;
    }
}

int busca_por_chave(Lista *listinha, int chave, Aluno *aluno){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }else{
        int i;

        for(i=0; i<listinha->tamanho;i++){
            if(listinha->dados[i].chave == chave){

                *aluno = listinha->dados[i];
                return 1;
            }
        }
    }

    return 0;
}

int busca_por_posicao(Lista *listinha, int posicao, Aluno *aluno){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }else{
        int i;

        for(i=0; i<listinha->tamanho;i++){
            if(i == posicao){
                
                *aluno = listinha->dados[i];
                return 1;
            }
        }
    }

    return 0;
}

int inserir_antes_chave(Lista *listinha, int chave, Aluno aluno){

    if(listinha == NULL || listinha->tamanho == MAX){
        return 0;
    }else{
        int i;

        for(i=0;i<listinha->tamanho;i++){

            if(listinha->dados[i].chave == chave){

                for(int j = listinha->tamanho; j > i; j--){

                    listinha->dados[j] = listinha->dados[j - 1];
                }

                listinha->dados[i] = aluno;
                listinha->tamanho++;
                return 1;
            }
        }
    }

    return 0;
}

int inserir_depois_chave(Lista *listinha, int chave, Aluno aluno){
    if (listinha == NULL || listinha->tamanho >= MAX) {
        return 0;  
    }

    int i;
    for (i = 0; i < listinha->tamanho; i++) {
        if (listinha->dados[i].chave == chave) {
            
            for (int j = listinha->tamanho; j > i + 1; j--) {
                listinha->dados[j] = listinha->dados[j - 1];
            }
            
            listinha->dados[i + 1] = aluno;
            listinha->tamanho++;
            return 1;  
        }
    }

    return 0;
}


