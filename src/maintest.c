#include "Setor/setor.c"
//Programa Main feito para testar as funções
int main(void){
    Movel *lista = lista_cria_movel();
    lista = lista_movel_adiciona_ordenado(lista, "jhoan", "bancada", 65.5, 20);
    lista = lista_movel_adiciona_ordenado(lista, "pedro", "banca", 47.0, 2);
    lista = lista_movel_adiciona_ordenado(lista, "lucas", "ban", 49.1, 3);
    lista_movel_imprime(lista);
    Movel *l2 = lista_movel_busca("pedro", lista);
    printf("%s", l2->nome);
    return 0;
}