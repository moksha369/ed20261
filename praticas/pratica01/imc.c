#include <stdio.h>

float calcular_imc(float altura, float peso) {
    if (altura <= 0 || peso <= 0) {
        return 0.0;
    }
    return peso / (altura * altura);
}

void testar_imc(float altura, float peso, float imc_esperado) {
    float imc_calc = calcular_imc(altura, peso);
    
    float diferenca = imc_calc - imc_esperado;
    if (diferenca < 0) {
        diferenca = -diferenca;
    }
    
    int passou = (diferenca <= 0.1) ? 1 : 0;
    
    printf("altura = %g, peso = %g, imc = %.1f => %d\n", altura, peso, imc_esperado, passou);
}

int main(void) {
    testar_imc(0, 50, 0.0);
    testar_imc(1.75, 0, 0.0);

    testar_imc(1.75, 50, 16.3);

    testar_imc(1.75, 65, 21.2);

    testar_imc(1.75, 85, 27.8);

    testar_imc(1.75, 95, 31.0);

    return 0;
}