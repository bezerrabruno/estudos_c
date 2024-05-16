#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\n");
    printf("      Bem vindo ao      \n");
    printf("  Jogo de Adivinhacao!  \n");
    printf("\n");

    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;

    double pontos = 1000;

    srand(time(0));
    int numerosecreto = rand() % 100;

    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil (4) Impossivel\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch(nivel) {
        case 1: 
            totaldetentativas = 24;
            break;
        case 2:
            totaldetentativas = 12;
            break;
        case 3:
            totaldetentativas = 6;
            break;
        default:
            totaldetentativas = 1;
            break;
    }

    printf("\n\n");

    for(int i = 1; i <= totaldetentativas; i++) {

        printf("-> Tentativa %d de %d\n", i, totaldetentativas);

        printf("Chute um numero: ");
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        acertou = chute == numerosecreto;

        if(acertou) {
            break;
        } else if(chute > numerosecreto) {
            printf("\nSeu chute foi maior do que o numero secreto!\n\n");
        } else {
            printf("\nSeu chute foi menor do que o numero secreto!\n\n");
        }

        double pontosperdidos = abs(chute * 10) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("\n");
    if(acertou) {
        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);
    } else {
        printf("\nVoce perdeu! Tente novamente!\n\n");
    }


}