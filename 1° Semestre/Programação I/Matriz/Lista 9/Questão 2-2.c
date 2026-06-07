/*2) Escrever um algoritmo para ler uma matriz (7,4) contendo valores inteiros (supor que os valores são
distintos). Após, encontrar o menor valor contido na matriz e sua posição.
2.1) Desafio 1: Refaça o exercício anterior, porém garanta que o usuário insira somente números
diferentes na matriz.
2.2) Desafio 2: Refaça o exercício anterior, porém permita que o usuário insira números iguais.
Assim, ao final você deve informar o menor número e a(s) posição(es) em que ele se encontra.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL, "");

  int dados[7][4], l, c, cont = 0, x = 0; //matriz, linha, coluna, contador
  int menorValor = 0; //menor valor da matriz
  int linMenorValor[28], colMenorValor[28]; //vetors para guardar os menores valores que podem ser iguais
  srand(time(NULL));

  //lendo a matriz
  for(l = 0; l < 7; l++){ //linha
    for(c = 0; c < 4; c++){ //coluna
      dados[l][c] = rand() % 40; //limita os números a um intervalo
    }
  }

  //encontrando o menor valor
  for(l = 0; l < 7; l++){ //linha
    for(c = 0; c< 4; c++){ //coluna
      //caso seja o primeiro valor
      if(l == 0 && c == 0){
        menorValor = dados[0][0]; //vai pegar o primeiro valor da matriz e vira referência
        linMenorValor[cont] = 0;
        colMenorValor[cont] = 0;
      } else{ //demais valores
        if(dados[l][c] < menorValor){ //vai comparar os valores com menorValor que tinha antes
          menorValor = dados[l][c]; //se for, atualiza com esse novo número
          cont = 0; //reinicia o contador
          linMenorValor[cont] = l; //a linha em que o valor está
          colMenorValor[cont] = c; //a coluna que o valor está
        }else if(dados[l][c] ==  menorValor){ //caso seja um valor repetido
          cont++; //guarda
          linMenorValor[cont] = l; //salva a linha
          colMenorValor[cont] = c; //salva a coluna
        }
      }
    }
  }

  //imprimindo a matriz
  for(l = 0; l < 7; l++){ //linha
    for(c = 0; c< 4; c++){ //coluna
      printf("%d   ", dados[l][c]);
    }
    printf("\n");
  }

  printf("\n\n"
         "Menor valor: %d\n", menorValor);

  //vai rodar até a posiçao final de cont
  while (x <= cont){
    printf("Posição: [%d][%d]\n", linMenorValor[x], colMenorValor[x]);
    x++;
  }

  return 0;
}
