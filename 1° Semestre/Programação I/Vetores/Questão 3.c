/*03 - Desenvolva um programa que leia 5 números inteiros e armazene em um vetor. Em
seguida, mostre na tela qual o maior número e em qual posição ele está no vetor*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num[5], i, j, aux;

    for (i = 0; i <= 4; i++) {
        printf("Digite um número: ");
        scanf("%d", &num[i]);
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(num[j] > num[j+1]) {
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
            }
        }
    }

    printf(num[5]);

    return 0;
}

