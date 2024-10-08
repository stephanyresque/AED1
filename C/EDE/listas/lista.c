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

int inserir_inicio(Lista *listinha, Aluno aluno){

    if (listinha == NULL || listinha->tamanho >= MAX) {
        return 0;  
    }

    for (int i = listinha->tamanho; i > 0; i--) {
        listinha->dados[i] = listinha->dados[i - 1];
    }

    listinha->dados[0] = aluno;
    listinha->tamanho++;
    return 1;

}

int inserir_final(Lista *listinha, Aluno aluno){

    if (listinha == NULL || listinha->tamanho >= MAX) {
        return 0;  
    }else{

        listinha->dados[listinha->tamanho] = aluno;
        listinha->tamanho++;
        return 1;
    }

    
}

int remover_por_chave(Lista *listinha, int chave){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }

    int i;
    for(i=0; i<listinha->tamanho;i++){

        if(listinha->dados[i].chave == chave){

            int j;
            for(j = i; j < listinha->tamanho - 1; j++){

                listinha->dados[j] = listinha->dados[j + 1];
            }

            listinha->tamanho--;
            return 1;
        }
    }

    return 0;   
}

int remover_por_posicao(Lista *listinha, int posicao){

    if(listinha == NULL || listinha->tamanho == 0){

        return 0;
    }else{
        int i;

        for(i=0; i<listinha->tamanho;i++){
            if(i == posicao){
                
                int j;
                for(j = i; j < listinha->tamanho - 1; j++){

                    listinha->dados[j] = listinha->dados[j + 1];
                }

                listinha->tamanho--;
                return 1;
            }
        }
    }

    return 0;
}

int inverter_lista(Lista *listinha){

    if (listinha == NULL || listinha->tamanho <= 1) {

        return 0;  
    }

    int inicio = 0;
    int fim = listinha->tamanho - 1;
    Aluno temp;

    while (inicio < fim) {
        
        temp = listinha->dados[inicio];
        listinha->dados[inicio] = listinha->dados[fim];
        listinha->dados[fim] = temp;

        
        inicio++;
        fim--;
    }

    return 1;
}

int concatenar_listas(Lista *lista1, Lista *lista2) {
    if (lista1 == NULL || lista2 == NULL) {
        return 0;  
    }

    
    if (lista1->tamanho + lista2->tamanho > MAX) {
        return 0;  
    }

    // Copiar os elementos da lista2 para o final da lista1
    for (int i = 0; i < lista2->tamanho; i++) {
        lista1->dados[lista1->tamanho] = lista2->dados[i];
        lista1->tamanho++;
    }

    return 1;  
}

int comparar_listas(Lista *lista1, Lista *lista2) {
    if (lista1 == NULL || lista2 == NULL){

        return 0;  
    }

    if (lista1->tamanho != lista2->tamanho){

        return 0;  
    }

    for (int i = 0; i < lista1->tamanho; i++) {
        
        if (lista1->dados[i].chave != lista2->dados[i].chave ||
            strcmp(lista1->dados[i].nome, lista2->dados[i].nome) != 0 ||
            lista1->dados[i].matricula != lista2->dados[i].matricula) {
            return 0;  
        }
    }

    return 1;  
}

void imprimir_lista(Lista *listinha) {
    if (listinha == NULL || listinha->tamanho == 0) {
        printf("A lista está vazia.\n");
        return;
    }

    for (int i = 0; i < listinha->tamanho; i++) {
        printf("Chave: %d, Nome: %s, Matrícula: %d\n", 
               listinha->dados[i].chave, listinha->dados[i].nome, listinha->dados[i].matricula);
    }
}

void liberar_lista(Lista *listinha){
    free(listinha);
}
