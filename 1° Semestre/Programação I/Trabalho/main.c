#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//importando as funções de login dos usuarios
#include "usuarios/login.h"

#define MAX 100
#define Arquivo "guias.txt"
//struct das guias

typedef struct {  //estrutura de armazenamento de informações das guias
    char titulo[50];
    char materia[50];
    char autor[50];
    int data;
    char livro[50];
    char conteudo[MAX];
} Guias; 

void removerQuebraLinha(char texto[]){ //remove a quebra delinha no final
    texto[strcspn(texto, "\n")] = '\0';
}

void menuAdmin(){}
void menuAluno(){}


int main(){
    char logindigitado[20], senhadigitada [20];
    Login session;

    printf("*-*------Login------*-*\n"
           "\n"
           "Usuário: %s"
           "\n"
           "Senha: %s");
    scanf("%s %s", logindigitado, senhadigitada);

    if(autenticar(logindigitado, senhadigitada, &session)){ //vai rodar a função
        printf("\n\nLogin feito com sucesso, seja bem vinde");

        if( session.tipo == 1){
            menuAdmin(); //chama a função de menu do admin
        }

        else if( session.tipo == 0){
            menuAluno(); //chama a função de menu do aluno
        }

    }
     else{
        printf("\n\nLogin incorreto.");
     }

}

