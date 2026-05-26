#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "");

    char nome[20];
    float av1, av2, rec, med;

    printf("Digite o seu nome: ");
    scanf(" %s", &nome);
    printf("Digite a nota da primeira avali��o: ");
    scanf("%f", &av1);
    printf("Digite a nota da segunda avali��o: ");
    scanf("%f", &av2);

    med = (av1 + av2)/2;


    if(med>=7.0){
        printf("%s, voc� ja est� aprovado com m�dia %.2f", nome, med);
    } else if (av1>av2 && med<7.0){
                rec = 14-av1;
                printf("%s, Voc� precisa tirar %.2f na REC para ser aprovado", nome, rec);
    } else {
            rec = 14-av2;
            printf("%s, Voc� precisa tirar %.2f na REC para ser aprovado", nome, rec);
    }


    return 0;
}

