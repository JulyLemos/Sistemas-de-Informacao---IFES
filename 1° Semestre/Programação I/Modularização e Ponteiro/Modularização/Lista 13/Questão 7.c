/*07  - Crie uma função areaRetangulo que receba a base e a altura de um retângulo ( float) e
retorne sua área. Na main, leia os valores e mostre a área calculada pela função*/

#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float areaRetangulo(float base, float altura);

int main(){
  setlocale(LC_ALL,"");

  float base, altura;

  printf("Digite a base do retângulo: ");
  scanf("%f", &base);
  printf("Digite a altura do retângulo: ");
  scanf("%f", &altura);

  printf("A área do retângulo é %.2f", areaRetangulo(base, altura));

  return 0;
}

float areaRetangulo(float base, float altura){

  return base*altura;
}
