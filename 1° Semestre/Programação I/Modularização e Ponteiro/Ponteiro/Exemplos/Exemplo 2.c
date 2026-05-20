#include<stdio.h>

int main(){

    int num[3];

    // & Referencia um endereço de memória
    // * Referencia o conteúdo de um endereço de memória

    printf("Valor de num: %d \n", num);
    printf("Endereço de memoria de num[0]: %d \n", &num[0]);

    return 0;

}
