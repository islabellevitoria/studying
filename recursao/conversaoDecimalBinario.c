#include<stdio.h>

//prototipo da funçao que realiza a conversao de binario pra decimal
void decimalBinario(int n);

int main(){

    //declaraçao e leitura das variaveis
    int i, n, k;

    scanf("%d", &k);

    //laço de repetiçao para enviar os nameros para a funçao
    for(i=0;i<k;i++){
        scanf("%d", &n);
        decimalBinario(n);
        printf("\n"); // Adiciona uma nova linha após a conversão de cada número
    }

    return 0;
}

void decimalBinario(int n){

    int r = n%2; //resto
    int q = n/2; //quociente

    //caso base: o loop continua ate que q == 0
    if(q != 0){
        decimalBinario(q);
    }

    printf("%d", r);

}


/*método alternativo de realizar a conversão, utilizando uma função int:

#include<stdio.h>

//protótipo da função que realiza a conversão de binário para decimal
int decimalBinario(int n);


int main(){

    //declaração  e leitura das variáveis
    int i, n, k;

    scanf("%d", &k);

    //laço de repetição para enviar os numeros para a função
    for(i=0;i<k;i++){
        scanf("%d", &n);
        decimalBinario(n);
        printf("\n"); // Adiciona uma nova linha após cada conversão
    }

    return 0;
}

int decimalBinario(int n){

    int r = n % 2; //resto
    int q = n / 2; //quociente

    //caso base: se o quociente for igual a 0, o loop acaba
    if(q == 0){
        printf("%d", r); // Imprime o ultimo dígito antes de retornar
        return r;
    }

    printf("%d", r);

    return decimalBinario(q);
}
*/
