#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void) {
    printf("--- TESTE DA FILA (FIFO) ---\n\n");

    Fila minha_fila = fila_criar();

    printf("Chegaram na fila: 10, 20 e 30...\n");
    fila_enfileirar(minha_fila, 10); 
    fila_enfileirar(minha_fila, 20); 
    fila_enfileirar(minha_fila, 30); 
    
    fila_exibir(minha_fila);

    printf("\nQuem e o primeiro da fila agora? %d\n", fila_inicio(minha_fila));

    printf("\nAtendendo o guiche: %d saiu da fila.\n", fila_desenfileirar(minha_fila));
    fila_exibir(minha_fila); 

    printf("\nAtendendo o guiche: %d saiu da fila.\n", fila_desenfileirar(minha_fila));
    fila_exibir(minha_fila); 

    printf("\nChegou mais alguem: 40 entrou na fila.\n");
    fila_enfileirar(minha_fila, 40);
    fila_exibir(minha_fila); 

    printf("\nDestruindo a fila para evitar memory leak...\n");
    fila_destruir(&minha_fila);
    
    if (minha_fila == NULL) {
        printf("Fila destruida com sucesso!\n");
    }

    return 0;
}