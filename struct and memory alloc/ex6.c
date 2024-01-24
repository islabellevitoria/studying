#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//alocar memoria dinamicamente

int main(){
    int n, i, tam;
    char buffer[10001]; //armazenamento temporario da string

    scanf("%d", &n);

    char *nomes[n]; //ponteiro de string funciona como uma matriz de string

    for(i=0;i<n;i++){//inicio do loop para preencher o buffer (getchar() para consumir o enter apos a entrada do n e antes da leitura do buffer);
        getchar();
        scanf("%[^\n]", buffer);
        size_t tam = strlen(buffer); //funcao para armazenar o tamanho do buffer
        nomes[i] = (char *)malloc((tam+1)*sizeof(char)); //aloca dinamicamente a memoria para que tenha o tamanho do nome digitado no buffer + \0
        strcpy(nomes[i], buffer); //copia o nome do buffer e cola no nomes[i] (primeiro elemento da matriz char)
    }

    //estrutura for que imprime os nomes e logo em seguida libera a memoria alocada
    for(i=0;i<n;i++){
        printf("%s\n", nomes[i]);
        free(nomes[i]);
    }

    return 0;
}
