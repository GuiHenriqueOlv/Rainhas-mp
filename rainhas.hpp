/// Copyright[2023]<Guilherme Henrique Oliveira Araujo>
/// \file rainhas.hpp
/// \brief Arquivo de cabeçalho para resolver o problema das N-Rainhas.
///
/// Este arquivo contém declarações de funções relacionadas à resolução do problema das N-Rainhas.
/// O problema das N-Rainhas é um quebra-cabeça clássico de posicionar N rainhas de xadrez em um tabuleiro
/// N x N de forma que nenhuma rainha ameace outra.
///
/// \author Guilherme Henrique Oliveira Araujo
/// \date 2023

#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

#include <vector>

/// \brief Valida o vetor de entrada para o problema das N-Rainhas.
///
/// Esta função verifica se o vetor de entrada contém posições válidas para as rainhas no problema das N-Rainhas.
/// O vetor deve representar uma permutação dos números de 0 a N-1, onde cada número representa a posição da linha
/// da rainha na coluna correspondente.
///Assertivas de entrada:
/// \param vetorTab O vetor de entrada que representa as posições das rainhas.
///Assertivas de saída:
/// \return 0 se o vetor for válido, -1 caso contrário.
int validaVetor(const std::vector<int>& vetorTab);

/// \brief Verifica se as rainhas no tabuleiro se ameaçam em linhas e colunas.
///
/// Esta função verifica se as rainhas no tabuleiro se ameaçam em linhas e colunas.
/// Ela verifica se há algum conflito na mesma linha ou coluna.
///Assertivas de entrada:
/// \param vetorTab O vetor que representa as posições das rainhas.
///Assertivas de saída:
/// \return 0 se nenhum conflito for encontrado, -1 caso contrário.
int verificaLinhaEColuna(const std::vector<int>& vetorTab);

/// \brief Verifica se as rainhas no tabuleiro se ameaçam em diagonais.
///
/// Esta função verifica se as rainhas no tabuleiro se ameaçam em diagonais.
/// Ela verifica se há algum conflito nas diagonais.
///Assertivas de entrada:
/// \param vetorTab O vetor que representa as posições das rainhas.
///Assertivas de saída:
/// \return 0 se nenhum conflito for encontrado, -1 caso contrário.
int verificaDiagonais(const std::vector<int>& vetorTab);

/// \brief Verifica se o vetor de entrada representa uma solução válida para o problema das N-Rainhas.
///
/// Esta função verifica se o vetor de entrada representa uma solução válida para o problema das N-Rainhas.
/// Ela valida o vetor verificando se não há conflitos em linhas, colunas e diagonais.
///Assertivas de entrada:
/// \param vetorTab O vetor de entrada que representa as posições das rainhas.
///Assertivas de saída:
/// \return 0 se o vetor representa uma solução válida, -1 caso contrário.
int verificaSolucao(const std::vector<int>& vetorTab);

#endif  // RAINHAS_HPP_
