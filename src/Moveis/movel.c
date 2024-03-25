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
    struct movel* proximo;
};

typedef struct movel Movel;

Movel* lista_cria_movel(void) {
    return NULL;
}

Movel* lista_movel_adiciona_ordenado(Movel* Lista, char nome[], char tipo[], float preco, int qtd_estoque){
    Movel* novo;
	Movel* anterior = NULL;
	Movel* p = Lista;
	while(p!=NULL && strcmp(nome, p->nome) > 0){
		anterior = p;
		p = p->proximo;
	}
	novo = (Movel*) malloc(sizeof(Movel));
	if (novo ==NULL){
		printf("Erro de alocação");
		exit(1);
	}
	novo->nome = nome;
	novo->tipo = nome;
	novo->preco = preco;
	novo->qtd_estoque = qtd_estoque;
	if(anterior ==NULL){
		novo->proximo = Lista;
		Lista = novo;
	}
	else {
		novo->proximo = anterior-> proximo;
		anterior->proximo = novo;
	}
	return Lista;
}

int lista_movel_vazia(Movel* a){
	return (a==NULL);
}

void lista_movel_imprime(Movel*a){
	Movel*p;
	for(p=a; p!=NULL; p=p->proximo){
		printf("Nome: %s\n, Preco: %f\n, Tipo: %s\n, Quantidade em estoque:%d\n ", p->nome, p->preco,p->tipo, p->qtd_estoque);
	}
}

Movel * lista_movel_busca(char nome[], Movel* l){
	Movel *p;
	for(p=l; p!=NULL; p=p->proximo){
		if(p->nome==nome){
			return p;
			}
	}
	return NULL;
}

Movel * lista_movel_retira(Movel*a, char nome[]){
	Movel* ant = NULL; 
    Movel* p = a;
    while(p->nome!=nome){
    	if (p==NULL)
        	return a;
        ant = p;
        p = p->proximo;
    }
    if (ant==NULL)
        a = p->proximo;
    else
        ant->proximo = p->proximo;
    free(p);
    return a;
}

void lista_movel_libera(Movel* l){
    Movel* p = l;
    Movel* t;
    while (p != NULL) {
        t = p->proximo;
        free(p);
        p = t;
    }
}