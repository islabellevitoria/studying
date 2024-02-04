#include<stdio.h>

int contaOrelha(int x){

    if(x==0){
        return 0;
    }

    if(x%2==0){
        return 3 + contaOrelha(x-1);
    }

    if(x%2!=0){
        return 2 + contaOrelha(x-1);
    }

}

int main(){

    int casos, i, x;

    scanf("%d", &casos);

    for(i=0;i<casos;i++){
        scanf("%d", &x);
        printf("%d\n", contaOrelha(x));
    }

    return 0;
}
