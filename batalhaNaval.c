#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5  // tamanho das matrizes de habilidade

// ==========================================
// Função para inicializar as matrizes de habilidade
// ==========================================
void inicializarHabilidades(int cone[TAM_HABILIDADE][TAM_HABILIDADE],
                            int cruz[TAM_HABILIDADE][TAM_HABILIDADE],
                            int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {

    int meio = TAM_HABILIDADE / 2;

    // Preencher Cone (triângulo de cima para baixo)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= meio - i && j <= meio + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Preencher Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == meio || j == meio) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Preencher Octaedro (losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// ==========================================
// Função para aplicar habilidade no tabuleiro
// ==========================================
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int linhaOrigem, int colunaOrigem) {

    int meio = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {

            // Calcula posição no tabuleiro
            int linhaTabuleiro = linhaOrigem + (i - meio);
            int colunaTabuleiro = colunaOrigem + (j - meio);

            // Verifica limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM) {

                // Aplica efeito apenas se a célula da habilidade for 1 e não for navio
                if (habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

// ==========================================
// Função para exibir o tabuleiro
// ==========================================
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {

    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // ==========================================
    // Posicionamento dos navios
    // ==========================================

    // Navio Horizontal
    int linhaH = 2, colunaH = 1;
    if (colunaH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++)
            if (tabuleiro[linhaH][colunaH + i] == 0)
                tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio Vertical
    int linhaV = 5, colunaV = 7;
    if (linhaV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++)
            if (tabuleiro[linhaV + i][colunaV] == 0)
                tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio Diagonal Principal
    int linhaD1 = 4, colunaD1 = 0;
    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        int livre = 1;
        for (int i = 0; i < TAM_NAVIO; i++)
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) livre = 0;
        if (livre)
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio Diagonal Secundária
    int linhaD2 = 0, colunaD2 = 9;
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        int livre = 1;
        for (int i = 0; i < TAM_NAVIO; i++)
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) livre = 0;
        if (livre)
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // ==========================================
    // Inicializa habilidades
    // ==========================================
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarHabilidades(cone, cruz, octaedro);

    // ==========================================
    // Aplica habilidades no tabuleiro
    // (pontos de origem definidos diretamente)
    // ==========================================
    aplicarHabilidade(tabuleiro, cone, 1, 3);      // Cone
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // Cruz
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);  // Octaedro

    // ==========================================
    // Exibe o tabuleiro final
    // ==========================================
    exibirTabuleiro(tabuleiro);

    return 0;
}