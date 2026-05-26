/*09 - Crie um programa que simule um sistema de votação. O programa deve permitir que o
usuário vote em um de 3 candidatos (código 1, 2 e 3) ou vote em branco (código 0). Ao final,
mostre o total de votos de cada candidato e a porcentagem de votos em branco. O programa
deve encerrar quando for digitado um número negativo para o código do candidato.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "");

    int voto, cand1 = 0, cand2 = 0, cand3 = 0, nulo = 0;

    do {
        printf("\nEscolha um candidato que deseja votar:"
               "\n1 - Candidato 1"
               "\n2 - Candidato 2"
               "\n3 - Candidato 3"
               "\n0 - Voto em branco\n");
        scanf(" %d", &voto);

        switch (voto) {
            case 1:
                cand1++;
                break;
            case 2:
                cand2++;
                break;
            case 3:
                cand3++;
                break;
            case 0:
                nulo++;
                break;

        }

    } while (voto >= 0);

     printf("\nVotos no candidato 1: %d"
               "\nVotos no candidato 2: %d"
               "\nVotos no candidato 3: %d"
               "\nVotos em branco: %d\n", cand1, cand2, cand3, nulo);



    return 0;
}
