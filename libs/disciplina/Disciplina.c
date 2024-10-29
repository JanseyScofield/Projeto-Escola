#include "Disciplina.h"

void mostrarDadosResumidosDisciplina(Disciplina disciplina){
	printf("Codigo: %d\n", disciplina.codigo);
	printf("Status: ");
	disciplina.ativa ? printf("Ativa\n") : printf("Inativa\n"); 
	printf("Nome: %s", disciplina.nome);
	printf("Turma: %d\n", disciplina.turma);
	printf("Semestre: %d\n", disciplina.semestre);
	printf("Professor(a): %s\n",  disciplina.professor->nome);
	printf("Quantidade de alunos: %d", disciplina.qtdAlunos);
}

void mostrarDisciplinas(Disciplina *disciplinas, int qtdDisciplinas){
	int iCont;
	
	printf("\nDisciplinas cadastradas:\n");
	for(iCont = 0; iCont < qtdDisciplinas && disciplinas[iCont].ativa; iCont++){
		printf("--------------------------------------\n");
		mostrarDadosResumidosDisciplina(disciplinas[iCont]);
    	printf("\n--------------------------------------\n");
	}
}

int buscarDisciplinaPorCodigo(Disciplina *disciplinas, int qtdDisciplinas){
	int inicio = 0;
	int fim = qtdDisciplinas - 1;
	int meio;
	int codigoDisciplina;
	int iCont, tamanhoArrayNovo = 1;
	
	for(iCont = 0; disciplinas[iCont].ativa; iCont++){
		tamanhoArrayNovo++;
	}

	Disciplina  disciplinasAtivas[tamanhoArrayNovo];

	copiarArrayDisciplinas(disciplinas, tamanhoArrayNovo, disciplinasAtivas);

	printf("Digite o codigo da disciplina: ");
    scanf("%d", &codigoDisciplina);
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;

		if(disciplinasAtivas[meio].codigo > codigoDisciplina){
			fim = meio - 1;
		}
		else if(disciplinasAtivas[meio].codigo < codigoDisciplina){
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
		indexDisciplina = buscarDisciplinaPorCodigo(disciplinas, qtdDisciplinas);
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

void ordenarDisciplinaPorStatus(Disciplina *disciplinas, int qtdDisciplinas){
	int iCont,jCont;
	Disciplina key;

	for(iCont = qtdDisciplinas - 1; iCont >= 0; iCont--){
		key = disciplinas[iCont];
		jCont = iCont - 1;
		while(jCont >= 0  && key.ativa > disciplinas[jCont].ativa){
			disciplinas[jCont + 1] = disciplinas[jCont];
			jCont--;
		}
		disciplinas[jCont + 1] = key;
	}
}

void copiarArrayDisciplinas(Disciplina  *listaDisciplina, int tamanhoArrayNovo, Disciplina *novoArray){
	int iCont;

	for(iCont = 0; iCont < tamanhoArrayNovo; iCont++){
		novoArray[iCont] = listaDisciplina[iCont];
	}
}