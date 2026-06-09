/* Questao 15 - Conversao decimal para binario
   Repeticao: while (gerar bits) + for (imprimir invertido)
   Condicional: if                                                   */
#include <stdio.h>

void decimalParaBinario(int n);

int main() {
    int n;
    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);
    decimalParaBinario(n);
    return 0;
}

void decimalParaBinario(int n) {
    int bits[32];
    int i, qtd = 0;

    if (n == 0) {
        printf("Binario: 0\n");
    }else
        if (n < 0) {
            printf("Numero invalido! Use um inteiro positivo.\n");
        }else{
            while (n > 0) {
                bits[qtd] = n % 2;
                n /= 2;
                qtd++;
            }

            /* Imprime na ordem inversa - for com indice controlado */
            printf("Binario: ");
            for (i = qtd - 1; i >= 0; i--) {
                printf("%d", bits[i]);
            }
            printf("\n");
        }
}
