#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;
    struct no *esq, *dir;

}No;

typedef struct{

    No *raiz;

}Arvore;

void inserir(Arvore *arv, int num){
    if(arv->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = num;
        novo->esq =  NULL;
        novo->dir = NULL;
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

void inserirEsquerda(No *no, int num){
    if(no->esq == NULL){
        No *novo = malloc(sizeof(No));
        novo->valor = num;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    }
    else{
        if(num < no->esq->valor){
            inserirEsquerda(no->esq,num);
        }
        if(num > no->esq->valor){
            inserirDireita(no->esq,num);
        }
    }

}

void inserirDireita(No *no, int num){
    if(no->dir == NULL){
        No *novo = malloc(sizeof(No));
        novo->valor = num;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    }
    else{
        if(num < no->dir->valor){
            inserirEsquerda(no->dir,num);
        }
        if(num > no->dir->valor){
            inserirDireita(no->dir,num);
        }
    }

}

void imprimir(No *raiz){

    if(raiz){
        imprimir(raiz->esq);
        printf("%d", raiz->valor);
        imprimir(raiz->dir);
    }

}

int main(){

    Arvore arv;
    int num;
}
