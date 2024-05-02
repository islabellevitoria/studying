#include<stdio.h>

int Fack(int m, int n);

int main(){

    int n, m;
    scanf("%d %d", &m, &n);
    printf("%d", Fack(m,n));

    return 0;
}

int Fack(int m, int n){

    if(m==0){
        return n+1;
    }

    if(n==0){
        return Fack(m-1,1);
    }

    if(n>0){
        return Fack(m-1, Fack(m,n-1));
    }
}
