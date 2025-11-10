#ifndef CLIENTE_H
#define CLIENTE_H

// registro das funcoes de clientes
void menu_Clientes();

// estrutura cliente
typedef struct
{
    int id;
    char nome[100];
    char cpf[15];
    char telefone[20];
    char email[100];
} Cliente;

// funcoes clientes
void cadastrarCliente();
void listarClientes();
void excluirCliente();
void atualizarCliente();

#endif