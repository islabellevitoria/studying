#include<stdio.h>
#include<stdlib.h>

typedef struct {

    int *vetor;
    int tamanho;

}Estrutura;

void insereElemento(Estrutura *estrutura, int i){
    int elemento;
    scanf("%d", &elemento);
    estrutura->vetor[i] = elemento;
    return;

}

int main(){

    Estrutura estrutura;
    int i;
    int tamanho;

    printf("Insira o tamanho do vetor: ");
    scanf("%d", &estrutura.tamanho);

    estrutura.vetor = (int *)malloc(estrutura.tamanho * sizeof(int));

    if(estrutura.vetor==NULL){
        printf("Nao foi possivel alocar memoria");
        return 1;
    }

    printf("Insira os elementos do vetor: ");
    for( i = 0; i < estrutura.tamanho; i++){
        insereElemento(&estrutura, i);
    }

    printf("Elementos do vetor: \n");
    for(i=0;i<estrutura.tamanho;i++){
    printf("%d ", estrutura.vetor[i]);
    }

    printf("\n");

    free(estrutura.vetor);

    return 0;
}