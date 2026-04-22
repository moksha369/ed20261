#include <stdio.h>

int calcular_saque(int valor, int qtd_notas[7]) {
    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    
    if (valor <= 0 || valor > 1000) {
        for(int i = 0; i < 7; i++) qtd_notas[i] = 0;
        return -1; 
    }
    
    int restante = valor;
    for (int i = 0; i < 7; i++) {
        qtd_notas[i] = restante / notas[i];
        restante = restante % notas[i];
    }
    return restante;
}

void testar_saque(int valor, int e200, int e100, int e50, int e20, int e10, int e5, int e2, int resto_esperado) {
    int qtd[7] = {0};
    int resto_calc = calcular_saque(valor, qtd);
    
    int passou = 1; 
    
    if (resto_calc != resto_esperado) passou = 0;
    if (qtd[0] != e200) passou = 0;
    if (qtd[1] != e100) passou = 0;
    if (qtd[2] != e50) passou = 0;
    if (qtd[3] != e20) passou = 0;
    if (qtd[4] != e10) passou = 0;
    if (qtd[5] != e5) passou = 0;
    if (qtd[6] != e2) passou = 0;

    printf("saque = %d, resto_esperado = %d => %d\n", valor, resto_esperado, passou);
}

int main(void) {
    testar_saque(387, 1, 1, 1, 1, 1, 1, 1, 0); 
    testar_saque(100, 0, 1, 0, 0, 0, 0, 0, 0);
    testar_saque(8, 0, 0, 0, 0, 0, 1, 1, 1); 
    testar_saque(1500, 0, 0, 0, 0, 0, 0, 0, -1); 

    return 0;
}