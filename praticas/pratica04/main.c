#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100000

void copiar_vetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main(void) {
    int vetor_original[TAM];
    int vetor_bubble[TAM], vetor_selection[TAM], vetor_quick[TAM];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < TAM; i++) {
        vetor_original[i] = rand() % 1000;
    }

    copiar_vetor(vetor_original, vetor_bubble, TAM);
    copiar_vetor(vetor_original, vetor_selection, TAM);
    copiar_vetor(vetor_original, vetor_quick, TAM);

    printf("--- BENCHMARK DE ORDENACAO (N=%d) ---\n\n", TAM);

    // BUBBLE SORT
    clock_t inicio_b = clock();
    bubble_sort(vetor_bubble, TAM);
    clock_t fim_b = clock();
    printf("Tempo Bubble Sort   : %f segundos\n", ((double)(fim_b - inicio_b)) / CLOCKS_PER_SEC);

    // SELECTION SORT
    clock_t inicio_s = clock();
    selection_sort(vetor_selection, TAM);
    clock_t fim_s = clock();
    printf("Tempo Selection Sort: %f segundos\n", ((double)(fim_s - inicio_s)) / CLOCKS_PER_SEC);

    // QUICK SORT
    clock_t inicio_q = clock();
    quick_sort(vetor_quick, 0, TAM - 1);
    clock_t fim_q = clock();
    printf("Tempo Quick Sort    : %f segundos\n", ((double)(fim_q - inicio_q)) / CLOCKS_PER_SEC);

    return 0;
}