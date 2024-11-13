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
    int repeticoes = 100000;  // Reduzido para 100.000 inserções para acelerar a execução

    // Abre o arquivo tempo.txt no modo de apêndice para manter os registros anteriores
    arquivo = fopen("tempo.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Iniciando o teste de tempo para inserção de elementos no final da lista (100.000 inserções)...\n");
    fprintf(arquivo, "\nEstatísticas de tempo para inserção de elementos no final da lista (100.000 inserções):\n");

    // Itera sobre cada valor de N especificado
    for (int i = 0; i < num_tamanhos; i++) {
        int N = tamanhos[i];
        printf("Criando lista e realizando inserções para N = %d...\n", N);

        unsigned long int soma_tempo = 0;

        // Realiza as inserções no final da lista e mede o tempo total
        for (int r = 0; r < repeticoes; r++) {
            Lista *listinha = cria_lista();
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

            // Calcula o tempo em milissegundos para esta inserção de N elementos
            tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
            soma_tempo += tempo;

            liberar_lista(listinha);
        }

        // Calcula o tempo médio de inserção para N elementos
        unsigned long int tempo_medio = soma_tempo / repeticoes;

        // Salva o valor de N e o tempo médio de inserção no arquivo
        fprintf(arquivo, "N = %d, Tempo total = %lu ms, Tempo médio por inserção = %lu µs\n", N, soma_tempo, tempo_medio);
        fflush(arquivo); // Garante que os dados sejam gravados imediatamente

        // Exibe o valor de N e o tempo médio no terminal
        printf("N = %d, Tempo total = %lu ms, Tempo médio por inserção = %lu µs\n", N, soma_tempo, tempo_medio);
    }

    // Fecha o arquivo
    fclose(arquivo);
    printf("Estatísticas de tempo para inserção de elementos no final da lista salvas em tempo.txt\n");
    printf("Teste concluído.\n");

    return 0;
}
