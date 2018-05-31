#include "listDuplaEnc.h"
#include <stdlib.h>

struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){ //Vê se a lista não é nula
        Elem* no;
        while((*li) != NULL){  //(*li) conteudo de li for diferente de NULL
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//Continuar aula 18