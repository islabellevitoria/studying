#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removerEspaco(char vet[]) {
    int i, j = 0;
    for (i = 0; vet[i] != '\0'; i++) {
        if (vet[i] != ' ') {
            vet[j++] = vet[i];
        }
    }
    vet[j] = '\0';
}

char Palindromo(char vet[], int i, int j) {
    if (i >= j) return printf("PALINDROMO\n");
    if (vet[i] != vet[j]) return printf("NAO PALINDROMO\n");
    return Palindromo(vet, i + 1, j - 1);
}

int main(){
    int n, m;
    scanf("%d", &n);
    while(n!=0){
        scanf("%d", &m);
        char *vet = (char *)malloc(sizeof(char) * 2000);
        scanf(" %[^\n]", vet);
        removerEspaco(vet);
        int tam = strlen(vet);
        Palindromo(vet, 0, tam - 1);
        free(vet);
        n--;
    }
    return 0;
}
