#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listasequencial.h"

#define NUM_TESTES 8
int tamanhos_n[] = {100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000};

int main() {
    Lista *lista_estatica;
    Numero number;
    clock_t inicio, fim;
    unsigned long int tempo;
    int i, j, posicao_aleatoria;
    FILE *arquivo;

    // Abre o arquivo "tempo.txt" para escrita
    arquivo = fopen("tempo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo tempo.txt\n");
        return 1;
    }

    for (i = 0; i < NUM_TESTES; i++) {
        int n = tamanhos_n[i];

        // Cria a lista estática
        lista_estatica = cria_lista();

        // Inserção de N elementos no início da lista
        for (j = 0; j < n; j++) {
            number.valor = j;
            inserir_inicio(lista_estatica, number);
        }

        // Medição do tempo de inserção no início
        inicio = clock();
        for (j = 0; j < n; j++) {
            number.valor = j;
            inserir_inicio(lista_estatica, number);
        }
        fim = clock();
        tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
        fprintf(arquivo, "Tempo de inserção no início (%d elementos): %lu ms\n", n, tempo);

        // Inserção de N elementos no final da lista
        for (j = 0; j < n; j++) {
            number.valor = j;
            inserir_fim(lista_estatica, number);
        }

        // Medição do tempo de inserção no final
        inicio = clock();
        for (j = 0; j < n; j++) {
            number.valor = j;
            inserir_fim(lista_estatica, number);
        }
        fim = clock();
        tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
        fprintf(arquivo, "Tempo de inserção no final (%d elementos): %lu ms\n", n, tempo);

        // Consulta de N elementos aleatórios
        for (j = 0; j < n; j++) {
            posicao_aleatoria = rand() % tamanho_lista(lista_estatica);
            consulta_por_indice(lista_estatica, &number, posicao_aleatoria);
        }

        // Medição do tempo de consulta
        inicio = clock();
        for (j = 0; j < n; j++) {
            posicao_aleatoria = rand() % tamanho_lista(lista_estatica);
            consulta_por_indice(lista_estatica, &number, posicao_aleatoria);
        }
        fim = clock();
        tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
        fprintf(arquivo, "Tempo de consulta (%d elementos): %lu ms\n\n", n, tempo);

        liberar_lista(lista_estatica);
    }

    fclose(arquivo);

    return 0;
}