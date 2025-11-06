#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro (reutilizada)
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n   0 1 2 3 4 5 6 7 8 9\n");
    printf("  ---------------------\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); 
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tab[i][j]); 
        }
        printf("\n"); 
    }
}

int main() {
    
    // 1. Represente o Tabuleiro: Matriz 10x10, inicializada com 0 (Água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {AGUA}; // Inicializa todos com 0
    
    // 2. Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios
    // Ambos são preenchidos com o valor 3 (NAVIO)
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO}; // {3, 3, 3}
    int navio_vertical[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};   // {3, 3, 3}

    
    // --- Posicionamento do Navio Horizontal (Início: Linha 2, Coluna 1) ---
    int linha_h = 2; 
    int coluna_h = 1; 
    
    // Loop para COPIAR o valor 3 de cada posição do vetor para o tabuleiro
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        // tabuleiro[Linha Fixa][Coluna Inicial + j] = valor do vetor navio_horizontal[j]
        tabuleiro[linha_h][coluna_h + j] = navio_horizontal[j];
    }

    
    // --- Posicionamento do Navio Vertical (Início: Linha 5, Coluna 6) ---
    int linha_v = 5; 
    int coluna_v = 6; 
    
    // Loop para COPIAR o valor 3 de cada posição do vetor para o tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // tabuleiro[Linha Inicial + i][Coluna Fixa] = valor do vetor navio_vertical[i]
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

  // --- Posicionamento do Navio diagonal 1 (Início: linha 5, coluna 1)
     int linha_inicial_p = 5;
     int coluna_inicial_p = 1;
 // k representa o (deslocamento)
for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int i = linha_inicial_p + k;
        int j = coluna_inicial_p + k;
        
        // Colocamos uma checagem simples de limite para garantir que funcione
        if (i < TAMANHO_TABULEIRO && j < TAMANHO_TABULEIRO) {
            tabuleiro[i][j] = NAVIO; 
        }
    }

      // --- Posicionamento do Navio diagonal 2 (Início: linha 0, coluna 7)

    int linha_inicial_s = 0;
    int coluna_inicial_s = 7; 
    
    // k representa o (deslocamento)
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int i = linha_inicial_s + k; // A linha aumenta
        int j = coluna_inicial_s - k; // A coluna diminui
        
        // Colocamos uma checagem simples de limite para garantir que funcione
        if (i < TAMANHO_TABULEIRO && j >= 0) {
            tabuleiro[i][j] = NAVIO; 
        }
     } 
    // 3. Exiba o Tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
