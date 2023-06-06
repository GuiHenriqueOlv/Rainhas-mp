#include <vector>
#include <algorithm>

int verificaLinhaEColuna(const std::vector<int>& vetorTab) {
    for (int i = 0; i < 8; i++) {
        int numRainhas = std::count(vetorTab.begin() + i * 8, vetorTab.begin() + (i + 1) * 8, 1);
        if (numRainhas > 1) {
            return 0;  // Mais de uma rainha na mesma linha
        }
    }

    return 1;  // É uma solução válida
}

int verificaDiagonais(const std::vector<int>& vetorTab) {
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            if (vetorTab[linha * 8 + coluna] == 1) {
                // Verificar diagonais principais
                for (int i = 1; i < 8; i++) {
                    if (linha + i < 8 && coluna + i < 8) {
                        if (vetorTab[(linha + i) * 8 + (coluna + i)] == 1) {
                            return 0;  // Mais de uma rainha na mesma diagonal principal
                        }
                    }
                    if (linha - i >= 0 && coluna - i >= 0) {
                        if (vetorTab[(linha - i) * 8 + (coluna - i)] == 1) {
                            return 0;  // Mais de uma rainha na mesma diagonal principal
                        }
                    }
                }

                // Verificar diagonais secundárias
                for (int i = 1; i < 8; i++) {
                    if (linha - i >= 0 && coluna + i < 8) {
                        if (vetorTab[(linha - i) * 8 + (coluna + i)] == 1) {
                            return 0;  // Mais de uma rainha na mesma diagonal secundária
                        }
                    }
                    if (linha + i < 8 && coluna - i >= 0) {
                        if (vetorTab[(linha + i) * 8 + (coluna - i)] == 1) {
                            return 0;  // Mais de uma rainha na mesma diagonal secundária
                        }
                    }
                }
            }
        }
    }

    return 1;  // É uma solução válida
}


