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

Movel* lista_movel_cria(void) {
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
	if (novo == NULL){
		printf("Erro de alocação");
		exit(1);
	}
	strcpy(novo->nome,nome);
    strcpy(novo->tipo,tipo);
	novo->preco = preco;
	novo->qtd_estoque = qtd_estoque;
	if(anterior == NULL){
		novo->proximo = Lista;
		Lista = novo;
	}
	else {
		novo->proximo = anterior-> proximo;
		anterior->proximo = novo;
	}
	return Lista;
}

int lista_movel_vazia(Movel* l){
	return (l==NULL);
}

void lista_movel_imprime(Movel*l){
	Movel*p;
	for(p = l; p != NULL; p = p->proximo){
		printf("Nome: %s\t\tPreco: %.2f\t\tTipo: %s\t\tQuantidade em estoque:%d\n", p->nome, p->preco,p->tipo, p->qtd_estoque);
	}
}

Movel *lista_movel_busca(char nome[], Movel* l){
	Movel *p;
	for(p=l; p!=NULL; p=p->proximo){
		if(strcmp(nome, p->nome) == 0){
			return p;
			}
	}
	return NULL;
}

Movel *lista_movel_retira(Movel*l, char nome[]){
	Movel* anterior = NULL; 
    Movel* p = l;
    while(strcmp(p->nome,nome)!=0){
    	if (p==NULL){
        	return l;
		}
        anterior = p;
        p = p->proximo;
    }
    if (anterior==NULL){
        l = p->proximo;
	}	
    else {
        anterior->proximo = p->proximo;
	}
    free(p);
    return l;
} 

Movel* lista_movel_edita(Movel* l, char nome_busca[], char nome[], char tipo[], float preco, int qtd_estoque) {
	Movel *p;
    for (p = l; p != NULL; p = p->proximo) {
        if (strcmp(nome_busca, p->nome) == 0) {
            strcpy(p->nome, nome);
            strcpy(p->tipo, tipo);
            p->preco = preco;
            p->qtd_estoque = qtd_estoque;
            return l;
        }
    }
    return l;
}

void lista_movel_libera(Movel** l){
    Movel* p = *l;
    Movel* t;
    while (p != NULL) {
        t = p->proximo;
        free(p);
        p = t;
    }
}