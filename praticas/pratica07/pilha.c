#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo; 
} No;

struct pilha_t {
    No *topo;
};

Pilha pilha_criar() {
    Pilha p = (Pilha) malloc(sizeof(struct pilha_t));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(Pilha p) {
    if (p == NULL) return 1;
    return (p->topo == NULL) ? 1 : 0;
}

void pilha_empilhar(Pilha p, int valor) {
    if (p == NULL) return;

    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return; 

    novo->valor = valor;
    novo->proximo = p->topo; 
    
    p->topo = novo;
}

int pilha_desempilhar(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("[Erro] A pilha esta vazia. Nao ha o que desempilhar.\n");
        return -1;
    }

    No *removido = p->topo; 
    int valor_removido = removido->valor; 
    
    p->topo = removido->proximo;
    
    free(removido); 
    return valor_removido;
}

int pilha_topo(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("[Erro] A pilha esta vazia.\n");
        return -1;
    }
    return p->topo->valor;
}

void pilha_exibir(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha esta vazia.\n");
        return;
    }

    No *atual = p->topo;
    printf("Pilha (TOPO -> BASE): [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo; 
    }
    printf("]\n");
}

void pilha_destruir(Pilha *p) {
    if (p != NULL && *p != NULL) {
        No *atual = (*p)->topo;
        while (atual != NULL) {
            No *proximo = atual->proximo; 
            free(atual);
            atual = proximo;
        }
        free(*p); 
        *p = NULL; 
    }
}