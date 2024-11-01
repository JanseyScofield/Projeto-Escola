#include "Disciplinadb.h"
#include "../utils.h"

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Pessoa *professores, int qtdProfessores){
	Disciplina novaDisciplina;
	char cpf[TAM_CPF];
	char op = 'a';
	int sair = 0;
	
	while(op != 'n' && !sair){
		novaDisciplina.codigo = *qtdDisciplinas + 1;
		novaDisciplina.ativa = 1;
		printf("Informe o nome: ");
		fgets(novaDisciplina.nome, TAM_NOME, stdin);
		printf("Digite a turma: ");
		scanf("%d", &novaDisciplina.turma);
		printf("Digite o semestre da disciplina: ");
		scanf("%d", &novaDisciplina.semestre);
		limparBuffer();
		printf("Digite o CPF do professor da matéria: ");
		fgets(cpf, TAM_CPF, stdin);

		int cpfValido = validarCPF(cpf);
		
		int posProfessor;

		if (!cpfValido)
			printf("\nCPF invalido.");
		else 
			posProfessor = buscarPessoaPorCPF(professores, qtdProfessores, cpf);

		if(posProfessor ==  - 1 || !professores[posProfessor].ativa || !cpfValido) {
			entradaInvalida();
			printf("Deseja continuar (s/n)?");
			while(op != 's' && op != 'n')
				scanf(" %c", &op);
		}
		else {
			Pessoa professor = professores[posProfessor];
			professores[posProfessor].qtdMaterias++;
			Pessoa *ponteiroProf = &professores[posProfessor];
			novaDisciplina.professor = ponteiroProf;
			novaDisciplina.qtdAlunos = 0;
			disciplinas[*qtdDisciplinas] = novaDisciplina;
			(*qtdDisciplinas)++;
			printf("Disciplina cadastrada com sucesso!");
			sair = 1;
		}
	}
	limparBuffer();
}

void deletarDisciplina(Disciplina *disciplinas, int qtdDisciplinas){
    int codigoDisciplina, posicaoDisciplina;
    Disciplina *disciplina;
    char confirmar[1];
    int sairOperacao = 0;

    posicaoDisciplina = encontrarPosicaoDisciplina(disciplinas, qtdDisciplinas);

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
    ordenarDisciplinaPorStatus(disciplinas, qtdDisciplinas);
}

void atualizarDisciplina(Disciplina *disciplinas, int qtdDisciplinas, Pessoa *professores, int qtdProfessores){
	int escolha, sair = 0;
	char ativarDisciplina[2];
	int posicaoDisciplina;
	Disciplina *disciplina;
	char cpf[TAM_CPF];
	
	while(!sair){
		posicaoDisciplina = buscarDisciplinaPorCodigo(disciplinas, qtdDisciplinas);
		if(posicaoDisciplina == -1){
			printf("Disciplina nao encontrada. Digite novamente.\n");
		}
		else{
			disciplina = &disciplinas[posicaoDisciplina];
			if(!disciplina->ativa){
				printf("Disciplina inativa. Digite novamente.\n");
			}
			else{

				sair = 1;		
			}
		}
	}
	
	printf("Informe o  novo nome: ");
	fgets(disciplina->nome, TAM_NOME, stdin);
	printf("Digite a turma: ");
	scanf("%d", &disciplina->turma);
	printf("Digite o semestre da disciplina: ");
	scanf("%d", &disciplina->semestre);
	limparBuffer();

	disciplina->professor->qtdMaterias--;
	printf("Digite o CPF do novo professor da matéria: ");
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
	disciplina->professor = ponteiroProf;
	printf("Disciplina atualizada com sucesso!");
	limparBuffer();
}

void matricularAluno(Disciplina *disciplinas, int qtdDisciplinas, Pessoa *alunos, int qtdAlunos){
	int posicaoDisciplina, alunoMatriculado, posAluno;
	char cpf[TAM_CPF];
	Disciplina *disciplina;
	Pessoa *aluno;

	posicaoDisciplina = encontrarPosicaoDisciplina(disciplinas, qtdDisciplinas);

	disciplina = &disciplinas[posicaoDisciplina];
	limparBuffer();
	
	do{
		printf("Digite o CPF do aluno que deseja matricular:\n");
		fgets(cpf, TAM_CPF, stdin);
		limparBuffer();
		
		alunoMatriculado = -1;
		if(disciplina->qtdAlunos > 0){
			alunoMatriculado = buscarPessoaPorCPF(*disciplina->alunos, disciplina->qtdAlunos, cpf);
			if(alunoMatriculado != -1){
				printf("Aluno ja matriculado nessa disciplina. Digite outro cpf.\n");
				posAluno = -1;
			}
		}

		if(alunoMatriculado == -1){
			posAluno = buscarPessoaPorCPF(alunos, qtdAlunos, cpf);
			if(posAluno == -1){
				printf("Aluno nao encontrado. Digite novamente.\n");
			}
			else{
				aluno = &alunos[posAluno];
				if(!aluno->ativa){
					printf("Aluno inativo. Digite outro cpf.");
					posAluno = -1;
				}
			}
		}

	}while(posAluno == -1);


	aluno->qtdMaterias++;
	disciplina->alunos[disciplina->qtdAlunos] = aluno;
	disciplina->qtdAlunos++;

	printf("Aluno matriculado na disciplina com sucesso!");
}

void excluirAlunoDisciplina(Disciplina *disciplinas, int qtdDisciplinas){
	int posDisciplina, posAluno;
	char cpfAluno[TAM_CPF];
	Disciplina *disciplina;

	posDisciplina = encontrarPosicaoDisciplina(disciplinas, qtdDisciplinas);
	disciplina = &disciplinas[posDisciplina];
	limparBuffer();
	
	do{
		printf("Digite o cpf do aluno que deseja excluir: ");
		fgets(cpfAluno, TAM_CPF, stdin);
		limparBuffer();
		posAluno = buscarPessoaPorCPF(*disciplina->alunos, disciplina->qtdAlunos, cpfAluno);
		if(posAluno == -1){
			printf("Esse aluno nao esta cadastrado nessa disciplina. Digite outro cpf.");
		}
	}while(posAluno == -1);
	
	disciplina->alunos[posAluno] = NULL;
	printf("Aluno excluido da disciplina com sucesso!");
	ordenarListaAlunosPorMatriculados(disciplina->alunos, disciplina->qtdAlunos);
	disciplina->qtdAlunos--;
}
