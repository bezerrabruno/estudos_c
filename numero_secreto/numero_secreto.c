#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validaRodada(int acertou, int vida, int numeroMaior,double pontos) {
    if(acertou) {
        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.2f pontos!!\n\n", pontos);

        return 0;
    } else if(vida < 1) {
        printf("\nVoce perdeu! Tente novamente!\n\n");

        return 0;

    } else {
        if(numeroMaior) {
            printf("\nSeu chute foi maior do que o numero secreto!");

            return 1;
        } else {
            printf("\nSeu chute foi menor do que o numero secreto!");

            return 1;
        }
    }
}

int numeroSecreto() {
    srand(time(0));
    return rand() % 100;
}

int main() {
    int chute;
    int nivel;
    int totaldetentativas;
    double pontos = 1000;
    char continuar;

    int numerosecreto = numeroSecreto();

    printf("\n");
    printf("      Bem vindo ao      \n");
    printf("  Jogo de Adivinhacao!  \n");
    printf("\n");

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

    for(int i = 1; i <= totaldetentativas; i++) {
        printf("___________________________________________\n");
        printf("-> Tentativa %d de %d\n", i, totaldetentativas);
        printf("Chute um numero: ");
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        int validacao = validaRodada(chute == numerosecreto, totaldetentativas - i, chute > numerosecreto, pontos);

        if(validacao) {
            double pontosperdidos = abs(chute * 10) / 2.0;
            pontos = pontos - pontosperdidos;

            printf("\n");

            continue;
        }

        printf("Deseja jogar novamente?\n");
        printf("(s)Sim / (n)Nao\n");
        scanf("%s", &continuar);

       if(continuar == 's') {
           i = 0;
           pontos = 1000;
           int numerosecreto = numeroSecreto();
           printf("Reiniciando...\n");

           continue;
       } else {
           printf("Obrigado por jogar :)\n");

           break;
       }
    }
}