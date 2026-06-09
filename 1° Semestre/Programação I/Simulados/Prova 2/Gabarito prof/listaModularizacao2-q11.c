/* Questao 11 - Operacao com dois numeros via menu
   Repeticao: --- | Condicional: switch-case                         */
#include <stdio.h>

void executarOperacao(float a, float b, char op);

int main() {
    float a, b;
    char op;

    printf("===== MENU DE OPERACOES =====\n");
    printf(" +  Soma\n");
    printf(" -  Subtracao\n");
    printf(" *  Multiplicacao\n");
    printf(" /  Divisao\n");

    printf("Digite dois numeros: ");
    scanf("%f %f", &a, &b);
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op);

    executarOperacao(a, b, op);
    return 0;
}

void executarOperacao(float a, float b, char op) {
    switch (op) {
        case '+':
            printf("Resultado: %.2f\n", a + b);
            break;
        case '-':
            printf("Resultado: %.2f\n", a - b);
            break;
        case '*':
            printf("Resultado: %.2f\n", a * b);
            break;
        case '/':
            if (b == 0.0) {
                printf("Erro: divisao por zero!\n");
            } else {
                printf("Resultado: %.2f\n", a / b);
            }
            break;
        default:
            printf("Operacao invalida!\n");
    }
}
