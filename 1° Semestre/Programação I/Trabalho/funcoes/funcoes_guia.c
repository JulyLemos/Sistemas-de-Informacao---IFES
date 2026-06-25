#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_guia.h"

void removerQuebraLinha(char texto[]){ //remove a quebra de linha no final
    texto[strcspn(texto, "\n")] = '\0';
}

//função gravar, para escrever no arquivo, w escreve, r lê
void gravarGuia(Guia catalogo[], int n){
    FILE *fp = fopen(ARQUIVO, "w");
    if (fp == NULL){
        printf("Erro: não foi possível abrir o arquivo para escrevê-lo");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s\n", catalogo[i].nome); //é basicamente o printf, porém, opera com arquivo, fp é um ponteiro de arquivo
        fprintf(fp, "%s\n", catalogo[i].materia);
        fprintf(fp, "%s\n", catalogo[i].autor);
        fprintf(fp, "%d\n", catalogo[i].data);
        fprintf(fp, "%s\n", catalogo[i].conteudo);
        fprintf(fp, "%s\n", catalogo[i].livro);
    }

    fclose(fp); //fecha o arquivo em que o ponteiro está aberto, complemento de fopen
    printf("Arquivo \"%s\" atualizado (%d guias). \n", ARQUIVO, n);
}

//leitura, vai carregar o arquivo com r de read
int lerGuia(Guia catalogo[]) {
    FILE *fp = fopen(ARQUIVO, "r");

    if (fp == NULL){
        printf("O arquivo \"%s\" ainda não existe.\n", ARQUIVO);
        return 0;
    }

    int n = 0;
    char linha[200];
    while (fgets(catalogo[n].nome, 50, fp) != NULL) {
        removerQuebraLinha(catalogo[n].nome);
        if (strlen(catalogo[n].nome) == 0) continue; //strlen retorna o comprimento da string
        //se estiver vazio, pula

        fgets(catalogo[n].materia, 20, fp);
        removerQuebraLinha(catalogo[n].materia);

        fgets(catalogo[n].autor, 50, fp);
        removerQuebraLinha(catalogo[n].autor);

        fgets(linha, 200, fp); catalogo[n].data = atoi(linha);

        fgets(catalogo[n].conteudo, 200, fp);
        removerQuebraLinha(catalogo[n].conteudo);

        fgets(catalogo[n].livro, 50, fp);
        removerQuebraLinha(catalogo[n].livro);

        n++;
        if (n >= MAX_GUIAS) break;
    }

    fclose(fp);
    return n;
}

//imprime uma selecao de forma organizada
void imprimirGuia(Guia g){
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\nTema..............: %s\n", g.nome);
    printf("Matéria.............: %s\n", g.materia);
    printf("Autor...............: %s\n", g.autor);
    printf("Data de Publicação..: %d\n", g.data);
    printf("Conteúdo do Guia....: %s\n", g.conteudo);
    printf("Catálogo............: %s\n", g.livro);
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}


//Pesquisa exata, em que o nome é igual
//strcmp(a, b) == 0  significa que as duas palavras sao IGUAIS
int pesquisarPorNome(Guia catalogo[], int n, char alvo[]){
    for (int i = 0; i < n; i++){
        if(strcmp(catalogo[i].nome, alvo) == 0){
            return i;
        }
    }
    return -1; // não encontrado
}

//Pesquisa por texto
//strstr(campo, termo) devolve != NULL quando o termo aparece no campo.
//Observacao: e sensivel a maiusculas/minusculas ("Brasil" != "brasil").
void pesquisarTexto(Guia catalogo[], int n, char termo[]) {
    int encontrou = 0;

    for (int i = 0; i < n; i++){
        if (strstr(catalogo[i].nome, termo) != NULL ||
            strstr(catalogo[i].materia, termo) != NULL ||
            strstr(catalogo[i].autor, termo) != NULL ||
            strstr(catalogo[i].conteudo, termo) != NULL ||
            strstr(catalogo[i].livro, termo) != NULL) {
                imprimirGuia(catalogo[i]);
                encontrou = 1;
            }
    }
    if (!encontrou) {
        printf("Nada encontrado para \"%s\". \n", termo);
    }
}

//Alteração de dados
//1 - achar a seleçao pelo nme, 2-ler os dados e gravar no vetor
//lê um novo texto; se estiver vazio(só enter), mantem o valor atual
void lerCampoTexto(char destino[], int tamanho){
    char buffer[200];
    fgets(buffer, 200, stdin);
    removerQuebraLinha(buffer);
    if (strlen(buffer) > 0){ //caso digitou algo, troca
        strncpy(destino, buffer, tamanho - 1);
        destino[tamanho - 1] = '\0';
    }
    //se não digitou, o destino continua com valor antigo
}

void alterarGuia(Guia catalogo[], int n){
    char alvo[50];

    printf("\nDigite o nome da guia que deseja alterar: ");
    fgets(alvo, 50, stdin);
    removerQuebraLinha(alvo);

    int pos = pesquisarPorNome(catalogo, n, alvo);
    if (pos == -1) {
        printf("\nGuia \"%s\" não encontrada. \n", alvo);
        return;
    }

    printf("\nGuia encontrada. Dados atuais: \n");
    imprimirGuia(catalogo[pos]);

    printf("\nDigite os novos dados(ou apenas enter para manter o atual):\n");

    char linha[200];

    printf("\nNovo nome.........:");
    lerCampoTexto(catalogo[pos].nome, 50);

    printf("\nNova matéria: ");
    lerCampoTexto(catalogo[pos].materia, 20);

    printf("\nNovo autor: ");
    lerCampoTexto(catalogo[pos].autor, 20);

    printf("\nNovo data: ");
    fgets(linha, 200, stdin);
    removerQuebraLinha(linha);
    if (strlen(linha) > 0) catalogo[pos].data = atoi(linha);

    printf("\nNovo conteúdo: ");
    lerCampoTexto(catalogo[pos].conteudo, 200);

    printf("\nNovo livro: ");
    lerCampoTexto(catalogo[pos].livro, 50);

    printf("\n >> Dados alterados na memória. Veja como ficou: \n");
    imprimirGuia(catalogo[pos]);
}

//excluir guia
void excluirGuia(Guia catalogo[], int *n) {
    char alvo[50];

    printf("\nDigite o nome da guia que deseja excluir: ");
    fgets(alvo, 50, stdin);
    removerQuebraLinha(alvo);

    int pos = pesquisarPorNome(catalogo, *n, alvo);
    if (pos == -1){
        printf("\nGuia \"%s\" não encontrada.\n", alvo);
        return;
    }

    printf("\nGuia encontrada: \n");
    imprimirGuia(catalogo[pos]);

    //desloca todos os itens seguintes uma posição para trás
    for (int i = pos; i < *n -1; i++){
        catalogo[i] = catalogo[i + 1];
    }
    (*n)--; //vetor tem um ite a menos

    printf("\n>> Guia excluída\n");
}

void criarGuia(Guia catalogo[], int *n) {
    if (*n >= MAX_GUIAS) {
        printf("\nLimite de guias atingido.\n");
        return;
    }

    char linha[200];
    int pos = *n; // nova guia vai na próxima posição livre

    printf("\n=== Criar novo guia ===\n");

    printf("\nNome do guia: ");
    lerCampoTexto(catalogo[pos].nome, 50);

    printf("\nMatéria: ");
    lerCampoTexto(catalogo[pos].materia, 20);

    printf("\nAutor: ");
    lerCampoTexto(catalogo[pos].autor, 50);

    printf("\nData de publicação: ");
    fgets(linha, 200, stdin);
    removerQuebraLinha(linha);
    catalogo[pos].data = atoi(linha);

    printf("\nConteúdo: ");
    lerCampoTexto(catalogo[pos].conteudo, 200);

    printf("\nLivro: ");
    lerCampoTexto(catalogo[pos].livro, 50);

    (*n)++; // agora o vetor tem mais um item

    printf("\n>> Guia criado com sucesso! Veja como ficou:\n");
    imprimirGuia(catalogo[pos]);
}
