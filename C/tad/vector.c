#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct floatvector{
    int size;
    int capacity;
    float *vetor;
};

FloatVector* create(int capacity)
{
    FloatVector *vet;
    vet = (FloatVector*)calloc(1, sizeof(FloatVector));

    vet->capacity = capacity;
    vet->size = 0;
    vet->vetor = (float*)calloc(capacity, sizeof(float));

    return vet;
}

void destroy(FloatVector **vet)
{
    free( (*vet)->vetor );
    free(*vet);
    *vet = NULL;
}

void append(FloatVector *vet, float val)
{
    if(vet->size == vet->capacity)
    {
        printf("Vetor cheio.");
        exit(EXIT_FAILURE);
    }
    vet->vetor[vet->size] = val;
    vet->size++;
}

void print(const FloatVector *vet)
{
    for(int i = 0; i < vet->size; i++)
    {
        printf("[%d]: %f\n ", i, vet->vetor[i]);
    }
}

int size(const FloatVector *vet)
{
    return vet->size;
}

int capacity(const FloatVector *vet)
{
    return vet->capacity;
}

float at(const FloatVector *vet,int index)
{
    if((index < 0) || (index > vet->size))
    {
        printf("Indice invalido.");
        exit(EXIT_FAILURE);
    }
    return vet->vetor[index];
}

float get(const FloatVector *vet,int index)
{
    if((index < 0) || (index > vet->size))
    {
        printf("Indice invalido.");
        exit(EXIT_FAILURE);
    }
    return vet->vetor[index];
}

void set(FloatVector *vet,float val, int index)
{
    if((index < 0) || (index > vet->size))
    {
        printf("Indice invalido.");
        exit(EXIT_FAILURE);
    }
    vet->vetor[index] = val;
}









