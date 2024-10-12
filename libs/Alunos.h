#ifndef ALUNOS
#define ALUNOS
#include <stdio.h>
#include "Pessoa.h"
#define TAM_LISTA_ALUNOS 1000

void cadastrarAluno();

typedef struct{
    Pessoa pessoa;
    int ativo = 1;

}Aluno;

Aluno alunos[TAM_LISTA_ALUNOS];
int qtdAlunos = 0;



#endif