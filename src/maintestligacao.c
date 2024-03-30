#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Setor/setor.c"

int main() {
    Setor* lista_setores = lista_setor_cria();

    lista_setores = lista_setor_adiciona_ordenado(lista_setores, "Sala", "Setor de móveis para sala");
    lista_setores = lista_setor_adiciona_ordenado(lista_setores, "Cozinha", "Setor de móveis para cozinha");
    lista_setores = lista_setor_adiciona_ordenado(lista_setores, "Quarto", "Setor de móveis para quarto");

    lista_setores->moveis = lista_movel_adiciona_ordenado(lista_setores->moveis, "Sofá", "Estofado", 500.0, 10);
    lista_setores->moveis = lista_movel_adiciona_ordenado(lista_setores->moveis, "Mesa", "Madeira", 200.0, 5);

    Setor* cozinha = lista_setor_busca("Cozinha", lista_setores);
    if (cozinha != NULL) {
        cozinha->moveis = lista_movel_adiciona_ordenado(cozinha->moveis, "Geladeira", "Eletrodoméstico", 1500.0, 3);
    }

    printf("Lista de Setores e Móveis:\n");
    lista_setor_imprime(lista_setores);

    //free memory
    lista_setor_libera(lista_setores);

    return 0;
}
