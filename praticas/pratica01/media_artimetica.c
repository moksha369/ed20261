#include <stdio.h>

float calcular_media(int n, float valores[]) {
    if (n <= 0 || n > 100) {
        return 0.0;
    }
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += valores[i];
    }
    return soma / n;
}

void testar_media(int n, float valores[], float esperado) {
    float calc = calcular_media(n, valores);
    
    float diferenca = calc - esperado;
    if (diferenca < 0) {
        diferenca = -diferenca;
    }
    
    int passou = (diferenca <= 0.01) ? 1 : 0;
    
    printf("qtd_numeros = %d, media_esperada = %.2f => %d\n", n, esperado, passou);
}

int main(void) {
    float v1[] = {10.0, 20.0, 30.0};
    testar_media(3, v1, 20.0);

    float v2[] = {5.5, 6.5};
    testar_media(2, v2, 6.0);

    float v3[] = {100.0};
    testar_media(1, v3, 100.0);

    float v_vazio[] = {};
    testar_media(0, v_vazio, 0.0); 

    return 0;
}