#include <vector>
#include <algorithm>
#include <cassert>

int validaVetor(const std::vector<int>& vetorTab) {
    int rainhas = 0;
    if (vetorTab.size() != 64) {
        return -1;  // Tamanho inválido
    }

    for (int quadrado : vetorTab) {
        if (quadrado == 1) {
            rainhas++;
        }
        assert(quadrado == 0 || quadrado == 1);
    }

    if (rainhas != 8) {
        return -1;  // Não tem 8 rainhas
    }

    return 1;  // É uma solução válida
}

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
    for (int linha1 = 0; linha1 < 8; linha1++) {
        for (int coluna1 = 0; coluna1 < 8; coluna1++) {
            if (vetorTab[linha1 * 8 + coluna1] == 1) {
                for (int linha2 = linha1 + 1; linha2 < 8; linha2++) {
                    for (int coluna2 = 0; coluna2 < 8; coluna2++) {
                        if (vetorTab[linha2 * 8 + coluna2] == 1) {
                            if (coluna1 == coluna2 ||
                                linha1 + coluna1 == linha2 + coluna2 ||
                                linha1 - coluna1 == linha2 - coluna2) {
                                return 0;  // Mais de uma rainha na mesma diagonal
                            }
                        }
                    }
                }
            }
        }
    }

    return 1;  // É uma solução válida
}

int verificaSolucao(const std::vector<int>& vetorTab) {
    int validacao = validaVetor(vetorTab);
    if (validacao == -1) {
        return -1;  // Vetor inválido
    }

    if (validacao != 1) {
        return 0;  // Mais ou menos de 8 rainhas
    }

    if (verificaLinhaEColuna(vetorTab) != 1 || verificaDiagonais(vetorTab) != 1) {
        return 0;  // Não é uma solução válida
    }

    return 1;  // É uma solução válida
}