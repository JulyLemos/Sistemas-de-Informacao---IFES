/* Questao 02 - Classificacao de IMC
   Repeticao: --- | Condicional: if/else encadeados                  */
#include <stdio.h>

void classificarIMC(float peso, float altura);

int main() {
    float peso, altura;
    printf("Digite o peso (kg): ");
    scanf("%f", &peso);
    printf("Digite a altura (m): ");
    scanf("%f", &altura);

    classificarIMC(peso, altura);
    return 0;
}

void classificarIMC(float peso, float altura) {
    float imc = peso / (altura * altura);
    printf("IMC = %.2f -> ", imc);

    if (imc < 18.5f) {
        printf("Abaixo do peso\n");
    } else if (imc < 25.0) {
        printf("Normal\n");
    } else if (imc < 30.0) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidade\n");
    }
}
