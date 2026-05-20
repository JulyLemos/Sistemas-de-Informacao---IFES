#include<stdio.h>

//prototipo da função soma
int somar(int x, int y); //prototipação

int main(){

    int a, b, soma;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite outro número: ");
    scanf("%d", &b);

    soma = somar(a, b);

    printf("Soma: %d", soma);

    return 0;
}

int somar(int x, int y) {
    return x + y;
}
