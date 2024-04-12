#ifndef SETOR_H
#define SETOR_H

#include "../Moveis/moveis.c"

typedef struct setor Setor;

// Cria uma lista de setores
Setor* lista_setor_cria(void);

// Adiciona um setor na lista de forma ordenada
Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]);

// Busca um setor na lista
Setor* lista_setor_busca(char nome[], Setor* lista);

// Remove um setor da lista
Setor* lista_setor_remove(Setor*lista, char nome[]);

// Le um arquivo e salva os setores e moveis
Setor *lista_ler_no_arquivo(Setor* lista, char nome[]);

// Imprime os moveis de um setor
void imprime_moveis_setor(Setor* lista);

// Libera lista lista de setores
void lista_setor_libera(Setor* lista);

// Imprime lista lista de setores
void lista_setor_imprime(Setor* lista);

// Salva os setores e moveis em um arquivo
void lista_escrever_no_arquivo(Setor* lista, char nome[]);

// Verifica se lista lista de setores esta vazia
int lista_setor_vazia(Setor* lista);

#endif //SETOR_H