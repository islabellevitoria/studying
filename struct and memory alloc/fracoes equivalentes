#include <stdio.h>
#include<stdlib.h>
 
struct fracao{ //estrutura da fracao
 
    int numerador, denominador;
};
 
int main(){
 
    int n, m, i, j, x, y, k, e;
 
    scanf("%d", &n);
 
    for(j=1;j<=n;j++){
        scanf("%d", &m);
        struct fracao fracao[m];
        for(i=0;i<m;i++){
            scanf("%d/%d", &x, &y);
            fracao[i].numerador = x;
            fracao[i].denominador = y;
        }
 
        printf("Caso de teste %d\n", j);
 
        for(i = 0; i < m-1; i++){
            e = 0;
            for(k = i+1; k < m; k++){
                if(fracao[i].numerador*fracao[k].denominador == fracao[k].numerador*fracao[i].denominador){
                    e += 1;
                    printf("%d/%d equivalente a %d/%d\n", fracao[i].numerador, fracao[i].denominador, fracao[k].numerador, fracao[k].denominador);
                }
            }
        }
 
        if(e==0){
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
    }
 
    return 0;
}
