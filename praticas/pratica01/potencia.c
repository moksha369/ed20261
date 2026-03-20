#include <stdio.h>

long long calcular_potencia(int base, int expoente) {
    if (expoente < 0) {
        return -1; 
    }
    long long resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

void testar_potencia(int base, int expoente, long long esperado) {
    long long calc = calcular_potencia(base, expoente);
    int passou = (calc == esperado) ? 1 : 0;
    printf("base = %d, expoente = %d, esperado = %lld => %d\n", base, expoente, esperado, passou);
}

int main(void) {
    testar_potencia(2, 3, 8);
    testar_potencia(5, 2, 25);
    testar_potencia(10, 0, 1);
    testar_potencia(7, 0, 1);
    testar_potencia(9, 1, 9);
    testar_potencia(2, -3, -1);

    return 0;
}