/*) Sabendo-se que as letras do alfabeto são representadas pelos números abaixo:
0 1 2 3 45 6 7 8 9
A B C D E F G H I J
K L M N O P Q R S T
U V W X Y Z -
Faça um algoritmo que leia um nome e mostre o somatório das letras do nome com base no quadro acima.
Para facilitar, utilize a função “strlen()” para descobrir a quantidade de caracteres de uma palavra. Ao
final imprima a seguinte mensagem: “Fulano possui somatório Y”, onde Y é a soma descoberta.*/

#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>

int main(){
  setlocale(LC_ALL, "");

  char nome[20], letra;
  int tam, i, soma = 0;

  printf("Digite um nome: ");
  scanf("%[^\n]s", nome);

  tam = strlen(nome); //vai pegar o tamanho do nome

  for(i = 0; i < tam; i++){
    letra = nome[i];
    switch(letra){
      case 'a':
      case 'k':
      case 'u':
        soma+=0;
        break;
      case 'b':
      case 'l':
      case 'v':
        soma+=1;
        break;
      case 'c':
      case 'm':
      case 'w':
        soma+=2;
        break;
      case 'd':
      case 'n':
      case 'x':
        soma+=3;
        break;
      case 'e':
      case 'o':
      case 'y':
        soma+=4;
        break;
      case 'f':
      case 'p':
      case 'z':
        soma+=5;
        break;
      case 'g':
      case 'q':
        soma+=6;
        break;
      case 'h':
      case 'r':
        soma+=7;
        break;
      case 'i':
      case 's':
        soma+=8;
        break;
      case 'j':
      case 't':
        soma+=9;
        break;
      default:
        printf("Encontrado espaço ou caracter especial\n");
        break;
    }
  }

  printf("\nSoma é: %d", soma);

  return 0;
}
