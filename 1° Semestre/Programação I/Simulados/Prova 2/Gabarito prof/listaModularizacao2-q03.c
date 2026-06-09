/* Questao 03 - Conversor de unidades de comprimento
   Repeticao: --- | Condicional: switch-case                         */
#include <stdio.h>

void converterComprimento(float metros, int codigo);

int main() {
    float valor;
    int cod;

    printf("Digite o valor em metros: ");
    scanf("%f", &valor);
    printf("Unidade de destino (1=km, 2=cm, 3=mm, 4=pol): ");
    scanf("%d", &cod);

    converterComprimento(valor, cod);
    return 0;
}

void converterComprimento(float metros, int codigo) {
    switch (codigo) {
        case 1:
            printf("%.4f metros = %.4f km\n", metros, metros / 1000.0);
            break;
        case 2:
            printf("%.4f metros = %.4f cm\n", metros, metros * 100.0);
            break;
        case 3:
            printf("%.4f metros = %.4f mm\n", metros, metros * 1000.0);
            break;
        case 4:
            printf("%.4f metros = %.4f pol\n", metros, metros * 39.3701);
            break;
        default:
            printf("Codigo invalido!\n");
    }
}
