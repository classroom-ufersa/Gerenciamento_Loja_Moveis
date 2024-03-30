#ifndef MOVEL_H
#define MOVEL_H

#include "../Configs/settings.c"

typedef struct movel Movel;

Movel* lista_movel_cria(void);

Movel* lista_movel_adiciona_ordenado(Movel* Lista, char nome[], char tipo[], float preco, int qtd_estoque);

int lista_movel_vazia(Movel* l);

void lista_movel_imprime(Movel*l);

Movel* lista_movel_busca(char nome[], Movel* l);

Movel* lista_movel_retira(Movel*l, char nome[]);

void lista_movel_libera(Movel** l);

Movel* lista_movel_edita(Movel* l, char nome_busca[], char nome[], char tipo[], float preco, int qdt_estoque);

#endif //MOVEL_H