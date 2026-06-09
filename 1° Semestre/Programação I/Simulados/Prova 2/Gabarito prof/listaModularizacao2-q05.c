/* Questao 05 - Contagem de digitos de um numero
   Repeticao: while | Condicional: if                                */
#include <stdio.h>

int contarDigitos(int n);

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    printf("%d possui %d digito(s)\n", n, contarDigitos(n));
    return 0;
}

int contarDigitos(int n) {
    int qtd = 0;

    if (n == 0) {
        return 1;   /* zero tem 1 digito */
    }

    while (n != 0) {
        n /= 10;// remove o ultimo digito, ex: 1234 -> 123, 123 -> 12, 12 -> 1, 1 -> 0, vai dividindo até chegar a zero
        qtd++;
    }
    return qtd;
}
