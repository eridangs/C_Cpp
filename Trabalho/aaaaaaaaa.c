#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

void bubble_sort(void *base, size_t number_itens, size_t size, int (*compare)(const void *a, const void *b));

int main () {
    int numeros[] = {10, 19, 50, 63, 8, 153, 2};

    bubble_sort(numeros, sizeof(numeros) / sizeof(numeros[0]), sizeof(numeros[0]), &compare);

    for (int i = 0; i < 7; i++) {
        printf("%d \n", numeros[i]);
    }

    return 0;
}

void bubble_sort(void *base, size_t number_itens, size_t size, int (*compare)(const void *a, const void *b)) {
    int i, j;

    void *auxiliar = malloc(size);
    
    for (i = 0; i < number_itens - 1; i++) {
        for (j = 0; j < number_itens - i - 1; j++) {
            if ((*compare)(base + j * size, base + (j + 1) * size)) {
                memcpy(auxiliar, base + j * size, size);
                memcpy(base + j * size, base + (j + 1) * size, size);
                memcpy(base + (j + 1) * size, auxiliar, size);
            }
        }
    }

    free(auxiliar);
}

int compare(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}