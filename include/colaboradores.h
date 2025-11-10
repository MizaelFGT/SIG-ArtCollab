#ifndef COLABORADORES_H
#define COLABORADORES_H

typedef struct {
    int id;
    char nome[100];
    char cpf[30];
    char telefone[20];
    char email[100];
    char tipoArtesanato[100];
} Colaborador;

void menu_Colaboradores();
void cadastrarColaborador();
void listarColaboradores();
void atualizarColaborador();
void excluirColaborador();

#endif
