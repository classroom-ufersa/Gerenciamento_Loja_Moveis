#include "Setores/setores.c"

int main(void)
{
    char setor_nome[Max], setor_descricao[Max], movel_nome[Max], movel_tipo[Max], arquivo[Max];
    char op_menu[Max], op_submenu[Max];
    float movel_preco;
    int movel_quantidade;

    // Arquivo de dados padrão
    strcpy(arquivo, "DataBase.txt"); //strcpy(arquivo, "TesteBase.txt"); para testes no arquivo vazio

    // Inicialização da lista de setores
    Setor *setor = lista_setor_cria();
    Setor *aux = lista_setor_cria();

    // Carregar dados do arquivo para a lista de setores
    setor = lista_ler_no_arquivo(setor, arquivo);

    // Loop do menu principal
    do
    {
        // Exibir o menu principal
        settings_menu();
        printf("Digite uma opcao: ");
        scanf(" %[^\n]", op_menu);
        settings_clear();

        // Verificar a opção do menu principal
        if (settings_options(op_menu) == 0)
        {
            switch (op_menu[0])
            {
            case '1': // Adicionar movel
                printf("\t\t Adicionar movel\n");
                printf("1 - Adicionar movel a um setor existente\n2 - Criar novo setor\n");
                scanf(" %[^\n]", op_submenu);
                settings_clear();

                // Verificar a opção do submenu
                if (settings_options(op_submenu) == 0)
                {
                    switch (op_submenu[0])
                    {
                    case '1': // Adicionar movel a um setor existente
                        if (lista_setor_vazia(setor))
                        {
                            printf("Lista vazia");
                            printf("Pressione enter para continuar...");
                            settings_press_enter();
                            break;
                        }

                        // Selecionar o setor para adicionar o movel
                        printf("\t\tLista de setores\n");
                        lista_setor_imprime(setor);
                        printf("Digite o nome do setor que deseja adicionar o movel:");
                        scanf(" %[^\n]", setor_nome);
                        if (!settings_str_verify(setor_nome))
                        {
                            printf("Nome invalido\n");
                            break;
                        }
                        settings_captalize(setor_nome);
                        aux = lista_setor_busca(setor_nome, setor);

                        // Capturar os dados do movel
                        printf("Digite o nome do movel:\n");
                        scanf(" %[^\n]", movel_nome);
                        if (!settings_str_verify(movel_nome))
                        {
                            printf("Nome invalido\n");
                            break;
                        }
                        settings_captalize(movel_nome);

                        printf("Digite o tipo do movel:\n");
                        scanf(" %[^\n]", movel_tipo);
                        if (!settings_str_verify(movel_tipo))
                        {
                            printf("Nome invalido\n");
                            break;
                        }
                        settings_captalize(movel_tipo);

                        printf("Digite o preco do movel:\n");
                        scanf(" %f", &movel_preco);

                        printf("Digite o numero total de estoque:\n");
                        scanf(" %d", &movel_quantidade);

                        // Adicionar o movel ao setor
                        aux->moveis = lista_movel_adiciona_ordenado(aux->moveis, movel_nome, movel_tipo, movel_preco, movel_quantidade);
                        lista_escrever_no_arquivo(setor, arquivo);
                        break;

                    case '2': // Criar novo setor
                        printf("Digite o nome do setor:\n");
                        scanf(" %[^\n]", setor_nome);
                        if (!settings_str_verify(setor_nome))
                        {
                            printf("Nome invalido\n");
                            break;
                        }
                        settings_captalize(setor_nome);

                        printf("Digite a descricao do setor:\n");
                        scanf(" %[^\n]", setor_descricao);
                        if (!settings_str_verify(setor_descricao))
                        {
                            printf("Nome invalido\n");
                            break;
                        }
                        settings_captalize(setor_descricao);

                        // Adicionar o novo setor
                        setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
                        lista_escrever_no_arquivo(setor, arquivo);
                        break;

                    default:
                        printf("Opcao invalida");
                        break;
                    }
                }
                else
                {
                    printf("Digite uma opcao valida...");
                }
                break;

            case '2': // Remover movel
                settings_clear();
                if (lista_setor_vazia(setor))
                {
                    printf("Lista vazia");
                    break;
                }
                printf("\t\tLista de setores\n");
                lista_setor_imprime(setor);
                printf("Digite o nome do setor que esta o movel:");
                scanf(" %[^\n]", setor_nome);
                settings_captalize(setor_nome);
                aux = lista_setor_busca(setor_nome, setor);
                if (aux != NULL)
                {
                    lista_movel_imprime(aux->moveis);
                    printf("Digite o nome do movel que deseja remover:");
                    scanf(" %[^\n]", movel_nome);
                    settings_captalize(movel_nome);
                    aux->moveis = lista_movel_remove(aux->moveis, movel_nome);
                    lista_escrever_no_arquivo(setor, arquivo);
                }
                else
                {
                    settings_clear();
                    printf("Setor nao encontrado.\n");
                }
                break;

            // Outros casos omitidos para brevidade...

            case '8': // Sair
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

    printf("Programa encerrado");
    return 0;
}
