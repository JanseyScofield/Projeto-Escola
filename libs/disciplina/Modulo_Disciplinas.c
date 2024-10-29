#include "Modulo_Disciplinas.h"

void menuDisciplinas(){
    printf("MODULO DISCIPLINAS\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina");
    printf("2 - Atualizar Disciplina\n");
    printf("3 - Excluir Disciplina\n");
    printf("4 - Matricular aluno em uma disciplina\n");
    printf("5 - Relatorios Disciplina\n");
}
void ModuloDisciplinas(Disciplina disciplinas[], int *qtdDisciplinas, Pessoa professores[], int qtdProfessores, Pessoa alunos[], int qtdAlunos){
    int sair = 0;

    while(!sair)
    {   
        char entrada;
        int opcao;
        
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
                break;
            }
            case 2: {
                // Em breve
                break;
            }
            case 3: {
                deletarDisciplina(disciplinas, qtdDisciplinas);
                break;
            }
            case 4: {
                matricularAluno(disciplinas, qtdDisciplinas, alunos,  qtdAlunos);
                break;
            }
            case 5:
                // Em breve
                break;
            default: {
                entradaInvalida();
            }
        }
    }
}