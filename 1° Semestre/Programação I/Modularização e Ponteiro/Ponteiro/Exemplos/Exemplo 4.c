#include<stdio.h>

int main(){
    int num[3];

    // & Referencia um endereço de memória
    // * Referencia o conteúdo de um endereço de memória

    num[0] = 10;
    num[1] = 20;
    num[2] = 30;
    printf("Endereço de memoria de num[1]: %d \n", &num[1]);
    printf("Endereço de memoria de num+1: %d \n", num+1);

    return 0;

}
