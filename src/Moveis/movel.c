#include "movel.h"

struct movel{
    char nome[Max];
    char tipo[Max];
    char descricao[Max];
    float preco;
    int qtd_estoque;
};

Movel *adicionar_movel(Movel*a){
    a=(Movel*)malloc(sizeof(Movel));
    if (a==NULL){
        printf("Erro de alocação de memória");
        exit(1);
    }
    return a;
}

void remover_movel(Movel* a){


}

//Movel editar_movel(Movel* a, char[Max]){
  //  Movel b;/
 //  return b;
//}

void buscar_movel(Movel* a){
    
};


