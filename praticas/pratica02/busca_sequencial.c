#include <stdio.h>

int busca_sequencial(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i; 
        }
    }
    return -1; 
}

void testar_busca(int alvo, int indice_esperado) {
    int vetor[100];
    
    for (int i = 0; i < 100; i++) {
        vetor[i] = i * 2; 
    }

    int calc = busca_sequencial(vetor, 100, alvo);
    int passou = (calc == indice_esperado) ? 1 : 0;

    printf("buscando: %d | idx_esperado: %d | idx_calculado: %d => %d\n", alvo, indice_esperado, calc, passou);
}

int main(void) {
    testar_busca(0, 0);      
    testar_busca(198, 99);   
    testar_busca(50, 25);    
    testar_busca(999, -1);   
    return 0;
}