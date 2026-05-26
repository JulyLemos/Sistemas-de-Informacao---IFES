//Desenvolva um programa para o estacionamento pago de uma universidade que:
//1. Solicite o tipo de usu�rio (E-Estudante, S-Servidor, V-Visitante) - OK
//2. Pe�a o tempo de perman�ncia em horas (aceite valores decimais, ex: 2.5) - ok
//3. Use switch-case para definir a tarifa conforme o tipo de usu�rio:- Estudante:  - OK
//primeiras 2 horas gratuitas, depois R$ 3 por hora- - OK
//Servidor: primeiras 3 horas gratuitas,
//depois R$ 2 por hora- Visitante: R$ 5 por hora desde a entrada
//4. Calcule o valor a pagar conforme as regras acima
//5. Aplique um desconto de 20% se o pagamento for realizado at� as 18h
//(pergunte ao usu�rio se o pagamento ser� feito antes das 18h)
//O programa deve exibir o valor exato a ser pago com duas casas decimais.
//Formato de sa�da: "Valor a pagar: R$ [VALOR]

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main (){
    setlocale(LC_ALL, "");

    float tp, ph, hora;
    char usuario;

    printf("Tipo de usu�rio: ");
    scanf(" %c", &usuario);
    printf("Tempo de perman�ncia: ");
    scanf("%f", &tp);
    printf("Hor�rio do pagamento: ");
    scand("%f", &hora);

    switch (tolower(usuario)) {
        case 'e':
            ph = tp - 2;
            if (hora<=18){
                ph = ph * 3;
                ph = ph * 0.8;
                printf("O valor a ser paga de estacionamento � de R$%.2f", ph);
            } else {
                ph=ph*3;
                printf("O valor a pagar � de R$.2f", ph);
            }
        case 's':
            ph = ph - 3;
            ph =
        case 'v':
    }

    return 0;
}
