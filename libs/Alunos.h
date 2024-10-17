#ifndef ALUNOS
#define ALUNOS
#include <stdio.h>
#include "Pessoa.h"


void cadastrarAluno();
void listarAlunosMatriculados();
void menuAlunos(Pessoa *alunos, int *qtdAlunos);

Pessoa buscarAlunoPorCPF(Pessoa *alunos, int qtdAlunos, char cpf[12]){
    int iCont, jCont;
    int qtdDigitosIguais;

    for(iCont = 0; iCont < qtdAlunos; iCont++){
        qtdDigitosIguais = 0;
        for(jCont = 0; jCont < 11; jCont++){
            if(alunos[iCont].cpf[jCont] == cpf[jCont]){
                qtdDigitosIguais ++;
            }
            else{
                break;
            }
        }
        if(qtdDigitosIguais == 11){
            return alunos[iCont];
        }
    }

    Pessoa null;
    null.matricula = 0;
    null.ativa = 0;
    null.qtdMaterias = 0;
    return null;
}

void menuAlunos(Pessoa *alunos, int *qtdAlunos){
    int opcao;

    printf("    Alunos  /n");
    printf("O que deseja fazer?/n");
    printf("1 - Cadastrar alunos/n2 - Listar alunos matriculados/n3 - Editar aluno por matrícula/n4 - Deletar aluno por matrícula/n5 - Sair");
    scanf("%d", &opcao);
    switch (opcao){
        case 1:
            cadastrarAluno(alunos, qtdAlunos);
            break;
        case 2:
            listarAlunosMatriculados(alunos, *qtdAlunos);
            break;
        case 3:
            // Fazer posteriomente
            break;   
        case 4:
            // Fazer posteriomente
            break;
        case 5:
            break;
        default:
            printf("Valor invalido.");   
    }
}

void cadastrarAluno(Pessoa *alunos, int *qtdAlunos){
    Pessoa novoAluno;
    novoAluno = cadastrarPessoa(*qtdAlunos + 1);
    Pessoa alunoExiste = buscarAlunoPorCPF(alunos, *qtdAlunos, novoAluno.cpf);
    if(alunoExiste.matricula > 0){
        printf("Ja existe um aluno com esse CPF cadastrado no sistema.");
    }
    else{
        novoAluno.ativa = 1;
        novoAluno.qtdMaterias = 0;
        alunos[*qtdAlunos] = novoAluno;
        (*qtdAlunos)++;
        printf("Aluno cadastrado com sucesso!\n");
    }
}

void listarAlunosMatriculados(Pessoa *alunos, int qtdAlunos){
    if(qtdAlunos == 0 ){
        printf("Nao ha alunos cadastrados.");
    }
    else{
        printf("Todos os alunos matriculados:\n");
        mostrarPessoas(alunos, qtdAlunos);
    }
}

#endif
