#include <stdio.h>
#include <time.h> 

#define TAM 10

int percorrer_dois_lacos(int mat[TAM][TAM]) {
    int operacoes = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            operacoes += mat[i][j]; 
        }
    }
    return operacoes;
}

int percorrer_um_laco(int mat[TAM][TAM]) {
    int operacoes = 0;
    int total_elementos = TAM * TAM;
    int *ptr = &mat[0][0]; 

    for (int i = 0; i < total_elementos; i++) {
        operacoes += ptr[i]; 
    }
    return operacoes;
}

void testar_matriz(void) {
    int matriz[TAM][TAM];
    int soma_esperada = 0;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = 1; 
            soma_esperada++;
        }
    }


    int iteracoes = 10000000; 
    int calc_1 = 0, calc_2 = 0;

    printf("Iniciando benchmark de %d iteracoes. Aguarde...\n\n", iteracoes);

    clock_t inicio_1 = clock();
    for (int k = 0; k < iteracoes; k++) {
        calc_1 = percorrer_dois_lacos(matriz);
    }
    clock_t fim_1 = clock();
    double tempo_1 = ((double)(fim_1 - inicio_1)) / CLOCKS_PER_SEC;

    clock_t inicio_2 = clock();
    for (int k = 0; k < iteracoes; k++) {
        calc_2 = percorrer_um_laco(matriz);
    }
    clock_t fim_2 = clock();
    double tempo_2 = ((double)(fim_2 - inicio_2)) / CLOCKS_PER_SEC;

    int passou = (calc_1 == soma_esperada && calc_2 == soma_esperada) ? 1 : 0;
    
    printf("Validacao de Logica => Esperado: %d | M1: %d | M2: %d | Passou: %d\n", soma_esperada, calc_1, calc_2, passou);
    
    printf("Tempo com 2 lacos: %f segundos\n", tempo_1);
    printf("Tempo com 1 laco : %f segundos\n", tempo_2);
}

int main(void) {
    testar_matriz();
    return 0;
}