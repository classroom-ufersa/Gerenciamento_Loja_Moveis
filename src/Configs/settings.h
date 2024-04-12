/**
 * @file settings.h
 * @brief Este arquivo contém definições de funções e constantes relacionadas às configurações do programa.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max 50 ///< Tamanho máximo de uma string

/**
 * @brief Exibe o menu de configurações.
 */
void settings_menu(void);

/**
 * @brief Limpa o buffer do teclado.
 */
void settings_limpa_buffer(void);

/**
 * @brief Transforma uma string para maiúsculas.
 * 
 * @param string A string a ser transformada em maiúsculas.
 */
void settings_captalize(char *string);

/**
 * @brief Limpa a tela do console.
 */
void settings_clear(void);

/**
 * @brief Aguarda o usuário pressionar a tecla Enter.
 */
void settings_press_enter(void);

/**
 * @brief Verifica se a string passada contém apenas caracteres alfanuméricos.
 * 
 * @param string A string a ser verificada.
 * @return 1 se a string contém apenas caracteres alfanuméricos, 0 caso contrário.
 */
int settings_str_verify(char *string);

/**
 * @brief Exibe as opções disponíveis e obtém a escolha do usuário.
 * 
 * @param opcao A string que contém as opções válidas.
 * @return O índice da opção escolhida pelo usuário.
 */
int settings_options(char *opcao);

#endif // SETTINGS_H
