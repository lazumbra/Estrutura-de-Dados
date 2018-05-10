#include <stdio.h>
#include "listaDinEncad.h"

int main(){

    printf("Consegui fazer o makefile\n");
    Lista *li;
    li = cria_lista();
    libera_lista(li);


    return 0;
}