#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char idioma[50];
} Traducao;

Traducao traducoes[50] = {
    {"brasil", "Feliz Natal!"},
    {"alemanha", "Frohliche Weihnachten!"},
    {"austria", "Frohe Weihnacht!"},
    {"coreia", "Chuk Sung Tan!"},
    {"espanha", "Feliz Navidad!"},
    {"grecia", "Kala Christougena!"},
    {"estados-unidos", "Merry Christmas!"},
    {"inglaterra", "Merry Christmas!"},
    {"australia", "Merry Christmas!"},
    {"portugal", "Feliz Natal!"},
    {"suecia", "God Jul!"},
    {"turquia", "Mutlu Noeller"},
    {"argentina", "Feliz Navidad!"},
    {"chile", "Feliz Navidad!"},
    {"mexico", "Feliz Navidad!"},
    {"antardida", "Merry Christmas!"},
    {"canada", "Merry Christmas!"},
    {"irlanda", "Nollaig Shona Dhuit!"},
    {"belgica", "Zalig Kerstfeest!"},
    {"italia", "Buon Natale!"},
    {"libia", "Buon Natale!"},
    {"siria", "Milad Mubarak!"},
    {"marrocos", "Milad Mubarak!"},
    {"japao", "Merii Kurisumasu!"}
};

void FelizNatal(char *pais) {
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(traducoes[i].nome, pais) == 0) {
            printf("%s\n", traducoes[i].idioma);
            return;
        }
    }
    printf("-- NOT FOUND --\n");
}

int main() {
    char pais[50];

    while (scanf("%s", pais) != EOF) {
        FelizNatal(pais);
    }

    return 0;
}
