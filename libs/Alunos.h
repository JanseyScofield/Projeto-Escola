#ifndef ALUNOS
#define ALUNOS
#include <stdio.h>
#include "Pessoa.h"

void cadastrarAluno();
void listarAlunosMatriculados();
void menuAlunos(Pessoa *alunos, int *qtdAlunos);

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
    Pessoa alunoExiste = buscarPessoaPorCPF(alunos, *qtdAlunos, novoAluno.cpf);
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
