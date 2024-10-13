#ifndef ALUNOS
#define ALUNOS
#include <stdio.h>
#include "Pessoa.h"
#define TAM_LISTA_ALUNOS 1000

void cadastrarAluno();
void listarAlunosMatriculados();

typedef struct{
    Pessoa pessoa;
    int matriculado;
    int qtdMaterias;
}Aluno;

Aluno alunos[TAM_LISTA_ALUNOS];
int qtdAlunos = 0;

Aluno buscarAlunoPorCPF(char cpf[12]){
    int iCont, jCont;
    int qtdDigitosIguais;

    for(iCont = 0; iCont < qtdAlunos; iCont++){
        qtdDigitosIguais = 0;
        for(jCont = 0; jCont < 11; jCont++){
            if(alunos[iCont].pessoa.cpf[jCont] == cpf[jCont]){
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

    Aluno null;
    null.pessoa.matricula = 0;
    null.matriculado = 0;
    null.qtdMaterias = 0;
    return null;
}

void cadastrarAluno(){
    Aluno novoAluno;
    novoAluno.pessoa = cadastrarPessoa(qtdAlunos + 1);
    Aluno alunoExiste = buscarAlunoPorCPF(novoAluno.pessoa.cpf);
    if(alunoExiste.pessoa.matricula > 0){
        printf("Ja existe um aluno com esse CPF cadastrado no sistema.");
    }
    else{
        novoAluno.matriculado = 1;
        novoAluno.qtdMaterias = 0;
        alunos[qtdAlunos] = novoAluno;
        qtdAlunos++;
        printf("Aluno cadastrado com sucesso!\n");
    }
}

void listarAlunosMatriculados(){
    int iCont;
    printf("Todos os alunos matriculados:\n");
    for(iCont = 0; iCont < qtdAlunos; iCont++){
        if(alunos[iCont].matriculado){
            printf("--------------------------------------\n");
            mostrarPessoa(alunos[iCont].pessoa);
            printf("Quantidades de disciplinas: %d\n", alunos[iCont].qtdMaterias);
            printf("--------------------------------------\n");
        }
    }
}

#endif