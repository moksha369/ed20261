#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;


struct fila_t {
    No *inicio;
    No *fim;
};

Fila fila_criar() {
    Fila f = (Fila) malloc(sizeof(struct fila_t));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_esta_vazia(Fila f) {
    if (f == NULL) return 1;
    return (f->inicio == NULL) ? 1 : 0;
}

void fila_enfileirar(Fila f, int valor) {
    if (f == NULL) return;

    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return; 

    novo->valor = valor;
    novo->proximo = NULL; 

    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    
    f->fim = novo;
}

int fila_desenfileirar(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("[Erro] A fila esta vazia. Nao ha quem atender.\n");
        return -1;
    }

    No *removido = f->inicio; 
    int valor_removido = removido->valor;

    f->inicio = removido->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(removido); 
    return valor_removido;
}

int fila_inicio(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("[Erro] A fila esta vazia.\n");
        return -1;
    }
    return f->inicio->valor;
}

void fila_exibir(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Fila esta vazia.\n");
        return;
    }

    No *atual = f->inicio;
    printf("Fila (INICIO -> FIM): [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void fila_destruir(Fila *f) {
    if (f != NULL && *f != NULL) {
        No *atual = (*f)->inicio;
        while (atual != NULL) {
            No *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(*f);
        *f = NULL;
    }
}