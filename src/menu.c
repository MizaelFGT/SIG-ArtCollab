#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/produtos.h"
#include "../include/colaboradores.h"
#include "../include/vendas.h"
#include "../include/clientes.h"
#include "../include/funcionarios.h"

// FUNCAO LIXO
void nada()
{
    printf("NADA");
};

void menu_Main()
{
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do
    {
        system("clear||cls");
        // MENU PRINCIPAL
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║                                        ║\n");
        printf("║              🌟 UniArt 🌟              ║\n");
        printf("║                                        ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Produtos                        ║\n");
        printf("║  [2] ➜ Clientes                        ║\n");
        printf("║  [3] ➜ Colaboradores                   ║\n");
        printf("║  [4] ➜ Vendas                          ║\n");
        printf("║  [5] ➜ Relatórios                      ║\n");
        printf("║  [6] ➜ Funcionarios                    ║\n");
        printf("║                                        ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Sair                            ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        // MENU CASES

        switch (opcao)
        {
        case 1:
            menu_Produtos();
            break;
        case 2:
            menu_Clientes();
            break;
        case 3:
            menu_Colaboradores();
            break;
        case 4:
            menu_Vendas();
            break;
        case 5:
            nada();
            break;
        case 6:
            menu_Funcionarios();
        case 0:
            printf("\nEncerrando\n");
            system("clear||cls");
            break;
        default:
            printf("\nOpcao Invalida\n");
        }

    } while (opcao != 0);
}