#include <stdio.h>
#include "listaDinEncad.h"

int main(){

    printf("Consegui fazer o makefile\n");
    Lista *li;
    li = cria_lista();
    libera_lista(li);
    int x = tamanho_lista(li);
    int y = lista_vazia(li);

    //int x = insere_lista_inicio(li, dados_aluno);



    return 0;
}