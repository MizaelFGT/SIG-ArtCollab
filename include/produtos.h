#ifndef PRODUTOS_H
#define PRODUTOS_H

// Estrutura de Produto
typedef struct
{
    int id;
    char nome[50];
    float preco;
} Produto;

// Variveis globais
extern Produto produtos[100];
extern int totalProdutos;

// Funcs do modulo Produtos
int gerarIdProduto();
void cadastrarProduto();
void listarProdutos();
void atualizarProduto();
void excluirProduto();
void menu_Produtos();

#endif // PRODUTOS_H
