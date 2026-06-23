#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUIAS 100
#define ARQUIVO "guias.txt"


typedef struct {
    char nome[50];
    char materia[20];
    char autor[50];
    int data;
    char conteudo[200];
    char livro[50];
} Guia;

void removerQuebraLinha(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}


void gravarGuias (Guia salvar[], int n) {
    FILE *fp = fopen(ARQUIVO, "w");

    if (fp == NULL) {
        printf("ERRO AO SALVAR ARQUIVO. \n");
        return;
    }

    for (int i= 0; i < n; i++) {
        fprintf(fp, "%s\n", salvar[i].nome);
        fprintf(fp, "%s\n", salvar[i].materia);
        fprintf(fp, "%d\n", salvar[i].autor);
        fprintf(fp, "%d\n", salvar[i].data);
        fprintf(fp, "%s\n", salvar[i].conteudo);
        fprintf(fp, "%s\n", salvar[i].livro);
    }

    fclose(fp);
    printf (">> %d Guias gravados no arquivo \"%s\".\n", n, ARQUIVO);
}

int lerGuias (Guia salvar[]) {
    FILE *fp = fopen(ARQUIVO, "r");

    if (fp == NULL) {
        printf("Aviso: o arquivo \"%s\" ainda nao existe.\n", ARQUIVO);
        return 0;
    }

    int n = 0;
    char linha[200];

    while


}
