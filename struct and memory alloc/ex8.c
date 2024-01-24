#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int dia, mes, ano;
}DataNas;

typedef struct{

    DataNas datanas;
    char nome[100];
    int matricula;

}Dados;

void ComparaDataNasc();

//código que ordena alunos em ordem crescente de idade

int main(){

    int n, i;

    scanf("%d", &n);

    Dados alunos[n], temp;

    for(i=0;i<n;i++){
        getchar();
        scanf("%d%d%d%d%[^\n]", &alunos[i].matricula, &alunos[i].datanas.dia, &alunos[i].datanas.mes, &alunos[i].datanas.ano, alunos[i].nome);
    }

    ComparaDataNasc(alunos, temp, n, i); //funçao que compara a idade


    return 0;
}

void ComparaDataNasc(Dados *alunos, Dados temp, int n, int i) { 
    int j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (alunos[j].datanas.ano < alunos[j+1].datanas.ano) { //compara o ano
                temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            } else if (alunos[j].datanas.ano == alunos[j+1].datanas.ano) {
                if (alunos[j].datanas.mes < alunos[j+1].datanas.mes) { //se o ano for igual, compara o mes
                    temp = alunos[j];
                    alunos[j] = alunos[j+1];
                    alunos[j+1] = temp;
                } else if (alunos[j].datanas.mes == alunos[j+1].datanas.mes) {
                    if (alunos[j].datanas.dia < alunos[j+1].datanas.dia) { //se o ano e o mes forem iguais, compara o dia
                        temp = alunos[j];
                        alunos[j] = alunos[j+1];
                        alunos[j+1] = temp;
                    }
                }
            }
        }
    }

    for(i=0;i<n;i++){
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", alunos[i].matricula, alunos[i].nome, alunos[i].datanas.dia, alunos[i].datanas.mes, alunos[i].datanas.ano);
    }
}
