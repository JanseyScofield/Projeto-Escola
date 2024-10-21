#include <stdio.h>
#include <stdlib.h>
#include "pessoa/Pessoa.h"
#define TAM_LISTA_ALUNOS 50

typedef struct{
	int codigo;
	char nome[125];
	int turma;
	int semestre;
	Pessoa *professor;
	Pessoa *alunos[TAM_LISTA_ALUNOS];	
}Disciplina;

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores);


void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores){
	Disciplina novaDisciplina;
	char cpf[TAM_CPF];

	printf("Informe o nome:\n");
	fgets(novaDisciplina.nome, 125, stdin);
	printf("Digite a turma:\n");
	scanf("%d", &novaDisciplina.turma);
	printf("Digite o semestre da disciplina:\n");
	scanf("%d", &novaDisciplina.semestre);
	getchar();

	printf("Digite o CPF do professor da matéria: ");
	fgets(cpf, TAM_CPF, stdin);
	int posProfessor = buscarPessoaPorCPF(professores, qtdProfessores, cpf);
	while(1){
		if(posProfessor ==  - 1){
			printf("Esse professor nao existe. Digite outro CPF\n");
			fgets(cpf, TAM_CPF, stdin);
			posProfessor = buscarPessoaPorCPF(professores, qtdProfessores, cpf);
		}
		else{
			Pessoa professor = professores[posProfessor];
			if(!professor.ativa){
			printf("Esse professor esta inativo. Digite outro CPF\n");
			fgets(cpf, TAM_CPF, stdin);
			posProfessor = buscarPessoaPorCPF(professores, qtdProfessores, cpf);
			}
			else{
				break;
			}
		}
	}
	printf("Professor encontrado.");
	Pessoa *ponteiroProf = &professores[posProfessor];
	novaDisciplina.professor = ponteiroProf;
	int posicaoNovaDisciplina = *qtdDisciplinas > 0 ? *qtdDisciplinas - 1 : 0; 
	disciplinas[posicaoNovaDisciplina] = novaDisciplina;
	printf("Disciplina cadastrada com sucesso!");
}

