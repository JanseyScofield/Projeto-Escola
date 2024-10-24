#include <stdio.h>
#include <stdlib.h>
#include "libs/pessoa/Pessoa.h"
#include "libs/utils.h"
#include "libs/Modulo_Pessoa.h"
#include "libs/disciplina/Disciplina.h"
#include "libs/disciplina/Disciplinadb.h"

int main(){     
    Pessoa lstAlunos[TAM_LISTAS];
    int qtdAlunos = 2;
    Pessoa lstProfessores[TAM_LISTAS];
    int qtdProfessores = 1;
    Disciplina disciplinas[TAM_LISTAS];
    int qtdDisciplinas = 0;

    Data dataNascimento = {10, 8 , 1945};
    Pessoa professor = {1, "Maria", 'F',dataNascimento, "86086623538", 1, 0};
    Pessoa aluno1 = {1, "Jose", '2',dataNascimento, "85753637515", 1, 0};
    Pessoa aluno2 = {2, "Alice", '2',dataNascimento, "21335516549", 1, 0};
    lstProfessores[qtdProfessores- 1] = professor;
    lstProfessores[0] = aluno1;
    lstProfessores[qtdProfessores- 1] = professor;
    cadastrarDisciplina(disciplinas, &qtdDisciplinas, lstProfessores, qtdProfessores);
    limparBuffer();
    cadastrarDisciplina(disciplinas, &qtdDisciplinas, lstProfessores, qtdProfessores);
    limparBuffer();
    mostrarDisciplinaDetalhada(disciplinas,qtdDisciplinas);
    deletarDisciplina(disciplinas, &qtdDisciplinas);
    return 0;
}