/*1) Escrever um algoritmo para armazenar valores inteiros em uma matriz dados(5,6). A seguir, calcular a
média dos valores pares contidos na matriz e escrever seu conteúdo*/

#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>

int main(){
  setlocale(LC_ALL, "");

  int matr[5][6];
  float qtdpar = 0, media =0;

  //números que farão parte da matriz
  for (int i = 0; i <= 4; i++){ //primeiro a linha
    for (int t = 0; t <= 5; t++){ //segundo a coluna
      matr[i][t] = rand() % 20; //números aleatórios para a matriz na linha e na coluna
      printf("%d   ", matr[i][t]); //printa os números da primeira linha
    }
    printf("\n"); //pula linha quando acabar os elementos da linha que foi printada
  }

  //decisão para saber quais números são pares
  for (int i = 0; i <= 4; i++){
    for (int t = 0; t <= 5; t++){
      if(matr[i][t] % 2 == 0){
        printf("\nValores pares: %d", matr[i][t]);
        media = media + matr[i][t];
        qtdpar++;
      }
    }
  }

   media = media/qtdpar;
   printf("\nMedia do valores pares: %.2f\n\n", media);
   
   return 0;

}
