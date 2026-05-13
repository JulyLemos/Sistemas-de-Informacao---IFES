/*4 - Crie um programa que leia 8 números inteiros e armazene-os em um vetor. Em seguida,
peça ao usuário para escolher uma opção: 1 para mostrar os números em ordem crescente ou
2 para mostrar em ordem decrescente.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num[8], i, op, j, aux;

    for (i = 0; i < 8; i++){
        printf("Digite um número: ");
        scanf("%d", &num[i]);
    }



    printf("Digite uma opção:\n"
           "1 - Números em ordem decrescente\n"
           "2 - Números em ordem crescente\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            for(i = 0; i < 7; i++){
                for(j = 0; j < 7; j++){
                    if(num[j] < num[j+1]) {
                        aux = num[j];
                        num[j] = num[j+1];
                        num[j+1] = aux;
                    }
                }
            }
            break;
        case 2:
            for(i = 0; i < 7; i++){
                for(j = 0; j < 7; j++){
                    if(num[j] > num[j+1]) {
                        aux = num[j];
                        num[j] = num[j+1];
                        num[j+1] = aux;
                        }
                    }
                }
            break;

        default:
            printf("Não é válido.");

    }

    for (i = 0; i < 8; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
