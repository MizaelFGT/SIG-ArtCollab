#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/colaboradores.h"
#define ARQUIVO_COLABORADORES "dados/colaboradores.txt"


// Função para gerar novo ID
int gerarIdColaborador() {
    FILE *file = fopen(ARQUIVO_COLABORADORES, "r");
    if (!file) return 1;

    int maxId = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        int id;
        sscanf(linha, "%d;", &id);
        if (id > maxId) maxId = id;
    }
    fclose(file);
    return maxId + 1;
}

// Cadastrar colaborador
void cadastrarColaborador() {
    Colaborador c;
    c.id = gerarIdColaborador();

    printf("\nDigite o nome: ");
    while (getchar() != '\n');
    fgets(c.nome, sizeof(c.nome), stdin);
    c.nome[strcspn(c.nome, "\n")] = 0;

    printf("Digite o CPF: ");
    fgets(c.cpf, sizeof(c.cpf), stdin);
    c.cpf[strcspn(c.cpf, "\n")] = 0;

    printf("Digite o telefone: ");
    fgets(c.telefone, sizeof(c.telefone), stdin);
    c.telefone[strcspn(c.telefone, "\n")] = 0;

    printf("Digite o email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    printf("Tipo de artesanato fornecido: ");
    fgets(c.tipoArtesanato, sizeof(c.tipoArtesanato), stdin);
    c.tipoArtesanato[strcspn(c.tipoArtesanato, "\n")] = 0;

    FILE *file = fopen(ARQUIVO_COLABORADORES, "a");
    if (!file) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    fprintf(file, "%d;%s;%s;%s;%s;%s\n",
            c.id, c.nome, c.cpf, c.telefone, c.email, c.tipoArtesanato);
    fclose(file);

    printf("\n✅ Colaborador cadastrado com sucesso!\n");
}

// Listar colaboradores
void listarColaboradores() {
    FILE *file = fopen(ARQUIVO_COLABORADORES, "r");
    if (!file) {
        printf("\nNenhum colaborador cadastrado ainda.\n");
        return;
    }

    char linha[256];
    printf("\n📋 Lista de Colaboradores:\n");
    printf("ID | Nome | CPF | Telefone | Email | Tipo de Artesanato\n");
    printf("---------------------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), file)) {
        int id;
        char nome[100], cpf[30], telefone[20], email[100], tipo[100];
        sscanf(linha, "%d;%99[^;];%29[^;];%19[^;];%99[^;];%99[^\n]",
               &id, nome, cpf, telefone, email, tipo);
        printf("%d | %s | %s | %s | %s | %s\n", id, nome, cpf, telefone, email, tipo);
    }

    fclose(file);
}

// Atualizar colaborador
void atualizarColaborador() {
    FILE *file = fopen(ARQUIVO_COLABORADORES, "r");
    if (!file) {
        printf("\nNenhum colaborador cadastrado ainda.\n");
        return;
    }

    Colaborador colaboradores[1000];
    int total = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%29[^;];%19[^;];%99[^;];%99[^\n]",
               &colaboradores[total].id,
               colaboradores[total].nome,
               colaboradores[total].cpf,
               colaboradores[total].telefone,
               colaboradores[total].email,
               colaboradores[total].tipoArtesanato);
        total++;
    }
    fclose(file);

    int idAtualizar;
    printf("\nDigite o ID do colaborador que deseja atualizar: ");
    scanf("%d", &idAtualizar);
    getchar();

    int encontrado = 0, indice = -1;
    for (int i = 0; i < total; i++) {
        if (colaboradores[i].id == idAtualizar) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Colaborador com ID %d não encontrado!\n", idAtualizar);
        return;
    }

    printf("\n🔎 Colaborador encontrado:\n");
    printf("ID: %d\n", colaboradores[indice].id);
    printf("Nome: %s\n", colaboradores[indice].nome);
    printf("CPF: %s\n", colaboradores[indice].cpf);
    printf("Telefone: %s\n", colaboradores[indice].telefone);
    printf("Email: %s\n", colaboradores[indice].email);
    printf("Tipo de Artesanato: %s\n", colaboradores[indice].tipoArtesanato);

    char opcao;
    printf("\nDeseja atualizar os dados deste colaborador? (s/n): ");
    scanf("%c", &opcao);
    getchar();

    if (opcao != 's' && opcao != 'S') {
        printf("\n❌ Atualização cancelada.\n");
        return;
    }

    printf("\nDigite o novo nome (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(colaboradores[indice].nome, linha);
    }

    printf("Digite o novo CPF (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(colaboradores[indice].cpf, linha);
    }

    printf("Digite o novo telefone (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(colaboradores[indice].telefone, linha);
    }

    printf("Digite o novo email (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(colaboradores[indice].email, linha);
    }

    printf("Digite o novo tipo de artesanato (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(colaboradores[indice].tipoArtesanato, linha);
    }

    file = fopen(ARQUIVO_COLABORADORES, "w");
    if (!file) {
        printf("\nErro ao salvar as alterações!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%s;%s;%s;%s\n",
                colaboradores[i].id,
                colaboradores[i].nome,
                colaboradores[i].cpf,
                colaboradores[i].telefone,
                colaboradores[i].email,
                colaboradores[i].tipoArtesanato);
    }
    fclose(file);

    printf("\n✅ Colaborador atualizado com sucesso!\n");
}

// Excluir colaborador
void excluirColaborador() {
    FILE *file = fopen(ARQUIVO_COLABORADORES, "r");
    if (!file) {
        printf("\nNenhum colaborador cadastrado ainda.\n");
        return;
    }

    Colaborador colaboradores[1000];
    int total = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%29[^;];%19[^;];%99[^;];%99[^\n]",
               &colaboradores[total].id,
               colaboradores[total].nome,
               colaboradores[total].cpf,
               colaboradores[total].telefone,
               colaboradores[total].email,
               colaboradores[total].tipoArtesanato);
        total++;
    }
    fclose(file);

    int idExcluir;
    printf("\nDigite o ID do colaborador que deseja excluir: ");
    scanf("%d", &idExcluir);
    getchar();

    int encontrado = 0, indice = -1;
    for (int i = 0; i < total; i++) {
        if (colaboradores[i].id == idExcluir) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Colaborador com ID %d não encontrado!\n", idExcluir);
        return;
    }

    printf("\n⚠️ Colaborador encontrado:\n");
    printf("ID: %d\n", colaboradores[indice].id);
    printf("Nome: %s\n", colaboradores[indice].nome);
    printf("CPF: %s\n", colaboradores[indice].cpf);
    printf("Telefone: %s\n", colaboradores[indice].telefone);
    printf("Email: %s\n", colaboradores[indice].email);
    printf("Tipo de Artesanato: %s\n", colaboradores[indice].tipoArtesanato);

    char confirmar;
    printf("\nDeseja realmente excluir este colaborador? (s/n): ");
    scanf("%c", &confirmar);
    getchar();

    if (confirmar != 's' && confirmar != 'S') {
        printf("\n❌ Exclusão cancelada.\n");
        return;
    }

    for (int i = indice; i < total - 1; i++) {
        colaboradores[i] = colaboradores[i + 1];
    }
    total--;

    file = fopen(ARQUIVO_COLABORADORES, "w");
    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%s;%s;%s;%s\n",
                colaboradores[i].id,
                colaboradores[i].nome,
                colaboradores[i].cpf,
                colaboradores[i].telefone,
                colaboradores[i].email,
                colaboradores[i].tipoArtesanato);
    }
    fclose(file);

    printf("\n✅ Colaborador excluído com sucesso!\n");
}

// Menu de colaboradores
void menu_Colaboradores() {
    system("clear||cls");

    int opcao;
    do {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║       🎨 Menu de Colaboradores         ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Colaborador           ║\n");
        printf("║  [2] ➜ Listar Colaboradores            ║\n");
        printf("║  [3] ➜ Atualizar Colaborador           ║\n");
        printf("║  [4] ➜ Excluir Colaborador             ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarColaborador();
                break;
            case 2:
                listarColaboradores();
                break;
            case 3:
                atualizarColaborador();
                break;
            case 4:
                excluirColaborador();
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\n❌ Opção inválida!\n");
        }

        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcao != 0);
}