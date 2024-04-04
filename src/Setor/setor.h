#ifndef SETOR_H
#define SETOR_H

#include "../Moveis/movel.c"

typedef struct setor Setor;

Setor* lista_setor_cria(void);

void imprime_moveis_setor(Setor*a);

Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]);

Setor* lista_setor_busca(char nome[], Setor* l);

int lista_setor_vazia(Setor* a);

void lista_setor_libera(Setor* l);

Setor* lista_setor_retira(Setor*a, char nome[]);

void lista_setor_imprime(Setor*a);

void lista_salvar_no_arquivo(Setor* a, char nome[]);

#endif //SETOR_H