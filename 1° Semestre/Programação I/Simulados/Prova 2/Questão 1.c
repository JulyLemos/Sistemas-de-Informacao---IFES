/*01 - Crie uma função somaPares que receba um inteiro N e retorne a soma dos N primeiros 
números pares positivos (2 + 4 + 6 + ... até totalizar N termos). Na main, leia N e exiba o 
resultado retornado pela função.
Repetição: for
Por quê? o número de iterações é conhecido previamente (N termos), e o for é a 
estrutura mais natural para contagem fixa com contador, início e passo bem definidos.
Condicional: if
Por quê? será usada apenas para validar se N é positivo (validação simples de uma 
condição)*/

int somaPares(int N);

int main(){
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("N deve ser positivo.\n");
    } else{
        printf("Soma dos %d primeiros pares = %d", n, somaPares(n));
    }

    return 0;
}

int somaPares(int n){
    int i, soma = 0;

    for(i = 1; i<=n;  i++){
        soma+= 2 *i; //transforma o i no par, por exemplo, primeiro é 2*1 =2, 2*2=4, assim pegando os pares.
    }
    return soma;
}