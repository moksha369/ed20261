#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tabela_hash.h"

#define TAMANHO_PADRAO 7 

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

struct hash_t {
    int tamanho;
    No **tabela; 
};

int calcular_hash(int valor, int tamanho) {
    return abs(valor) % tamanho; 
}

TabelaHash hash_criar() {
    TabelaHash h = (TabelaHash) malloc(sizeof(struct hash_t));
    if (h != NULL) {
        h->tamanho = TAMANHO_PADRAO;
        h->tabela = (No**) malloc(h->tamanho * sizeof(No*)); 
        
        if (h->tabela == NULL) {
            free(h);
            return NULL;
        }

        for (int i = 0; i < h->tamanho; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}

int hash_esta_vazia(TabelaHash h) {
    if (h == NULL) return 1;
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return 0; 
        }
    }
    return 1;
}

void hash_inserir(TabelaHash h, int valor) {
    if (h == NULL) return;

    int indice = calcular_hash(valor, h->tamanho);

    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;
    
    novo->valor = valor;

    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;
}

int hash_buscar(TabelaHash h, int valor) {
    if (h == NULL) return 0;

    int indice = calcular_hash(valor, h->tamanho);
    No *atual = h->tabela[indice]; 

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

void hash_remover(TabelaHash h, int valor) {
    if (h == NULL) return;

    int indice = calcular_hash(valor, h->tamanho);
    No *atual = h->tabela[indice];
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return; 

    if (anterior == NULL) {
        h->tabela[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

void hash_exibir(TabelaHash h) {
    if (h == NULL) return;

    printf("--- TABELA HASH ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("Indice [%d] -> ", i);
        No *atual = h->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
    printf("-------------------\n");
}

void hash_destruir(TabelaHash *h) {
    if (h != NULL && *h != NULL) {
        for (int i = 0; i < (*h)->tamanho; i++) {
            No *atual = (*h)->tabela[i];
            while (atual != NULL) {
                No *proximo = atual->proximo;
                free(atual);
                atual = proximo;
            }
        }
        free((*h)->tabela);
        free(*h);
        *h = NULL;
    }
}