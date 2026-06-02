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

    int num[10], opcao, cont_pares, cont_impares;
    float soma_pares, soma_impares;

    //leitura dos números digitados pelo usuário
    printf("Digite 10 números inteiros:\n");
    for(int i = 0; i < 10; i++) { //pode inicializar o i dentro do for, sem precisar ser no início
        scanf("%d", &num[i]);
    }

    do {
        printf("\n----Menu----\n"
               "1- Vetor na na ordem original\n"
               "2- Vetor na ordem inversa\n"
               "3- Média dos valores pares\n"
               "4- Média dos valores ímpares\n"
               "5- Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nVetor na ordem original: ");
                for(int i = 0; i < 10; i++){
                    printf("%d", num[i]);
                }
                printf("\n");
                break;

            case 2:
                for (int i = 9; i >= 0; i--){
                    printf("%d", num[i]);
                }
                printf("\n");
                break;

            case 3:
                soma_impares = 0, soma_pares = 0; //zerou eles dentro do case

                for(int i = 0; i < 10; i++){
                    if(num[i] % 2 == 0){
                        soma_pares +=num[i];
                        cont_pares++;
                    }
                }

                if(cont_pares > 0){
                    printf("Média dos valores pares: %.2f\n", soma_pares/cont_pares); //pode fazer o cálculo direto no printf
                } else {
                    printf("\nNão há valores pares no vetor.");
                }
                break;

            case 4:
                soma_impares = 0, cont_impares = 0; //zera os contadores

                for(int i = 0; i < 10; i++){ //percorre o vetor
                    if(num[i] %2 != 0) { //verifica números pares dentro do vetor
                        soma_impares += num[i];
                        cont_impares++;
                    }
                }

                if(cont_impares > 0) {
                    printf("\nMédia dos valores ímpares: %.2f \n", soma_impares/cont_impares);
                } else{
                    printf("\nNão há valores ímpares no vetor");
                }
                break;

            case 5:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválido! Tente novamente.");
        }
    } while(opcao != 5);

    return 0;
}
