/*2) Escrever um algoritmo para ler uma matriz (7,4) contendo valores inteiros (supor que os valores são
distintos). Após, encontrar o menor valor contido na matriz e sua posição.
2.1) Desafio 1: Refaça o exercício anterior, porém garanta que o usuário insira somente números
diferentes na matriz.
2.2) Desafio 2: Refaça o exercício anterior, porém permita que o usuário insira números iguais.
Assim, ao final você deve informar o menor número e a(s) posição(es) em que ele se encontra*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int main(){
  setlocale(LC_ALL, "");

  int dados[7][4], l, c, auxL, auxC; //matriz, linha, coluna, auxiliares
  int menorValor = 0;
  int linMenorValor, colMenorValor; //linha e coluna do menor valor para dizer a posição do número
  int existe = 0;
  int auxValor;

  srand(time(NULL));

  //leitura da matriz
  for(l = 0; l< 7; l++){
      for(c = 0; c< 4; c++){
        do{
          existe = 0;
          auxValor = rand() % 40; //número para auxliar
          for(auxL = 0; auxL < l; auxL++){ //linha da matriz aux
            for(auxC = 0; auxC < c; auxC++){//coluna matriz aux
              if(auxValor == dados[auxL][auxC]){ //compara o valor de auxValor com o valor contido na posição aux de dados
                existe = 1;
                printf("Valor repetido: %d\n", auxValor);
              }
            }
          }
        } while(existe == 1);
          dados[l][c] = auxValor;
      }
  }

  //encontrando o menor valor
  menorValor = dados[0][0]; //primeiro número da matriz
  linMenorValor = 0; //inicializando
  colMenorValor = 0;

  for(l = 0; l < 7; l++){ //linha
    for (c = 0; c < 4; c++){ //coluna
      if(dados[l][c] < menorValor){
        menorValor = dados[l][c];
        linMenorValor = l;
        colMenorValor = c;
      }
    }
  }

  for (l = 0; l< 7; l++){
    for(c = 0; c < 4; c++){
      printf("%d   ", dados[l][c]);
    }
    printf("\n");
  }

  printf("\n\n");
  printf("Menor valor: %d\n"
         "Posição: [%d][%d]\n", menorValor, linMenorValor, colMenorValor);

  return 0;
}
