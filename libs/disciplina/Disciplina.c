#include "Disciplina.h"

void mostrarDadosResumidosDisciplina(Disciplina disciplina){
	printf("Codigo: %d\n", disciplina.codigo);
	printf("Nome: %s", disciplina.nome);
	printf("Turma: %d\n", disciplina.turma);
	printf("Semestre: %d\n", disciplina.semestre);
	printf("Professor(a): %s\n",  disciplina.professor->nome);
	printf("Quantidade de alunos: %d", disciplina.qtdAlunos);
}

void mostrarDisciplinas(Disciplina *disciplinas, int qtdDisciplinas){
	int iCont;
	
	printf("\nDisciplinas cadastradas:\n");
	for(iCont = 0; iCont < qtdDisciplinas; iCont++){
		printf("--------------------------------------\n");
		mostrarDadosResumidosDisciplina(disciplinas[iCont]);
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

void mostrarDisciplinaDetalhada(Disciplina *disciplinas, int qtdDisciplinas){
	int codigoDisciplina, indexDisciplina;

	do{
		printf("Digite o codigo da disciplina que deseja visualizar: ");
		scanf("%d", &codigoDisciplina);
		indexDisciplina = buscarDisciplinaPorCodigo(disciplinas, qtdDisciplinas, codigoDisciplina);
		if(indexDisciplina == -1){
			printf("Disciplina nao encontrada.\n");
		}
		else{
			break;
		}
	}while(1);
	printf("\n--------------------------------------\n");
	mostrarDadosResumidosDisciplina(disciplinas[indexDisciplina]);
	printf("\n");
	if(disciplinas[indexDisciplina].qtdAlunos >  0){
		int jCont;
		printf("Alunos cadastrados: \n");
		for(jCont = 0; jCont < disciplinas[indexDisciplina].qtdAlunos; jCont++){
			printf(" %d - %s\n", jCont + 1, disciplinas[indexDisciplina].alunos[jCont]->nome);			
		}
	}
	else{
		printf("Ainda nao ha alunos cadastrados nessa disciplina");
	}
	printf("\n--------------------------------------\n");
}