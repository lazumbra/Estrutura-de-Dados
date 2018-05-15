#include "listaDinEncad.h" 
#include <stdlib.h>

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista * cria_lista(){
    Lista* li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL) return 0;
    int cont = 0;
    //*li representa o início da lista.
    Elem* no = *li; 
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista *li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    //verifica se a lista é válida. Se a lista
    //não existir então ele retorna 0.
    if(li == NULL) return 0; 
    Elem* no = (Elem*) malloc(sizeof(Elem));
    //Analisar se ele consegue alocar memoria para esse nó.
    //Se ele não conseguiu alocar memória pra o nó, então eu saio da lista.
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){ // lista vazia: insere inicio
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no = NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)){ //insere inicio
        no->prox = (*li);
        *li = no;
        return 1;
    } else { //procura onde inserir
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //caso eu não tenha andado no while, então eu insiro no inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        
    }
    return  1;
}