#include<stdio.h>

int main(){
    int a, *b;

    // & Referencia um endereço de memória
    // * Referencia o conteúdo de um endereço de memória

    a = 50;
    printf("Valor anterior de A: %d \n", a);
    b = &a;
    *b=10;

    printf(" valor de a: %d \n", a);
    printf("valor de b: %d \n", b);
    printf(" valor da variavel apontada por b: %d \n", *b);

    return 0;

}
