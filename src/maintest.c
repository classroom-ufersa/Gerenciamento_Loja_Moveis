#include "Setor/setor.c"
//Programa Main feito para testar as funções
int main(void){
    Movel *lista = lista_movel_cria();
    lista = lista_movel_adiciona_ordenado(lista, "dda", "bancada", 65.5, 20);
    lista = lista_movel_adiciona_ordenado(lista, "bca", "banca", 47.0, 2);
    lista = lista_movel_adiciona_ordenado(lista, "cba", "ban", 49.1, 3);
    lista = lista_movel_adiciona_ordenado(lista, "abc", "ban", 49.1, 3);
    lista_movel_imprime(lista);
    /*Movel *l2 = lista_movel_busca("cba", lista);
    printf("%s", l2->nome);*/ //busca funcionando
    //printf("Lista depois de retirar: \n");
    //lista_movel_retira(lista, "dda");
    //lista_movel_imprime(lista);
    printf("Editando\n");
    lista_movel_edita(lista, "abc", "bbb", "bansd", 6.43, 10);
    lista_movel_imprime(lista);
    return 0;
}
