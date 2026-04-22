#include <stdio.h>
#include "conta.h"

void testar_tda_conta() {
    Conta c1 = conta_criar(1234);
    int passou_criacao = (c1 != NULL && conta_ver_saldo(c1) == 0.0f) ? 1 : 0;
    printf("1. Criacao da conta (saldo 0) => %d\n", passou_criacao);

    int res_deposito = conta_depositar(c1, 150.0f);
    int passou_deposito = (res_deposito == 1 && conta_ver_saldo(c1) == 150.0f) ? 1 : 0;
    printf("2. Deposito de 150.0 => %d\n", passou_deposito);

    int res_dep_inv = conta_depositar(c1, -50.0f);
    int passou_dep_inv = (res_dep_inv == 0 && conta_ver_saldo(c1) == 150.0f) ? 1 : 0;
    printf("3. Bloqueio de deposito negativo => %d\n", passou_dep_inv);

    int res_saque = conta_sacar(c1, 50.0f);
    int passou_saque = (res_saque == 1 && conta_ver_saldo(c1) == 100.0f) ? 1 : 0;
    printf("4. Saque de 50.0 (saldo vira 100) => %d\n", passou_saque);

    int res_saque_inv = conta_sacar(c1, 500.0f);
    int passou_saque_inv = (res_saque_inv == 0 && conta_ver_saldo(c1) == 100.0f) ? 1 : 0;
    printf("5. Bloqueio de saque sem saldo => %d\n", passou_saque_inv);

    conta_destruir(&c1);
    int passou_destruicao = (c1 == NULL) ? 1 : 0;
    printf("6. Destruicao da conta (ponteiro NULL) => %d\n", passou_destruicao);
}

int main(void) {
    printf("--- TESTES DO TDA CONTA ---\n");
    testar_tda_conta();
    return 0;
}