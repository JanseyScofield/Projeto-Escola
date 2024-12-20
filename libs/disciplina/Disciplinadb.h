#ifndef DISCIPLINASDB
#define DISCIPLINASDB
#include "Disciplina.h"
#define TAM_NOME 125

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores);
void deletarDisciplina(Disciplina *disciplinas, int qtdDisciplinas);
void atualizarDisciplina(Disciplina *disciplinas, int qtdDisciplinas, Pessoa *professores, int qtdProfessores);
void matricularAluno(Disciplina *disciplinas, int qtdDisciplinas, Pessoa *alunos, int qtdAlunos);
void excluirAlunoDisciplina(Disciplina *disciplinas, int qtdDisciplinas);
#endif
