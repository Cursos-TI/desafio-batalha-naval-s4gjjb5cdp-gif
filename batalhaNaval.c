#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ==============================
    // Nível Novato - Tabuleiro
    // ==============================

    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==============================
    // Posicionamento dos navios
    // ==============================

    // Navio Horizontal
    int linhaH = 2;   // terceira linha (índice 2)
    int colunaH = 1;  // segunda coluna (índice 1)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio Vertical
    int linhaV = 5;   // sexta linha (índice 5)
    int colunaV = 7;  // oitava coluna (índice 7)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // ==============================
    // Impressão do Tabuleiro com letras e números
    // ==============================

    // Imprime cabeçalho das colunas (A-J)
    printf("   "); // espaço para números das linhas
    for (char c = 'A'; c < 'A' + TAM; c++) {
        printf("%c ", c);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // numeração das linhas
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}