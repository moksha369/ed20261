#include <stdlib.h> 
#include "conta.h"

struct conta_t {
    int numero;
    float saldo;
};

Conta conta_criar(int numero) {
    Conta nova_conta = (Conta) malloc(sizeof(struct conta_t));
    
    if (nova_conta != NULL) {
        nova_conta->numero = numero;
        nova_conta->saldo = 0.0f; 
    }
    return nova_conta;
}

int conta_depositar(Conta c, float valor) {
    if (c == NULL || valor <= 0) {
        return 0; 
    }
    c->saldo += valor;
    return 1; 
}

int conta_sacar(Conta c, float valor) {
    if (c == NULL || valor <= 0 || c->saldo < valor) {
        return 0; 
    }
    c->saldo -= valor;
    return 1; 
}

float conta_ver_saldo(Conta c) {
    if (c == NULL) {
        return -1.0f; 
    }
    return c->saldo;
}

void conta_destruir(Conta *c) {
    if (c != NULL && *c != NULL) {
        free(*c);   
        *c = NULL;  
    }
}