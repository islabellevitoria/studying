#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{

    double u,x,y,z;
    double norma;

}Vetor;

int main(){

    Vetor vetor[100], temp;
    int n, i, j;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%lf%lf%lf%lf", &vetor[i].u, &vetor[i].x, &vetor[i].y, &vetor[i].z);
        vetor[i].norma = sqrt(vetor[i].u*vetor[i].u + vetor[i].x*vetor[i].x + vetor[i].y*vetor[i].y + vetor[i].z*vetor[i].z);

    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vetor[j].norma > vetor[j + 1].norma) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    for(j=0;j<n;j++){
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", vetor[j].u, vetor[j].x, vetor[j].y, vetor[j].z, vetor[j].norma);
    }

    return 0;

}
