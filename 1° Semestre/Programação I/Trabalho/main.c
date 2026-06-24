#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//define a constante para essa versão se ainda não foi definida.
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

//importando as funções de login dos usuarios
#include "usuarios/login.h"

//importar funções dos menus
#include "funcoes/funcoes_guia.h"



int main(void){

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    char logindigitado[20], senhadigitada [20];
    Login session;

    Guia catalogo[MAX_GUIAS];

    strcpy(catalogo[0].nome, "Pampas");
    strcpy(catalogo[0].materia, "Geografia");
    strcpy(catalogo[0].autor, "Diêgo Cavalcante");
    catalogo[0].data = 5;
    strcpy(catalogo[0].conteudo, "Pampas é lorem ipsum");
    strcpy(catalogo[0].livro, "Brasil: um país de todos os biomas.");


    strcpy(catalogo[1].nome, "Termodinâmica");
    strcpy(catalogo[1].materia, "Física");
    strcpy(catalogo[1].autor, "Maria Cardoso");
    catalogo[1].data = 12;
    strcpy(catalogo[1].conteudo, "Nós temos a dilatação...");
    strcpy(catalogo[1].livro, "Física elementar");


    int total = 2;

    /* ---- Grava (cria o arquivo) e depois le de volta ---- */
    gravarGuia(catalogo, total);

    Guia carregadas[MAX_GUIAS];
    int qtd = lerGuia(carregadas);
    printf(">> %d Guias carregada(s) do arquivo.\n", qtd);

    //menu interativo
    printf("\n\033[0;35m*-*-*-*-*-*-*- Login -*-*-*-*-*-*-*\033[0m\n");
    printf("Digite o Usuário e a Senha (separados por espaço): ");
    scanf("%s %s", logindigitado, senhadigitada);
    getchar();

    // Tenta autenticar o usuário
    if (autenticar(logindigitado, senhadigitada, &session)) {
        printf("\n\nLogin feito com sucesso, seja bem vinde, %s!\n", session.usuario);

        int opcao = -1; // Inicializa a variável de opção do menu
        char termo[100];

        // LOOP DO MENU INTERATIVO
        do {
            if (session.tipo == 1) { // --- MENU DO ADMIN ---
                printf("\n============ MENU ADMIN ============\n");
                printf("1 - Listar todas os guias\n");
                printf("2 - Pesquisar (digitar um termo)\n");
                printf("3 - Alterar um guia\n");
                printf("4 - Excluir uma guia\n");
                printf("5 - Criar novo guia\n");
                printf("0 - Sair\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &opcao);
                getchar();

                if (opcao == 1) {
                    for (int i = 0; i < qtd; i++) {
                        imprimirGuia(carregadas[i]);
                    }
                } else if (opcao == 2) {
                    printf("Digite o que deseja pesquisar: ");
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
                } else if (opcao != 0) {
                    printf("Opcao invalida.\n");
                }
            }
            else if (session.tipo == 0) { // --- MENU DO ALUNO ---
                printf("\n============ MENU ALUNO ============\n");
                printf("1 - Listar todas os guias\n");
                printf("2 - Pesquisar (digitar um termo)\n");
                printf("0 - Sair\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &opcao);
                getchar();

                if (opcao == 1) {
                    for (int i = 0; i < qtd; i++) {
                        imprimirGuia(carregadas[i]);
                    }
                } else if (opcao == 2) {
                    printf("Digite o que deseja pesquisar: ");
                    fgets(termo, 100, stdin);
                    removerQuebraLinha(termo);
                    pesquisarTexto(carregadas, qtd, termo);
                } else if (opcao != 0) {
                    printf("Opcao invalida.\n");
                }
            }

        } while (opcao != 0); // Continua no menu até digitar 0

    } else {
        // Esse else agora pertence perfeitamente ao 'if (autenticar...)' lá de cima
        printf("\n\nLogin incorreto. Acesso negado.\n");
    }

    printf("\nEncerrando o programa.\n");
    return 0;
}
