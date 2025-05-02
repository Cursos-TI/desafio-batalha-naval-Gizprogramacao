#include <stdio.h>

#define tamanho_tabuleiro 10
#define tamanho_navio 3
#define codigo_navio 3
#define codigo_agua 0
#define codigo_habilidade 5
#define tamanho_habilidade 5

void exibirTabuleiro(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro]) {
    printf("--- TABULEIRO ---\n\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            if (tabuleiro[i][j] == codigo_agua) printf("~ ");
            else if (tabuleiro[i][j] == codigo_navio) printf("N ");
            else if (tabuleiro[i][j] == codigo_habilidade) printf("* ");
        }
        printf("\n");
    }
}

void criarHabilidadeCone(int matriz[tamanho_habilidade][tamanho_habilidade]) {
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            int meio = tamanho_habilidade / 2;
            matriz[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

void criarHabilidadeCruz(int matriz[tamanho_habilidade][tamanho_habilidade]) {
    int meio = tamanho_habilidade / 2;
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            matriz[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

void criarHabilidadeOctaedro(int matriz[tamanho_habilidade][tamanho_habilidade]) {
    int meio = tamanho_habilidade / 2;
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            matriz[i][j] = (abs(meio - i) + abs(meio - j) <= meio) ? 1 : 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro],
    int habilidade[tamanho_habilidade][tamanho_habilidade],
    int origemLinha, int origemColuna) {
int meio = tamanho_habilidade / 2;
        for (int i = 0; i < tamanho_habilidade; i++) {
            for (int j = 0; j < tamanho_habilidade; j++) {
int linhaTab = origemLinha - meio + i;
int colTab = origemColuna - meio + j;
        if (linhaTab >= 0 && linhaTab < tamanho_tabuleiro &&
colTab >= 0 && colTab < tamanho_tabuleiro &&
habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] == codigo_agua) {
tabuleiro[linhaTab][colTab] = codigo_habilidade;
}
}
}
}

int podePosicionar(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro], int linha, int coluna, char direcao) {
    for (int i = 0; i < tamanho_navio; i++) {
        int l = linha + (direcao == 'V' ? i : (direcao == 'D' ? i : (direcao == 'E' ? -i : 0)));
        int c = coluna + (direcao == 'H' ? i : (direcao == 'D' ? i : (direcao == 'E' ? i : 0)));

        if (l < 0 || l >= tamanho_tabuleiro || c < 0 || c >= tamanho_tabuleiro)
            return 0;
        if (tabuleiro[l][c] != codigo_agua)
            return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro], int linha, int coluna, char direcao) {
    for (int i = 0; i < tamanho_navio; i++) {
        int l = linha + (direcao == 'V' ? i : (direcao == 'D' ? i : (direcao == 'E' ? -i : 0)));
        int c = coluna + (direcao == 'H' ? i : (direcao == 'D' ? i : (direcao == 'E' ? i : 0)));
        tabuleiro[l][c] = codigo_navio;
    }
}


int main(){

    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
    int cone[tamanho_habilidade][tamanho_habilidade];
    int cruz[tamanho_habilidade][tamanho_habilidade];
    int octaedro[tamanho_habilidade][tamanho_habilidade];

    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = codigo_agua;
        }
    }

    if (podePosicionar(tabuleiro, 2, 3, 'H')) posicionarNavio(tabuleiro, 2, 3, 'H');
    if (podePosicionar(tabuleiro, 5, 6, 'V')) posicionarNavio(tabuleiro, 5, 6, 'V');
    if (podePosicionar(tabuleiro, 0, 0, 'D')) posicionarNavio(tabuleiro, 0, 0, 'D');
    if (podePosicionar(tabuleiro, 9, 0, 'E')) posicionarNavio(tabuleiro, 9, 0, 'E');


    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);


    aplicarHabilidade(tabuleiro, cone, 1, 5);
    aplicarHabilidade(tabuleiro, cruz, 7, 3);
    aplicarHabilidade(tabuleiro, octaedro, 6, 8);

    exibirTabuleiro(tabuleiro);

    return 0;
}