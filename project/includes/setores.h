/**
 * @file setor.h
 * @brief Este arquivo contém definições de estruturas e funções relacionadas aos setores.
 */

#ifndef SETOR_H
#define SETOR_H

#include "../src/moveis.c"

/**
 * @struct setor
 * @brief Estrutura que representa um setor.
 */
typedef struct setor Setor;

/**
 * @brief Cria uma lista de setores.
 *
 * @return Um ponteiro para a lista de setores criada.
 */
Setor *lista_setor_cria(void);

/**
 * @brief Adiciona um setor na lista de forma ordenada.
 *
 * @param Lista A lista de setores onde o setor será adicionado.
 * @param nome O nome do setor a ser adicionado.
 * @param descricao A descrição do setor a ser adicionado.
 * @return Um ponteiro para a lista atualizada de setores.
 */
Setor *lista_setor_adiciona_ordenado(Setor *Lista, char nome[], char descricao[]);

/**
 * @brief Busca um setor na lista pelo nome.
 *
 * @param nome O nome do setor a ser buscado.
 * @param lista A lista de setores onde o setor será buscado.
 * @return Um ponteiro para o setor encontrado, ou NULL se não encontrado.
 */
Setor *lista_setor_busca(char nome[], Setor *lista);

/**
 * @brief Remove um setor da lista pelo nome.
 *
 * @param lista A lista de setores onde o setor será removido.
 * @param nome O nome do setor a ser removido.
 * @return Um ponteiro para a lista atualizada de setores.
 */
Setor *lista_setor_remove(Setor *lista, char nome[]);

/**
 * @brief Lê um arquivo e salva os setores e móveis.
 *
 * @param lista A lista de setores onde os setores e móveis serão salvos.
 * @param nome O nome do arquivo a ser lido.
 * @return Um ponteiro para a lista atualizada de setores.
 */
Setor *lista_ler_no_arquivo(Setor *lista, char nome[]);

/**
 * @brief Imprime os móveis de um setor.
 *
 * @param lista A lista de setores onde os móveis serão impressos.
 */
void imprime_moveis_setor(Setor *lista);

/**
 * @brief Libera a memória alocada para a lista de setores.
 *
 * @param lista A lista de setores a ser liberada.
 */
void lista_setor_libera(Setor *lista);

/**
 * @brief Imprime a lista de setores.
 *
 * @param lista A lista de setores a ser impressa.
 */
void lista_setor_imprime(Setor *lista);

/**
 * @brief Salva os setores e móveis em um arquivo.
 *
 * @param lista A lista de setores a ser salva.
 * @param nome O nome do arquivo onde os setores e móveis serão salvos.
 */
void lista_escrever_no_arquivo(Setor *lista, char nome[]);

/**
 * @brief Verifica se a lista de setores está vazia.
 *
 * @param lista A lista de setores a ser verificada.
 * @return 1 se a lista estiver vazia, 0 caso contrário.
 */
int lista_setor_vazia(Setor *lista);

#endif // SETOR_H