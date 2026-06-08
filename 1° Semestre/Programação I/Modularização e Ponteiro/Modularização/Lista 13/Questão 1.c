/*01 - Crie uma função chamada somar que recebe dois números inteiros como parâmetros e 
retorna a soma deles. No programa principal, leia dois inteiros digitados pelo usuário, chame a  
função e exiba o resultado*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

int somar(int x, int y);

int main(){
    setlocale(LC_ALL, "");

    int a, b, resultado;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    resultado = somar(a,b);

    printf("A soma dos dois números digitados é %d", resultado);
    //ou
    //printf("A soma dos dois números digitados é igual a %d",somar(a,b));

    return 0;
}

int somar (int x, int y){
    return x + y;
}