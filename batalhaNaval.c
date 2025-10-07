#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se há sobreposição
int verificaSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == NAVIO;
}

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio 1: horizontal (linha 1, coluna 2)
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linhaH, colunaH + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // Navio 2: vertical (linha 4, coluna 5)
    int linhaV = 4, colunaV = 5;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linhaV + i, colunaV)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // Navio 3: diagonal principal (linha 0, coluna 0)
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linhaD1 + i, colunaD1 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // Navio 4: diagonal secundária (linha 0, coluna 9)
    int linhaD2 = 0, colunaD2 = 9;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - TAMANHO_NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linhaD2 + i, colunaD2 - i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
