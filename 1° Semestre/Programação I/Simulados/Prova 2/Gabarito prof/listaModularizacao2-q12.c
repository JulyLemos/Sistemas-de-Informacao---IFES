/* Questao 12 - MDC pelo algoritmo de Euclides
   Repeticao: while | Condicional: if                                */
#include <stdio.h>

int mdc(int a, int b);

int main() {
    int a, b;
    printf("Digite dois inteiros positivos: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Valores invalidos! Devem ser positivos.\n");
        return 1;
    }

    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    return 0;
}

int mdc(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
