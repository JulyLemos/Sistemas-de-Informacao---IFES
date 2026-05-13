/*01 - Crie um programa que leia 10 números inteiros e armazene em um vetor. Em seguida,
verifique quantos números são positivos e quantos são negativos, mostrando o resultado na
tela.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL," ");

    float num[10];
    int i, pos = 0, neg = 0, neutro = 0;

    for (i = 0; i < 10; i++){
        printf("Digite um número: ");
        scanf("%f", &num[i]);

        if (num[i] > 0){
            pos++;
        } else if (num[i] < 0){
            neg++;
        } else {
            neutro++;
        }
    }



    printf("A quantidade de números positivos são de %d.\n"
           "A quantidade de números negativos são de %d.\n"
           "A quantidade de números neutros são de %d.", pos, neg, neutro);

        return 0;
}
