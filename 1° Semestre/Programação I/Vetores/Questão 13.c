/*13 - Dadas duas sequências com 5 números inteiros entre 0 e 9, calcular e armazenar a
sequência de números que representa a multiplicação das sequências anteriores. Por fim
imprimir as três sequências.
OBS.: Os vetores A e B deverão ser lidos pelo usuário. O vetor R será gerado pelo sistema.
Lembre-se que deve-se multiplicar a posição 0 do vetor A pela posição 4 do vetor B. E assim
por diante.*/

#include<ctype.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
  setlocale(LC_ALL, "");

  int vetorA[5], vetorB[5], vetorC[5], i;

  //números do vetor a
  for(i = 0; i<=4; i++){

    //printf("Digite o %d número: ", i);
    //scanf("%d", &vetorA[i]);

    vetorA[i] = rand() % 10;
    printf("\nVetor A: Número sorteado %d\n", vetorA[i]);
  }

  //sorteando números do vetor b
  for(i = 0; i<=4; i++){
    //printf("Digite o %d número:");
    //scanf("%d", &vetorB[i]);

    vetorB[i] = rand() % 10;
    printf("\nVetor B: Número sorteado %d\n", vetorB[i]);
  }

  //cálculo do vetor C
  for(i = 0; i <= 4; i++){
    vetorC[i] = vetorA[i] * vetorB[4-i]; /*é o tamanho do vetor menos o número atual
    na primeira iteraçao, vai ser vetorb[4-i], que é vetor[4-0] que é o último valor de vetorb, depois vetor[4-1]
    que vai ser o penúltimo valor do vetorb*/
  }

  //percorrendo vetores

  printf("\n\nNúmeros do vetor a");
  for(i = 0; i<=4; i++){
    printf("\n%d", vetorA[i]);
  }

  printf("\n\nNúmeros do vetor b");
  for(i = 0; i<= 4; i++){
    printf("\n%d", vetorB[i]);
  }

  printf("\n\nNúmeros do vetor c");
  for(i = 0; i<= 4; i++){
    printf("\n%d", vetorC[i]);
  }

  return 0;
}
