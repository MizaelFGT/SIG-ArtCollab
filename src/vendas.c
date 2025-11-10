#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vendas.h"

#include <stdio.h>
#pragma message(">> Compilando vendas.c correto")


Venda *vendas = NULL;
int totalVendas = 0;

// Gerar ID único para a venda
int gerarIdVenda()
{
    int maxId = 0;
    for (int i = 0; i < totalVendas; i++)
    {
        if (vendas[i].id > maxId)
        {
            maxId = vendas[i].id;
        }
    }
    return maxId + 1;
}

// Cadastrar venda
void cadastrarVenda()
{
    system("clear||cls");

    Venda v;
    v.id = gerarIdVenda();

    printf("\nDigite o ID do cliente: ");
    scanf("%d", &v.idCliente);

    printf("Digite o ID do produto: ");
    scanf("%d", &v.idProduto);

    printf("Digite a quantidade vendida: ");
    scanf("%d", &v.quantidade);

    printf("Digite o valor unitário do produto: ");
    scanf("%f", &v.valorUnitario);

    v.valorTotal = v.quantidade * v.valorUnitario;

    // Realoca o vetor de vendas dinamicamente
    vendas = realloc(vendas, (totalVendas + 1) * sizeof(Venda));
    if (!vendas)
    {
        printf("\n❌ Erro de memória!\n");
        exit(1);
    }

    vendas[totalVendas++] = v;

    printf("\n✅ Venda cadastrada com sucesso! (ID: %d)\n", v.id);
    printf("Valor total: R$ %.2f\n", v.valorTotal);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}

// Listar vendas
void listarVendas()
{
    system("clear||cls");

    if (totalVendas == 0)
    {
        printf("\nNenhuma venda cadastrada.\n");
    }
    else
    {
        printf("\n📋 Lista de Vendas:\n");
        printf("ID | Cliente | Produto | Qtd | Unitário | Total\n");
        printf("------------------------------------------------------\n");
        for (int i = 0; i < totalVendas; i++)
        {
            printf("%d | %d | %d | %d | R$ %.2f | R$ %.2f\n",
                   vendas[i].id,
                   vendas[i].idCliente,
                   vendas[i].idProduto,
                   vendas[i].quantidade,
                   vendas[i].valorUnitario,
                   vendas[i].valorTotal);
        }
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

// Atualizar venda
void atualizarVenda()
{
    system("clear||cls");

    if (totalVendas == 0)
    {
        printf("\nNenhuma venda cadastrada.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    int id;
    printf("\nDigite o ID da venda que deseja atualizar: ");
    scanf("%d", &id);
    getchar();

    Venda *v = NULL;
    for (int i = 0; i < totalVendas; i++)
    {
        if (vendas[i].id == id)
        {
            v = &vendas[i];
            break;
        }
    }

    if (!v)
    {
        printf("\n❌ Venda não encontrada!\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("\nVenda selecionada: Cliente %d | Produto %d | Qtd %d | Total R$ %.2f\n",
           v->idCliente, v->idProduto, v->quantidade, v->valorTotal);

    printf("\nDigite o novo ID do cliente (0 para manter): ");
    int novoCliente;
    scanf("%d", &novoCliente);
    if (novoCliente > 0)
        v->idCliente = novoCliente;

    printf("Digite o novo ID do produto (0 para manter): ");
    int novoProduto;
    scanf("%d", &novoProduto);
    if (novoProduto > 0)
        v->idProduto = novoProduto;

    printf("Digite a nova quantidade (0 para manter): ");
    int novaQtd;
    scanf("%d", &novaQtd);
    if (novaQtd > 0)
        v->quantidade = novaQtd;

    printf("Digite o novo valor unitário (0 para manter): ");
    float novoValor;
    scanf("%f", &novoValor);
    if (novoValor > 0)
        v->valorUnitario = novoValor;

    // Recalcular total
    v->valorTotal = v->quantidade * v->valorUnitario;

    printf("\n✅ Venda atualizada com sucesso!\n");
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}

// Excluir venda
void excluirVenda()
{
    system("clear||cls");

    if (totalVendas == 0)
    {
        printf("\nNenhuma venda cadastrada.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    int id;
    printf("\nDigite o ID da venda que deseja excluir: ");
    scanf("%d", &id);
    getchar();

    int indice = -1;
    for (int i = 0; i < totalVendas; i++)
    {
        if (vendas[i].id == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("\n❌ Venda não encontrada!\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    for (int i = indice; i < totalVendas - 1; i++)
    {
        vendas[i] = vendas[i + 1];
    }

    totalVendas--;
    vendas = realloc(vendas, totalVendas * sizeof(Venda)); // Reduz o tamanho do vetor

    printf("\n✅ Venda excluída com sucesso!\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

// Menu de vendas
void menu_Vendas()
{
    int opcao;
    do
    {
        system("clear||cls");
        printf("\n╔════════════════════════╗\n");
        printf("║         Vendas         ║\n");
        printf("╠════════════════════════╣\n");
        printf("║ [1] Cadastrar Venda    ║\n");
        printf("║ [2] Listar Vendas      ║\n");
        printf("║ [3] Atualizar Venda    ║\n");
        printf("║ [4] Excluir Venda      ║\n");
        printf("║ [0] Voltar             ║\n");
        printf("╚════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarVenda();
            break;
        case 2:
            listarVendas();
            break;
        case 3:
            atualizarVenda();
            break;
        case 4:
            excluirVenda();
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
