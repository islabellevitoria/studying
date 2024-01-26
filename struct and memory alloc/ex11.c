#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    double coeficiente;
    int expoente;
} TermoPolinomio;

void organizaPolinomio(TermoPolinomio organiza[], int tamanho);
void imprimeTermo(TermoPolinomio termo, int primeiro);

void somaOuSubtraiPolinomio(char operacao) {
    int m, n, i, j, cont=0;

    scanf("%d", &m);
    TermoPolinomio termosp1[m];

    for (i = 0; i < m; i++) {
        scanf("%lf %d", &termosp1[i].coeficiente, &termosp1[i].expoente);
    }

    scanf("%d", &n);
    TermoPolinomio termosp2[n];

    for (i = 0; i < n; i++) {
        scanf("%lf %d", &termosp2[i].coeficiente, &termosp2[i].expoente);
    }

    int tamanho = m + n;
    TermoPolinomio organiza[tamanho];

    for (i = 0; i < m; i++) {
        organiza[i] = termosp1[i];
    }

    for (i = m; i < tamanho; i++) {
        organiza[i] = termosp2[i - m];
    }

    organizaPolinomio(organiza, tamanho);
}

void organizaPolinomio(TermoPolinomio organiza[], int tamanho) {
    int i, j;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (organiza[j].expoente < organiza[j + 1].expoente) {
                TermoPolinomio temp = organiza[j];
                organiza[j] = organiza[j + 1];
                organiza[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (organiza[i].expoente == organiza[j].expoente) {
                organiza[i].coeficiente += organiza[j].coeficiente;
                organiza[j].expoente = -1;
                organiza[j].coeficiente = 0;
            }
        }
    }

    for (i = 0; i < tamanho; i++) {
        if (organiza[i].expoente >= 0) {
            imprimeTermo(organiza[i], (i == 0));
        }
    }

    printf("\n");
}

void imprimeTermo(TermoPolinomio termo, int primeiro) {
    if (termo.coeficiente > 0 && !primeiro) {
        printf("+");
    }

    if (termo.expoente > 0) {
        printf("%.2lfX^%d", termo.coeficiente, termo.expoente);
    } else {
        printf("%.2lf", termo.coeficiente);
    }
}

int main() {
    int casos, p;
    char operacao;

    scanf("%d", &casos);
    getchar();

    for (p = 0; p < casos; p++) {
        scanf(" %c", &operacao);

        if (operacao == '+' || operacao == '-') {
            somaOuSubtraiPolinomio(operacao);
        }
    }

    return 0;
}
