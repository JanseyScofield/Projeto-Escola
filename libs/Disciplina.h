#include <stdio.h>
#include "Pessoa.h"
#define TAM_LISTA_ALUNOS 50

typedef struct{
	int codigo;
	char nome[125];
	int turma;
	int semestre;
	Pessoa professor;
	Pessoa alunos[TAM_LISTA_ALUNOS];	
}Disciplina;
