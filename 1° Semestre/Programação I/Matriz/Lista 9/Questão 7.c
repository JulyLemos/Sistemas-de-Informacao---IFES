/* 7) Sabendo-se da existência da matriz abaixo:
1 2 3 4 5 6 7 8 9
A B C D E F G H I
J K L M N O P Q R
S T U V W X Y Z
Leia um número aleatório “tam” que corresponde ao tamanho da palavra a ser montada. Logo após, você
deve ler um número aleatório para linha e outro para coluna até que complete o tamanho total “tam”. Por
fim você deve exibir a palavra montada. Para ler um número aleatório, utilize a função rand() e srand().
Observe que a coluna 9 só possui 2 linhas, assim você deve tratar isso.*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>// necessario p/ as funçoes rand() e srand()
#include <time.h>//necessario p/ funçao time()

/*  srand(time(NULL)) objetiva inicializar o gerador de numeros aleatorios
    com o valor da funçao time(NULL). Este por sua vez, é calculado
    como sendo o total  de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execuçao o valor da "semente" sera diferente.
*/

int main(){
    int tam, qtd=0,l,c,i,j,cont=0; //tamanho, quantidade, linha, coluna, contadores

    // inicializando a matriz com valores nulos
    char letra, vLetras[3][10] = {{""}};

    // inicializando o vetor com valores nulos
    char alfabeto[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0"; // o 0 indica o fim da palavra

    // explicacao acima ^
    srand(time(NULL));

    // montando a matriz do alfabeto
    for (i=0; i<=2; i++) {
       for (j=0; j<=8; j++) {
            letra = alfabeto[cont]; //a letra recebe o valor do alfabeto na posiçao cont, que começa em 0, ou seja, a letra A
            vLetras[i][j] = letra; //a letra é atribuida a matriz vLetras na posiçao i,j, ou seja, a letra A é atribuida a posiçao 0,0 da matriz
            cont++;
       }
    }

    printf("Digite o tamanho da palavra a ser montada: \n");
    scanf("%d", &tam);

    // criando o vetor que vai armazenar a palavra criada. 1 unidade a mais para o \0, que indica o fim da palavra
    char nome[tam+1];

    do {
        /*
        printf("Digite a linha:\n");
        scanf("%d",&l);
        printf("Digite a coluna:\n");
        scanf("%d",&c);
        */

        // sorteando valor para l de 0 a 2
        l = rand() % 3;
        if (l != 2){
            // sorteando valor de 0 a 8
            c = rand() % 9; //caso não for a linha 2, nesse caso será ou a 0 ou a 1, onde tem letras a mais
        }else{
            // sorteando valor de 0 a 7
            c = rand() % 8; //nesse caso, é a linha 2, onde tem menos letras
        }
        printf("(%d) | Linha %d Coluna %d | Letra: %c\n", qtd, l, c, vLetras[l][c]);
        // atribuindo a letra a palavra nome
        nome[qtd] = vLetras[l][c];
        qtd++;

    } while (qtd < tam);

    // indicando que terminamos a edicao do nome, assim, colocamos o \0 para indicar o fim da palavra
    nome[tam] = '\0';
    printf("Palavra: %s", nome);

    return 0;
}
