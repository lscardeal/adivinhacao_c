#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTOS_INICIAIS 100
#define PALPITE_INICIAL 0
#define MAIOR_NUMERO 100.0
#define MENOR_NUMERO 0
#define randnum(min, max) \
        ((rand() % (short)(((max) + 1) - (min))) + (min))

float calculaPontos(short numeroSecreto, short palpite, float pontosAtuais) {
    return pontosAtuais - (abs(numeroSecreto - palpite) / 2.0);
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

    printf("Você tem que acertar o número entre 1 e 100 que eu pensei.\n\n", numeroSecreto);

    while (1) {

        printf("Qual é o seu palpite? ");
        scanf("%hd", &palpite);

        if (palpite < 1 || palpite > 100) {
            printf("O número é entre 1 e 100, burro.\n\n");
            continue;
        } else if (palpite == numeroSecreto) {
            printf("Parabéns, você acertou!\n");
            printf("Você fez %.1f pontos.\n", pontos);
            break;
        } else if (palpite > numeroSecreto) {
            pontos = calculaPontos(numeroSecreto, palpite, pontos);
            printf("Seu palpite é maior do que o número secreto.\n\n");
        } else if (palpite < numeroSecreto) {
            pontos = calculaPontos(numeroSecreto, palpite, pontos);
            printf("Seu palpite é menor do que o número secreto.\n\n");
        }

        if (pontos <= 0) {
            printf("Você é muito ruim. O numero secreto era %hd.\n", numeroSecreto);
            printf("Fim de jogo.\n\n");

            break;
        }
    }
    
}