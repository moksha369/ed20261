#include <stdio.h>

unsigned long long fat_iterativo(int n) {
    unsigned long long res = 1;
    for(int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

unsigned long long fat_recursivo(int n) {
    if(n <= 1) return 1;
    return n * fat_recursivo(n - 1);
}

void testar_fatorial(int n, unsigned long long esperado) {
    unsigned long long calc_iter = fat_iterativo(n);
    unsigned long long calc_rec = fat_recursivo(n);
    
    int passou = (calc_iter == esperado && calc_rec == esperado) ? 1 : 0;
    
    printf("fatorial(%d) | esperado: %llu => iterativo:%llu recursivo:%llu | Passou: %d\n", 
           n, esperado, calc_iter, calc_rec, passou);
}

int main(void) {
    testar_fatorial(0, 1);
    testar_fatorial(1, 1);
    testar_fatorial(5, 120);
    testar_fatorial(10, 3628800); 
    return 0;
}