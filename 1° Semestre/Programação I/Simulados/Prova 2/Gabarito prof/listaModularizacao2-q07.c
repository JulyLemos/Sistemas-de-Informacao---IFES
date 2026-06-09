/* Questao 07 - Inverso de um numero inteiro
   Repeticao: while | Condicional: if                                */
#include <stdio.h>

int inverterNumero(int n);

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numero invalido!\n");
        return 1;
    }

    printf("Inverso: %d\n", inverterNumero(n));
    return 0;
}

int inverterNumero(int n) {
    int inverso = 0;

    while (n > 0) {
        inverso = inverso * 10 + (n % 10); /*pega o ultimo digito de n e adiciona ao inverso, 
        ex: 1234 -> 0*10 + 4 = 4, 123 -> 4*10 + 3 = 43, 12 -> 43*10 + 2 = 432, 1 -> 432*10 + 1 = 4321*/
        n /= 10; //até  chegar a 0
    }
    return inverso;
}
