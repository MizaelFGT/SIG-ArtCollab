#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/funcionarios.h"
#define ARQUIVO_FUNCIONARIOS "dados/funcionarios.txt"

// Função para gerar novo ID
int gerarIdFuncionario() {
    FILE *file = fopen(ARQUIVO_FUNCIONARIOS, "r");
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

// Cadastrar novo funcionário
void cadastrarFuncionario() {
    Funcionario f;
    f.id = gerarIdFuncionario();

    printf("\nDigite o nome: ");
    while(getchar() != '\n');
    fgets(f.nome, sizeof(f.nome), stdin);
    f.nome[strcspn(f.nome, "\n")] = 0;

    printf("Digite o CPF (formato 000.000.000-00): ");
    fgets(f.cpf, sizeof(f.cpf), stdin);
    f.cpf[strcspn(f.cpf, "\n")] = 0;

    printf("Digite o telefone: ");
    fgets(f.telefone, sizeof(f.telefone), stdin);
    f.telefone[strcspn(f.telefone, "\n")] = 0;

    printf("Digite o email: ");
    fgets(f.email, sizeof(f.email), stdin);
    f.email[strcspn(f.email, "\n")] = 0;

    printf("Digite o cargo: ");
    fgets(f.cargo, sizeof(f.cargo), stdin);
    f.cargo[strcspn(f.cargo, "\n")] = 0;

    FILE *file = fopen(ARQUIVO_FUNCIONARIOS, "a");
    if (!file) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    fprintf(file, "%d;%s;%s;%s;%s;%s\n", f.id, f.nome, f.cpf, f.telefone, f.email, f.cargo);
    fclose(file);

    printf("\n✅ Funcionário cadastrado com sucesso!\n");
}

// Listar funcionários
void listarFuncionarios() {
    FILE *file = fopen(ARQUIVO_FUNCIONARIOS, "r");
    if (!file) {
        printf("\nNenhum funcionário cadastrado ainda.\n");
        return;
    }

    char linha[256];
    printf("\n📋 Lista de Funcionários:\n");
    printf("ID | Nome | CPF | Telefone | Email | Cargo\n");
    printf("------------------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), file)) {
        int id;
        char nome[100], cpf[30], telefone[20], email[100], cargo[50];
        sscanf(linha, "%d;%99[^;];%29[^;];%19[^;];%99[^;];%49[^\n]",
               &id, nome, cpf, telefone, email, cargo);
        printf("%d | %s | %s | %s | %s | %s\n", id, nome, cpf, telefone, email, cargo);
    }

    fclose(file);
}

// Excluir funcionário
void excluirFuncionario() {
    FILE *file = fopen(ARQUIVO_FUNCIONARIOS, "r");
    if (!file) {
        printf("\nNenhum funcionário cadastrado ainda.\n");
        return;
    }

    Funcionario funcionarios[1000];
    int total = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%29[^;];%19[^;];%99[^;];%49[^\n]",
               &funcionarios[total].id,
               funcionarios[total].nome,
               funcionarios[total].cpf,
               funcionarios[total].telefone,
               funcionarios[total].email,
               funcionarios[total].cargo);
        total++;
    }
    fclose(file);

    int idExcluir;
    printf("\nDigite o ID do funcionário que deseja excluir: ");
    scanf("%d", &idExcluir);
    getchar();

    int encontrado = 0, indice = -1;
    for (int i = 0; i < total; i++) {
        if (funcionarios[i].id == idExcluir) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Funcionário com ID %d não encontrado!\n", idExcluir);
        return;
    }

    printf("\n⚠️ Funcionário encontrado:\n");
    printf("ID: %d\n", funcionarios[indice].id);
    printf("Nome: %s\n", funcionarios[indice].nome);
    printf("CPF: %s\n", funcionarios[indice].cpf);
    printf("Telefone: %s\n", funcionarios[indice].telefone);
    printf("Email: %s\n", funcionarios[indice].email);
    printf("Cargo: %s\n", funcionarios[indice].cargo);

    char confirmar;
    printf("\nDeseja realmente excluir este funcionário? (s/n): ");
    scanf("%c", &confirmar);
    getchar();

    if (confirmar != 's' && confirmar != 'S') {
        printf("\n❌ Exclusão cancelada.\n");
        return;
    }

    for (int i = indice; i < total - 1; i++) {
        funcionarios[i] = funcionarios[i + 1];
    }
    total--;

    file = fopen(ARQUIVO_FUNCIONARIOS, "w");
    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%s;%s;%s;%s\n",
                funcionarios[i].id,
                funcionarios[i].nome,
                funcionarios[i].cpf,
                funcionarios[i].telefone,
                funcionarios[i].email,
                funcionarios[i].cargo);
    }
    fclose(file);

    printf("\n✅ Funcionário excluído com sucesso!\n");
}

//atualizar funcionario

void atualizarFuncionario() {
    FILE *file = fopen(ARQUIVO_FUNCIONARIOS, "r");
    if (!file) {
        printf("\nNenhum funcionário cadastrado ainda.\n");
        return;
    }

    Funcionario funcionarios[1000];
    int total = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%29[^;];%19[^;];%99[^;];%49[^\n]",
               &funcionarios[total].id,
               funcionarios[total].nome,
               funcionarios[total].cpf,
               funcionarios[total].telefone,
               funcionarios[total].email,
               funcionarios[total].cargo);
        total++;
    }
    fclose(file);

    int idAtualizar;
    printf("\nDigite o ID do funcionário que deseja atualizar: ");
    scanf("%d", &idAtualizar);
    getchar();

    int encontrado = 0, indice = -1;
    for (int i = 0; i < total; i++) {
        if (funcionarios[i].id == idAtualizar) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Funcionário com ID %d não encontrado!\n", idAtualizar);
        return;
    }

    printf("\n🔎 Funcionário encontrado:\n");
    printf("ID: %d\n", funcionarios[indice].id);
    printf("Nome: %s\n", funcionarios[indice].nome);
    printf("CPF: %s\n", funcionarios[indice].cpf);
    printf("Telefone: %s\n", funcionarios[indice].telefone);
    printf("Email: %s\n", funcionarios[indice].email);
    printf("Cargo: %s\n", funcionarios[indice].cargo);

    char opcao;
    printf("\nDeseja atualizar os dados deste funcionário? (s/n): ");
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
        strcpy(funcionarios[indice].nome, linha);
    }

    printf("Digite o novo CPF (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(funcionarios[indice].cpf, linha);
    }

    printf("Digite o novo telefone (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(funcionarios[indice].telefone, linha);
    }

    printf("Digite o novo email (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(funcionarios[indice].email, linha);
    }

    printf("Digite o novo cargo (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(funcionarios[indice].cargo, linha);
    }

    // Reescreve o arquivo com os dados atualizados
    file = fopen(ARQUIVO_FUNCIONARIOS, "w");
    if (!file) {
        printf("\nErro ao salvar as alterações!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%s;%s;%s;%s\n",
                funcionarios[i].id,
                funcionarios[i].nome,
                funcionarios[i].cpf,
                funcionarios[i].telefone,
                funcionarios[i].email,
                funcionarios[i].cargo);
    }
    fclose(file);

    printf("\n✅ Funcionário atualizado com sucesso!\n");
}




// Menu de Funcionários
void menu_Funcionarios() {
    system("clear||cls");

    int opcao;
    do {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║         👨‍💼 Menu Funcionários           ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Funcionário           ║\n");
        printf("║  [2] ➜ Listar Funcionários             ║\n");
        printf("║  [3] ➜ Atualizar Funcionário           ║\n");
        printf("║  [4] ➜ Excluir Funcionário             ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarFuncionario();
                break;
            case 2:
                listarFuncionarios();
                break;
            case 3:
                atualizarFuncionario();
                break;
            case 4:
                excluirFuncionario();
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
