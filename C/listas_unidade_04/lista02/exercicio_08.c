#include <stdio.h>

void verificarOrdenado(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {  
        if (vetor[i] > vetor[i + 1]) {       
            printf("NÃO ORDENADO\n");
            return;                          
        }
    }
    printf("ORDENADO\n");                   
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};  
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    verificarOrdenado(vetor, tamanho);

    return 0;
}
