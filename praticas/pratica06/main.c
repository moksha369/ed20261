#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

int main(void) {
    printf("--- TESTE DA LISTA LINEAR DINAMICA ---\n\n");

    Lista minha_lista = lista_criar();
    lista_exibir(minha_lista); 

    printf("\nInserindo os valores 10, 20, 30 e 40...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista);

    printf("\nBuscando o valor 20...\n");
    if (lista_buscar(minha_lista, 20)) {
        printf(">> O valor 20 foi ENCONTRADO na lista!\n");
    } else {
        printf(">> O valor 20 NAO existe na lista.\n");
    }

    printf("Buscando o valor 99...\n");
    if (lista_buscar(minha_lista, 99)) {
        printf(">> O valor 99 foi ENCONTRADO na lista!\n");
    } else {
        printf(">> O valor 99 NAO existe na lista.\n");
    }

    printf("\nRemovendo o valor 30 (meio)...\n");
    lista_remover(minha_lista, 30);
    lista_exibir(minha_lista);

    printf("Removendo o valor 10 (inicio)...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    printf("Removendo o valor 40 (final)...\n");
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista);

    printf("\nDestruindo a lista para limpar a memoria RAM...\n");
    lista_destruir(&minha_lista);
    
    if (minha_lista == NULL) {
        printf("Lista destruida com sucesso!\n");
    }

    return 0;
}