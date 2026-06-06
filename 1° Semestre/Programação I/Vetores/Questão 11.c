/*11 - Escreva um algoritmo que leia um vetor A de 50 posições e escreva a posição de cada
elemento igual a 10 deste vetor*/

#include<ctype.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
    setlocale(LC_ALL,"");

    int num[50], i, qtd = 0;

    srand(time(NULL));

    for(i = 0; i <= 49; i++){
        //printf("Digite um valor para o num na posicao [%d]\n",i);
        //scanf("%d", &num[i]);
        //digitar um por um seria muito demorado

        // sortenado valores aleatorios
        num[i] = rand() % 15;
        printf("(%d) Numero sorteado: %d\n", i, num[i]);
    }
    // Pausa a tela
    system("pause");
    // Limpa a tela
    system("cls");

    for(i = 0; i <= 49; i++){ //percorre o vetor
        if (num[i] == 10){ //testa se o valor guardado é igual a 10
            printf("Numero igual a 10 encontrado na posicao: %d\n", i);
            qtd++;
        }
    }

    // Condicional para o caso de não encontrar nenhum numero 10
    if (qtd == 0){
        printf("Nenhum numero 10 encontrado!");
    }


    return 0;

}
