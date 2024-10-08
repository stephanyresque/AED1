#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    
    Lista *minha_lista = criar_lista();
    Lista *outra_lista = criar_lista();

    Aluno aluno1 = {101, "Alice", 12345};
    Aluno aluno2 = {102, "Bob", 67890};
    Aluno aluno3 = {103, "Charlie", 11223};
    Aluno aluno4 = {104, "Diana", 44556};
    Aluno aluno5 = {105, "Eve", 77889};

    inserir_inicio(minha_lista, aluno1);
    inserir_final(minha_lista, aluno2);
    inserir_inicio(minha_lista, aluno3); // Este será o primeiro
    inserir_final(minha_lista, aluno4);  // Este será o último


    printf("Lista inicial:\n");
    imprimir_lista(minha_lista);

    
    Aluno encontrado;
    if (busca_por_chave(minha_lista, 102, &encontrado)) {
        printf("\nAluno encontrado: %s, matrícula: %d\n", encontrado.nome, encontrado.matricula);
    } else {
        printf("\nAluno com chave 102 não encontrado.\n");
    }

    
    inserir_antes_chave(minha_lista, 102, aluno5);

    
    printf("\nLista após inserir o aluno antes da chave 102:\n");
    imprimir_lista(minha_lista);

    
    remover_por_chave(minha_lista, 103); 
    printf("\nLista após remover o aluno com chave 103:\n");
    imprimir_lista(minha_lista);

    
    inserir_inicio(outra_lista, aluno3); 
    concatenar_listas(minha_lista, outra_lista);

    printf("\nLista após a concatenação:\n");
    imprimir_lista(minha_lista);

    
    inverter_lista(minha_lista);
    printf("\nLista após a inversão:\n");
    imprimir_lista(minha_lista);

    
    if (comparar_listas(minha_lista, outra_lista)) {
        printf("\nAs listas são iguais.\n");
    } else {
        printf("\nAs listas são diferentes.\n");
    }

    
    liberar_lista(minha_lista);
    liberar_lista(outra_lista);

    return 0;
}
