#include "../includes/settings.h"

void settings_menu(void){
    
    printf("\t\tCadastro de moveis/setores.\n");
    printf("***************************\n");
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

void settings_captalize(char *string){
    int tamanho = strlen(string);
    for (int i = 0; i < tamanho; i++){
        string[i] = toupper(string[i]);
    }
}

void settings_clear(void){
    #ifdef _WIN32
        system("cls");
    #elif __APPLE__
        system("clear");
    #elif __linux__
        system("clear");
    #endif
}
void settings_press_enter(void){
    settings_limpa_buffer();    
    while(getchar() != '\n');
}

int settings_str_verify(char *string){
    int verificador = strlen(string);
    for (int i = 0; i < verificador; i++){
        if ((string[i] >= 'A' && string [i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z') || string[i] == ' '){
            continue;
        }
        else{
            return 0;
        }   
    }
    return 1;
}

int settings_options(char *opcao){
    int tamanho = strlen(opcao);
    if (tamanho > 1){
        return 0;
    }
    return 1;
}
