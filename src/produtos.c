#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/produtos.h"

#define MAX_PRODUTOS 100

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

// reutilizando funcao
int gerarIdProduto()
{
    int maxId = 0;
    for (int i = 0; i < totalProdutos; i++)
    {
        if (produtos[i].id > maxId)
        {
            maxId = produtos[i].id;
        }
    }
    return maxId + 1;
}

// Cadastrar produto (simulado)
void cadastrarProduto()
{
    system("clear||cls");
    if (totalProdutos >= MAX_PRODUTOS)
    {        
        printf("\n❌ Limite de produtos atingido!\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    Produto p;
    p.id = gerarIdProduto();

    printf("\nDigite o nome do produto: ");
    getchar(); // limpa buffer
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Digite o preço do produto: ");
    scanf("%f", &p.preco);

    produtos[totalProdutos++] = p;

    printf("\n✅ Produto cadastrado com sucesso! (ID: %d)\n", p.id);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}

// Listar produtos
void listarProdutos()
{
    system("clear||cls");
    if (totalProdutos == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
    }
    else
    {
        printf("\n📋 Lista de Produtos:\n");
        printf("ID | Nome | Preço\n");
        printf("-----------------------------\n");
        for (int i = 0; i < totalProdutos; i++)
        {
            printf("%d | %s | R$ %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
        }
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

// Atualizar produto
void atualizarProduto()
{
    system("clear||cls");
    if (totalProdutos == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    int id;
    printf("\nDigite o ID do produto que deseja atualizar: ");
    scanf("%d", &id);
    getchar();

    Produto *p = NULL;
    for (int i = 0; i < totalProdutos; i++)
    {
        if (produtos[i].id == id)
        {
            p = &produtos[i];
            break;
        }
    }

    if (!p)
    {
        printf("\n❌ Produto não encontrado!\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("\nProduto selecionado: %s | R$ %.2f\n", p->nome, p->preco);

    printf("Digite o novo nome (deixe em branco para manter): ");
    char linha[50];
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n')
    {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(p->nome, linha);
    }

    printf("Digite o novo preço (0 para manter): ");
    float novoPreco;
    scanf("%f", &novoPreco);
    getchar();
    if (novoPreco > 0)
        p->preco = novoPreco;

    printf("\n✅ Produto atualizado!\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

// Excluir produto
void excluirProduto()
{
    system("clear||cls");
    if (totalProdutos == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    int id;
    printf("\nDigite o ID do produto que deseja excluir: ");
    scanf("%d", &id);
    getchar();

    int indice = -1;
    for (int i = 0; i < totalProdutos; i++)
    {
        if (produtos[i].id == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("\n❌ Produto não encontrado!\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    for (int i = indice; i < totalProdutos - 1; i++)
    {
        produtos[i] = produtos[i + 1];
    }
    totalProdutos--;

    printf("\n✅ Produto excluído!\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

// Menu de produtos
void menu_Produtos()
{
    int opcao;
    do
    {
        system("clear||cls");
        printf("\n╔════════════════════════╗\n");
        printf("║       Produtos         ║\n");
        printf("╠════════════════════════╣\n");
        printf("║ [1] Cadastrar Produto  ║\n");
        printf("║ [2] Listar Produtos    ║\n");
        printf("║ [3] Atualizar Produto  ║\n");
        printf("║ [4] Excluir Produto    ║\n");
        printf("║ [0] Voltar             ║\n");
        printf("╚════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            atualizarProduto();
            break;
        case 4:
            excluirProduto();
            break;
        case 0:
            printf("\nVoltando...\n");
            break;
        default:
            printf("\n❌ Opção inválida!\n");
            getchar();
            break;
        }
    } while (opcao != 0);
}
