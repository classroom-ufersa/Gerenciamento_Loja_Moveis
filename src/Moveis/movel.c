#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movel.h"

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
		printf("Erro de alocacao na lista_movel_adiciona_ordenado\n");
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
	printf("Movel adicionado com sucesso\n");
	return Lista;
}

Movel *lista_movel_busca(Movel* lista, char nome[]){
	Movel *p = lista;
	for(p; p!=NULL; p=p->proximo){
		if(strcmp(nome, p->nome) == 0){
			return p;
			}
	}
	return NULL;
}

Movel *lista_movel_remove(Movel* lista, char nome[]){
	Movel* anterior = NULL; 
    Movel* p = lista;
    while(strcmp(p->nome,nome)!=0){
    	if (p==NULL){
        	return lista;
		}
        anterior = p;
        p = p->proximo;
    }
    if (anterior==NULL){
        lista = p->proximo;
	}	
    else {
        anterior->proximo = p->proximo;
	}
	printf("Movel removido com sucesso\n");
	printf("Pressione enter para continuar...");
	settings_press_enter();
    free(p);
    return lista;
}

Movel* lista_movel_edita(Movel* lista, char nome_busca[], char nome[], char tipo[], float preco, int qtd_estoque) { 
	Movel *p;
    for (p = lista; p != NULL; p = p->proximo) {
        if (strcmp(nome_busca, p->nome) == 0) {
            strcpy(p->nome, nome);
            strcpy(p->tipo, tipo);
            p->preco = preco;
            p->qtd_estoque = qtd_estoque;
			printf("Movel editado com sucesso\n");
            return lista;
        }
    }
    return lista;
}

int lista_movel_vazia(Movel* lista){ 
	return (lista==NULL);
}

void lista_movel_imprime(Movel* lista){ 
	Movel*p;
	for(p = lista; p != NULL; p = p->proximo){
		printf("Movel: %s\t\tPreco:R$%.1f\t\tTipo: %s\t\tQuantidade em estoque:%d\n", p->nome, p->preco,p->tipo, p->qtd_estoque);
	}
}
 
void lista_movel_libera(Movel* lista){
    Movel* p = lista;
    Movel* t;
    while (p != NULL) {
        t = p->proximo;
        free(p);
        p = t;
    }
}