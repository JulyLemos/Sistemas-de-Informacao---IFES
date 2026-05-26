/*08 - Faça um programa que leia as notas de 5 alunos em 3 provas e armazene em um vetor.
Calcule a média de cada aluno e informe se o aluno foi aprovado (média >= 6.0), está em
recuperação (4.0 <= média < 6.0) ou reprovado (média < 4.0).*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"");

    float nota[5][3];
    float media[5] = {0};

    for(int i = 0; i < 5; i++){
        printf("Digite as 3 notas do aluno %d: \n", i+1);
        for(int j = 0; j < 3; j++){
            scanf("%f", &nota[i][j]);
            media[i] += nota[i][j];
        }
        media[i] /= 3;
    }

    printf("\nSituação dos alunos:\n");
    for(int i = 0; i < 5; i++) {
        printf("\nAluno %d - Média: %.2f - ", i+1, media[i]);

        if(media[i] >= 7.0) {
            printf("Aprovado");
        } else if(media[i] >= 5.0){
            printf("Recuperação");
        } else {
            printf("Reprovado");
        }
    }

    return 0;
}
