#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// registro das funcoes de funcionarios
void menu_Funcionarios();

// estrutura funcionario
typedef struct {
    int id;
    char nome[100];
    char cpf[16];      
    char telefone[20];
    char email[100];
    char cargo[50]
} Funcionario;


//funcoes funcionario
void cadastrarFuncionario();
void listarFuncionario();
void excluirFuncionario();
void atualizarFuncionario();

#endif