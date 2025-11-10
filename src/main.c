// includes
#include <stdio.h>
#include <stdlib.h>
#include "../include/animacao.h"
#include "../include/sobre.h"
#include "../include/menu.h"

//MAIN
int main() {
    animar_Menu();
    int opcao;

    do {
        // Menu principal
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║                                        ║\n");
        printf("║             🌟 UniArt 🌟               ║\n");
        printf("║                                        ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Menu                            ║\n");
        printf("║  [2] ➜ Equipe                          ║\n");
        printf("║  [3] ➜ Sobre                           ║\n");
        printf("║  [0] ➜ Sair                            ║\n");
        printf("╚════════════════════════════════════════╝\n");

        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        // Limpar tela 
        system("clear||cls");

        switch(opcao) {
            case 1:
                menu_Main();
                break;
            case 2:
                equipe_Main();
                break;
            case 3:
                sobre_Main();
                break;
            case 0:
                printf("\nEncerrando\n");
                break;
            default:
                printf("\nOpcao Invalida\n");
        }
    } while(opcao != 0);
    animar_Fim();

    return 0;
}


