#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 10

typedef struct {

    char *nome;
    int idade;

}Aluno;

typedef struct {

    Aluno aluno[max];

}Classe;

void inserirAlunosTurma(Classe *classe){

    int i;
        for(i=0;i<max;i++){
            printf("Escreva o nome do aluno %d: ", i+1);
            scanf("%[^\n]", classe->aluno[i].nome);
            getchar();
            printf("escreva a idade do aluno %d: ", i+1);
            scanf("%d", &classe->aluno[i].idade);
            getchar();
        }

        return;

}

void imprimeLista(Classe *classe){

    int i;
    for(i=0;i<max;i++){
        printf("nome: %s ", classe->aluno[i].nome);
        printf("idade: %d", classe->aluno[i].idade);
        printf("\n");
    }

    return;
}

int main(){

    Classe classe;
    int i;

    for(i=0;i<max;i++){
        classe.aluno[i].nome = (char*)malloc(50 * sizeof(char));
        if(classe.aluno[i].nome==NULL){
            printf("Erro ao alocar memoria\n");
            return 1;
        }
    }

    inserirAlunosTurma(&classe);
    imprimeLista(&classe);

    for(i=0;i<max;i++){
        free(classe.aluno[i].nome);
    }


    return 0;
}