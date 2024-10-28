#include "Pessoa.h"
#include "../utils.h"
#ifndef DB
#define DB

void cadastrarPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]);
void atualizarPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]);
void excluirPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]);

void listarPessoasOrdenadasPorSexo(Pessoa lstPessoa[], int quantidade, char ordem);
void listarPessoasOrdenadasPorNome(Pessoa lstPessoa[], int quantidade);
void listarPessoasOrdenadasPorData(Pessoa lstPessoa[], int quantidade);
void buscarPessoasAtravesDeStr(Pessoa lstPessoa[], Pessoa encontrados[], int quantidade, char letras[]);

#endif