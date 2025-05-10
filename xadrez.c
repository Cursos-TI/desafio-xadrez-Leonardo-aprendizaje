#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h> // Para Windows
#define PAUSE system("pause")
#define CLEAR system("cls")
#else
#include <unistd.h>  // Para Unix
#define Sleep(x) usleep((x)*1000)
#define PAUSE getchar()
#define CLEAR system("clear")
#endif

#define TAM 8
#define DELAY 500

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\nMovimento das Peças no Tabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", TAM - i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

// Limpa o tabuleiro (preenche com '.')
void limparTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';
}

// Movimento recursivo da torre (direita)
void moverTorre(char tabuleiro[TAM][TAM], int linha, int coluna, int passos) {
    if (passos == 0 || coluna + 1 >= TAM) return;

    tabuleiro[linha][coluna] = '*';
    coluna++;
    tabuleiro[linha][coluna] = 'T';

    CLEAR;
    imprimirTabuleiro(tabuleiro);
    printf("Direita\n\n");
    Sleep(DELAY);

    moverTorre(tabuleiro, linha, coluna, passos - 1);
}

// Movimento recursivo do bispo com loops aninhados (diagonal cima direita)
void moverBispo(char tabuleiro[TAM][TAM], int linha, int coluna, int passos) {
    if (passos == 0 || linha - 1 < 0 || coluna + 1 >= TAM) return;

    for (int i = linha - 1; i >= linha - 1; i--) {
        for (int j = coluna + 1; j <= coluna + 1; j++) {
            tabuleiro[linha][coluna] = '*';
            tabuleiro[i][j] = 'B';

            CLEAR;
            imprimirTabuleiro(tabuleiro);
            printf("Diagonal Cima Direita\n\n");
            Sleep(DELAY);

            moverBispo(tabuleiro, i, j, passos - 1);
        }
    }
}

// Movimento recursivo da rainha (baixo esquerda)
void moverRainha(char tabuleiro[TAM][TAM], int linha, int coluna, int passos) {
    if (passos == 0 || linha + 1 >= TAM || coluna - 1 < 0) return;

    tabuleiro[linha][coluna] = '*';
    linha++;
    coluna--;
    tabuleiro[linha][coluna] = 'R';

    CLEAR;
    imprimirTabuleiro(tabuleiro);
    printf("Diagonal Baixo Esquerda\n\n");
    Sleep(DELAY);

    moverRainha(tabuleiro, linha, coluna, passos - 1);
}

// Movimento do cavalo com loops aninhados e múltiplas condições
void moverCavalo(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = linha - 2; i >= 0; i--) {
        for (int j = coluna + 1; j < TAM; j++) {
            if (i < 0 || j >= TAM) break;

            tabuleiro[linha][coluna] = '*';
            tabuleiro[i][j] = 'C';

            CLEAR;
            imprimirTabuleiro(tabuleiro);
            printf("Cima\nDireita\n\n");
            Sleep(DELAY);

            return;
        }
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    char escolha;
    int continuar = 1;
    const int linhaInicial = 7, colunaInicial = 0; // Posição inicial (linha 8, coluna A)

    while (continuar) {
        limparTabuleiro(tabuleiro);

        printf("Escolha a peça que deseja mover (ou 'S' para sair):\n");
        printf("T: Torre, B: Bispo, R: Rainha, C: Cavalo\n");
        printf("Digite a letra da peça: ");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);

        if (escolha == 'S') {
            printf("Saindo...\n");
            break;
        }

        switch (escolha) {
            case 'T':
                tabuleiro[linhaInicial][colunaInicial] = 'T';
                imprimirTabuleiro(tabuleiro);
                Sleep(DELAY);
                moverTorre(tabuleiro, linhaInicial, colunaInicial, 5);
                break;

            case 'B':
                tabuleiro[linhaInicial][colunaInicial] = 'B';
                imprimirTabuleiro(tabuleiro);
                Sleep(DELAY);
                moverBispo(tabuleiro, linhaInicial, colunaInicial, 5);
                break;

            case 'R':
                tabuleiro[linhaInicial][colunaInicial] = 'R';
                imprimirTabuleiro(tabuleiro);
                Sleep(DELAY);
                moverRainha(tabuleiro, linhaInicial, colunaInicial, 5);
                break;

            case 'C':
                tabuleiro[linhaInicial][colunaInicial] = 'C';
                imprimirTabuleiro(tabuleiro);
                Sleep(DELAY);
                moverCavalo(tabuleiro, linhaInicial, colunaInicial);
                break;

            default:
                printf("Opção inválida!\n");
        }

        printf("\nPressione ENTER para continuar...\n");
        getchar(); getchar(); // Aguarda ENTER
    }

    return 0;
}
