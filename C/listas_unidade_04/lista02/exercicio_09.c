#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == alvo) {   
            return meio;             
        }
        else if (vetor[meio] < alvo) {
            inicio = meio + 1;       
        } else {
            fim = meio - 1;          
        }
    }

    return -1; 
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11}; 
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo = 7; 

    int resultado = buscaBinaria(vetor, tamanho, alvo);

    if (resultado != -1) {
        printf("Elemento encontrado na posição: %d\n", resultado);
    } else {
        printf("Elemento não encontrado\n");
    }

    return 0;
}
