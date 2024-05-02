#include<stdio.h>

//prototipo da fun�ao que realiza a conversao de binario pra decimal
void decimalBinario(int n);

int main(){

    //declara�ao e leitura das variaveis
    int i, n, k;

    scanf("%d", &k);

    //la�o de repeti�ao para enviar os nameros para a fun�ao
    for(i=0;i<k;i++){
        scanf("%d", &n);
        decimalBinario(n);
        printf("\n"); // Adiciona uma nova linha ap�s a convers�o de cada n�mero
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


/*m�todo alternativo de realizar a convers�o, utilizando uma fun��o int:

#include<stdio.h>

//prot�tipo da fun��o que realiza a convers�o de bin�rio para decimal
int decimalBinario(int n);


int main(){

    //declara��o  e leitura das vari�veis
    int i, n, k;

    scanf("%d", &k);

    //la�o de repeti��o para enviar os numeros para a fun��o
    for(i=0;i<k;i++){
        scanf("%d", &n);
        decimalBinario(n);
        printf("\n"); // Adiciona uma nova linha ap�s cada convers�o
    }

    return 0;
}

int decimalBinario(int n){

    int r = n % 2; //resto
    int q = n / 2; //quociente

    //caso base: se o quociente for igual a 0, o loop acaba
    if(q == 0){
        printf("%d", r); // Imprime o ultimo d�gito antes de retornar
        return r;
    }

    printf("%d", r);

    return decimalBinario(q);
}
*/
