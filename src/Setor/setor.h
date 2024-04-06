#ifndef SETOR_H
#define SETOR_H

#include "../Moveis/movel.c"

typedef struct setor Setor;

Setor* lista_setor_cria(void);

Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]);

Setor* lista_setor_busca(char nome[], Setor* l);

Setor* lista_setor_remove(Setor*a, char nome[]);

Setor *lista_ler_no_arquivo(Setor* a, char nome[]);

void imprime_moveis_setor(Setor*a);

void lista_setor_libera(Setor* l);

void lista_setor_imprime(Setor*a);

void lista_salvar_no_arquivo(Setor* a, char nome[]);

int lista_setor_vazia(Setor* a);

#endif //SETOR_H