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