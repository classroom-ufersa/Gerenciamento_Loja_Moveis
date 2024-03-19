#ifndef MOVEL_H
#define MOVEL_H

#include "../Configs/settings.c"

typedef struct movel Movel;

Movel *adicionar_movel(Movel* a);

void remover_movel(Movel* a);

//Movel editar_movel(Movel* a, char[Max]);

void buscar_movel(Movel* a);

#endif //MOVEL_H