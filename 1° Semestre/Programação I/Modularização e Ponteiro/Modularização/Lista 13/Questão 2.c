/*02  -   Implemente   uma   função   quadrado   que   receba   um   número   inteiro   e   retorne   o   seu 
quadrado. Na main, leia um valor e mostre o quadrado utilizando a função.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

int quadrado(int x);

int main(){
    setlocale(LC_ALL, "");

    int x;

    printf("Digite um número qualquer para descobrir o seu quadrado: ");
    scanf("%d", &x);

    printf("O quadrdo do número digitado é %d", quadrado(x));
}

int quadrado(int x){
    return x * x;
}