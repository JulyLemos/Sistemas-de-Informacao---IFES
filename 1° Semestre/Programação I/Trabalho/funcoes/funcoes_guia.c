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
        fprintf(fp, "%s\n", catalogo[i].data);
        fprintf(fp, "%s\n", catalogo[i].livro);
        fprintf(fp, "%s\n", catalogo[i].conteudo);
    }

    fclose(fp); //fecha o arquivo em que o ponteiro está aberto, complemento de fopen
    printf("Arquivo \"%s\" atualizado (%d guias). \n", ARQUIVO, n);
}

//leitura, vai carregar o arquivo com r de read
int lerGuia