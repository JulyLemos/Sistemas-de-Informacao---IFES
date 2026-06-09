/*02 - Implemente a função classificarIMC que recebe o peso (kg) e a altura (m) de uma pessoa,
calcula o IMC = peso / (altura * altura) e imprime a faixa correspondente: “Abaixo do peso” (<
18.5), “Normal” (18.5 a 24.9), “Sobrepeso” (25 a 29.9), “Obesidade” (>= 30). Na main, leia peso
e altura e chame a função.
Repetição: Não necessita
Por quê? Esta questão não exige repetição: o cálculo é direto, baseado em entrada
única.
Condicional: if/else encadeados (else if)
Por quê? As faixas do IMC são intervalos contínuos com limites variados (não são
valores discretos), por isso o switch-case não se aplica bem.*/

#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

float classificarIMC(float kilos, float altura);

int main(){
  setlocale(LC_ALL, "");

  float kilos, altura;

  printf("Digite os kilos: ");
  scanf("%f", &kilos);
  printf("Digite a altura: ");
  scanf("%f", &altura);

  classificarIMC(kilos, altura);

  return 0;
}

float classificarIMC(float kilos, float altura){ //poderia ser void

  printf("IMC = %.2f\n", kilos/(altura*altura));

  if(kilos/(altura * altura) < 18.5f){
    return printf("Abaixo do peso");
  } else if(kilos/(altura * altura) < 25.0){
    return printf("Normal");
  } else if(kilos/(altura*altura) < 30.0){
    return printf("Sobrepeso");
  } else{
    printf("Obesidade");
  }
}