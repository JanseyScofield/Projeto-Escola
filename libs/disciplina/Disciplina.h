#ifndef DISCIPLINAS
#define DISCIPLINAS
#include <stdio.h>
#include "../pessoa/Pessoa.h"
#include "../utils.h"
#define TAM_LISTA_ALUNOS 60
#define TAM_NOME 125

typedef struct{
	int codigo;
	int ativa;	
	char nome[TAM_NOME];
	int turma;
	int semestre;
	Pessoa *professor;
	Pessoa *alunos[TAM_LISTA_ALUNOS];
	int qtdAlunos;
}Disciplina;

void mostrarDadosResumidosDisciplina(Disciplina disciplina);
void mostrarDisciplinas(Disciplina *disciplinas, int qtdDisciplinas);
int buscarDisciplinaPorCodigo(Disciplina *disciplinas, int qtdDisciplinas);
void mostrarDisciplinaDetalhada(Disciplina *disciplinas, int qtdDisciplinas);
void ordenarDisciplinaPorStatus(Disciplina *disciplinas, int qtdDisciplinas);
void copiarArrayDisciplinas(Disciplina  *listaDisciplina, int tamanhoArrayNovo, Disciplina *novoArray);
#endif