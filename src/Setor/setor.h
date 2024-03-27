#ifndef SETOR_H
#define SETOR_H

#include "../Moveis/movel.c"

typedef struct setor Setor;

Setor* lista_setor_cria(void);

Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]);

int lista_setor_vazia(Setor* a);

void lista_setor_libera(Setor* l);

Setor * lista_setor_retira(Setor*a, char nome[]);

void lista_setor_imprime(Setor*a);

#endif //SETOR_H