/*3) Faça um algoritmo que de 10 clientes leia seu nome, cidade, telefone e e-mail e armazene em uma
matriz (10,4). Após a leitura deve-se exibir uma pergunta pela posição da linha (registro). Ao informar
uma posição deve-se buscar e escrever na tela as informações do cliente informado na posição.*/

#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<time.h>

int main(){
  setlocale(LC_ALL, "");

  char dados[10][4][20]; //o 20 é um vtor que vai guardar cada letra das palavras que forem digitadas
  //é a capacidade máxima de caracteres que consegue digitar
  int i, reg;

  srand(time(NULL));

  for(i = 0; i<=9; i++){ //lê os campos da linha
    system("cls"); //limpa a tela

    printf("\tLendo o registro %d\n", i+1); //o \t faz a tabulação
    printf("Digite o nome: ");
    scanf("%[^\n]s", dados[i][0]); //aqui a coluna ja está especificada, não precisa de um outro for para percorrê-la
    printf("Digite a cidade: ");
    scanf("%s",  dados[i][1]); //então é: o cliente atual que está digitando [i] + a coluna de cidade [1]
    printf("Digite o telefone; ");
    scanf("%s", dados[i][2]);
    printf("Digite o email: ");
    scanf("%s", dados[i][3]);
    getchar();
  }

  do{
    printf("Digite o número do registro que deseja exibir (1 a 10):\n");  //pega o número do registro que desejas ver
    scanf("%d", &reg);
  } while (reg <= 0 || reg > 10); //se o numero digitado estiver nesse intervalo, ele recomeça o do

  printf("\n\tExibindo o registro %d\n \n", reg);
  printf("Nome %s: \n", dados[reg-1][0]);
  printf("Cidade %s: \n", dados[reg-1][1]);
  printf("Telefone %s: \n",dados[reg-1][2]);
  printf("Email %s: \n", dados[reg-1][3]);

  return 0;
}
