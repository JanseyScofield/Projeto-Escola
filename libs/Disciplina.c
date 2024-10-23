#include "Disciplina.h"

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores){
	Disciplina novaDisciplina;
	char cpf[TAM_CPF];

	novaDisciplina.codigo = *qtdDisciplinas + 1;
	novaDisciplina.ativa = 1;
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
	professores[posProfessor].qtdMaterias++;
	Pessoa *ponteiroProf = &professores[posProfessor];
	novaDisciplina.professor = ponteiroProf;
	novaDisciplina.qtdAlunos = 0;
	disciplinas[*qtdDisciplinas] = novaDisciplina;
	(*qtdDisciplinas)++;
	printf("Disciplina cadastrada com sucesso!");
}

void mostrarDadosResumidosDisciplina(Disciplina disciplina){
	printf("Codigo: %d\n", disciplina.codigo);
	printf("Nome: %s", disciplina.nome);
	printf("Turma: %d\n", disciplina.turma);
	printf("Professor(a): %s\n",  disciplina.professor->nome);
	printf("Quantidade de alunos: %d", disciplina.qtdAlunos);
}

void mostrarDisciplinas(Disciplina *disciplinas, int qtdDisciplinas){
	int iCont;
	
	printf("\nDisciplinas cadastradas:\n");
	for(iCont = 0; iCont < qtdDisciplinas; iCont++){
		printf("--------------------------------------\n");
		mostrarDadosResumidosDisciplina(disciplinas[iCont]);
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

int buscarDisciplinaPorCodigo(Disciplina *disciplinas, int qtdDisciplinas, int codigoDisciplina){
	int inicio = 0;
	int fim = qtdDisciplinas - 1;
	int meio;
 
	while(inicio <= fim){
		meio = inicio + fim / 2;

		if(disciplinas[meio].codigo > codigoDisciplina){
			fim = meio - 1;
		}
		else if(disciplinas[meio].codigo < codigoDisciplina){
			inicio = meio + 1;
		}
		else{
			return meio;
		}
	}

	return -1;
}