#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTOS_INICIAIS 100.0
#define PALPITE_INICIAL 0
#define MAIOR_NUMERO 100
#define MENOR_NUMERO 1
#define TENTATIVAS_FACIL 20
#define TENTATIVAS_MEDIO 10
#define TENTATIVAS_DIFICIL 5
#define randnum(min, max) \
        ((rand() % (short)(((max) + 1) - (min))) + (min))

float calculaPontos(short numeroSecreto, short palpite, float pontosAtuais) {
    return pontosAtuais - (abs(numeroSecreto - palpite) / 2.0);
}

short tentativasRestantes(short tentativas, short rodada) {
    return tentativas+1-rodada;
}

int main() {
    printf("\n");
    printf("************************************\n");
    printf("* Bem-vindo ao jogo de ADIVINHAÇÃO *\n");
    printf("************************************\n\n");

    srand(time(NULL));
    short numeroSecreto = randnum(MENOR_NUMERO, MAIOR_NUMERO);
    float pontos = PONTOS_INICIAIS;
    short palpite = PALPITE_INICIAL;
    short dificuldade;
    short tentativas;

    printf("Você tem que acertar o número entre 1 e 100 que eu pensei.\n\n");

    while(1) {
        printf("Escolha a dificuldade:\n");
        printf("(1) Facil\n");
        printf("(2) Medio\n");
        printf("(3) Dificil\n");
        printf("> ");
        scanf("%hd", &dificuldade);
        printf("\n");

        if (dificuldade < 1 || dificuldade > 3) {
            printf("Essa não é uma opção valida. Escolha novamente.\n\n");
        } else {
            break;
        }
    }

    switch (dificuldade) {
    case 1:
        tentativas = TENTATIVAS_FACIL;
        break;
    case 2:
        tentativas = TENTATIVAS_MEDIO;
        break;
    case 3: 
        tentativas = TENTATIVAS_DIFICIL;
        break;
    default:
        break;
    }

    for (short rodada = 1; rodada <= tentativas; rodada++) {

        if (rodada == tentativas) {
            printf("Essa é sua última tentativa!\n");
        } else {
            printf("Você tem %hd tentativas.\n", tentativasRestantes(tentativas, rodada));
        }

        printf("Qual é o seu palpite?\n");
        printf("> ");
        scanf("%hd", &palpite);
        printf("\n");

        if (palpite < 1 || palpite > 100) {
            printf("O número é entre 1 e 100, burro.\n\n");
            rodada--;
            continue;
        } else if (palpite == numeroSecreto) {
            printf("Parabéns, você acertou!\n");
            pontos = pontos + (tentativasRestantes(tentativas, rodada) * 10);
            printf("Você fez %.1f pontos.\n", pontos);
            break;
        } else if (palpite > numeroSecreto) {
            pontos = calculaPontos(numeroSecreto, palpite, pontos);
            printf("Seu palpite é maior do que o número secreto.\n\n");
        } else if (palpite < numeroSecreto) {
            pontos = calculaPontos(numeroSecreto, palpite, pontos);
            printf("Seu palpite é menor do que o número secreto.\n\n");
        }

        if (pontos <= 0 || rodada == tentativas) {
            printf("Você é muito ruim. O numero secreto era %hd.\n", numeroSecreto);
            printf("Fim de jogo.\n\n");

            break;
        }
    }
    
}