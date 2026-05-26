/*01 - Crie um programa que leia 10 n�meros inteiros e armazene em um vetor. Em seguida,
verifique quantos n�meros s�o positivos e quantos s�o negativos, mostrando o resultado na
tela.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"");

    float num[10];
    int i, pos = 0, neg = 0, neutro = 0;

    for (i = 0; i < 10; i++){
        printf("Digite um n�mero: ");
        scanf("%f", num[i]);

        if (num[i] >= 0){
            pos++;
        } else if (num[i] < 0){
            neg++;
        } else {
            neutro++;
        }
    }

    printf("A quantidade de n�meros positivos s�o de %i", pos,
        "A quantidade de n�meros negativos s�o de %i", neg,
        "A quantidade de n�meros neutros s�o de %i", neutro);

        return 0;
}
