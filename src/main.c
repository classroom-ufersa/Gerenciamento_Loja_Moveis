#include "Setor/setor.c"

int main(void){
    FILE *DataBase;
    char op_submenu,op_menu, setor_nome[Max], setor_descricao[Max], movel_nome[Max], movel_tipo[Max] ; 
    float movel_preco;
    int movel_quantidade;
    Setor *setor = lista_setor_cria();
    Setor *aux = NULL;
    do{
        menu();
        printf("Digite uma opcao:");
        scanf("%c", &op_menu);
        switch (op_menu){
        case '1': //adicionar movel
            printf("\t\t Adicionar movel\n");
            printf("1 - Adicionar movel a um setor existente\n2 - Criar novo setor\n");
            scanf("%s", &op_submenu);
            switch (op_submenu){
            case '1':
                if (lista_setor_vazia(setor)){
                    printf("Setor nao encontrado");
                    break;
                }
                printf("\t\tLista de setores");
                lista_setor_imprime(setor);
                printf("Digite o nome do setor que deseja adicionar o movel:");
                gets(setor_nome);
                aux = lista_setor_busca(setor_nome, setor);
                printf("Digite o nome do movel:\n");
                gets(movel_nome);
                printf("Digite o tipo do movel:\n");
                gets(movel_tipo);
                printf("Digite o preco do movel:\n");
                scanf("%f", &movel_preco);
                printf("Digite o numero total de estoque:\n");
                scanf("%d", &movel_quantidade);
                aux->moveis = lista_movel_adiciona_ordenado(aux->moveis, movel_nome, movel_tipo, movel_preco, movel_quantidade);
                break;
            case '2':
                printf("Digite o nome do setor:\n");
                gets(setor_nome);
                printf("Digite a descricao do setor:\n");
                gets(setor_descricao);
                setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
                break;
            default:
                printf("Opcao invalida");
                break;
            }
            break;
        case '2': //remover movel
            printf("Digite o nome do setor que está o movel:");
            gets(setor_nome);
            aux = lista_setor_busca(setor_nome, setor);
            printf("Digite o nome do movel que deseja remover:");
            gets(movel_nome);
            lista_movel_retira(aux, movel_nome);
            break;
        case '3': //editar movel
            printf("Digite o nome do setor do movel:");
            gets(setor_nome);
            aux = lista_setor_busca(setor_nome, setor);
            printf("Digite o nome do movel que deseja editar:");
            char nome_movel_editar[Max];
            gets(nome_movel_editar);
            printf("Digite o novo nome:");
            gets(movel_nome);
            printf("Digite o tipo:");
            gets(movel_tipo); 
            printf("Digite o preco:");
            scanf("%f", &movel_preco);
            printf("Digite a quantidade de estoque disponivel:");
            scanf("%d", &movel_quantidade);
            aux->moveis = lista_movel_edita(aux->moveis, nome_movel_editar, movel_nome, movel_tipo, movel_preco, movel_quantidade);
            break;
        case '4': //adicionar setor
            printf("Digite o nome do setor:\n");
            gets(setor_nome);
            printf("Digite a descricao do setor:\n");
            gets(setor_descricao);
            setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
            break;
        case '5': //remover setor
            printf("Digite o nome do setor que deseja remover:");
            gets(setor_nome);
            aux = lista_setor_busca(setor_nome, setor;)
            lista_setor_libera(aux);
            break;
        case '6': //Listar setores e moveis
            break;
        case '7': //buscar movel
            printf("Digite o nome do movel que deseja buscar:");
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