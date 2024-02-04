#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int somaVetor(int vetor[], int tam){

    if(tam==0){
        return 0;
    }

    return vetor[tam-1] + somaVetor(vetor, tam-1);

}


int main(){

    int i, tam = 0, casos, j;

    scanf("%d", &casos);

    for(i=0;i<casos;i++){

        scanf("%d", &tam);
        int vetor[tam];

        for(j=0;j<tam;j++){

            scanf("%d", &vetor[j]);
        }

        printf("%d\n", somaVetor(vetor, tam));
    }

    return 0;
}
