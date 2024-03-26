#include "setor.h"

struct setor{
    char nome[50];
    char descricao[50];
    Movel* moveis;
    struct setor *proximo;
};

Setor* lista_cria_setor(void) {
    return NULL;
}

Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]){
    Setor* novo;
	Setor* anterior = NULL;
	Setor* p = Lista;
	while(p!=NULL && strcmp(nome, p->nome) > 0){
		anterior = p;
		p = p->proximo;
	}
	novo = (Setor*) malloc(sizeof(Setor));
	if (novo ==NULL){
		printf("Erro de alocação");
		exit(1);
	}
	strcpy(nome, novo->nome);
    strcpy(descricao, novo->descricao);
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

int lista_setor_vazia(Setor* a){
	return (a==NULL);
}

void lista_setor_libera(Setor* l){
    Setor* p = l;
    Setor* t;
    while (p != NULL) {
        t = p->proximo;
        free(p);
        p = t;
    }
}

Setor * lista_setor_retira(Setor*a, char nome[]){
	Setor *ant = NULL; 
    Setor *p = a;
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

void lista_setor_imprime(Setor*a){
	Setor*p;
	for(p=a; p!=NULL; p=p->proximo){
		printf("Nome: %s\n, Descricao: %s\n", p->nome, p->descricao);
	}
}