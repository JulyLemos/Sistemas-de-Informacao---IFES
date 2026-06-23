/* ============================================================================
 *
 *  OBJETIVO: mostrar como GRAVAR, LER, PESQUISAR e ALTERAR dados em um
 *  ARQUIVO TEXTO. O usuario pode digitar um termo para pesquisar e tambem
 *  alterar os dados de uma selecao ja gravada.
 *
 *  IMPORTANTE: e um MODELO DE ESTUDO. Entendam a logica e ADAPTEM ao
 *  sistema do seu grupo. Copiar sem adaptacao NAO sera aceito.
 *
 *  COMO FUNCIONA A ALTERACAO EM ARQUIVO TEXTO:
 *  Nao da para "editar no meio" do arquivo. O caminho e sempre:
 *    1) carregar os dados para o vetor (LER);
 *    2) alterar o item no vetor (na MEMORIA);
 *    3) REGRAVAR o arquivo inteiro por cima (GRAVAR).
 *
 *  FORMATO DO ARQUIVO: um campo por linha (6 linhas por selecao). Assim
 *  nomes com espaco (ex.: "Costa Rica") funcionam com fgets sem complicacao.
 * ============================================================================ */

#include <stdio.h>   /* fopen, fclose, fprintf, fgets, printf, scanf ... */
#include <string.h>  /* strcmp, strstr, strcspn, strcpy ...              */
#include <stdlib.h>  /* atoi (converte texto em numero inteiro)          */

#define MAX_SELECOES 50
#define ARQUIVO "selecoes.txt"

typedef struct {
    char nome[50];
    char confederacao[20];
    int  ranking;
    int  titulos;
    char craque[50];
    char curiosidade[200];
} Selecao;


/* Remove o '\n' que o fgets() deixa no fim da linha. */
void removerQuebraLinha(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}


/* ============================================================================
 *  1) GRAVACAO  ->  salva o vetor de selecoes no arquivo texto ("w" = write)
 *     O modo "w" APAGA o conteudo antigo e grava tudo de novo. E justamente
 *     por isso que ele serve tanto para criar quanto para ATUALIZAR o arquivo.
 * ============================================================================ */
void gravarSelecoes(Selecao times[], int n) {
    FILE *fp = fopen(ARQUIVO, "w");
    if (fp == NULL) {
        printf("ERRO: nao foi possivel abrir o arquivo para gravar.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s\n", times[i].nome);
        fprintf(fp, "%s\n", times[i].confederacao);
        fprintf(fp, "%d\n", times[i].ranking);
        fprintf(fp, "%d\n", times[i].titulos);
        fprintf(fp, "%s\n", times[i].craque);
        fprintf(fp, "%s\n", times[i].curiosidade);
    }
    fclose(fp);
    printf(">> Arquivo \"%s\" atualizado (%d selecao(oes)).\n", ARQUIVO, n);
}


/* ============================================================================
 *  2) LEITURA  ->  carrega o arquivo de volta para o vetor ("r" = read)
 *     Retorna quantas selecoes foram lidas.
 * ============================================================================ */
int lerSelecoes(Selecao times[]) {
    FILE *fp = fopen(ARQUIVO, "r");
    if (fp == NULL) {
        printf("Aviso: o arquivo \"%s\" ainda nao existe.\n", ARQUIVO);
        return 0;
    }
    int n = 0;
    char linha[200];
    while (fgets(times[n].nome, 50, fp) != NULL) {
        removerQuebraLinha(times[n].nome);
        if (strlen(times[n].nome) == 0) continue;

        fgets(times[n].confederacao, 20, fp);
        removerQuebraLinha(times[n].confederacao);

        fgets(linha, 200, fp); times[n].ranking = atoi(linha);
        fgets(linha, 200, fp); times[n].titulos = atoi(linha);

        fgets(times[n].craque, 50, fp);
        removerQuebraLinha(times[n].craque);

        fgets(times[n].curiosidade, 200, fp);
        removerQuebraLinha(times[n].curiosidade);

        n++;
        if (n >= MAX_SELECOES) break;
    }
    fclose(fp);
    return n;
}


/* Imprime uma selecao de forma organizada. */
void imprimirSelecao(Selecao s) {
    printf("---------------------------------------------\n");
    printf("Selecao......: %s\n", s.nome);
    printf("Confederacao.: %s\n", s.confederacao);
    printf("Ranking FIFA.: %d\n", s.ranking);
    printf("Titulos......: %d\n", s.titulos);
    printf("Craque.......: %s\n", s.craque);
    printf("Curiosidade..: %s\n", s.curiosidade);
    printf("---------------------------------------------\n");
}


/* ============================================================================
 *  3a) PESQUISA EXATA  ->  acha a selecao cujo NOME e exatamente igual ao alvo
 *      strcmp(a, b) == 0  significa que as duas palavras sao IGUAIS.
 *      Retorna o indice encontrado, ou -1 se nao achar.
 * ============================================================================ */
int pesquisarPorNome(Selecao times[], int n, char alvo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(times[i].nome, alvo) == 0) {
            return i;
        }
    }
    return -1;
}


/* ============================================================================
 *  3b) PESQUISA POR TEXTO  ->  procura um TERMO DENTRO de qualquer campo
 *      strstr(campo, termo) devolve != NULL quando o termo aparece no campo.
 *      Observacao: e sensivel a maiusculas/minusculas ("Brasil" != "brasil").
 * ============================================================================ */
void pesquisarTexto(Selecao times[], int n, char termo[]) {
    int encontrou = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(times[i].nome, termo)         != NULL ||
            strstr(times[i].confederacao, termo) != NULL ||
            strstr(times[i].craque, termo)       != NULL ||
            strstr(times[i].curiosidade, termo)  != NULL) {
            imprimirSelecao(times[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nada encontrado para \"%s\".\n", termo);
    }
}


/* ============================================================================
 *  4) ALTERACAO  ->  muda os dados de uma selecao ja existente
 *      Passos: 1) achar a selecao (pelo nome);
 *              2) ler os novos dados do usuario e gravar NO VETOR.
 *      A regravacao do arquivo e feita logo em seguida, no menu (opcao 3).
 *      DICA: se o usuario apenas apertar ENTER sem digitar nada, o campo
 *      ANTIGO e mantido (ver a funcao lerCampoTexto abaixo).
 * ============================================================================ */

/* Le um novo texto; se vier vazio (so ENTER), mantem o valor atual. */
void lerCampoTexto(char destino[], int tamanho) {
    char buffer[200];
    fgets(buffer, 200, stdin);
    removerQuebraLinha(buffer);
    if (strlen(buffer) > 0) {                 /* digitou algo? entao troca */
        strncpy(destino, buffer, tamanho - 1);
        destino[tamanho - 1] = '\0';
    }
    /* se nao digitou nada, 'destino' continua com o valor antigo */
}

void alterarSelecao(Selecao times[], int n) {
    char alvo[50];

    printf("Digite o NOME da selecao que deseja alterar: ");
    fgets(alvo, 50, stdin);
    removerQuebraLinha(alvo);

    int pos = pesquisarPorNome(times, n, alvo);
    if (pos == -1) {
        printf("Selecao \"%s\" nao encontrada.\n", alvo);
        return;
    }

    printf("\nSelecao encontrada. Dados atuais:\n");
    imprimirSelecao(times[pos]);

    printf("\nDigite os NOVOS dados (ou apenas ENTER para manter o atual):\n");

    char linha[200];

    printf("Novo nome.........: ");
    lerCampoTexto(times[pos].nome, 50);

    printf("Nova confederacao.: ");
    lerCampoTexto(times[pos].confederacao, 20);

    printf("Novo ranking......: ");
    fgets(linha, 200, stdin);
    removerQuebraLinha(linha);
    if (strlen(linha) > 0) times[pos].ranking = atoi(linha);

    printf("Novos titulos.....: ");
    fgets(linha, 200, stdin);
    removerQuebraLinha(linha);
    if (strlen(linha) > 0) times[pos].titulos = atoi(linha);

    printf("Novo craque.......: ");
    lerCampoTexto(times[pos].craque, 50);

    printf("Nova curiosidade..: ");
    lerCampoTexto(times[pos].curiosidade, 200);

    printf("\n>> Dados alterados na memoria. Veja como ficou:\n");
    imprimirSelecao(times[pos]);
}


/* ============================================================================
 *  PROGRAMA PRINCIPAL  ->  menu com listar, pesquisar e alterar.
 * ============================================================================ */
int main(void) {

    /* ---- Dados de exemplo (so para ter o que gravar na primeira vez) ---- */
    Selecao times[MAX_SELECOES];

    strcpy(times[0].nome, "Brasil");
    strcpy(times[0].confederacao, "CONMEBOL");
    times[0].ranking = 5;  times[0].titulos = 5;
    strcpy(times[0].craque, "Vinicius Junior");
    strcpy(times[0].curiosidade, "Unica selecao a disputar todas as Copas do Mundo.");

    strcpy(times[1].nome, "Marrocos");
    strcpy(times[1].confederacao, "CAF");
    times[1].ranking = 12; times[1].titulos = 0;
    strcpy(times[1].craque, "Achraf Hakimi");
    strcpy(times[1].curiosidade, "1o pais africano a chegar a uma semifinal de Copa (2022).");

    strcpy(times[2].nome, "Escocia");
    strcpy(times[2].confederacao, "UEFA");
    times[2].ranking = 39; times[2].titulos = 0;
    strcpy(times[2].craque, "Scott McTominay");
    strcpy(times[2].curiosidade, "Disputou a primeira partida internacional da historia.");

    int total = 3;

    /* ---- Grava (cria o arquivo) e depois le de volta ---- */
    gravarSelecoes(times, total);

    Selecao carregadas[MAX_SELECOES];
    int qtd = lerSelecoes(carregadas);
    printf(">> %d selecao(oes) carregada(s) do arquivo.\n", qtd);

    /* ---- MENU INTERATIVO ---- */
    int opcao;
    char termo[100];

    do {
        printf("\n============ MENU ============\n");
        printf("1 - Listar todas as selecoes\n");
        printf("2 - Pesquisar (digitar um termo)\n");
        printf("3 - Alterar uma selecao\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar();  /* consome o ENTER que sobra apos o scanf */

        if (opcao == 1) {
            for (int i = 0; i < qtd; i++) {
                imprimirSelecao(carregadas[i]);
            }

        } else if (opcao == 2) {
            printf("Digite o que deseja pesquisar: ");
            fgets(termo, 100, stdin);
            removerQuebraLinha(termo);
            pesquisarTexto(carregadas, qtd, termo);

        } else if (opcao == 3) {
            alterarSelecao(carregadas, qtd);
            /* REGRAVA o arquivo para a alteracao ficar salva em disco. */
            gravarSelecoes(carregadas, qtd);

        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    printf("Encerrando o programa.\n");
    return 0;
}