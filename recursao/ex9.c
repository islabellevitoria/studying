#include<stdio.h>

int potencia(int x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return x;
    }

    else {

        return x * potencia(x, n-1);
    }
}

int main(){

    int casos, x, n, i;

    scanf("%d", &casos);

    for(i=0;i<casos;i++){
        scanf("%d %d", &x, &n);
        printf("%d\n", potencia(x,n));
    }

    return 0;
}


