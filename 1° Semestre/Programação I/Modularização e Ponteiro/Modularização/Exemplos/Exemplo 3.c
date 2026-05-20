#include<stdio.h>

//prototipo da função soma
void imprimirValor(int x);
//parâmetro por valor

int main(){

    int a, b;

    printf("Digite um numero: ");
    scanf("%d", &a);

    printf("Digite outro número: ");
    scanf("%d", &b);

    imprimirValor(a);
    imprimirValor(b);

    //só para testar o valor de a
    printf("Valor de A em main: %d\n", a);
    printf("Valor de B em main: %d\n", b);

    return 0;
}

void imprimirValor(int x) {
    printf("Valor: %d\n", x);
}
