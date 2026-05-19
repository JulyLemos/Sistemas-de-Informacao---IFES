/*05 - Faça um programa que leia 10 números inteiros e armazene em um vetor. - OK*/
/* Em seguida,peça ao usuário para digitar um número - OK*/
/* e verifique se este número está no vetor, mostrando em qual posição ele foi encontrado.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<string.h>

int main(){
    setlocale(LC_ALL, "");

    int num[10];
    int encontrado = 0, verif, i;

    for (i = 0; i < 10; i++){
        printf("Digite um número: ");
        scanf(" %d", &num[i]);
    }

    printf("\n\nDigite um número para ser buscado no vetor: ");
    scanf(" %d", &verif);

    for (i = 0; i < 10; i ++){
        if(num[i] == verif){
            printf("O número %d foi encontrado na posição %d. \n", verif, i);
            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("O número %d não foi encontrado no vetor", verif);
    }

    return 0;
}
