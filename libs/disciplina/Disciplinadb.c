#include "Disciplinadb.h"

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

void deletarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas){
    int codigoDisciplina, posicaoDisciplina;
    Disciplina *disciplina;
    char confirmar[1];
    int sairOperacao = 0;

    do{
        printf("Digite o codigo da disciplina que deseja deletar: ");
        scanf("%d", &codigoDisciplina);
        posicaoDisciplina = buscarDisciplinaPorCodigo(disciplinas, *qtdDisciplinas, codigoDisciplina);
        if(posicaoDisciplina ==  -1){
            printf("Disciplina nao encontrada. Digite outro codigo.\n");
        }
        else{
            break;
        }
    }while(1);
    
    disciplina = &disciplinas[posicaoDisciplina];
    mostrarDadosResumidosDisciplina(*disciplina);
    limparBuffer();
    do{
        printf("\nDeseja mesmo deletar essa disciplina?('S' para sim e 'N' para nao)\n");
        scanf("%c", &confirmar[0]);
        toUpper(confirmar);
        switch(confirmar[0]){
            case 'S':
                disciplina->ativa = 0;
                printf("Disciplina deletada com sucesso!");
                (*qtdDisciplinas)--;
                sairOperacao = 1;
                break;
            case 'N':
                printf("Operacao cancelada.");
                sairOperacao = 1;
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
        }
    }while(!sairOperacao);
}