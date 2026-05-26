// An�lise de Conjunto Num�rico
//Implemente um programa em C que receba 8 n�meros inteiros como entrada e realize as seguintes
//an�lises:
//� Calcule a quantidade de n�meros positivos
//� Calcule a quantidade de n�meros negativos
//� Calcule a quantidade de n�meros iguais a zero
//� Ao final, exiba na tela os resultados de cada contagem

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    int pos = 0, neg = 0, zero = 0, num, i;

    for (i  = 1; i < 9; i++) {
        printf("Digite o %d� n�mero: ", i);
        scanf("%d", &num);

        if (num > 0){
            pos ++;
        } else if (num < 0) {
            neg ++;
        } else {
            zero++;
        }
    }
    printf(
           "\nA quantidade de n�meros positivos s�o: %d"
           "\nA quantidade de n�meros negativos s�o: %d"
           "\nA quantidade de zeros: %d", pos, neg, zero);

}
