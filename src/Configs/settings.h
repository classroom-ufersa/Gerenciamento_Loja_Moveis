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

void settings_str_verify(char *nome);



#endif //SETTINGS_H