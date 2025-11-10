#ifndef VENDAS_H
#define VENDAS_H

typedef struct
{
    int id;
    int idCliente;
    int idProduto;
    int quantidade;
    float valorUnitario;
    float valorTotal;
} Venda;

void cadastrarVenda();
void listarVendas();
void atualizarVenda();
void excluirVenda();
void menu_Vendas();

#endif
