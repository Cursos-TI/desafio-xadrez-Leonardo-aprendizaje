#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 8

// Função para limpar a tela (multiplataforma)
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para pausar até o usuário apertar Enter
void pausarComEnter() {
    printf("\nPressione ENTER para continuar...\n");
    //while (getchar() != '\n'); // Limpa o buffer, EU PREFERI DEIXAR SEM O GETCHAR, POIS ESTAVA TENDO QUE APERTAR 2 VEZES O ENTER.
    getchar(); // Espera o Enter real
}

// Imprimir o tabuleiro
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

// Movimento da Torre
void movimentoTorre(char tabuleiro[TAM][TAM], int linha, int coluna, int movimento) {
    for (int i = 1; i <= movimento; i++) {
        tabuleiro[linha][coluna] = '*';
        coluna++;
        tabuleiro[linha][coluna] = 'T';
        limparTela();
        imprimirTabuleiro(tabuleiro);
        pausarComEnter();
    }
}

// Movimento do Bispo
void movimentoBispo(char tabuleiro[TAM][TAM], int linha, int coluna, int movimento) {
    for (int i = 1; i <= movimento; i++) {
        tabuleiro[linha][coluna] = '*';
        linha++;
        coluna++;
        tabuleiro[linha][coluna] = 'B';
        limparTela();
        imprimirTabuleiro(tabuleiro);
        pausarComEnter();
    }
}

// Movimento da Rainha
void movimentoRainha(char tabuleiro[TAM][TAM], int linha, int coluna, int movimento) {
    for (int i = 1; i <= movimento; i++) {
        tabuleiro[linha][coluna] = '*';
        linha++;
        coluna--;
        tabuleiro[linha][coluna] = 'R';
        limparTela();
        imprimirTabuleiro(tabuleiro);
        pausarComEnter();
    }
}

// Movimento do Cavalo
void movimentoCavalo(char tabuleiro[TAM][TAM], int linha, int coluna, int movimento) {
    for (int i = 1; i <= movimento; i++) {
        tabuleiro[linha][coluna] = '*';
        linha += 2;
        coluna -= 1;
        tabuleiro[linha][coluna] = 'C';
        limparTela();
        imprimirTabuleiro(tabuleiro);
        pausarComEnter();
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    char escolha;
    int linha = 0;
    int coluna = 0;
    int continuar = 1;

    // Inicializa o tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    tabuleiro[linha][coluna] = 'T';

    while (continuar) {
        printf("Escolha a peça que deseja mover (ou 'S' para sair):\n");
        printf("T: Torre, B: Bispo, R: Rainha, C: Cavalo\n");
        printf("Digite a letra da peça: ");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);

        if (escolha == 'S') {
            printf("Saindo...\n");
            continuar = 0;
        } else {
            // Limpa buffer antes de usar getchar
            getchar();

            switch (escolha) {
                case 'T':
                    tabuleiro[linha][coluna] = 'T';
                    imprimirTabuleiro(tabuleiro);
                    pausarComEnter();
                    limparTela();
                    movimentoTorre(tabuleiro, linha, coluna, 5);
                    break;

                case 'B':
                    tabuleiro[linha][coluna] = 'B';
                    imprimirTabuleiro(tabuleiro);
                    pausarComEnter();
                    limparTela();
                    movimentoBispo(tabuleiro, linha, coluna, 5);
                    break;

                case 'R':
                    tabuleiro[linha][coluna] = 'R';
                    imprimirTabuleiro(tabuleiro);
                    pausarComEnter();
                    limparTela();
                    movimentoRainha(tabuleiro, linha, coluna, 5);
                    break;

                case 'C':
                    tabuleiro[linha][coluna] = 'C';
                    imprimirTabuleiro(tabuleiro);
                    pausarComEnter();
                    limparTela();
                    movimentoCavalo(tabuleiro, linha, coluna, 5);
                    break;

                default:
                    printf("Opção inválida! Tente novamente.\n");
            }
        }
    }

    return 0;
}
