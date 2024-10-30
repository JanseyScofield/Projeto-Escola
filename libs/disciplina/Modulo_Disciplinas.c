#include "Modulo_Disciplinas.h"

void menuDisciplinas(){
    printf("MODULO DISCIPLINAS\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina");
    printf("2 - Atualizar Disciplina\n");
    printf("3 - Excluir Disciplina\n");
    printf("4 - Relatorios Disciplina\n");
}
void ModuloDisciplinas(Disciplina disciplinas[], int *qtdDisciplinas, Pessoa professores[], int qtdProfessores, Pessoa alunos[], int qtdAlunos){
    int sair = 0;

    while(!sair)
    {   
        char entrada, entradaAtualizar;
        int opcao,  opcaoAtualizar;
        
        limparTela();
        menuDisciplinas();
        scanf(" %c", &entrada);
        limparBuffer();
        opcao = charToNumber(entrada);   
        switch(opcao)
        {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                cadastrarDisciplina(disciplinas, qtdDisciplinas, professores,  qtdProfessores);
                limparBuffer();
                break;
            }
            case 2: {
                printf("O que deseja atualizar?\n");
                printf("0 - Voltar\n");
                printf("1 - Dados da Disciplina");
                printf("2 - Matricular um aluno\n");
                printf("3 - Excluir um aluno\n");

                scanf(" %c", &entradaAtualizar);
                limparBuffer();
                opcaoAtualizar = charToNumber(entradaAtualizar);
                switch(opcaoAtualizar){
                    case 0:
                        break;
                    case 1:
                        atualizarDisciplina(disciplinas, *qtdDisciplinas, professores, qtdProfessores);
                        break;
                    case 2:
                        matricularAluno(disciplinas, *qtdDisciplinas, alunos, qtdAlunos);
                        limparBuffer();
                        break;
                    case 3:
                        excluirAlunoDisciplina(disciplinas, *qtdDisciplinas);
                        limparBuffer();
                        break;
                    default:
                        entradaInvalida();
                }   
                break;
            }
            case 3: {
                deletarDisciplina(disciplinas, *qtdDisciplinas);
                limparBuffer();
                break;
            }
            case 4: {
                // em breve
                break;
            }
            default: {
                entradaInvalida();
            }
        }
    }
}
