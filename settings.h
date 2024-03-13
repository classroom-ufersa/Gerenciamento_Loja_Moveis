#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 50

typedef struct movel Movel;

typedef struct setor Setor;


//Funções de movel
Movel adicionar_movel(Movel* a);

void remover_movel(Movel* a);

Movel editar_movel(Movel* a, char[Max]);

void buscar_movel(Movel* a);



//Funções de setor
Setor adicionar_setor(Setor* a );

void remover_setor(Setor *a );





//Funções gerais
void listar(void);

void menu(void);

void limpa_buffer(void);




