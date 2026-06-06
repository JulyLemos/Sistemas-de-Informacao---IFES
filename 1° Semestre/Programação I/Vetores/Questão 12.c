/*12 - Escrever um algoritmo que leia 50 números quaisquer e armazene em um vetor, um de
cada vez, e conta quantos deles estão em cada um dos intervalos [0,25], (25,50], (50,75],
(75,100].
12.1) Desafio: Garanta que o usuário só insira números no intervalo de 0 a 100. Ou seja,
valores abaixo de 0 e maiores que 100 não podem ser inseridos.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

/*  srand(time(NULL)) objetiva inicializar o gerador de numeros aleatorios
    com o valor da funcao time(NULL). Este por sua vez, é calculado
    como sendo o total  de segundos passados desde 1 de janeiro de 1970
    ate a data atual.
    Desta forma, a cada execucao o valor da "semente" sera diferente.
*/

int main(){
    setlocale(LC_ALL, "");

    int num[50], i, qtd0a25 = 0, qtd26a50 = 0, qtd51a75 = 0, qtd76a100 = 0;

    // explicacao acima ^
    srand(time(NULL));

    for(i = 0; i <= 49; i++){
        // caso queira digitar um por um
        /*do{
        printf("Digite um valor para o num na posicao [%d]\n",i);
        scanf("%d", &num[i]);
        }while((num[i] < 0) || (num[i] > 100));*/


        // sortenado valores aleatorios
        num[i] = rand() % 100; //limita o número ao intervalo que desejo
        printf("(%d) Numero sorteado: %d\n", i, num[i]);
    }
    // Pausa a tela
    system("pause");
    // Limpa a tela
    system("cls");

    for(i = 0; i <= 49; i++){ //o intervalo, a quantidade de números que tem no array
        if (num[i] <= 25){ //primeiro intervalo
            qtd0a25++; //contador
        }else
            if (num[i] <= 50){
                qtd26a50++;
            }else
                if (num[i] <= 75){
                    qtd51a75++;
                }else{
                    qtd76a100++;
                }
    }

    printf("Quantidade de Numeros entre 0 e 25: %d\n", qtd0a25);
    printf("Quantidade de Numeros entre 26 e 50: %d\n", qtd26a50);
    printf("Quantidade de Numeros entre 51 e 75: %d\n", qtd51a75);
    printf("Quantidade de Numeros entre 76 e 100: %d\n", qtd76a100);

    return 0;
}


