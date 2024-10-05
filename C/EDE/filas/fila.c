#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct fila{
    int tamanho;
    Aluno dados[MAX];
};

Fila *cria_fila(){
    Fila *filha;

    filha = (Fila*)malloc(sizeof(Fila));

    if(filha == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }else{
        int i;

        filha->tamanho = 0;

    }

    return filha;
}

int fila_vazia(Fila *filha){

    if(filha == NULL){

        return -1;
    }

    if(filha->tamanho == 0){

        return 1;
    }else{

        return 0;
    }
}

int inserir_elemento(Fila *filha, Aluno aluno){

    if(filha == NULL){

        return 0;
    }else{
        
        filha->dados[filha->tamanho] = aluno;
        filha->tamanho++;
        
        return 1;
    }

}

int tamanho_fila(Fila *filha){

    if(filha == NULL){

        return 0;
    }else{

        return filha->tamanho;
    }

}

int remover_elemento(Fila *filha){

    if(filha == NULL || fila_vazia(filha)){

        return 0;
    }else{
        int i;

        for(i=0;i<filha->tamanho - 1;i++){
            filha->dados[i] = filha->dados[i+1];
        }
        filha->tamanho--;
        
        return 1;
    }

}

void mostrar_elemento(Fila *filha, int posicao){

    if(filha == NULL || fila_vazia(filha) || posicao < 0 || posicao > MAX || posicao > filha->tamanho - 1){

        printf("Erro ao mostrar dados do aluno.\n");
        exit(1);
    }else{

        printf("------ DADOS ALUNO ------\n");
        printf("Nome: %s", filha->dados[posicao].nome);
        printf("Matricula: %d\n", filha->dados[posicao].matricula);
        printf("Media: %.2f\n", filha->dados[posicao].media);

    }

}

int consulta_final(Fila *filha, Aluno *aluno){

    if(filha == NULL || fila_vazia(filha)){

        return 0;
    }else{

        *aluno = filha->dados[filha->tamanho-1];

        return 1;
    }
}
int consulta_inicio(Fila *filha, Aluno *aluno){

    if(filha == NULL || fila_vazia(filha)){

        return 0;
    }else{

        *aluno = filha->dados[0];

        return 1;
    }
}

void imprimir_fila(Fila *filha){

    if(filha == NULL || fila_vazia(filha)){

        printf("Erro ao mostrar dados do aluno.\n");
        exit(1);
    }else{
        int i;

        for(i=0;i<filha->tamanho;i++){
            printf("DADO %d:\n", i);
            printf("Nome: %s", filha->dados[i].nome);
            printf("Matricula: %d\n", filha->dados[i].matricula);
            printf("Media: %.2f\n", filha->dados[i].media);
        }
    }
}

void liberar_fila(Fila *filha){
    free(filha);
}

int fila_cheia(Fila *filha){

    if(filha == NULL){

        return -1;
    }else if(filha->tamanho == MAX){

        return 1;
    }else{

        return 0;
    }
}

