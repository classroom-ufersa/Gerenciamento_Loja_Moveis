/**
 * @file movel.h
 * @brief Este arquivo contém definições de estruturas e funções relacionadas a móveis.
 */

#ifndef MOVEL_H
#define MOVEL_H

#include "../Configs/settings.c"

/**
 * @struct movel
 * @brief Estrutura que representa um móvel.
 */
typedef struct movel Movel;

/**
 * @brief Cria uma lista de móveis.
 * 
 * @return Um ponteiro para a lista de móveis criada.
 */
Movel* lista_movel_cria(void);

/**
 * @brief Adiciona um móvel na lista de forma ordenada.
 * 
 * @param Lista A lista de móveis onde o móvel será adicionado.
 * @param nome O nome do móvel a ser adicionado.
 * @param tipo O tipo do móvel a ser adicionado.
 * @param preco O preço do móvel a ser adicionado.
 * @param qtd_estoque A quantidade em estoque do móvel a ser adicionado.
 * @return Um ponteiro para a lista atualizada de móveis.
 */
Movel* lista_movel_adiciona_ordenado(Movel* Lista, char nome[], char tipo[], float preco, int qtd_estoque);

/**
 * @brief Busca um móvel na lista pelo nome.
 * 
 * @param lista A lista de móveis onde o móvel será buscado.
 * @param nome O nome do móvel a ser buscado.
 * @return Um ponteiro para o móvel encontrado, ou NULL se não encontrado.
 */
Movel* lista_movel_busca(Movel* lista, char nome[]);

/**
 * @brief Remove um móvel da lista pelo nome.
 * 
 * @param lista A lista de móveis onde o móvel será removido.
 * @param nome O nome do móvel a ser removido.
 * @return Um ponteiro para a lista atualizada de móveis.
 */
Movel* lista_movel_remove(Movel* lista, char nome[]);

/**
 * @brief Edita um móvel na lista.
 * 
 * @param lista A lista de móveis onde o móvel será editado.
 * @param nome_busca O nome do móvel a ser editado.
 * @param nome O novo nome do móvel.
 * @param tipo O novo tipo do móvel.
 * @param preco O novo preço do móvel.
 * @param qdt_estoque A nova quantidade em estoque do móvel.
 * @return Um ponteiro para a lista atualizada de móveis.
 */
Movel* lista_movel_edita(Movel* lista, char nome_busca[], char nome[], char tipo[], float preco, int qdt_estoque);

/**
 * @brief Verifica se a lista de móveis está vazia.
 * 
 * @param lista A lista de móveis a ser verificada.
 * @return 1 se a lista estiver vazia, 0 caso contrário.
 */
int lista_movel_vazia(Movel* lista);

/**
 * @brief Imprime a lista de móveis.
 * 
 * @param lista A lista de móveis a ser impressa.
 */
void lista_movel_imprime(Movel* lista);

/**
 * @brief Libera a memória alocada para a lista de móveis.
 * 
 * @param lista A lista de móveis a ser liberada.
 */
void lista_movel_libera(Movel* lista);

#endif // MOVEL_H
