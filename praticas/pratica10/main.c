#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main(void) {
    printf("=== TESTE DA TABELA HASH COM ENCADEAMENTO ===\n\n");

    TabelaHash meu_hash = hash_criar();

    printf("Inserindo valores (alguns vao causar colisao proposital)...\n");
    hash_inserir(meu_hash, 10);
    hash_inserir(meu_hash, 22);
    hash_inserir(meu_hash, 31);

    hash_inserir(meu_hash, 7);
    hash_inserir(meu_hash, 14);
    hash_inserir(meu_hash, 21);

    hash_exibir(meu_hash);

    printf("\nBuscando o valor 22...\n");
    if (hash_buscar(meu_hash, 22)) {
        printf(">> Valor 22 ENCONTRADO na tabela!\n");
    } else {
        printf(">> Valor 22 NAO encontrado.\n");
    }

    printf("Buscando o valor 99...\n");
    if (hash_buscar(meu_hash, 99)) {
        printf(">> Valor 99 ENCONTRADO na tabela!\n");
    } else {
        printf(">> Valor 99 NAO encontrado.\n");
    }

    printf("\nRemovendo o valor 31 (sem colisao)...\n");
    hash_remover(meu_hash, 31);
    
    printf("Removendo o valor 14 (do meio de uma lista com colisao)...\n\n");
    hash_remover(meu_hash, 14);
    
    hash_exibir(meu_hash);

    printf("\nDestruindo a Tabela Hash e limpando a RAM...\n");
    hash_destruir(&meu_hash);
    
    if (meu_hash == NULL) {
        printf("Tabela destruida com sucesso!\n");
    }

    return 0;
}