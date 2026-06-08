#include<stdio.h>

void imprimirTabuada(int n);

int main(){
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    imprimirTabuada(n);

    return 0;
}

void imprimirTabuada(int n) {
    int i;

    for (i = 0; i < 11; i++){
        printf("%d * %d = %d\n", n, i, n*i); 
    }
}