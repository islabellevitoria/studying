#include <stdio.h>

int numeroReverso(int n, int reverso);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", numeroReverso(n, 0));

    return 0;
}

int numeroReverso(int n, int reverso) {

    if (n == 0) {
        return reverso;

    }

    reverso = (reverso * 10) + (n % 10);

    return numeroReverso(n / 10, reverso);
}
