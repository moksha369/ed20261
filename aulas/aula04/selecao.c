#include "selecao.h"

#define TAMANHO 10

int busca_sequencial(int v[], int n, int valor) {
    for(int i = 0; i < n; i++) { // O(n)
        if(v[i] == valor) {
            return i;
        } 
    }
    return -1;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar_vetor(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}

int quick_select(int v[], int inicio, int fim) {
    if (inicio == fim) {
        return inicio;
    }

    int pivo = particionar_vetor(v, inicio, fim);

    if (v[pivo] == valor) {
        return pivo;
    } else if (v[pivo] < valor) {
        quick_select(v, inicio, pivo - 1, valor);
    } else {
        quick_select(v, pivo + 1, fim, valor);
    }
}