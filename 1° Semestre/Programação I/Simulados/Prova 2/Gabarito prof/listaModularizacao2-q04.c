/* Questao 04 - Validar senha numerica de 4 digitos
   Repeticao: do-while | Condicional: if                             */
#include <stdio.h>

int lerSenhaValida();

int main() {
    int senha = lerSenhaValida();
    printf("Senha aceita: %d\n", senha);
    return 0;
}

int lerSenhaValida() {
    int senha;
    do {
        printf("Digite uma senha de 4 digitos (1000 a 9999): ");
        scanf("%d", &senha);

        if (senha < 1000 || senha > 9999) {
            printf("Senha invalida! Tente novamente.\n");
        }
    } while (senha < 1000 || senha > 9999);

    return senha;
}
