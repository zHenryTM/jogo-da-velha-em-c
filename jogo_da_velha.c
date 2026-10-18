#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char jogo_da_velha[9];

void jogada_jogador() {
    int posicao;
    while (1) {
        scanf("%d", &posicao);
        if (jogo_da_velha[posicao] == 'V') {
            jogo_da_velha[posicao] = 'X';
            break;
        } else {
            printf("Escolha uma posicao vazia\n");
        }
    }
}

void jogada_maquina() {
    int posicoes_ocupadas = 0;
    for (int i = 0; i < 9; i++) {
        if (jogo_da_velha[i] != 'V') {
            posicoes_ocupadas++;
        }
    }
    int vetor_posicoes_ocupadas[posicoes_ocupadas];
    for (int i = 0, j = 0; i < 9; i++) {
        if (jogo_da_velha[i] != 'V') {
            vetor_posicoes_ocupadas[j] = i;
            j++;
        }
    }
    int posicao = rand() % posicoes_ocupadas;
    while (1) {
        // tentando ir à esquerda
        if (posicao - 1 >= 0 && posicao - 1 < 9) {
            posicao = posicao - 1;
            jogo_da_velha[posicao] = 'O';
            break;
        }
        // tentando ir à direita
        if (posicao + 1 >= 0 && posicao + 1 < 9) {
            posicao = posicao + 1;
            jogo_da_velha[posicao] = 'O';
            break;
        }
        // tentando ir pra cima
        if (posicao - 3 >= 0 && posicao - 3 < 9) {
            posicao = posicao - 3;
            jogo_da_velha[posicao] = 'O';
            break;
        }
        // tentando ir à baixo
        if (posicao + 3 >= 0 && posicao + 3 < 9) {
            posicao = posicao + 3;
            jogo_da_velha[posicao] = 'O';
            break;
        }
    }
}

void exibir_tela() {
    for (int i = 0; i < 3; i++) {
        if (jogo_da_velha[i] == 'V') {
            printf(" |"); 
        } else {
            printf("%c|", jogo_da_velha[i]);
        }
    }
    printf("\n");
    for (int i = 3; i < 6; i++) {
        if (jogo_da_velha[i] == 'V') {
            printf(" |"); 
        } else {
            printf("%c|", jogo_da_velha[i]);
        }
    }
    printf("\n");
    for (int i = 6; i < 9; i++) {
        if (jogo_da_velha[i] == 'V') {
            printf(" |"); 
        } else {
            printf("%c|", jogo_da_velha[i]);
        }
    }
    printf("\n");
}

void start() {
    for (int i = 0; i < 9; i++) {
        jogo_da_velha[i] = 'V';
    }
}

int main() {
    int jogadas_restantes;
    srand(time(NULL));
    start();
    for (jogadas_restantes = 9; jogadas_restantes > 0; jogadas_restantes--) {
        jogada_jogador();
        jogada_maquina();
        exibir_tela();
    }
    return 0;
}
