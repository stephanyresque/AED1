#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listasequencial.h"

int main() {
    FILE *arquivo;
    clock_t inicio, fim;
    unsigned long int tempo;
    int tamanhos[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int repeticoes_consulta = 1000000; 
    int repeticoes_insercao_final = 100000;   

    srand(time(NULL));

    arquivo = fopen("tempo.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "\nEstatísticas de tempo para inserção de elementos no início da lista sequencial (sem repetições):\n");
    printf("Iniciando o teste de tempo para insercao de elementos no inicio da lista sequencial...\n");
    for (int i = 0; i < num_tamanhos; i++) {
        int N = tamanhos[i];
        Lista* listinha = cria_lista();
        if (listinha == NULL) {
            printf("Erro ao criar a lista para N = %d\n", N);
            continue;
        }

        inicio = clock();
        for (int j = 0; j < N; j++) {
            Numero num;
            num.valor = j;
            inserir_inicio(listinha, num);
        }
        fim = clock();

        tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
        fprintf(arquivo, "N = %d, Tempo = %lu ms\n", N, tempo);
        printf("N = %d, Tempo = %lu ms\n", N, tempo);

        liberar_lista(listinha);
    }

    fprintf(arquivo, "\nEstatísticas de tempo para inserção de elementos no final da lista sequencial (100.000 inserções):\n");
    printf("Iniciando o teste de tempo para insercao de elementos no final da lista sequencial...\n");
    for (int i = 0; i < num_tamanhos; i++) {
        int N = tamanhos[i];
        unsigned long int soma_tempo = 0;

        for (int r = 0; r < repeticoes_insercao_final; r++) {
            Lista* listinha = cria_lista();
            if (listinha == NULL) {
                printf("Erro ao criar a lista para N = %d\n", N);
                continue;
            }

            inicio = clock();
            for (int j = 0; j < N; j++) {
                Numero num;
                num.valor = j;
                inserir_fim(listinha, num);
            }
            fim = clock();

            tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
            soma_tempo += tempo;

            liberar_lista(listinha);
        }

        unsigned long int tempo_medio = soma_tempo / repeticoes_insercao_final;
        fprintf(arquivo, "N = %d, Tempo total = %lu ms, Tempo médio por inserção no final = %lu µs\n", N, soma_tempo, tempo_medio);
        printf("N = %d, Tempo total = %lu ms, Tempo medio por insercao no final = %lu µs\n", N, soma_tempo, tempo_medio);
    }

    fprintf(arquivo, "\nEstatísticas de tempo para consulta de elementos aleatórios na lista sequencial (1.000.000 consultas):\n");
    printf("Iniciando o teste de tempo para consulta de elementos aleatorios na lista sequencial...\n");
    for (int i = 0; i < num_tamanhos; i++) {
        int N = tamanhos[i];
        Lista* listinha = cria_lista();
        if (listinha == NULL) {
            printf("Erro ao criar a lista para N = %d\n", N);
            continue;
        }

        for (int j = 0; j < N; j++) {
            Numero num;
            num.valor = j;
            inserir_fim(listinha, num);
        }

        unsigned long int soma_tempo = 0;

        for (int r = 0; r < repeticoes_consulta; r++) {
            int pos = rand() % N;  
            Numero num;

            inicio = clock();
            consulta_por_indice(listinha, &num, pos);
            fim = clock();

            tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
            soma_tempo += tempo;
        }

        unsigned long int tempo_medio = soma_tempo / repeticoes_consulta;
        fprintf(arquivo, "N = %d, Tempo total = %lu ms, Tempo médio por consulta = %lu µs\n", N, soma_tempo, tempo_medio);
        printf("N = %d, Tempo total = %lu ms, Tempo medio por consulta = %lu µs\n", N, soma_tempo, tempo_medio);

        liberar_lista(listinha);
    }

    fclose(arquivo);
    printf("Todos os testes concluidos e salvos em tempo.txt\n");

    return 0;
}
