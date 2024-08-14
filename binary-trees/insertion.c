#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;
    struct no *esq, *dir;

}No;

typedef struct{

    No *raiz;

}Arvore;

void inserirEsquerda(No *raiz, int num);
void inserirDireita(No *raiz, int num);

No* criarNo(int num){

    No *novo = (No*)malloc(sizeof(No));
    novo->valor = num;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;

}

void inserir(Arvore *arv, int num){
    if(arv->raiz == NULL){
        No *novo = criarNo(num);
        arv->raiz = novo;
    }
    else{
        if(num < arv->raiz->valor){
            inserirEsquerda(arv->raiz,num);
        }
        else{
            inserirDireita(arv->raiz,num);
        }
    }
}

void inserirEsquerda(No *node, int num){
    if(node->esq == NULL){
        No *novo = malloc(sizeof(No));
        novo->valor = num;
        novo->esq = NULL;
        novo->dir = NULL;
        node->esq = novo;
    }
    else{
        if(num < node->esq->valor){
            inserirEsquerda(node->esq,num);
        }
        if(num > node->esq->valor){
            inserirDireita(node->esq,num);
        }
    }

}

void inserirDireita(No *node, int num){
    if(node->dir == NULL){
        No *novo = criarNo(num);
        node->dir = novo;
    }
    else{
        if(num < node->dir->valor){
            inserirEsquerda(node->dir,num);
        }
        if(num > node->dir->valor){
            inserirDireita(node->dir,num);
        }
    }

}

void imprimir(No *raiz){

    if(raiz){
        imprimir(raiz->esq);
        printf("%d ", raiz->valor);
        imprimir(raiz->dir);
    }

}

int main(){

    Arvore a;
    a.raiz = NULL;
    int num;

    inserir(&a,500);
    inserir(&a,700);
    inserir(&a,200);
    inserir(&a,300);

    imprimir(a.raiz);


return 0;
}
