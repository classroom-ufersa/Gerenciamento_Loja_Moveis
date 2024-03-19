#include "Setor/setor.c"

int main(void){
    char opcao;
    
    do
    {
        menu();
        printf("\nDigite uma opcão:");
        scanf("%c", &opcao);
        
    } while (opcao != 5);


    if (opcao >=49 && opcao < 54){ //tabela ascii de 1 a 5
        
    }
    
    return 0;
}