#ifndef DISCIPLINASDB
#define DISCIPLINASDB
#include "Disciplina.h"
#define TAM_NOME 125

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores);
void deletarDisciplina(Disciplina *disciplinas, int qtdDisciplinas);
void atualizarDisciplina(Disciplina *disciplinas, int qtdDisciplinas);
void matricularAluno(Disciplina *disciplinas, int qtdDisciplinas, Pessoa *alunos, int qtdAlunos);
#endif