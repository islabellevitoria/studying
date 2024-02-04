#include<stdio.h>

int logNaBase2(int x){

    if(x==1){
        return 0;
    }

    return 1 + logNaBase2(x/2);

}

int main(){

    int n, x;

    scanf("%d", &n);

    while(n--){
        scanf("%d", &x);
        printf("%d\n", logNaBase2(x));
    }

    return 0;
}
