#include <stdio.h>
#include "Pessoa.h"
#define TAM_LISTA_ALUNOS 50

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *pessoas, int qtdPessoas);

typedef struct{
	int codigo;
	char nome[125];
	int turma;
	int semestre;
	Pessoa professor;
	Pessoa alunos[TAM_LISTA_ALUNOS];	
}Disciplina;

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *pessoas, int qtdPessoas){
	Disciplina novaDisciplina;
	char cpf[TAM_CPF];
	printf("Informe o nome:\n");
	fgets(novaDisciplina.nome, 125, stdin);
	printf("Digite a turma:\n");
	scanf("%d", &novaDisciplina.turma);
	printf("Digite o semestre da disciplina:\n");
	scanf("%d", &novaDisciplina.semestre);
	printf("Digite o CPF do professor da matéria: ");
	fgets(cpf, TAM_CPF, stdin);
	Pessoa professor = buscarPessoaPorCPF(pessoas, qtdPessoas, cpf);
	while(!professor.ativa){
		printf("Esse professor esta inativo ou nao existe. Digite outro CPF\n");
		fgets(cpf, TAM_CPF, stdin);
		professor = buscarPessoaPorCPF(pessoas, qtdPessoas, cpf);
	}
}
