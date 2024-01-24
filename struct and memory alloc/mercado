#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{

    double preco;
    char nome[50];

}Produto;

int main(){

    int casos, produtos, compras, i, j, k;

    scanf("%d", &casos);

    for(i=0;i<casos;i++){

        scanf("%d", &produtos);

        Produto lista_de_produtos[100];

            for(j=0;j<produtos;j++){

                scanf("%s%lf", lista_de_produtos[j].nome, &lista_de_produtos[j].preco);  //entrada dos prod disponiveis + preço
            }

            scanf("%d", &compras);

            double valor_gasto = 0.0;

            for(j=0;j<compras;j++){

                char nomeProduto[50];
                int itens;

                scanf("%s %d", nomeProduto, &itens); //entrada dos prod que a muie quer + qtd

                for(k=0;k<produtos;k++){

                    if (strcmp(nomeProduto, lista_de_produtos[k].nome) == 0) {
                    valor_gasto += itens * lista_de_produtos[k].preco;

                        break;
                    }
                }
            }

            printf("R$ %.2lf\n", valor_gasto);
    }

    return 0;
}
