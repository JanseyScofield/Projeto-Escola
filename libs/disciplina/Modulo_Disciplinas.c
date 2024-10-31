#include "Modulo_Disciplinas.h"

void menuDisciplinas(){
    printf("MODULO DISCIPLINAS\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
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
                limparTela();
                if(qtdProfessores == 0){
                    printf("Nao pode cadastrar disciplina sem professor cadastrado.\n");
                }
                else{
                    cadastrarDisciplina(disciplinas, qtdDisciplinas, professores,  qtdProfessores);
                    limparBuffer();
                }
                esperarEnter();
                break;
            }
            case 2: {
                if(*qtdDisciplinas == 0){
                    printf("Ainda nao ha disciplinas cadastradas.\n");
                }
                else{
                    printf("O que deseja atualizar?\n");
                    printf("0 - Voltar\n");
                    printf("1 - Dados da Disciplina\n");
                    printf("2 - Matricular um aluno\n");
                    printf("3 - Excluir um aluno\n");

                    scanf(" %c", &entradaAtualizar);
                    limparBuffer();
                    opcaoAtualizar = charToNumber(entradaAtualizar);
                    switch(opcaoAtualizar){
                        case 0:
                            break;
                        case 1:
                            if(*qtdDisciplinas == 0){
                               printf("Ainda nao ha disciplinas cadastradas.\n");
                            }
                            else{
                                atualizarDisciplina(disciplinas, *qtdDisciplinas, professores, qtdProfessores);
                                limparBuffer();
                            }
                            break;
                        case 2:
                            if(qtdAlunos = 0){
                                printf("Ainda nao ha alunos cadastradas.\n");
                            }
                            else if(*qtdDisciplinas == 0){
                                printf("Ainda nao ha disciplinas cadastradas.\n");
                            }
                            else{
                                matricularAluno(disciplinas, *qtdDisciplinas, alunos, qtdAlunos);
                                limparBuffer();
                            }
                            break;
                        case 3:
                            if(qtdAlunos = 0){
                                printf("Ainda nao ha alunos cadastradas.\n");
                            }
                            else{
                                excluirAlunoDisciplina(disciplinas, *qtdDisciplinas);
                                limparBuffer();
                            }
                }
                esperarEnter();
                break;
                }
            }
            case 3: {
                if(*qtdDisciplinas == 0){
                    printf("Ainda nao ha disciplinas cadastradas.\n");
                }
                else{
                    deletarDisciplina(disciplinas, *qtdDisciplinas);
                    limparBuffer();
                }
                esperarEnter();
                break;
            }
            case 4: {
                printf("O que deseja visualizar?\n");
                printf("0 - Voltar\n");
                printf("1 - Listar todas as disciplinas\n");
                printf("2 - Listar uma disciplina\n");

                scanf(" %c", &entradaAtualizar);
                limparBuffer();
                opcaoAtualizar = charToNumber(entradaAtualizar);
                switch(opcaoAtualizar){
                    case 0:
                        break;
                    case 1:
                        if(*qtdDisciplinas == 0){
                            printf("Ainda nao ha disciplinas cadastradas");
                        }
                        else{
                            mostrarDisciplinas(disciplinas, *qtdDisciplinas);
                        }
                        esperarEnter();
                        limparBuffer();
                        break;
                    case 2:
                        if(*qtdDisciplinas == 0){
                            printf("Ainda nao ha disciplinas cadastradas"); 
                        }
                        else if(qtdAlunos == 0){
                            printf("Ainda nao ha aluno cadastrados"); 
                        }
                        else{
                            mostrarDisciplinaDetalhada(disciplinas, *qtdDisciplinas);
                        }
                        esperarEnter();
                        limparBuffer();
                        break;
                    default:
                        entradaInvalida();
                        break;
                }              
                break;
            }
            default: {
                entradaInvalida();
            }
        }
    }
}
