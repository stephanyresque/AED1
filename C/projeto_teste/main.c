#include <stdio.h>
#include "float_vector.h"

int main() {
    // Cria um vetor com capacidade para 5 elementos
    FloatVector *vec = create(5);

    // Adiciona alguns valores ao vetor
    append(vec, 1.5);
    append(vec, 2.5);
    append(vec, 3.5);

    // Imprime o conteúdo do vetor
    printf("Vetor após adicionar elementos:\n");
    print(vec);

    // Altera o valor do elemento no índice 1
    set(vec, 1, 4.4);

    // Imprime o vetor após a modificação
    printf("Vetor após alterar o elemento no índice 1:\n");
    print(vec);

    // Libera a memória alocada para o vetor
    destroy(&vec);

    return 0;
}