/*2) Escrever um algoritmo para ler uma matriz (7,4) contendo valores inteiros (supor que os valores são
distintos). Após, encontrar o menor valor contido na matriz e sua posição.
2.1) Desafio 1: Refaça o exercício anterior, porém garanta que o usuário insira somente números
diferentes na matriz.
2.2) Desafio 2: Refaça o exercício anterior, porém permita que o usuário insira números iguais.
Assim, ao final você deve informar o menor número e a(s) posição(es) em que ele se encontra*/

#include<ctype.h>
#include<locale.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
  setlocale(LC_ALL, "");

  int l = 0, c = 0, m[7][4], menor, plmenor, pcmenor;

  for ( l = 0; l <=6; l++){ //linha
    for(c = 0; c<= 3; c++){ //coluna
      printf("Digite o número inteiro da posição [%d,%d] da matriz:\n", l, c);
      scanf("%d", &m[l][c]);
    }
  }

  printf("\nA matriz é \n\n"); //imprimir a matriz

  for(l = 0; l<=6; l++){ //linha
    for(c = 0; c<=3; c++){ //coluna
      printf("%d   ", m[l][c]); //imprime linha por linha
    }
    printf("\n"); //pula
  }

  menor = m[0][0]; //o menor valor é o primeiro valor da matriz

  plmenor = 0, pcmenor = 0; //inicializa os valores

  for(l = 0; l<= 6; l++){ //linha
    for(c = 0; c<=3; c++){ //coluna
      if(m[l][c] < menor){ //se o valor da posição l-c for menor que o 'menor'
        menor = m[l][c]; //menor vai guardar esse valor
        plmenor = l; //vai guardar a linha em que ele está
        pcmenor = c; //e vai guardar a coluna em que ele está
      }
    }
  }

  printf("\n");
  printf("\nO menor valor é %d na posição [%d][%d]", menor, plmenor, pcmenor);

  return 0;
}
