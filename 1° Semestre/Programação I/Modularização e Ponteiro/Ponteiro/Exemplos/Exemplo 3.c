#include<stdio.h>

int main(){

    int num[3];

    // & Referencia um endereço de memória
    // * Referencia o conteúdo de um endereço de memória

    num[0] = 10;
    num[1] = 20;
    num[2] = 30;
    printf("Valor apontado por num: %d \n", *(num+1));
    printf("Valor de num[1]: %d \n", num[1]);
    puts("\n"); // pulando uma linha
    printf("Valor apontado por num+2: %d \n", *(num+2));
    printf("Valor de num[2]: %d \n", num[2]);

    return 0;

}
