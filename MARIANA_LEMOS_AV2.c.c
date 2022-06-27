#include <stdio.h>
#include <stdlib.h> // para usar a função rand
#include <time.h>  // para usar a função time

    int sorteiaCaraOuCoroa(){
        int sorteiaCaraouCoroa ();
        int aleatorio;
        srand(time(NULL));
        aleatorio = (rand () % 2)+1;

return aleatorio;
}

    void escreveResultado (int Moeda){
        if(Moeda == 1){
            printf("Cara");
                      }
        if(Moeda == 2){
            printf("Coroa");
                      }
}

    int garanteEntradaAceitavel (int nMin, int nMax){
        int ValidaValor = 0;
        int Valor = 0;
            while(ValidaValor == 0){
            printf("Digite um valor entre %d e %d:\n", nMin, nMax);
            scanf("%i", &Valor);
            if(Valor < nMin || Valor > nMax){ //Verifica se o valor digitado está entre o intervalo recebido por parâmetro::: cara/coroa ou valor
            printf("Valor fora da faixa. Tente novamente.\n");
                                            }
            else{
            ValidaValor = 1; //A variável de controle recebe o valor 1, caso o usuário digite um valor válido
                }
}
    return Valor; ////Retorna a uma variável de controle utilizada no loop
}

    int main() {
        float Saldo = 10.00;
        int Jogada = 0;
        int Moeda = 0;
        int Valor = 0;
        void escreveResultado();
        int garanteEntradaAceitavel();
        int sorteiaCaraOuCoroa();

while (Saldo > 0.00){
    printf("Seu saldo eh de %.2f reais.\n", Saldo);

    printf("Escolha da jogada (1 para cara e 2 para coroa).\n");
    Moeda = garanteEntradaAceitavel(1, 2); //Valida intervalo entre 1 e 2, caso não seja valor aceitável, a função pede para tentar novamente
    printf("Voce escolheu ");
    escreveResultado(Moeda); //Essa função recebe o valor digitado entre 1 e 2, e retorna o valor inerente à moeda, sendo 1=cara e 2=coroa
    printf("\n");

    printf("Escolha do valor da aposta (em centavos).\n");
    Valor = garanteEntradaAceitavel(1, Saldo*100); //Valida novamente a entrada digitada pelo usuario, mas dessa vez, o valor da aposta, em que o mínimo é 1 e o máximo é o saldo atual

    Jogada = sorteiaCaraOuCoroa(); //Essa função faz o sorteio aleatório
    printf("O resultado do sorteio foi ");
    escreveResultado (Jogada); //Aqui usa novamente a função para escrever se é cara ou coroa, mas com o resultado do sorteio
    printf("\n");
        if(Jogada == Moeda){ //Verifica se a jogada é igual ao valor digitado pelo usuário (cara ou coroa)
           Saldo = Saldo + (Valor / 100.00);
           printf("Voce ganhou!\n");//se for igual, a soma do saldo atual é o valor da aposta dividido por 100, pois o valor informado pelo usuário foi em centavos
                            }
        else{
             Saldo = Saldo - (Valor / 100.00);
             printf("Voce perdeu!\n"); //se for diferente: perdeu. Então, subtrai do saldo atual o valor da aposta dividido por 100
            }
}       if(Saldo==0.00){
        printf("Voce foi a falencia!\n");
                    }
        return 0;
}
