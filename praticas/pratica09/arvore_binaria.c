#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
} No;

struct arvore_t {
    No *raiz;
};

Arvore arvore_criar() {
    Arvore a = (Arvore) malloc(sizeof(struct arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(Arvore a) {
    if (a == NULL) return 1;
    return (a->raiz == NULL) ? 1 : 0;
}

No* inserir_no(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
        }
        return novo;
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    } 
    else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor);
    }

    return raiz;
}

void exibir_pre_ordem_no(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        exibir_pre_ordem_no(raiz->esquerda);
        exibir_pre_ordem_no(raiz->direita);
    }
}

void exibir_em_ordem_no(No *raiz) {
    if (raiz != NULL) {
        exibir_em_ordem_no(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em_ordem_no(raiz->direita);
    }
}

void exibir_pos_ordem_no(No *raiz) {
    if (raiz != NULL) {
        exibir_pos_ordem_no(raiz->esquerda);
        exibir_pos_ordem_no(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void destruir_no(No *raiz) {
    if (raiz != NULL) {
        destruir_no(raiz->esquerda);
        destruir_no(raiz->direita);
        free(raiz);
    }
}

void arvore_inserir(Arvore a, int valor) {
    if (a == NULL) return;
    a->raiz = inserir_no(a->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n"); return;
    }
    printf("Pre-Ordem : [ ");
    exibir_pre_ordem_no(a->raiz);
    printf("]\n");
}

void arvore_exibir_em_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n"); return;
    }
    printf("Em-Ordem  : [ ");
    exibir_em_ordem_no(a->raiz);
    printf("]\n");
}

void arvore_exibir_pos_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n"); return;
    }
    printf("Pos-Ordem : [ ");
    exibir_pos_ordem_no(a->raiz);
    printf("]\n");
}

void arvore_destruir(Arvore *a) {
    if (a != NULL && *a != NULL) {
        destruir_no((*a)->raiz);
        free(*a);
        *a = NULL;
    }
}