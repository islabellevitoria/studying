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
        if(num < no->esq){
            inserirEsquerda(no->esq,num);
        }
        else{
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
        if(num < no->dir){
            inserirEsquerda(no->dir,num);
        }
        else{
            inserirDireita(no->dir,num);
        }
    }

}

int main(){

    Arvore *arv;
    int num;
}
