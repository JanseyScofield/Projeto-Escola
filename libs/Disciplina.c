#include "Disciplina.h"

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores){
	Disciplina novaDisciplina;
	char cpf[TAM_CPF];

	novaDisciplina.codigo = *qtdDisciplinas + 1;
	printf("Informe o nome:\n");
	fgets(novaDisciplina.nome, 125, stdin);
	printf("Digite a turma:\n");
	scanf("%d", &novaDisciplina.turma);
	printf("Digite o semestre da disciplina:\n");
	scanf("%d", &novaDisciplina.semestre);
	limparBuffer();

	printf("Digite o CPF do professor da matéria: ");
	fgets(cpf, TAM_CPF, stdin);	
	while (!validarCPF(cpf)){
		printf("CPF invalido. Digite novamente: ");
		fgets(cpf, TAM_CPF, stdin);	
	}
	
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

	Pessoa *ponteiroProf = &professores[posProfessor];
	novaDisciplina.professor = ponteiroProf;
	disciplinas[*qtdDisciplinas] = novaDisciplina;
	novaDisciplina.qtdAlunos = 0;
	(*qtdDisciplinas)++;
	printf("Disciplina cadastrada com sucesso!");
}

void mostrarDisciplinas(Disciplina *disciplinas, int qtdDisciplinas){
	int iCont;
	
	printf("\nDisciplinas cadastradas:\n");
	for(iCont = 0; iCont < qtdDisciplinas; iCont++){
		printf("--------------------------------------\n");
		printf("Codigo: %d\n", disciplinas[iCont].codigo);
		printf("Nome: %s", disciplinas[iCont].nome);
		printf("Turma: %d\n", disciplinas[iCont].turma);
		printf("Professor(a): %s\n",  disciplinas[iCont].professor->nome);
		// if(disciplinas[iCont].qtdAlunos >  0){
		// 	int jCont;
		// 	printf("Alunos cadastrados: \n");
		// 	for(jCont = 0; jCont < disciplinas[iCont].qtdAlunos; jCont++){
		// 		printf(" %d - %s\n", jCont + 1, disciplinas[iCont].alunos[jCont]->nome);			
		// 	}
		// }
		// else{
		// 	printf("Ainda nao ha alunos cadastrados nessa disciplina");
		// }
		//Deixei comentado, pois vou usar essa logica depois em outro lugar.
    	printf("\n--------------------------------------\n");
	}
}