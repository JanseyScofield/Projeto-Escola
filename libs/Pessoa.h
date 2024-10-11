#include <stdio.h>
#include "Data.h"
#ifndef PESSOA
#define PESSOA
#define tam 256

typedef struct {
    char nome[tam];
    char sexo;
    Data data;
    char cpf[15] // "000.000.000-00" + '\0'
} Pessoa;

Pessoa cadastrarPessoa()

Pessoa cadastrarPessoa() {
    Pessoa pessoa;
    fgets(pessoa.nome, tam, stdin);
    scanf("%c", &pessoa.sexo);
    // Adicionar cadastro de DATA
    scanf("%s", &pessoa.cpf);

    return pessoa;
}

#endif