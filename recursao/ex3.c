#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int contagemX(char string[], int tam) {
    if(tam == 0) {
        return 0;
    }

    return (string[0] == '5') + contagemX(string + 1, tam - 1);
}

int main() {
    int n, i;

    scanf("%d", &n);
    getchar();
    char *string[n];

    for (i = 0; i < n; i++) {
        string[i] = malloc(50);
        scanf("%[^\n]", string[i]);
        getchar();
    }

    for (i = 0; i < n; i++) {
        printf("%d\n", contagemX(string[i], strlen(string[i])));
        free(string[i]);
    }

    return 0;
}
