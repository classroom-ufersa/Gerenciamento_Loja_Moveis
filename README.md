# Gerenciamento_Loja_Moveis

Sistema criado para o gerenciamento de uma loja de móveis: 

Este sistema é capaz de armazenar setores e móveis por meio do uso de listas encadeadas interligadas. É criada uma lista encadeada de setores, onde cada nó dessa lista contém uma lista encadeada de móveis, estabelecendo uma conexão entre ambos. O usuário é capaz de adicionar, remover, editar e buscar um móvel específico dentro de cada setor criado, além de adicionar e remover esses setores.

## Topicos

- [Lista de arquivos](#Lista-de-arquivos)
- [Como executar o projeto](#Como-executar-o-projeto)
- [Menu principal](#Menu-principal)
- [Adicionar movel](#Adicionar-movel)
- [Remover movel](#Remover-movel)
- [Editar movel](#Editar-movel)
- [Adicionar setor](#Adicionar-setor)
- [Remover setor](#Remover-setor)
- [Listar setores e moveis](#Listar-setores-e-moveis)
- [Buscar movel](#Buscar-movel)
- [Sair](#Sair)

## Lista de arquivos

- project
  - bin
    - main.exe
  - data
    - DataBase.txt
  - includes
    - moveis.h
    - setores.h
    - settings.h
  - src
    - main.c
    - moveis.c
    - setores.c
    - settings.c
  - gitignore
  - README.md

## Como executar o projeto

Para executar o projeto, basta abrir o arquivo main.c no terminal integrado e executar os seguintes passos:

    1° Passo: gcc main.c -o ../bin/main.exe	 

    2° Passo: ../bin/main.exe

## Menu principal

- Adicionar móvel
- Remover móvel
- Editar móvel
- Adicionar novo setor
- Remover setor existente
- Listar todos os setores e móveis
- Buscar móvel
- Sair

## Adicionar móvel

Esta função adiciona um movel a lista de moveis de forma ordenada, ou seja, o movel é adicionado de forma que a lista permaneça ordenada alfabeticamente.

```c
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
```

## Remover móvel

Esta função remove um movel da lista de moveis, caso o movel não seja encontrado, a função retorna a lista sem alterações.

```c
Movel* lista_movel_remove(Movel* lista, char nome[]){
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
```

## Editar móvel

Esta função permite a edição de um movel e todos os seus atributos caso o movel seja encontrado na lista.
```c
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
```

## Adicionar setor

Esta função adiciona um setor a lista de setores de forma ordenada, ou seja, o setor é adicionado de forma que a lista permaneça ordenada alfabeticamente.

```c
Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]){ 
    Setor* novo;
    Setor* anterior = NULL;
    Setor* p = Lista;
    while(p != NULL && strcmp(nome, p->nome) > 0){
        anterior = p;
        p = p->proximo;
    }
    novo = (Setor*) malloc(sizeof(Setor));
    if (novo == NULL){
        printf("Erro de alocacao");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->descricao, descricao);
    novo->moveis = NULL;
    if(anterior == NULL){
        novo->proximo = Lista;
        Lista = novo;
    }
    else {
        novo->proximo = anterior-> proximo;
        anterior->proximo = novo;
    }
    printf("Setor adicionado com sucesso\n");
    return Lista;
}
```

## Remover setor

Esta função remove um setor da lista de setores, caso o setor não seja encontrado, a função retorna a lista sem alterações.

```c
Setor* lista_setor_remove(Setor* lista, char nome[]){ 
	Setor *anterior = NULL; 
    Setor *p = lista;
    while(strcmp(p->nome, nome)!=0){
        anterior = p;
        p = p->proximo;
        if (p==NULL){
            printf("Setor nao encontrado\n");
        	return lista;
        }
    }
    if (anterior==NULL){
        lista = p->proximo;
        printf("Setor removido com sucesso\n");
        settings_press_enter();
    }
    else{
        anterior->proximo = p->proximo;
    }
    free(p);
    return lista;
}
```

## Listar setores e móveis

Esta função imprime todos os setores e seus respectivos moveis.

```c
void imprime_moveis_setor(Setor* lista){ 
    Setor*p;
	for(p = lista; p != NULL; p = p->proximo){
		printf("Setor: %s\t\t%s\n", p->nome, p->descricao);
        lista_movel_imprime(p->moveis);
        printf("\n");
	}
}

void lista_movel_imprime(Movel* lista){ 
	Movel*p;
	for(p = lista; p != NULL; p = p->proximo){
		printf("Movel: %s\t\tPreco:R$%.1f\t\tTipo: %s\t\tQuantidade em estoque:%d\n", p->nome, p->preco,p->tipo, p->qtd_estoque);
	}
}
```

## Buscar móvel

Essa função busca um movel na lista de moveis e retorna o movel caso ele seja encontrado.

```c
Movel *lista_movel_busca(Movel* lista, char nome[]){
	Movel *p = lista;
	for(p; p!=NULL; p=p->proximo){
		if(strcmp(nome, p->nome) == 0){
			return p;
			}
	}
	return NULL;
}
```

## Sair

Essa opção encerra o programa.

```c
case '8': //main.c
                break;
            default:
                printf("Digite uma opcao valida...");
                break;
            }
        }
        else printf("Digite uma opcao valida...");
    } while (op_menu[0] != '8');
    printf("Programa encerrado");
```

## Desenvolvedores
>[Marcelo Henrique 🥇](https://github.com/marcelohenrique0)
>
>[Nattan Ferreira 🥇](https://github.com/NattanFerreira)