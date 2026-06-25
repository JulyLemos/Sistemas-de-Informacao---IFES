//José Luiz Gussani Nery, July Lemos da Silva, Kash V Fernandes Azevedo Rezende.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include "projeto/usuarios/login.h"
#include "projeto/funcoes/funcoes_guia.h"

int main(void) {

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Carrega os guias do arquivo (se não existir, começa vazio)
    Guia carregadas[MAX_GUIAS];
    int qtd = lerGuia(carregadas);
    printf(">> %d Guias carregada(s) do arquivo.\n", qtd);

    // Menu de acesso
    int escolhaInicial = -1;
    Login session;
    char logindigitado[20], senhadigitada[20];
    int autenticado = 0;

    do {
        printf("\n\e[1;94m*-*-*-*-*-*-*- Acesso -*-*-*-*-*-*-*\033[0m\n");
        printf(" 1 - Cadastrar novo usuário\n");
        printf(" 2 - Fazer login\n");
        printf("\e[1;31m 0 - Sair\033[0m\n");
        printf("Escolha: ");
        scanf("%d", &escolhaInicial);
        getchar();

        if (escolhaInicial == 1) {
            cadastrarUsuario();
        } else if (escolhaInicial == 2) {
            printf("\nUsuário: ");
            scanf("%s", logindigitado);
            printf("Senha: ");
            scanf("%s", senhadigitada);
            getchar();

            if (autenticar(logindigitado, senhadigitada, &session)) {
                autenticado = 1;
            } else {
                printf("\nLogin incorreto. Tente novamente.\n");
            }
        } else if (escolhaInicial != 0) {
            printf("Opcao inválida.\n");
        }

    } while (!autenticado && escolhaInicial != 0);

    if (!autenticado) {
        printf("\nEncerrando o programa.\n");
        return 0;
    }

    printf("\n\nLogin feito com sucesso, seja bem vindo, %s!\n", session.usuario);

    // Menu principal
    int opcao = -1;
    char termo[100];

    do {
        if (session.tipo == 1) { // MENU ADMIN
            printf("\n\e[1;94m============ MENU ADMIN ============\033[0m\n");
            printf("1 - Listar todas os guias\n");
            printf("2 - Pesquisar (digitar um termo)\n");
            printf("3 - Alterar um guia\n");
            printf("4 - Excluir uma guia\n");
            printf("5 - Criar novo guia\n");
            printf("6 - Cadastrar novo usuário\n");
            printf("\e[1;31m0 - Sair\033[0m\n");
            printf("Escolha uma opção: ");

            scanf("%d", &opcao);
            getchar();

            if (opcao == 1) {
                for (int i = 0; i < qtd; i++) imprimirGuia(carregadas[i]);
            } else if (opcao == 2) {
                printf("\nDigite o que deseja pesquisar: ");
                fgets(termo, 100, stdin);
                removerQuebraLinha(termo);
                pesquisarTexto(carregadas, qtd, termo);
            } else if (opcao == 3) {
                alterarGuia(carregadas, qtd);
                gravarGuia(carregadas, qtd);
            } else if (opcao == 4) {
                excluirGuia(carregadas, &qtd);
                gravarGuia(carregadas, qtd);
            } else if (opcao == 5) {
                criarGuia(carregadas, &qtd);
                gravarGuia(carregadas, qtd);
            } else if (opcao == 6) {
                cadastrarUsuario();
            } else if (opcao != 0) {
                printf("\nOpção inválida.\n");
            }

        } else { // MENU ALUNO
            printf("\n\e[1;94m============ MENU ALUNO ============\033[0m\n");
            printf("1 - Listar todas os guias\n");
            printf("2 - Pesquisar (digitar um termo)\n");
            printf("\e[1;31m0 - Sair\033[0m\n");
            printf("Escolha uma opção: ");

            scanf("%d", &opcao);
            getchar();

            if (opcao == 1) {
                for (int i = 0; i < qtd; i++) imprimirGuia(carregadas[i]);
            } else if (opcao == 2) {
                printf("\nDigite o que deseja pesquisar: ");
                fgets(termo, 100, stdin);
                removerQuebraLinha(termo);
                pesquisarTexto(carregadas, qtd, termo);
            } else if (opcao != 0) {
                printf("Opção inválida.\n");
            }
        }

    } while (opcao != 0);

    printf("\nEncerrando o programa.\n");
    return 0;
}
