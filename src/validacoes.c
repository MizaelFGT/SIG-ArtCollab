#include <string.h>
#include <ctype.h>
#include "../include/validacoes.h"

//------------------------------------------------
//@OPENAI FUNCOES CRIADAS VIA https://chatgpt.com/
//------------------------------------------------


// Nome: apenas letras e espaços, mínimo 2 caracteres
int validarNome(const char *nome) {
    if (strlen(nome) < 2) return 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha((unsigned char)nome[i]) && nome[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

// CPF: deve ter 11 dígitos (não faz cálculo oficial)
int validarCPF(const char *cpf) {
    char numeros[12];
    int j = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit((unsigned char)cpf[i])) {
            numeros[j++] = cpf[i];
        }
    }
    numeros[j] = '\0';
    return (strlen(numeros) == 11);
}

// Telefone: 10 ou 11 dígitos
int validarTelefone(const char *telefone) {
    char numeros[20];
    int j = 0;
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (isdigit((unsigned char)telefone[i])) {
            numeros[j++] = telefone[i];
        }
    }
    numeros[j] = '\0';
    return (strlen(numeros) >= 10 && strlen(numeros) <= 11);
}

// Email: precisa ter '@' e '.' depois do '@'
int validarEmail(const char *email) {
    const char *arroba = strchr(email, '@');
    if (!arroba || arroba == email) return 0;
    const char *ponto = strchr(arroba, '.');
    return (ponto && ponto > arroba + 1);
}
