/* Questao 10 - Maior, menor e media de uma sequencia (encerra com 0)
   Repeticao: do-while | Condicional: if                             */
#include <stdio.h>

void analisarSequencia();

int main() {
    analisarSequencia();
    return 0;
}

void analisarSequencia() {
    float valor, maior = 0.0, menor = 0.0, soma = 0.0;
    int qtd = 0;

    do {
        printf("Digite um valor (0 para encerrar): ");
        scanf("%f", &valor);

        if (valor != 0.0) {
            if (qtd == 0) {
                maior = valor;
                menor = valor;
            } else {
                if (valor > maior) maior = valor;
                if (valor < menor) menor = valor;
            }
            soma += valor;
            qtd++;
        }
    } while (valor != 0.0);

    if (qtd == 0) {
        printf("Nenhum valor lido.\n");
    } else {
        printf("Maior : %.2f\n", maior);
        printf("Menor : %.2f\n", menor);
        printf("Media : %.2f\n", soma / qtd);
    }
}
