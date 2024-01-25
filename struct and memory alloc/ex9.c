#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{

    double u, x, y, z;

}Ponto;


int main(){

    int n, i;

    scanf("%d", &n);

    Ponto ponto[n];
    double distancia[n-1];

    for(i=0;i<n;i++){
        scanf("%lf%lf%lf%lf", &ponto[i].u, &ponto[i].x, &ponto[i].y, &ponto[i].z);
    }

    for(i=0;i<n-1;i++){

        distancia[i] = sqrt(pow(ponto[i].u - ponto[i+1].u,2) + pow(ponto[i].x - ponto[i+1].x,2) + pow(ponto[i].y - ponto[i+1].y,2) + pow(ponto[i].z - ponto[i+1].z,2));
    }


    for(i=0;i<n-1;i++){
        printf("%.2lf\n", distancia[i]);
    }

    return 0;

}
