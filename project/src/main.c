#include "setores.c"

int main(void)
{
    char setor_nome[Max], setor_descricao[Max], movel_nome[Max], movel_tipo[Max], arquivo[Max];
    char op_menu[Max], op_submenu[Max];
    float movel_preco;
    int movel_quantidade;
    strcpy(arquivo, "../data/DataBase.txt"); //strcpy(arquivo, "TesteBase.txt"); para testes no arquivo vazio
    Setor *setor = lista_setor_cria();
    Setor *aux = lista_setor_cria();
    setor = lista_ler_no_arquivo(setor, arquivo);
    settings_clear();
    do
    {
        do
        {
            settings_menu();
            printf("Digite uma opcao: ");
            scanf(" %[^\n]", op_menu);
            settings_clear();
        } while (strlen(op_menu)> 1);
            switch (op_menu[0])
            {
            case '1': // adicionar movel
                printf("\t\t Adicionar movel\n");
                printf("1 - Adicionar movel a um setor existente\n2 - Criar novo setor\n");
                scanf(" %[^\n]", op_submenu);
                if (strlen(op_submenu) > 1)
                {
                    printf("Digite uma opcao valida...\n");
                    break;
                }
                
                settings_clear();
                switch (op_submenu[0])
                {
                    if (settings_options(op_submenu) == 0)
                    {
                    case '1': // adicionar movel a um setor existente
                        if (lista_setor_vazia(setor))
                        {
                            printf("Lista vazia");
                            printf("Pressione enter para continuar...");
                            settings_press_enter();
                            break;
                        }
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
                        if (movel_preco < 0){
                            printf("valor invalido");
                            break;
                        }
                        printf("Digite o numero total de estoque:\n");
                        scanf(" %d", &movel_quantidade);
                        if (movel_quantidade < 0){
                            printf("valor invalido");
                            break;
                        }
                        aux->moveis = lista_movel_adiciona_ordenado(aux->moveis, movel_nome, movel_tipo, movel_preco, movel_quantidade);
                        lista_escrever_no_arquivo(setor, arquivo);
                        break;
                    case '2': // criar setor
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
                        setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
                        lista_escrever_no_arquivo(setor, arquivo);
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
            case '3': // editar movel
                settings_clear();
                if (lista_setor_vazia(setor))
                {
                    printf("Lista vazia");
                    break;
                }
                printf("\t\tLista de setores\n");
                lista_setor_imprime(setor);
                printf("Digite o nome do setor do movel:");
                scanf(" %[^\n]", setor_nome);
                if (!settings_str_verify(setor_nome))
                {
                    printf("Nome invalido\n");
                    break;
                }
                settings_captalize(setor_nome);
                aux = lista_setor_busca(setor_nome, setor);
                if (aux == NULL){
                    settings_clear();
                    break;
                }
                /*if (setor_nome == 0){
                    break;
                }*/
                lista_movel_imprime(aux->moveis);
                printf("\nDigite o nome do movel que deseja editar:");
                char nome_movel_editar[Max];
                scanf(" %[^\n]", nome_movel_editar);
                if (!settings_str_verify(setor_nome))
                {
                    printf("Nome invalido\n");
                    break;
                }
                settings_captalize(nome_movel_editar);
                settings_clear();
                printf("Digite o novo nome:");
                scanf(" %[^\n]", movel_nome);
                if (!settings_str_verify(movel_nome))
                {
                    printf("Nome invalido\n");
                    break;
                }
                settings_captalize(movel_nome);
                printf("Digite o tipo:");
                scanf(" %[^\n]", movel_tipo);
                if (!settings_str_verify(movel_tipo))
                {
                    printf("Nome invalido\n");
                    break;
                }
                settings_captalize(movel_tipo);
                printf("Digite o preco:");
                scanf(" %f", &movel_preco);
                if (movel_preco < 0){
                    printf("valor invalido");
                    break;
                }
                printf("Digite a quantidade de estoque disponivel:");
                scanf(" %d", &movel_quantidade);
                if (movel_quantidade < 0){
                    printf("valor invalido");
                    break;
                }
                aux->moveis = lista_movel_edita(aux->moveis, nome_movel_editar, movel_nome, movel_tipo, movel_preco, movel_quantidade);
                lista_escrever_no_arquivo(setor, arquivo);
                break;
            case '4': // adicionar setor
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
                setor = lista_setor_adiciona_ordenado(setor, setor_nome, setor_descricao);
                lista_escrever_no_arquivo(setor, arquivo);
                break;
            case '5': // remover setor
                if (lista_setor_vazia(setor))
                {
                    printf("Lista vazia");
                    printf("Pressione enter para continuar...");
                    settings_press_enter();
                    break;
                }
                settings_clear();
                printf("\t\tLista de setores\n");
                lista_setor_imprime(setor);
                printf("Digite o nome do setor que deseja remover:");
                scanf(" %[^\n]", setor_nome);
                if (!settings_str_verify(setor_nome))
                {
                    printf("Nome invalido\n");
                    break;
                }
                settings_captalize(setor_nome);
                if (setor != NULL)
                {
                    setor = lista_setor_remove(setor, setor_nome);
                    lista_escrever_no_arquivo(setor, arquivo);
                }
                else
                {
                    printf("Lista de setores vazia!\n");
                }
                break;
            case '6': //listar
                if (!lista_setor_vazia(setor))
                {
                    settings_clear();
                    imprime_moveis_setor(setor);
                    settings_press_enter();
                    settings_clear();
                    
                }
                else
                {
                    printf("Lista vazia!\n");
                }
                break;
            case '7': // buscar móvel
                if (lista_setor_vazia(setor))
                {
                    printf("Lista vazia");
                    break;
                }
                printf("\t\tLista de setores\n");
                lista_setor_imprime(setor);
                printf("\nDigite o nome do setor em que esta o movel: ");
                scanf(" %[^\n]", setor_nome);
                if (!settings_str_verify(setor_nome))
                {
                    printf("Nome invalido\n");
                    break;
                }
                settings_captalize(setor_nome);
                aux = lista_setor_busca(setor_nome, setor);
                if (aux != NULL)
                {
                    printf("Digite o nome do movel que deseja buscar: ");
                    scanf(" %[^\n]", movel_nome);
                    if (!settings_str_verify(movel_nome))
                    {
                        printf("Nome invalido\n");
                        break;
                    }
                    settings_captalize(movel_nome);
                    aux->moveis = lista_movel_busca(aux->moveis, movel_nome);
                    if (aux->moveis != NULL)
                    {
                        printf(" Movel encontrado\n");
                        printf(" Nome: %s\tTipo: %s\tPreco: %.2f\tQuantidade: %d\n", aux->moveis->nome, aux->moveis->tipo, aux->moveis->preco, aux->moveis->qtd_estoque);
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
                printf("Saindo...\n");
                break;
            default:
                printf("Digite uma opcao valida....");
                break;
            }
    } while (op_menu[0] != '8');
    printf("Programa encerrado");
    return 0;
}
