/*06 - Desenvolva um programa que leia o preço de 12 produtos e armazene em um vetor. - OK
Em seguida, aplique um desconto de acordo com a seguinte regra: se o preço for maior que R$
100,00, desconto de 10%; - if
caso contrário, desconto de 5%. - else
Mostre os novos preços dos produtos.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<string.h>

//Finalizar

int main(){
    setlocale(LC_ALL, "");

    int produtos[5], i;

    for (i = 0; i < 5; i++){
        printf("Digite o preço do produto: ");
        scanf(" %d\n", &produtos[i]);
        printf("\n%d", produtos[i]);
    }

    if (produtos[i] > 100){
        produtos[i] = produtos[i]*0.9;
        printf(" %d", produtos[i]);
    } else {
        produtos[i] = produtos[i]*0.95;
        printf(" %d", produtos[i]);
    }

    printf("A");

    return 0;
}
