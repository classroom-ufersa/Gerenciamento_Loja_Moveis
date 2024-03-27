#include "Setor/setor.c"

int main(void){
    char op_submenu,op_menu, setor[Max], movel[Max];
    Setor *s = lista_setor_cria();
    Movel *m = lista_movel_cria();
    do{
        menu();
        printf("Digite uma opcao:");
        scanf("%c", &op_menu);
        switch (op_menu){
        case '1': //adicionar movel
            printf("\t\t Adicionar movel\n");
            printf("1 - Adicionar movel a um setor existente\n2 - Criar novo setor\n");
            scanf("%d", &op_submenu);
            switch (op_submenu){
            case '1':
                printf("\t\tLista de setores");
                lista_setor_imprime(s);
                printf("Digite o nome do setor que deseja adicionar o movel:");
                gets(setor);
                s = lista_setor_busca(setor);
                printf("Cadastre o movel com: Nome, Tipo, Preco e quantidade em estoque.\n");
                scanf("%s%s%f%d",s->moveis->nome, s->moveis->tipo, s->moveis->preco, s->moveis->qtd_estoque);
                if (lista_setor_vazia(s) != NULL){
                    printf("Movel adicionado com sucesso.");
                }
                break;
            case '2':
                printf("Digite o nome e a descricao do setor\n");
                scanf("%s%s", s->proximo->nome, s->proximo->descricao);
                break;
            default:
                break;
            }
            break;
        case '2': //remover movel
            printf("Digite o nome do movel que deseja remover:");
            gets(movel);
            lista_movel_retira(m, movel);
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

    } while (op_menu != '8');
}