/*04 - Crie uma função maiorEntreDois que receba dois números reais (float) e retorne o maior
deles. Na main, leia dois valores e exiba o maior usando a função.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

float maiorEntreDois(float x, float y);

int main(){
  setlocale(LC_ALL, "");

  float x, y;

  printf("Digite o primeiro número: ");
  scanf("%f", &x);
  printf("Digite o segundo número: ");
  scanf("%f", &y);

  printf("%.2f é maior", maiorEntreDois(x,y));

  return 0;
}

float maiorEntreDois(float x, float y){
  if(x > y){
    return x;
  } else {
    return y;
  }
}
