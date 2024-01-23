#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    int codigo_curso;
    double valor_credito;
    char nome_curso[100];
    char nome_aluno[50];
    int codigo_aluno;
    int qtd_credito;

}Universidade;

typedef struct{
     Universidade universidade;

}Aluno;

int main(){

    Universidade listaCursos[50];
    Aluno listaAlunos[50];

    int cursos, alunos, i, j, k, l;

    scanf("%d", &cursos);

    for(i=0; i<cursos;i++){

            scanf("%d", &listaCursos[i].codigo_curso);
            scanf("%lf", &listaCursos[i].valor_credito);
            getchar();
            scanf("%[^\n]", listaCursos[i].nome_curso);
    }

    scanf("%d", &alunos);

    for(j=0; j<alunos; j++){
        getchar();
        scanf("%[^\n]", listaAlunos[j].universidade.nome_aluno);
        scanf("%d", &listaAlunos[j].universidade.codigo_aluno);
        scanf("%d", &listaAlunos[j].universidade.qtd_credito);
    }


    for(k=0;k<alunos;k++){
        l = 0;
        for(l=0;l<cursos;l++){

            if(listaAlunos[k].universidade.codigo_aluno == listaCursos[l].codigo_curso){
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n", listaAlunos[k].universidade.nome_aluno, listaCursos[l].nome_curso, listaAlunos[k].universidade.qtd_credito,
                listaCursos[l].valor_credito, (listaAlunos[k].universidade.qtd_credito*listaCursos[l].valor_credito));
            }

        }
    }

    return 0;
}


