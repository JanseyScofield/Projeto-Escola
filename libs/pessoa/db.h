#include "Pessoa.h"
#include "../utils.h"
#ifndef DB
#define DB

void cadastrarPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]);
void atualizarPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]);
void excluirPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]);

#endif