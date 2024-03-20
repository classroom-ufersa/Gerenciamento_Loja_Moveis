#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movel.h"

#define Max 50
struct movel {
    char nome[Max];
    char tipo[Max];
    float preco;
    int qtd_estoque;
    int info;
    struct movel* prox;
};

typedef struct movel Movel;

Movel* lista_cria_movel(void) {
    return NULL;
}

Movel* lista_movel_adiciona_ordenado(Movel* Lista, char nome[], char tipo[], float preco, int qtd_estoque, int v){
    Movel* novo;
	Movel* ant = NULL;
	Movel* p = Lista;
	while(p!=NULL && strcmp(nome, p->nome) > 0){
		ant = p;
		p = p->prox;
	}

	novo = (Movel*) malloc(sizeof(Movel));
	novo->info = v;
	if(ant ==NULL){
		novo->prox = Lista;
		Lista = novo;
	}
	else {
		novo->prox = ant-> prox;
		ant->prox = novo;
	}
	return Lista;
}

int lista_movel_vazia(Movel* a){

}

void lista_movel_imprime(Movel*a){

}

Movel * lista_movel_busca(int elemento, Movel* l){

}

Movel * lista_movel_retira(Movel*a, char nome[]){

}