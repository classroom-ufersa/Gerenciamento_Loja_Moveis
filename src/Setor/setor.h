#ifndef SETOR_H
#define SETOR_H

#include "../Moveis/movel.c"

typedef struct setor Setor;

// Cria uma lista de setores
Setor* lista_setor_cria(void);

// Adiciona um setor na lista de forma ordenada
Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]);

// Busca um setor na lista
Setor* lista_setor_busca(char nome[], Setor* l);

// Remove um setor da lista
Setor* lista_setor_remove(Setor*a, char nome[]);

// Le um arquivo e salva os setores e moveis
Setor *lista_ler_no_arquivo(Setor* a, char nome[]);

// Imprime os moveis de um setor
void imprime_moveis_setor(Setor*a);

// Libera a lista de setores
void lista_setor_libera(Setor* l);

// Imprime a lista de setores
void lista_setor_imprime(Setor*a);

// Salva os setores e moveis em um arquivo
void lista_escrever_no_arquivo(Setor* a, char nome[]);

// Verifica se a lista de setores esta vazia
int lista_setor_vazia(Setor* a);

#endif //SETOR_H