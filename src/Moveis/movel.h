#ifndef MOVEL_H
#define MOVEL_H

#include "../Configs/settings.c" 

typedef struct movel Movel; 

// Cria uma lista de moveis
Movel* lista_movel_cria(void);

// Adiciona um movel na lista de forma ordenada
Movel* lista_movel_adiciona_ordenado(Movel* Lista, char nome[], char tipo[], float preco, int qtd_estoque);

// Busca um movel na lista
Movel* lista_movel_busca(char nome[], Movel* l);

// Remove um movel da lista
Movel* lista_movel_remove(Movel*l, char nome[]);

// Edita um movel da lista
Movel* lista_movel_edita(Movel* l, char nome_busca[], char nome[], char tipo[], float preco, int qdt_estoque);

// Verifica se a lista de moveis esta vazia
int lista_movel_vazia(Movel* l);

// Imprime a lista de moveis
void lista_movel_imprime(Movel*l);

// Libera a lista de moveis
void lista_movel_libera(Movel** l);

#endif // MOVEL_H