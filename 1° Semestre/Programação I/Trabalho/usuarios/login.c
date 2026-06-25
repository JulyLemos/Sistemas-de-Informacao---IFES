/*implementação das funções, é o código*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

int autenticar(char *usuario, char *senha, Login *loginCompleto){
    FILE *fp = fopen(ARQUIVO_USUARIOS,"r");
    if (fp==NULL){
        printf("Nenhum usuário cadastrado ainda.\n");
        return 0;
    }

    Login temp;
    while (fscanf(fp,"%s %s %d", temp.usuario, temp.senha, &temp.tipo) ==3) {
        if (strcmp(usuario, temp.usuario) == 0 && strcmp(senha, temp.senha) == 0) {
            strcpy(loginCompleto->usuario, temp.usuario);
            loginCompleto->tipo = temp.tipo;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void cadastrarUsuario() {
    Login novo;
    char tipoDigitado[10];

    printf("\n=== Cadastrar novo usuário  ===\n");

    printf("\nNome de usuário: ");
    scanf("%s", novo.usuario);

    printf("\nDigite uma senha: ");
    scanf("%s", novo.senha);

    do {
        printf("\nTipo de usuário (admin/aluno): ");
        scanf("%s", tipoDigitado);
        getchar();

        if (strcmp(tipoDigitado, "admin") != 0 && strcmp(tipoDigitado, "aluno") != 0) {
            printf("Tipo inválido. Digite apenas \"admin\" ou \"aluno\".\n");
        }
    } while (strcmp(tipoDigitado, "admin") != 0 && strcmp(tipoDigitado, "aluno") != 0);

    if (strcmp(tipoDigitado, "admin") == 0) {
        novo.tipo = 1;
    } else {
        novo.tipo = 0;
    }

    FILE *fp = fopen(ARQUIVO_USUARIOS, "a");
    if (fp== NULL) {
        printf("\nErro ao acessar usuarios\n");
        return;
    }

    fprintf(fp, "%s %s %d\n", novo.usuario, novo.senha, novo.tipo);
    fclose(fp);

    printf(">> Usuário \"%s\" cadastrado com sucesso !\n", novo.usuario);

}

//separar para caso for usuário normal ou administrador
/*nesse caso devem ser 2 menus, um que apareçam funções apenas para o usuário,
e outro que irão aparecer funções apenas para o administrador*/
