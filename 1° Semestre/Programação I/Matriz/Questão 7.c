/*) Sabendo-se da existência da matriz abaixo:
1 2 3 4 5 6 7 8 9
A B C D E F G H I
J K L M N O P Q R
S T U V W X Y Z
Leia um número aleatório “tam” que corresponde ao tamanho da palavra a ser montada. Logo após, você
deve ler um número aleatório para linha e outro para coluna até que complete o tamanho total “tam”. Por
fim você deve exibir a palavra montada. Para ler um número aleatório, utilize a função rand() e srand().
Observe que a coluna 9 só possui 2 linhas, assim você deve tratar isso.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<string.h>
#include<time.h>

int main(){
    char quadro[3][10] = {{""}};
    char alfabeto[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int l, c, i = 0, tam;

    for (l = 0; l < 3; l++){
        for (c = 0; c < 9; c++) {
            quadro[l][c] = alfabeto[i];
            i++;
        }
    }
     srand(time(NULL));
     printf("Digite o tamanho da palavra: ");
     scanf(" %d", &tam);

     char palavra[tam + 1];

     for ( i = 0; i < tam; i++){
        l = rand() % 3;
        if (l == 2){
            c = rand() % 8;
        } else {
            c = rand() % 9;
        }
        palavra[i] = quadro[l][c];

     }
        palavra[tam] = '\0';
        printf(" %s", palavra);


     return 0;

}
