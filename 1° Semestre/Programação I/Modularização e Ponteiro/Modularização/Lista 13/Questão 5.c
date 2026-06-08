/*05 - Faça uma função celsiusParaFahrenheit que receba uma temperatura em graus Celsius
(float) e retorne a temperatura convertida em Fahrenheit. Fórmula: F = C * 1.8 + 32. Na main,
leia uma temperatura e mostre a conversão.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

float celsiusParaFahrenheit(float celsius);

int main(){
  setlocale(LC_ALL, "");

  float temp;

  printf("Digite a temperatura em Celsius: ");
  scanf("%f", &temp);

  printf("A temperatura em Fahrenheit é %.2f", celsiusParaFahrenheit(temp));

  return 0;
}

float celsiusParaFahrenheit(float celsius){
  //float fah;

  return (celsius*1.8)+32;
}
