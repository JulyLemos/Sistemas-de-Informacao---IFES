/* Questao 13 - Sequencia de Fibonacci - N primeiros termos
   Repeticao: for | Condicional: if                                  */
#include <stdio.h>

void imprimirFibonacci(int n);

int main() {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);
    imprimirFibonacci(n);
    return 0;
}

void imprimirFibonacci(int n) {
    int i, a = 0, b = 1, prox;

    if (n < 1) {
        printf("N deve ser >= 1!\n");
        return;
    }

    if (n == 1) {
        printf("%d\n", a);
        return;
    }

    printf("%d %d", a, b);
    for (i = 3; i <= n; i++) {
        prox = a + b;
        printf(" %d", prox);
        a = b;
        b = prox;
    }
    printf("\n");
}
