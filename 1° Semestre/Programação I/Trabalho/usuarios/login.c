/*implementação das funções, é o código*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

int autenticar(char *usuario, char *senha, Login *loginCompleto){
    //caso seja admin
    if(strcmp(usuario, "admin") == 0 && strcmp(senha, "admin123") == 0){
        strcpy(loginCompleto->usuario, usuario);
        loginCompleto->tipo = 1; //para admin
        return 1;
    }

    else if(strcmp(usuario, "aluno") == 0 && strcmp(senha, "aluno123") == 0){
        strcpy(loginCompleto->usuario, usuario);
        loginCompleto->tipo = 0; //aluno
        return 1;
    }

    return 0;
}

//separar para caso for usuário normal ou administrador
/*nesse caso devem ser 2 menus, um que apareçam funções apenas para o usuário,
e outro que irão aparecer funções apenas para o administrador*/
