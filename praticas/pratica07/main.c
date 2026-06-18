#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
    printf("--- TESTE DA PILHA (FILO / LIFO) ---\n\n");

    Pilha minha_pilha = pilha_criar();

    printf("Empilhando os valores 10, 20 e 30...\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30); 
    
    pilha_exibir(minha_pilha);

    printf("\nQual eh o valor no topo agora? %d\n", pilha_topo(minha_pilha));

    printf("\nDesempilhando um elemento: %d saiu da pilha.\n", pilha_desempilhar(minha_pilha));
    pilha_exibir(minha_pilha);

    printf("\nDesempilhando outro elemento: %d saiu da pilha.\n", pilha_desempilhar(minha_pilha));
    pilha_exibir(minha_pilha);

    printf("\nQual eh o valor no topo agora? %d\n", pilha_topo(minha_pilha));

    printf("\nDestruindo a pilha para evitar memory leak...\n");
    pilha_destruir(&minha_pilha);
    
    if (minha_pilha == NULL) {
        printf("Pilha destruida com sucesso!\n");
    }

    return 0;
}