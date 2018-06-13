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

int tamanho_lista(Lista* li){
    if(li == NULL) return 0; // Analisa se a lista é vazia
    int cont = 0;
    Elem* no = *li; //Crio um nó auxiliar pra receber o primeiro nó da lista.
    //O conteudo de li (*li) é o prieiro elemento. 
    //Elem* no = *li; significa que nó recebe o primeiro elemento.
    while(no != NULL){ //Aqui eu vou percorrer a lista.
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0; // Aqui você está assuindo que a lista nunca está cheia, pois aqui temos uma 
    //lista dinâmica.
}

//1 indique True e 0 indica False
int lista_vazia(Lista *li){
    if(li == NULL) //Veririfica se não existe lista
        return 1;
    if(*li == NULL) // Aqui ele analisa se o conteudo da lista (primeiro nó da lista) está vazio
        return 1;
    return 0;
}

//ótimo explicação na aula 19  em tempo 4:23
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0; //verifica se a lista é válida. Retorna zero se não existir uma lista.
    Elem* no = (Elem*) malloc(sizeof(Elem)); // Se tiver a lista você aloca espaço para um novo nó.
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    //Lista não vazia: apontar para o anterior!
    if(*li != NULL) //se isso é verdadeiro então não existia uma lista vazia
        (*li)->ant = no;
    *li = no; //Digo que o primeiro elemento da lista agora será o eleento que eu acabei de colocar
    return 1;
}

//Pra insserir no final eu preciso percorrer a lista
int insere_lista_final(lista* li, struct aluno al){
    if(li == NULL) return 0; //verifico se a lista existe. Se não existir eu já retorno 0 de cara.
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0; //Vejo se eu consegui alocar memória para um elemento, se não consegui
    //eu já retorno 0 de cara.
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//Lista vazia: insere início
        no->ant = NULL;
        *li = no; //Aqui estou dizendo que o primeiro elemento da lista passa a ser o nó
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

//ver um bom exemplo na aula 19, tempo 10:17
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0; //Faço a verificação se a lista é vazia
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0; //Verifico se a alocação realmente aconteceu.
    no->dados = al; //Aqui eu faço a cópia dos dados
    if(lista_vazia(li)){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    } else{//procura onde inserir
    Elem *ante, *atual = *li; //lembrando que atual começa co o inicio da lista
    while(atual != NULL && atual->dados.matricula < al.matricula){
        ante = atual;
        atual = atual->prox;
    }
    if(atual == *li){//insere inicio. Se isso acontece quer dizer que eu nunca andei na lista
        no->ant = NULL;
        (*li)->ant = no;
        no->prox = (*li);
        *li = no;
    }else{
        no->prox = ante->prox;
        no->ant = ante;
        ante->prox = no;
        if(atual != NULL) //Se atual for igual a nu significa que eu estou no fim da lista
            atual->ant = no;
    }
    return 1;

    }
}
//Continuar aula 20