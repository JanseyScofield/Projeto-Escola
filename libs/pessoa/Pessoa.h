#ifndef PESSOA
#define PESSOA
#define tam 256
#define TAM_CPF 12
#include "../Data.h"

typedef struct {
    int matricula; 
    char nome[tam];
    char sexo;
    Data data;
    char cpf[TAM_CPF];
    int ativa;
    int qtdMaterias;
} Pessoa;

int validarSexo(char sexo);
int validarNumerosVerificadores(char cpf[], int limite);
int validarCPF(char cpf[]);
int buscarPessoaPorCPF(Pessoa pessoas[], int qtdPessoas, char cpf[12]);
void mostrarPessoa(Pessoa pessoa);
void mostrarPessoas(Pessoa *pessoas, int qtdPessoas);
void ordenandoPessoasAtivas(Pessoa ListaPessoas[], int qtdPessoas);
void ordenandoPessoasPorSexo(Pessoa pessoa[], int qtdPessoas, char sexo);
void ordenandoPessoasPorNome(Pessoa pessoa[], int qtdPessoas);
void ordenandoPessoasPorData(Pessoa pessoa[], int qtdPessoas);
void ordenandoPessoasPorAno(Pessoa pessoa[], int qtdPessoas);
void ordenandoPessoasPorMes(Pessoa pessoa[], int qtdPessoas);
void ordenandoPessoasPorDia(Pessoa pessoa[], int qtdPessoas);
void copiarArrayDePessoas(Pessoa *arrayOriginal, Pessoa *arrayNovo, int quantidade);

#endif
