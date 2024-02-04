#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Soma(int n) {

    if (n == 1) {
        return 1;
    }

    if(n==0){
        return 0;
    }

    else{

        return n + Soma(n-1);
    }

}

int main(){

    int t, i;

    scanf("%d", &t);

    int num[t];

    for(i=0;i<t;i++){
        scanf("%d", &num[i]);
    }

    for(i=0;i<t;i++){
        printf("%d\n", Soma(num[i]));
    }

    return 0;
}
