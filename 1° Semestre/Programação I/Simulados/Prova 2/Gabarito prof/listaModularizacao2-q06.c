/* Questao 06 - Dia da semana por extenso
   Repeticao: --- | Condicional: switch-case                         */
#include <stdio.h>

void imprimirDiaSemana(int dia);

int main() {
    int d;
    printf("Digite um numero de 1 a 7: ");
    scanf("%d", &d);
    imprimirDiaSemana(d);
    return 0;
}

void imprimirDiaSemana(int dia) {
    switch (dia) {
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
            printf("Terca-feira\n");
            break;
        case 4:
            printf("Quarta-feira\n");
            break;
        case 5:
            printf("Quinta-feira\n");
            break;
        case 6:
            printf("Sexta-feira\n");
            break;
        case 7:
            printf("Sabado\n");
            break;
        default:
            printf("Dia invalido\n");
    }
}
