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

    //int x = insere_lista_final(li, dados_alunos);

    // int x = remove_lista_inicio(li)

    //int x = remove_lista_final(li);

    //int x = remove_lista(li, matricula_aluno);

    // int x = consulta_lista_pos(li, posicao, &dados_alunos);

    //int x = consulta_lista_mat(li, posicao, &dados_alunos);



    return 0;
}