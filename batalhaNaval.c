#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ==========================================
    // Criação do tabuleiro 10x10
    // ==========================================

    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========================================
    // Posicionamento do Navio Horizontal
    // ==========================================

    int linhaH = 2;
    int colunaH = 1;

    // Verifica se o navio cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {

            // Verifica se a posição está livre
            if (tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }

    // ==========================================
    // Posicionamento do Navio Vertical
    // ==========================================

    int linhaV = 5;
    int colunaV = 7;

    // Verifica se o navio cabe no tabuleiro
    if (linhaV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {

            // Verifica se a posição está livre
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // ==========================================
    // Posicionamento do Navio Diagonal Principal
    // (linha e coluna aumentam juntas)
    // ==========================================

    int linhaD1 = 4;
    int colunaD1 = 0;

    if (linhaD1 + TAM_NAVIO <= TAM &&
        colunaD1 + TAM_NAVIO <= TAM) {

        int livre = 1;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                livre = 0;
            }
        }

        // Posiciona o navio se todas as posições estiverem livres
        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // ==========================================
    // Posicionamento do Navio Diagonal Secundária
    // (linha aumenta e coluna diminui)
    // ==========================================

    int linhaD2 = 0;
    int colunaD2 = 9;

    if (linhaD2 + TAM_NAVIO <= TAM &&
        colunaD2 - (TAM_NAVIO - 1) >= 0) {

        int livre = 1;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                livre = 0;
            }
        }

        // Posiciona o navio se todas as posições estiverem livres
        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // ==========================================
    // Exibição do Tabuleiro
    // ==========================================

    // Cabeçalho com letras A até J
    printf("   ");

    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf("%c ", letra);
    }

    printf("\n");

    // Exibe as linhas numeradas e o conteúdo do tabuleiro
    for (int i = 0; i < TAM; i++) {

        printf("%2d ", i + 1);

        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}