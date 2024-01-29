#include<stdio.h>

typedef struct{

    int moradores;
    int consumo;

}Imovel;

void valorConsumo(Imovel *imovel, Imovel temp, int cont, int n);

int main(){
    int n = 1, i, cont = 0;
    Imovel temp;

    while(n != 0){
        scanf("%d", &n);
        if(n==0){
            break;
        }
        cont++;
        Imovel imovel[n];

        for(i=0;i<n;i++){
            scanf("%d %d", &imovel[i].moradores, &imovel[i].consumo);
        }
        valorConsumo(imovel, temp, cont, n);
    }
    return 0;
}

void valorConsumo(Imovel *imovel, Imovel temp, int cont, int n){

    int i, j, tot = 0;
    double consumo_medio = 0;

    for(i=0;i<n;i++){ //calcula o consumo medio e de cada morador
        consumo_medio += imovel[i].consumo;
        tot += imovel[i].moradores;
        imovel[i].consumo = imovel[i].consumo/imovel[i].moradores;
    }

    consumo_medio = (consumo_medio)/tot;

    for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
        if(imovel[j].consumo > imovel[j+1].consumo) {
            temp = imovel[j];
            imovel[j] = imovel[j+1];
            imovel[j+1] = temp;
        }
    }
}

    printf("Cidade# %d:\n", cont);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(imovel[i].consumo == imovel[j].consumo){
                imovel[i].moradores += imovel[j].moradores;
                imovel[j].moradores = 0;
            }
        }
        if(imovel[i].moradores!=0){
            printf("%d-%d ", imovel[i].moradores, imovel[i].consumo);
        }
    }
    printf("\n");
    printf("Consumo medio: %.2lf m3.\n", consumo_medio);
}
