#include <stdio.h>

#define tamanho_tabuleiro 10
#define tamanho_navio 3
#define codigo_navio 3
#define codigo_agua 0

void exibirtabuleiro (int tabuleiro [tamanho_tabuleiro][tamanho_tabuleiro]){

    printf("--- TABULEIRO --- \n\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int podePosicionar(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro], int linha, int coluna, char direcao) {
    for (int i = 0; i < tamanho_navio; i++) {
        int l = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);

               if (l >= tamanho_tabuleiro || c >= tamanho_tabuleiro)
            return 0;

                if (tabuleiro[l][c] != codigo_agua)
            return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro], int linha, int coluna, char direcao) {
    for (int i = 0; i < tamanho_navio; i++) {
        int l = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);
        tabuleiro[l][c] = codigo_navio;
    }
}

    int main(){

        int tabuleiro [tamanho_tabuleiro][tamanho_tabuleiro];

        for (int i = 0; i < tamanho_tabuleiro; i++){
          for (int j = 0; i < tamanho_tabuleiro; j++){
         tabuleiro [i][j] = codigo_agua;
          }
          
        }
        
    int linha1 = 2, coluna1 = 3;
    int linha2 = 5, coluna2 = 6;

    if (podePosicionar(tabuleiro, linha1, coluna1, 'H')) {
        posicionarNavio(tabuleiro, linha1, coluna1, 'H');
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
        return 1;
    }

    if (podePosicionar(tabuleiro, linha2, coluna2, 'V')) {
        posicionarNavio(tabuleiro, linha2, coluna2, 'V');
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
        return 1;
    }

exibirtabuleiro(tabuleiro);

    return 0;
    
    }