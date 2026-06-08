/*11 - Implemente uma calculadora simples utilizando modularização. O programa deve possuir,
no mínimo, quatro funções: somar, subtrair, multiplicar e dividir, cada uma recebendo dois
números reais e retornando o resultado da operação. Na main:
• Exiba um menu com as opções (1-Somar, 2-Subtrair, 3-Multiplicar, 4-Dividir, 0-Sair). OK
• Leia a opção escolhida e os dois númerosOK.
• Utilize estrutura condicional (switch ou if/else) para chamar a função correspondente.
• Repita o menu até que o usuário escolha sair (estrutura de repetição).
• Trate divisão por zero exibindo uma mensagem de erro.*/

#include<ctype.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void exibirMenu();

float somar(float x, float y) {
     float resultado = x + y; //declaração direta
     //ou x = x + y;
    return resultado;
}
float subtrair(float x, float y) {
    float resultado = x - y;
    return resultado;
}
float multiplicar(float x, float y) {
    float resultado = x * y;
    return resultado;
}
float dividir(float x, float y) {
    float resultado = x/y;
    return resultado;
}

int main(){
    setlocale(LC_ALL, "");

    int op;
    float a, b, resultado;

    do {
        printf("Digite o valor de A:");
        scanf("%f, &a");
        printf("Digite o valor de B:");
        scanf("%f, &b");

        exibirMenu(); //procedimento -> exibir menu para o usuário


        do{
            printf("\nDigite sua opção: ");
            scanf("%d", &op);

            if (op == 0) {
                printf("Encerrando o sistema...");
            } else if (op < 1 || op > 4){
                printf("Opção inválida!");
            }
        } while (op < 0 || op > 4);

        if (op == 0) {
            printf("Encerrando o sistema...");
        } else{
            //fazer todo o cálculo
            switch(op){
            case 1:
                resultado = somar(a,b);
                break;

            case 2:
                resultado = subtrair(a,b);
                break;

            case 3:
                resultado = multiplicar(a,b);
                break;

            case 4:
                if (b == 0) {
                    printf("Impossível ter divisão por 0\n\n\n");
                } else {
                    resultado = dividir(a,b);
                } break;

            default:
                printf("Opção inválida.");
                break;
            }
            printf("O resultado da operação é: %.2f", resultado);
            printf("\n\n");

        }
    }while (op != 0);



    return 0;
}

void exibirMenu(){
    printf("\n\n\n_________ Menu__________\n");
    printf("\nDigite 1 para somar"
           "\nDigite 2 para subtrair"
           "\nDigite 3 para multiplicar"
           "\nDigite 4 para dividir"
           "\nDigite 0 para sair\n ");
}
