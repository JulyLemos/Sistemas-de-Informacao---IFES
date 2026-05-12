/*02 - Faça um programa que leia a temperatura média de cada mês do ano, armazenando-as
em um vetor. Em seguida, calcule a média anual das temperaturas e mostre todas as
temperaturas acima da média anual, e em que mês elas ocorreram (mostrar o mês por
extenso: janeiro, fevereiro, ...).
Dica: Crie os meses assim: char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio",
"Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>2

int main() {
    setlocale(LC_ALL, "Portuguese");

    float temp[12],media, soma;
    int i;
    char *meses[] = {"Janeiro","Fevereiro", "Março", "Abril", "Maio","Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    for (i = 0; i < 12; i++){
        printf("Digite a temperatura do mês de %s: ", meses[i]);
        scanf("%f", &temp[i]);
        soma += temp[i];
    }

    printf("\nA média anual é de: %.2f \n", (media = soma/12));

    for (i = 0; i < 12; i++){
        if (temp[i] > media){
            printf("%s: %.2f°C\n", meses[i], temp[i]);
        }
    }

    return 0;
}
