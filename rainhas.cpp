#include <vector>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <iostream>

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

    for (int coluna = 0; coluna < 8; coluna++) {
        int rainhas = 0;
        for (int linha = 0; linha < 8; linha++) {
            if (vetorTab[linha * 8 + coluna] == 1) {
                rainhas++;
            }
        }
        if (rainhas > 1) {
            return 0;  // Mais de uma rainha na mesma coluna
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

int verificaSolucao(const std::vector<int>& vetorTab) {
    if (validaVetor(vetorTab) != 1) {
        return -1;  // Entrada inválida
    }

    if (verificaLinhaEColuna(vetorTab) != 1 || verificaDiagonais(vetorTab) != 1) {
        std::ofstream outFile("ataques.txt");
        if (!outFile) {
            std::cout << "Erro ao criar o arquivo 'ataques.txt'." << std::endl;
            return -1;
        }
        for (int linha1 = 0; linha1 < 8; linha1++) {
            for (int coluna1 = 0; coluna1 < 8; coluna1++) {
                if (vetorTab[linha1 * 8 + coluna1] == 1) {
                    for (int linha2 = linha1 + 1; linha2 < 8; linha2++) {
                        for (int coluna2 = 0; coluna2 < 8; coluna2++) {
                            if (vetorTab[linha2 * 8 + coluna2] == 1) {
                                if (coluna1 == coluna2 ||
                                    linha1 - coluna1 == linha2 - coluna2 ||
                                    linha1 + coluna1 == linha2 + coluna2) {
                                    outFile << linha1 << "," << coluna1 << " " << linha2 << "," << coluna2 << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        outFile.close();
        return 0;  // Não é uma solução válida
    }

    return 1;  // É uma solução válida
}