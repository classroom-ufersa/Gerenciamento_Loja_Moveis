#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define Max 50

//Funções gerais

void settings_menu(void);

void settings_limpa_buffer(void);

void settings_captalize(char *nome);

void settings_clear(void);

void settings_press_enter(void);

int settings_str_verify(char *nome);

int settings_options(char *opcao);



#endif //SETTINGS_H