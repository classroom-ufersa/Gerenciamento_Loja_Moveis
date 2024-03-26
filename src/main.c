#include "Setor/setor.c"

int main(void){
    char opcao;
    do{
        menu();
        printf("Digite uma opcao:");
        scanf("%c", &opcao);
        switch (opcao){
        case '1': //adicionar movel
            printf("\t\t Adicionar movel\n");
            printf("1 - Adicionar movel a um setor existente\n2 - Criar novo setor\n");
            break;
        case '2': //remover movel
            printf("Digite o nome do movel que deseja remover:");
            break;
        case '3': //editar movel
            printf("Digite o nome do movel que deseja editar:");
            printf("Digite o novo nome: \nDigite o novo tipo \n Digite o preco: \n, Digite a quantidade de estoque disponivel");
            break;
        case '4': //adicionar setor
            print("Digite o nome do novo setor: \nDigite a descricao do setor:");
            break;
        case '5': //remover setor
            print("Digite o nome do setor que deseja remover:");
            break;
        case '6': //Listar setores e moveis
            
            break;
        case '7': //buscar movel
            
            break;
        case '8': //sair
            printf("Programa encerrado");
                return 0;
            break;    
        default:
            printf("Digite uma opcao valida...");
            break;
        }

    } while (opcao != '8');
}