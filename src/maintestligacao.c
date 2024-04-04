#include "Setor/setor.c"

int main() {
    Setor* lista_setores = lista_setor_cria();

    lista_setores = lista_setor_adiciona_ordenado(lista_setores, "Cozinha", "Setor de moveis para cozinha");
    lista_setores = lista_setor_adiciona_ordenado(lista_setores, "Sala", "Setor de moveis para sala");
    lista_setores = lista_setor_adiciona_ordenado(lista_setores, "Quarto", "Setor de moveis para quarto");

    lista_setores->moveis = lista_movel_adiciona_ordenado(lista_setores->moveis, "Mesa", "Movel", 150.0, 5);
    lista_setores->moveis = lista_movel_adiciona_ordenado(lista_setores->moveis, "Cadeira", "Movel", 50.0, 10);
    lista_setores->proximo->moveis = lista_movel_adiciona_ordenado(lista_setores->proximo->moveis, "Sofa", "Movel", 300.0, 3);
    lista_setores->proximo->moveis = lista_movel_adiciona_ordenado(lista_setores->proximo->moveis, "Poltrona", "Movel", 200.0, 7);
    lista_setores->proximo->proximo->moveis = lista_movel_adiciona_ordenado(lista_setores->proximo->proximo->moveis, "Cama", "Movel", 250.0, 2);
    lista_setores->proximo->proximo->moveis = lista_movel_adiciona_ordenado(lista_setores->proximo->proximo->moveis, "Guarda-roupa", "Movel", 400.0, 4);

    imprime_moveis_setor(lista_setores);

    lista_setor_libera(lista_setores);

    return 0;
}