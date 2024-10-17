#ifndef ALUNOS
#define ALUNOS
#include <stdio.h>
#include "Pessoa.h"
#define TAM_LISTA_ALUNOS 1000

void cadastrarAluno();
void listarAlunosMatriculados();

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
    printf("Todos os alunos matriculados:\n");
    mostrarPessoas(alunos, qtdAlunos);
}

#endif