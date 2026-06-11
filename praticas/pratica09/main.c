#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main(void) {
    printf("--- TESTE DA ARVORE BINARIA DE BUSCA ---\n\n");

    Arvore minha_arvore = arvore_criar();

    printf("Inserindo valores: 50, 30, 70, 20, 40, 60 e 80...\n\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    printf("Verificando percursos da arvore:\n");
 
    arvore_exibir_pre_ordem(minha_arvore); 

    arvore_exibir_em_ordem(minha_arvore);  
  
    arvore_exibir_pos_ordem(minha_arvore); 

    printf("\nDestruindo a arvore para evitar memory leak...\n");
    arvore_destruir(&minha_arvore);
    
    if (minha_arvore == NULL) {
        printf("Arvore destruida com sucesso!\n");
    }

    return 0;
}