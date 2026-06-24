#ifndef FUNCOES_GUIA_H
#define FUNCOES_GUIA_H

#define MAX_GUIAS 50
#define ARQUIVO "guias.txt"

typedef struct {
    char nome[50];
    char materia[20];
    char autor[20];
    int data;
    char conteudo[200];
    char livro[50];
} Guia;

//protótipo das funções
void removerQuebraLinha(char texto[]); //função para quebrar linha após digitar algo
void gravarGuia(Guia catalogo[], int n); //função para gravar, popular o struct
int lerGuia(Guia catalogo[]); //função para ler guia
void imprimirGuia(Guia g); //função para imprimir guia
int pesquisarPorNome(Guia catalogo[], int n, char alvo[]); //função para pesquisar na guia pelo nome
void pesquisarTexto(Guia catalogo[], int n, char termo[]); //função para pesquisar na guia pelo texto
void lerCampoTexto(char destino[], int tamanho); //função para ler o campo do texto
void alterarGuia(Guia catalogo[], int n); //função para alterar algo na guia
void excluirGuia(Guia catalogo[], int *n); //função para excluir guia
void criarGuia(Guia catalogo[], int *n); //função para criar guia

#endif
