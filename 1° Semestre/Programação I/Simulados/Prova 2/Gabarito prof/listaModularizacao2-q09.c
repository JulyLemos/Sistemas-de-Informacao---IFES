/* Questao 09 - Tabela de quadrados e cubos
   Repeticao: for | Condicional: if                                  */
#include <stdio.h>

void tabelaPotencias(int inicio, int fim);

int main() {
    int a, b;
    printf("Digite o inicio e o fim do intervalo: ");
    scanf("%d %d", &a, &b);
    tabelaPotencias(a, b);
    return 0;
}

void tabelaPotencias(int inicio, int fim) {
    int i;

    if (inicio > fim) {
        printf("Intervalo invalido!\n");
        return;
    }

    printf("%s %s %s\n", "N", "N^2", "N^3");
    printf("------------------------------\n");
    for (i = inicio; i <= fim; i++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
    }
}
