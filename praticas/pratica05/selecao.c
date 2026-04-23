#include "selecao.h"

int linear_search(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i; 
        }
    }
    return -1; 
}

static int partition(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; 
    int i = (inicio - 1);

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return (i + 1);
}

int quick_select(int vetor[], int inicio, int fim, int k) {
    if (inicio <= fim) {
        int pivo_idx = partition(vetor, inicio, fim);
        
        if (pivo_idx == k) {
            return vetor[pivo_idx];
        } 
        else if (pivo_idx > k) {
            return quick_select(vetor, inicio, pivo_idx - 1, k);
        } 
        else {
            return quick_select(vetor, pivo_idx + 1, fim, k);
        }
    }
    return -1;
}