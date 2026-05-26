/*07 - Crie um programa que leia 15 números inteiros e armazene em um vetor. - OK
Em seguida, peça ao usuário para escolher uma das opções: 1 para mostrar apenas os números positivos, 2
para mostrar apenas os negativos ou 3 para mostrar a soma de todos.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<string.h>

int main (){
    setlocale(LC_ALL, "");

    int num[15], i, pos = 0, neg = 0, soma = 0, op;

    for (i = 0; i<15; i++){
        printf("Digite um número: ");
        scanf(" %d", &num[i]);
    }

    printf("Digite uma opção:"
           "\n1- Mostrar números positivos."
           "\n2- Mostrar números negativos."
           "\n3- Soma dos números.\n");
    scanf(" %d", &op);

    switch(op){
        case 1:
            for (i = 0; i<15; i++){
                if (num[i]>=0){
                    printf("\n %d", num[i]);
                }
            }
            break;

        case 2:
            for (i = 0; i<15; i++){
                if(num[i]<0){
                    printf(" %d", num[i]);
                }
            }
            break;

        case 3:
            for (i = 0; i<15; i++){
                    soma = soma + num[i];
            }
             printf("%d", soma);
            break;
    }

    return 0;
}
