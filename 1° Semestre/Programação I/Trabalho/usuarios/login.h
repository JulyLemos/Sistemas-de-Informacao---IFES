/*quais funções e estruturas existem, apenas*//*quais funções e estruturas existem, apenas*/

#ifndef LOGIN_H
#define LOGIN_H

#define ARQUIVO_USUARIOS "usuarios.txt"
#define MAX_USUARIOS 50

typedef struct { //estrutura para armazenar dados de login
    char usuario[20];
    char senha[20];
    int tipo; //0 para aluno, 1 para admin
} Login;

int autenticar(char *usuario, char *senha, Login *loginCompleto);
//a função, que vai receber o login e a senha, vai autenticar o usuário
//ponteiro para o endereço de memória do struct, que vai, ou foi preenchido
void cadastrarUsuario();

#endif
