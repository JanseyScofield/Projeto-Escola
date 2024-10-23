#include <stdio.h>
#include <stdlib.h>
#include "libs/pessoa/Pessoa.h"
#include "libs/utils.h"
#include "libs/Modulo_Pessoa.h"
#include "libs/Disciplina.h"

int main(){     
    Pessoa lstAlunos[TAM_LISTAS];
    int qtdAlunos = 0;
    Pessoa lstProfessores[TAM_LISTAS];
    int qtdProfessores = 1;
    Disciplina disciplinas[TAM_LISTAS];
    int qtdDisciplinas = 0;

    Data dataNascimento = {10, 8 , 1945};
    Pessoa professor = {1, "Maria", 'F',dataNascimento, "86086623538", 1, 0};
    lstProfessores[qtdProfessores- 1] = professor;
    cadastrarDisciplina(disciplinas, &qtdDisciplinas, lstProfessores, qtdProfessores);
    limparBuffer();
    cadastrarDisciplina(disciplinas, &qtdDisciplinas, lstProfessores, qtdProfessores);
    mostrarDisciplinas(disciplinas, qtdDisciplinas);
    int posicaoDisciplina = (disciplinas, qtdDisciplinas, 1);
    printf("%d", posicaoDisciplina);
    return 0;
}