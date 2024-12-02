#include <stdio.h>   
#include <stdlib.h>  
#include <math.h>   
#include <string.h>  

// Função para imprimir o vetor no console
void printfVet(int *V, int N) {
    int i;
    for (i = 0; i < N; i++)              // Itera por todos os elementos do vetor
        printf("%2d ", V[i]);            // Imprime cada elemento com espaçamento fixo
    printf("\n");                        // Quebra de linha ao final
}

// Função para mesclar dois subvetores ordenados
void merge(int *V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;             // Flags para indicar se os subvetores foram percorridos completamente
    tamanho = fim - inicio + 1;         // Tamanho do intervalo a ser mesclado
    p1 = inicio;                        // Ponteiro para o início do primeiro subvetor
    p2 = meio + 1;                      // Ponteiro para o início do segundo subvetor
    temp = (int *)malloc(tamanho * sizeof(int)); // Aloca memória temporária para armazenar os valores mesclados

    if (temp != NULL) {                 // Verifica se a memória foi alocada com sucesso
        for (i = 0; i < tamanho; i++) { // Itera para mesclar os subvetores
            if (!fim1 && !fim2) {       // Ambos os subvetores ainda possuem elementos
                if (V[p1] < V[p2])      // Compara o menor elemento dos dois subvetores
                    temp[i] = V[p1++];  // Adiciona o menor elemento ao vetor temporário
                else
                    temp[i] = V[p2++];

                if (p1 > meio) fim1 = 1; // Marca que o primeiro subvetor foi completamente percorrido
                if (p2 > fim) fim2 = 1; // Marca que o segundo subvetor foi completamente percorrido
            } else {                    // Apenas um dos subvetores ainda possui elementos
                if (!fim1)
                    temp[i] = V[p1++];  // Copia os elementos restantes do primeiro subvetor
                else
                    temp[i] = V[p2++];  // Copia os elementos restantes do segundo subvetor
            }
        }

        // Copia os elementos ordenados do vetor temporário de volta para o vetor original
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);                         // Libera a memória alocada para o vetor temporário
}

// Função recursiva para aplicar o Merge Sort
void mergeSort(int *V, int inicio, int fim) {
    int meio;
    if (inicio < fim) {                 // Verifica se o intervalo contém mais de um elemento
        meio = floor((inicio + fim) / 2); // Calcula o índice do meio
        mergeSort(V, inicio, meio);       // Chama recursivamente para a primeira metade
        mergeSort(V, meio + 1, fim);      // Chama recursivamente para a segunda metade
        merge(V, inicio, meio, fim);      // Mescla as duas metades ordenadas
    }
}

// Função principal do programa
int main() {
    int vet[8] = {0, 23, 4, 67, -8, 90, 54, 21}; // Define o vetor a ser ordenado
    int N = 8;                                  // Define o tamanho do vetor

    printf("Sem ordenar:\n");
    printfVet(vet, N);                          // Imprime o vetor original

    mergeSort(vet, 0, N - 1);                   // Ordena o vetor usando Merge Sort

    printf("Ordenado:\n");
    printfVet(vet, N);                          // Imprime o vetor ordenado

    return 0;                                   
}
