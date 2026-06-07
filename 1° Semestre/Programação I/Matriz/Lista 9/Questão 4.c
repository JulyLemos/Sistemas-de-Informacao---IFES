/*4) Considere uma matriz onde são registados os espectadores dos jogos de campeonato de futebol da
primeira divisão, dividindo-os em sócios, não sócios, crianças, convidados, imprensa e policias. Só existe
um estádio. Considere um total de 50 jogos. Policiais e imprensa não devem ser considerados como
espectadores. Desenvolva um algoritmo que determine e indique:
a) Em que jogo se verificou um número maior de espectadores;
b) Em que(ais) jogo(s), ao longo do ano, a porcentagem de policiais em relação ao número total de
espectadores, foi inferior a 30%.
c) Em quais jogos não houve crianças?
d) Qual o total geral de público não pagante (policiais, imprensa, convidados e crianças)?
Veja o exemplo de matriz:*/

#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>

int main(){
  setlocale(LC_ALL, "");

  int dados[50][6], i, j, totalEsp = 0, maiorNumEsp = 0, partidaMaiorEsp = 0, qtdPartPolMenor30 = 0;
  int partidasPolMenor30[50], partidasSemCriancas[50], qtdPartSemCriancas = 0, totalPublicoNaoPagante = 0;

  srand(time(NULL));

  for(i = 0; i < 50; i++){

    //sorteando valores aleatorios
    printf("\nNúmero de sócios da partida %d", i);
    dados[i][0] = rand() %100;

    //recebendo numero de socios da partida
    /*
    printf("\nDigite o número de sócios da partida %d", i);
    scanf("%d", &dados[i][0]); -> caso queira fazer para as outras colunas, é só copiar e colar,
    mas alterando o valor de dados, ficando dados[i][1], dados[i][2], e assim por diante
     */

     printf("\nNúmero de não sócios da partida %d", i);
     dados[i][1] = rand() % 100;

     printf("\nNúmero de crianças da partida %d", i);
     dados[i][2] = rand() % 100;

     printf("\nNúmero de convidados da partida %d", i);
     dados[i][3] = rand() % 100;

     printf("\nNúmero de policiais da partida %d", i);
     dados[i][4] = rand() % 100;

     printf("\nNúmero de pessoas da imprensa da partida %d", i);
     dados[i][5] = rand() % 100;


    }

    for (i = 0; i < 50; i++){ //linha
      totalEsp = 0; //resolvendo o maior numero de espectadores -> letra a
      for(j = 0; j<=3; j++){
        totalEsp+=dados[i][j];
      }
      if(totalEsp > maiorNumEsp){
        //guarda o maior numero de espectadores
        maiorNumEsp = totalEsp;
        //guarda a partida que teve o maior numero de espectadores
        partidaMaiorEsp = i;
      }

      //letra b, quais partidas o numero de policiais foi menor
      if(dados[i][4] < (totalEsp * 0.3)){
        partidasPolMenor30[qtdPartPolMenor30] = i;
        qtdPartPolMenor30++;
      }

      //letra c, quais partidas não teve crianças
      if(dados[i][2] == 0){
        partidasSemCriancas[qtdPartSemCriancas] = i;
        qtdPartSemCriancas++;
      }

      //letra d, total de publico não pagante
      totalPublicoNaoPagante += (dados[i][2] + dados[i][3] + dados[i][4] + dados[i][5]);
    }

    //system("cls");

    printf("\nLetra a: o jogo com maior número de espectadores (%d) é: %d", maiorNumEsp, partidaMaiorEsp+1);

    //letra b
    if(qtdPartPolMenor30 > 0){
      printf("\nLetra b: jogos em que o número de policiais era menor que 30 porcento dos espectadores...");
      for(i = 0; i < qtdPartPolMenor30; i++){
        printf("\nJogo: %d   | Numero de policiais: %d", partidasPolMenor30[i]+1, dados[partidasPolMenor30[i]][4]);
      }
    } else{
      printf("\nLetra b: Não tivemos partidas em que o numero de policiais era menor que 30porcento dos espectadores");
    }

    //imprimind letra c
    if(qtdPartSemCriancas > 0){
      printf("\nLetra c: jogos em que não houve presença de crianças");
      for(i = 0; i < qtdPartSemCriancas; i++){
        printf("\nJogo: %d", partidasSemCriancas[i]);
      }
    } else{
      printf("\nLetra c: Não tivemos partidas em que não houve crianças");
    }

    //letra d
    printf("\nLetra d: total de publico não pagante %d", totalPublicoNaoPagante);

  return 0;
}
