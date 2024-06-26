#include "../includes/setores.h"

struct setor
{
    char nome[Max];
    char descricao[Max];
    Movel *moveis;
    struct setor *proximo;
};

Setor *lista_setor_cria(void)
{
    return NULL;
}

Setor *lista_setor_adiciona_ordenado(Setor *Lista, char nome[], char descricao[])
{
    Setor *novo;
    Setor *anterior = NULL;
    Setor *p = Lista;
    while (p != NULL && strcmp(nome, p->nome) > 0)
    {
        anterior = p;
        p = p->proximo;
    }
    novo = (Setor *)malloc(sizeof(Setor));
    if (novo == NULL)
    {
        printf("Erro de alocacao");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->descricao, descricao);
    novo->moveis = NULL;
    if (anterior == NULL)
    {
        novo->proximo = Lista;
        Lista = novo;
    }
    else
    {
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    printf("Setor adicionado com sucesso\n");
    return Lista;
}

Setor *lista_setor_busca(char nome[], Setor *lista)
{
    Setor *p;
    for (p = lista; p != NULL; p = p->proximo)
    {
        if (strcmp(nome, p->nome) == 0)
        {
            return p;
        }
    }
    printf("Setor nao encontrado\n");
    return NULL;
}

Setor *lista_setor_remove(Setor *lista, char nome[])
{
    Setor *anterior = NULL;
    Setor *p = lista;
    while (strcmp(p->nome, nome) != 0)
    {
        anterior = p;
        p = p->proximo;
        if (p == NULL)
        {
            printf("Setor nao encontrado\n");
            return lista;
        }
    }
    if (anterior == NULL)
    {
        lista = p->proximo;
        printf("Setor removido com sucesso\n");
        settings_press_enter();
    }
    else
    {
        anterior->proximo = p->proximo;
    }
    free(p);
    return lista;
}

Setor *lista_ler_no_arquivo(Setor *lista, char nome[])
{
    FILE *file = fopen(nome, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    char linha[200];
    char setor[Max], descricao[Max], movel[Max], tipo[Max];
    float preco;
    int quantidade;
    Setor *aux;
    while (fgets(linha, 200, file) != NULL)
    {
        if (strstr(linha, "Setor:") != NULL)
        {
            sscanf(linha, "Setor:%[^\t]\t%[^\n]", setor, descricao);
            lista = lista_setor_adiciona_ordenado(lista, setor, descricao);
            aux = lista_setor_busca(setor, lista);
        }
        else
        {
            sscanf(linha, "Movel:%[^\t]\t%[^\t]\t%f\t%d", movel, tipo, &preco, &quantidade);
            aux->moveis = lista_movel_adiciona_ordenado(aux->moveis, movel, tipo, preco, quantidade);
        }
    }
    fclose(file);
    return lista;
}

void imprime_moveis_setor(Setor *lista)
{
    Setor *p;
    for (p = lista; p != NULL; p = p->proximo)
    {
        printf("Setor: %s\t\t%s\n", p->nome, p->descricao);
        lista_movel_imprime(p->moveis);
        printf("\n");
    }
}

void lista_setor_libera(Setor *lista)
{
    Setor *p = lista;
    Setor *t;
    while (p != NULL)
    {
        t = p->proximo;
        free(p);
        p = t;
    }
}

void lista_setor_imprime(Setor *lista)
{
    Setor *p;
    for (p = lista; p != NULL; p = p->proximo)
    {
        printf("Nome: %s\t\t Descricao: %s\n", p->nome, p->descricao);
    }
}

void lista_escrever_no_arquivo(Setor *lista, char nome[])
{
    FILE *file = fopen(nome, "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    Setor *setores = lista;
    Movel *moveis;
    while (setores != NULL)
    {
        fprintf(file, "Setor:%s\t%s\n", setores->nome, setores->descricao);
        moveis = setores->moveis;
        while (moveis != NULL)
        {
            fprintf(file, "Movel:%s\t%s\t%f\t%d\n", moveis->nome, moveis->tipo, moveis->preco, moveis->qtd_estoque);
            moveis = moveis->proximo;
        }
        setores = setores->proximo;
    }
    fclose(file);
}

int lista_setor_vazia(Setor *lista)
{
    return (lista == NULL);
}