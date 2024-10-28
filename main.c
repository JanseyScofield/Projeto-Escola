#include <stdio.h>
#include <stdlib.h>
#include "libs/pessoa/Pessoa.h"
#include "libs/utils.h"
#include "libs/Modulo_Pessoa.h"

void menuInicial();

int main(){
     int qtdAlunos = 0, qtdProfessores = 0, qtdDisciplinas = 0;
     int sair = 0;

     Pessoa lstAlunos[TAM_LISTAS];
     Pessoa lstProfessores[TAM_LISTAS];


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
                    limparTela();
                    sair = 1;
                    break;
               }
               case 1: {
                    char tipo[] = "ALUNO";
                    ModuloPessoa(lstAlunos, &qtdAlunos, tipo);
                    break;
               }
               case 2: {
                    char tipo[] = "PROFESSOR";
                    limparTela();
                    ModuloPessoa(lstProfessores, &qtdProfessores, tipo);
                    break;
               }
               default: {
                    entradaInvalida();
               }
          }
     }

     return 0;
}

void menuInicial() {
     printf("PROJETO ESCOLA\n");
     printf("0 - Sair\n");
     printf("1 - Aluno\n");
     printf("2 - Professor\n");
     printf("3 - Disciplina\n");
     printf("\n");
}