/*03 - Construa uma função ehPar que receba um número inteiro e retorne 1 se ele for par e 0 se
for ímpar (utilize  uma estrutura condicional). Na  main, leia um número  e use a  função para
informar se ele é par ou ímpar.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

int par(int x);

int main(){
  setlocale(LC_ALL, "");

  int x;

  printf("Digite um número: ");
  scanf("%d", &x);

  if(par(x)){ //pega o número e joga dentro da função
    printf("%d é par\n", x);
  } else{
    printf("%d é ímpar", x);
  }

  return 0;
}

int par(int x){
  if(x % 2 == 0){
    return 1; //1 para computador é verdadeiro
  } else {
    return 0; //0 para computador é falso
  }
}
