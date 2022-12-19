#include <stdio.h>

#define TENTATIVAS 5

int main() {
    printf("\n");
    printf("************************************\n");
    printf("* Bem-vindo ao jogo de ADIVINHAÇÃO *\n");
    printf("************************************\n\n");

    printf("Você tem %d chances para acertar o número que eu pensei.\n\n", TENTATIVAS);

    int numeroSecreto = 42;
    int palpite;

    for (int i = 1; i <= TENTATIVAS; i++) {
        if (i == TENTATIVAS) {
            printf("Essa é sua última tentativa!\n");
        }

        printf("Qual é o seu palpite? ");
        scanf("%d", &palpite);        

        if (palpite < 0) {
            printf("Você não pode chutar números negativos.\n\n");
            i--;
            continue;
        } else if (palpite == numeroSecreto) {
            printf("Parabéns, você acertou!\n\n");
            break;
        } else if (palpite > numeroSecreto) {
            printf("Seu palpite é maior do que o número secreto.\n\n");
        } else if (palpite < numeroSecreto) {
            printf("Seu palpite é menor do que o número secreto.\n\n");
        }

        if (i == TENTATIVAS) {
            printf("Acabaram suas tentativas...\n");
        }
    }
    
}