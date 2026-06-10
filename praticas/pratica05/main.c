#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include "selecao.h"

#define TAM 100000

void copiar_vetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main(void) {
    int vetor_original[TAM];
    int vetor_qs[TAM];
    
    srand((unsigned int)time(NULL));

    for (int i = 0; i < TAM; i++) {
        vetor_original[i] = rand() % 1000;
    }
    copiar_vetor(vetor_original, vetor_qs, TAM);

    int alvo = vetor_original[TAM / 2];
    
    int k = TAM / 2;

    printf("--- BENCHMARK DE SELECAO (N=%d) ---\n\n", TAM);

    clock_t inicio_ls = clock();
    int indice_encontrado = linear_search(vetor_original, TAM, alvo);
    clock_t fim_ls = clock();
    
    clock_t inicio_qs = clock();
    int kesimo_elemento = quick_select(vetor_qs, 0, TAM - 1, k);
    clock_t fim_qs = clock();

    printf("Resultados das Operacoes:\n");
    printf("- Linear Search encontrou o valor %d no indice: %d\n", alvo, indice_encontrado);
    printf("- Quick Select definiu que o %d-esimo menor elemento eh: %d\n\n", k + 1, kesimo_elemento);

    printf("Tempo de Execucao:\n");
    printf("Tempo Linear Search : %f segundos\n", ((double)(fim_ls - inicio_ls)) / CLOCKS_PER_SEC);
    printf("Tempo Quick Select  : %f segundos\n", ((double)(fim_qs - inicio_qs)) / CLOCKS_PER_SEC);

    return 0;
}