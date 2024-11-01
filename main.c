#include <stdio.h>
#include <stdlib.h>
#include "libs/disciplina/Disciplina.h"
#include "libs/disciplina/Modulo_Disciplinas.h"
#include "libs/pessoa/Pessoa.h"
#include "libs/utils.h"
#include "libs/Modulo_Pessoa.h"

#define TAM_LISTAS 10

void menuInicial();

int main(){
     int qtdAlunosAtivos = 0, qtdProfessoresAtivos = 0, qtdDisciplinasAtivas = 0;
     int qtdAlunosCadastrados = 0, qtdProfessoresCadastrados = 0;
     int sair = 0;

     Pessoa lstAlunos[TAM_LISTAS];
     Pessoa lstProfessores[TAM_LISTAS];
     Disciplina lstDisciplinas[TAM_LISTAS];

     for(int i = 0; i < TAM_LISTAS; i++)
     {
          lstAlunos[i].ativa = 0;
          lstProfessores[i].ativa = 0;
     }

     while(!sair) {
          char entrada;
          int opcao;

          limparTela();
          
          menuInicial();
          
          scanf(" %c", &entrada);
          limparBuffer();
          opcao = charToNumber(entrada);

          switch(opcao) {
               case 0: {
                    sair = 1;
                    break;
               }
               case 1: {
                    char tipo[] = "ALUNO";
                    ModuloPessoa(lstAlunos, &qtdAlunosCadastrados, &qtdAlunosAtivos, tipo);
                    break;
               }
               case 2: {
                    char tipo[] = "PROFESSOR";
                    ModuloPessoa(lstProfessores, &qtdProfessoresCadastrados, &qtdProfessoresAtivos, tipo);
                    break;
               }
               case 3: {
                    ModuloDisciplinas(lstDisciplinas, &qtdDisciplinasAtivas, lstProfessores, qtdProfessoresAtivos, lstAlunos, qtdAlunosAtivos);
                    break;
               }
               default: {
                    entradaInvalida();
               }
          }
     }
     
     limparTela();

     exit(0);
}

void menuInicial() {
     printf("PROJETO ESCOLA\n");
     printf("Qual modulo deseja entrar?\n");
     printf("0 - Sair\n");
     printf("1 - Modulo Aluno\n");
     printf("2 - Modulo Professor\n");
     printf("3 - Modulo Disciplina\n");
     printf("\n");
}
