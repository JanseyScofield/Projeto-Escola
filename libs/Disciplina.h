#ifndef DISCIPLINAS
#define DISCIPLINAS
#include <stdio.h>
#include <stdlib.h>
#include "pessoa/Pessoa.h"
#include "utils.h"
#define TAM_LISTA_ALUNOS 50

typedef struct{
	int codigo;
	char nome[125];
	int turma;
	int semestre;
	Pessoa *professor;
	Pessoa *alunos[TAM_LISTA_ALUNOS];
	int qtdAlunos;	
}Disciplina;

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores);
void mostrarDisciplinas(Disciplina *disciplinas, int qtdDisciplinas);

#endif