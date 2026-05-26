//terminar 

/*10 - Desenvolva um programa que leia um vetor de 10 números inteiros. Em seguida,
implemente um menu com as seguintes opções:
1. Mostrar o vetor na ordem original
2. Mostrar o vetor na ordem inversa
3. Calcular a média dos valores pares
4. Calcular a média dos valores ímpares
5. Sair do programa*/

#include<ctype.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    setlocale(LC_ALL, "");

    int num[10];

    for (int i = 0; i < 10; i++){
        printf("Digite o %d número: ", i);
        scanf(" %d", &num[i]);
    }

    do {
        
    }

    return 0;
}
