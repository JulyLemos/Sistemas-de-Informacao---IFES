//Desenvolva um programa em C que solicite ao usu�rio dois n�meros inteiros representando o in�cio e o
//fim de um intervalo. - OK
//O programa deve exibir todos os n�meros inteiros contidos neste intervalo(incluindo os limites),
//em ordem crescente.
//Implemente o tratamento adequado caso o primeiro n�mero
//seja maior que o segundo.

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){

    setlocale(LC_ALL, "");

    int num1, num2, i, c;

    printf("Digite o primeiro n�mero: ");
    scanf("%d", &num1);
    printf("Digite o segundo n�mero: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        c = num1;
        num1 = num2;
        num2 = c;
    }
    for (i = num1; i <= num2; i++) {
        printf(" %d", i);

    }
    return 0;
}


