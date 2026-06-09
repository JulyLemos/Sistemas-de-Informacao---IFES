/*06 - Implemente uma função media que receba três notas (float) e retorne a média aritmética.
Na main, leia as três notas e exiba a média.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

float media(float n1, float n2, float n3);

int main(){
  setlocale(LC_ALL, "");

  float n1, n2, n3;

  printf("Digite a primeira nota: ");
  scanf("%f", &n1);
  printf("Digite a segunda nota: ");
  scanf("%f", &n2);
  printf("Digite a terceira nota: ");
  scanf("%f", &n3);

  printf("A media das notas é %.2f", media(n1,n2,n3));

  return 0;
}

float media(float n1, float n2, float n3){
  return (n1+n2+n3)/3.0f; //para entender que 3.0 é um float e que o programa não precisa transformar em double
}
