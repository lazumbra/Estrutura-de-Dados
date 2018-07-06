# Arvore Binária

Playlist de estrutura de dados. Link: [https://www.youtube.com/playlist?list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka](https://www.youtube.com/playlist?list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka) 

- Conteúdo a partir da aula **69**

- Podemos calcular o numero de nós de uma árvora usando 2^h-1, onde **"h"** é a altura da árvore.

Uma árvore binária pode ter as seguintes operações:
1. Criação da árvore
1. Inserção de um elemento
1. Remoção de um elemento
1. Acesso a um elemento
1. Destruição da árvore.

A implementação de árvore pode ser feita de duas maneiras:

1. Estática (Heap) - Não é uma boa forma de implementação
1. Dinâmica - (Lista encadeada)

Informações básicas de uma árvore que deve ser implementado.
- Árvore está vazia?
- Número de nós
- Altura da árvore

- Podemos percorrer uma árvore de 3 formas mais importantes (é bom lembrar que existe outras formas de percorrer uma árvore).
  - **Pré-Ordem:** Visita a raiz, o filho da esquerda e o filho da direita
  - **Em-Ordem:** Visita o filho da esquerda, a raiz e o filho da direita.
  - **Pós-Ordem:** Visita o filho da esqueda, o filho da direita e depois visita a raiz.

**Criação da árvore:** Em outras palavras é a criação da raiz. A raiz é um ***nó especial*** que aponta para o primeiro elemento da árvore.
**Destruição da árvore:** É preciso eu percorrer todos os nós da árvore e liberar a memória de cada n

Abaixo podemos ver como seria uma implementação de árvore binária de forma dinâmica. Onde cada nó da arvore tem dois filhos(Dois ponteiros. Um a direita e o outro a esquerda).

![Image](/home/jefferson/Documents/medley/resources/SkGEE5jMm_SyBPDciMm.png)



## Implementação Alocação dinâmica
- Para guardar o pŕimeiro nó da árvore você precisqa utilizar um ***"ponteiro para ponteiro"*** 

OBS: Lembre que um ***"ponteiro para ponteiro"***  guarda um endereço de um ***ponteiro.*** É importante usar um ponteiro para ponteiro no primeiro elemento, pois assim é fácil mudar a ***raiz*** da árvore. Se eu estiver implementando uma árvore que não tem balanceamento ou que eu não precise saber quem é a raiz então eu não preciso usar **ponteiro para ponteiro.**

- **ArvoreBinaria.h -** Definir 
  - os prototipos das funções
  - o tipo de dado armazenado na árvore
  - o ponteiro **arvore**

- **ArvoreBinaria.c** - Definir
  - O tipo de dado **árvore**
  - implementar as funções 

ArvBin já é um ponteiro (NO* ArvBin). Então quando eu declaro `ArvBin* raiz;` Essa raiz é um ponteiro para ponteiro. 
```c
//ArvoreBinaria.h
typedef struct NO* ArvBin;

//ArvoreBinaria.c
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
}

//Programa principal
ArvBin * raiz;
```

O que acontece é o seguinte. Quando eu crio a árvore usando `cria_ArvBin()`, de cara a raiz vai apontar para um elemnento (valor) NULL. De acordo com que eu vou acrescentando valores a árvore, a raíz vai apontar para o primeiro elmento.
![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_H1wEAVnMQ.png)

```c
//ArvoreBinaria.h
ArvBin* cria_ArvBin();


//ArvoreBinaria.c
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


//Programa principal
ArvBin* raiz = cria_ArvBin();
```


![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_S1n2lrhzQ.png)


```c
//ArvoreBinaria.h
void libera_ArvBin(ArvBin* raiz);


//ArvoreBinaria.c
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);//Libera o nó da esquerda recursivamente.
    libera_NO(no->dir);//Libera o nó da direita recursivamente.
    free(no);
    no == NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//Libera cada nó
    free(raiz); //Libera a raiz
}


//Programa principal
libera_ArvBin(raiz);
```

```c
//ArvoreBinaria.h
int estaVazia_ArvBin(ArvBin *raiz);


//ArvoreBinaria.c
//Retorna 1 (árvore está vazia) se a raiz for igual a NULL (verificando se ela [raiz] existe ) 
//Ou se o conteúdo da raiz é igual a NULL
int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1; //A árvore está vazia
    if(*raiz == NULL)//O conteúdo da raiz é igual a NULL
        return 1;
    return 0;
}


//Programa principal
int x = estaVazia_ArvBin(raiz);
if(estaVazia_ArvBin(raiz));
```


![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_ryylHH3M7.png)


```c
//ArvoreBinaria.h
int altura_ArvBin(ArvBin *raiz);


//ArvoreBinaria.c
int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}


//Programa principal
int x = altura_ArvBin(raiz);
```


![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_H1DdorhzQ.png)


```c
//ArvoreBinaria.h
int totalNO_ArvBin(ArvBin *raiz);


//ArvoreBinaria.c
int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}


//Programa principal
int x = totalNO_ArvBin(raiz);
```


![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_SkCtar3fX.png)


```c
//ArvoreBinaria.h
void preOrdem_ArvBin(ArvBin *raiz);


//ArvoreBinaria.c
void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));//Estou passando o endereço do filho da esquerda
        preOrdem_ArvBin(&((*raiz)->dir));//Aqui eu estou passando o endereço do filho da direita
    }
}

//Programa principal
preOrdem_ArvBin(raiz);
```


![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_rJ0YCS2fQ.png)


```c
//ArvoreBinaria.h
void emOrdem_ArvBin(ArvBin *raiz);


//ArvoreBinaria.c
void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}


//Programa principal
emOrdem_ArvBin(raiz);
```


![Image](/home/jefferson/my-notes-Medleytext/resources/SkGEE5jMm_BkZw182fm.png)


```c
//ArvoreBinaria.h
void posOrdem_ArvBin(ArvBin *raiz);

//ArvoreBinaria.c
void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info)
    }
}

//Programa principal
posOrdem_ArvBin(raiz);
```

```c
//ArvoreBinaria.h
int x = insere_ArvBin(raiz,valor);


//ArvoreBinaria.c
int x = insere_ArvBin(ArvBin raiz,int valor){
    if(raiz ==NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->infor = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant =  NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0; //elemento já existe
            }
            if(valor >Ç atual->info)
                atual = atual->dir;
            else
                atual = atual->esq
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;

}

//Programa principal
```

```c
//ArvoreBinaria.h


//ArvoreBinaria.c


//Programa principal

```







