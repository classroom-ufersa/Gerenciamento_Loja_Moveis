#include "Setor/setor.c"

int main(void)
{
    char setor_nome[Max], setor_descricao[Max], movel_nome[Max], movel_tipo[Max], diretorio[Max];
    char op_menu[Max], op_submenu[Max];
    float movel_preco;
    int movel_quantidade;
    strcpy(diretorio, "DataBase.txt");
    Setor *setor = lista_setor_cria();
    Setor *aux = lista_setor_cria();
    setor = lista_ler_no_arquivo(setor, diretorio);
    do
    {
        settings_menu();
        printf("Digite uma opcao: ");
        scanf(" %[^\n]", op_menu);
        if (settings_options(op_menu) == 0)
        {
            switch (op_menu[0])
            {
            case '1': // adicionar movel
                printf("\t\t Adicionar movel\n");
                printf("1 - Adicionar movel a um setor existente\n2 - Criar novo setor\n");
                scanf(" %[^\n]", op_submenu);
                switch (op_submenu[0])
                {
                    if (settings_options(op_submenu)==0)
                    {
                    case '1':
                        if (lista_setor_vazia(setor))
                        {
                            printf("Setor nao encontrado");
                            break;
                        }
                        printf("\t\tLista de setores\n");
                        lista_setor_imprime(setor);
                        printf("Digite o nome do setor que deseja adicionar o movel:");
                        scanf(" %[^\n]s", setor_nome);
                        settings_captalize(setor_nome);
                        aux = lista_setor_busca(setor_nome, setor);
                        printf("Digite o nome do movel:\n");
                        scanf(" %[^\n]s", movel_nome);
                        settings_captalize(movel_nome);
                        printf("Digite o tipo do movel:\n");
                        scanf(" %[^\n]s", movel_tipo);
                        settings_captalize(movel_tipo);
                        printf("Digite o preco do movel:\n");
                        scanf(" %f", &movel_preco);
                        printf("Digite o numero total de estoque:\n");
                        scanf(" %d", &movel_quantidade);
                        aux->moveis = lista_movel_adiciona_ordenado(aux->moveis, movel_nome, movel_tipo, movel_preco, movel_quantidade);
                        lista_escrever_no_arquivo(setor, diretorio);
                        break;
                    case '2':
                        printf("Digite o nome do setor:\n");
                        scanf(" %[^\n]s", setor_nome);
                        settings_captalize(setor_nome);
                        printf("Digite a descricao do setor:\n");
                        scanf(" %[^\n]s", setor_descricao);
                        settings_captalize(setor_descricao);
                        setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
                        lista_escrever_no_arquivo(setor, diretorio);
                        break;
                    default:
                        printf("Opcao invalida");
                        break;
                    }
                    else
                    {
                        printf("Digite uma opcao valida...");
                    }
                    break;
                }
                break;
            case '2': // remover movel
                printf("Digite o nome do setor que esta o movel:");
                scanf(" %[^\n]s", setor_nome);
                settings_captalize(setor_nome);
                aux = lista_setor_busca(setor_nome, setor);
                if (aux != NULL)
                {
                    printf("Digite o nome do movel que deseja remover:");
                    scanf(" %[^\n]s", movel_nome);
                    settings_captalize(movel_nome);
                    aux->moveis = lista_movel_remove(aux->moveis, movel_nome);
                }
                else
                {
                    printf("Setor nao encontrado.\n");
                }
                break;
            case '3': // editar movel
                printf("Digite o nome do setor do movel:");
                scanf(" %[^\n]s", setor_nome);
                settings_captalize(setor_nome);
                aux = lista_setor_busca(setor_nome, setor);
                printf("Digite o nome do movel que deseja editar:");
                char nome_movel_editar[Max];
                scanf(" %[^\n]s", nome_movel_editar);
                settings_captalize(nome_movel_editar);
                printf("Digite o novo nome:");
                scanf(" %[^\n]s", movel_nome);
                settings_captalize(movel_nome);
                printf("Digite o tipo:");
                scanf(" %[^\n]s", movel_tipo);
                settings_captalize(movel_tipo);
                printf("Digite o preco:");
                scanf(" %f", &movel_preco);
                printf("Digite a quantidade de estoque disponivel:");
                scanf(" %d", &movel_quantidade);
                aux->moveis = lista_movel_edita(aux->moveis, nome_movel_editar, movel_nome, movel_tipo, movel_preco, movel_quantidade);
                lista_escrever_no_arquivo(setor, diretorio);
                break;
            case '4': // adicionar setor
                printf("Digite o nome do setor:\n");
                scanf(" %[^\n]s", setor_nome);
                settings_captalize(setor_nome);
                printf("Digite a descricao do setor:\n");
                scanf(" %[^\n]s", setor_descricao);
                settings_captalize(setor_descricao);
                setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
                lista_escrever_no_arquivo(setor, diretorio);
                break;
            case '5': // remover setor
                printf("Digite o nome do setor que deseja remover:");
                scanf(" %[^\n]s", setor_nome);
                settings_captalize(setor_nome);
                if (setor != NULL)
                {
                    setor = lista_setor_remove(setor, setor_nome);
                    printf("Setor removido com sucesso!\n");
                    lista_escrever_no_arquivo(setor, diretorio);
                }
                else
                {
                    printf("Lista de setores vazia!\n");
                }
                break;
            case '6':
                if (setor != NULL)
                {
                    imprime_moveis_setor(setor);
                }
                else
                {
                    printf("Lista vazia!\n");
                }
                break;
            case '7': // buscar móvel
                printf("Digite o nome do setor que esta o movel: ");
                scanf(" %[^\n]s", setor_nome);
                settings_captalize(setor_nome);
                aux = lista_setor_busca(setor_nome, aux);
                if (aux != NULL)
                {
                    printf("Digite o nome do movel que deseja buscar: ");
                    scanf(" %[^\n]s", movel_nome);
                    settings_captalize(movel_nome);
                    aux->moveis = lista_movel_busca(movel_nome, aux->moveis);
                    if (aux->moveis != NULL)
                    {
                        printf("Movel encontrado\n");
                        break;
                    }
                    else
                    {
                        printf("Movel nao encontrado\n");
                        break;
                    }
                }
                else
                {
                    printf("Setor nao encontrado\n");
                    break;
                }
            case '8': // sair
                printf("Programa encerrado");
                return 0;
                break;
            default:
                printf("Digite uma opcao valida...");
                break;
            }
        }
        else
        {
            printf("Digite uma opcao valida...");
        }

    } while (op_menu[0] != '8');
}
