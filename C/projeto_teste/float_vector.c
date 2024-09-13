#include <stdio.h>
#include <stdlib.h>
#include "float_vector.h"

struct float_vector {
    float *data;
    int size;
    int capacity;
};

FloatVector *create(int capacity) {
    FloatVector *vec = (FloatVector *)malloc(sizeof(FloatVector));
    vec->data = (float *)malloc(capacity * sizeof(float));
    vec->size = 0;
    vec->capacity = capacity;
    return vec;
}

void destroy(FloatVector **vec) {
    if (vec && *vec) {
        free((*vec)->data);
        free(*vec);
        *vec = NULL;
    }
}

int size(const FloatVector *vec) {
    return vec->size;
}

int capacity(const FloatVector *vec) {
    return vec->capacity;
}

float at(const FloatVector *vec, int index) {
    if (index >= 0 && index < vec->size) {
        return vec->data[index];
    }
    return 0.0; // Handle out of bounds
}

float get(const FloatVector *vec, int index) {
    return at(vec, index);
}

void append(FloatVector *vec, float val) {
    if (vec->size >= vec->capacity) {
        // Optionally handle resizing
        return;
    }
    vec->data[vec->size++] = val;
}

void set(FloatVector *vec, int index, float val) {
    if (index >= 0 && index < vec->size) {
        vec->data[index] = val;
    }
}

void print(const FloatVector *vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%f ", vec->data[i]);
    }
    printf("\n");
}
