#include "settings.h"

void settings_menu(void){
    printf("\n***************************\n");
    printf("\t\tCadastro de moveis/setores.\n");
    printf("1-Adicionar Movel\n");
    printf("2-Remover Movel\n");
    printf("3-Editar Movel\n");
    printf("4-Adicionar Setor\n");
    printf("5-Remover Setor\n");
    printf("6-Listar setores e moveis\n");
    printf("7-Buscar Movel\n");
    printf("8-Sair\n");
    printf("***************************\n");
}
void settings_limpa_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void settings_captalize(char *nome){
    int tamanho = strlen(nome);
    for (int i = 0; i < tamanho; i++){
        nome[i] = toupper(nome[i]);
    }
}

void settings_clear(void){
    system("clear");
}

void settings_press_enter(void){
    while(getchar() != '\n');
}

void settings_str_verify(char *nome){
    int tamanho = strlen(nome);
    for (int i = 0; i < tamanho; i++){
        if (nome[i] == ' '){
            nome[i] = '_';
        }
    }
}


