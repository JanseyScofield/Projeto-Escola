#include <stdio.h>
#include <stdlib.h>
#include "libs/Pessoa.h"
#include "libs/utils.h"
#include "libs/Modulo_Professor.h"

void menuInicial();

int main(){
     int qtdAlunos = 0, qtdProfessores = 0, qtdDisciplinas = 0;
     int sair = 0;
     int opcao;

     Pessoa lstAlunos[TAM_LISTAS];
     Pessoa lstProfessores[TAM_LISTAS];


     while(!sair) {
          limparTela();
          menuInicial();
          
          scanf("%d", &opcao);
          limparBuffer();

          switch(opcao) {
               case 0: {
                    limparTela();
                    sair = 1;
                    break;
               }
               case 2: {
                    int sairProfessor = 0;
                    limparTela();
                    ModuloProfessor(lstProfessores, &qtdProfessores);
                    break;
               }
               default: {
                    limparTela();
                    printf("Entrada invalida.\n");
                    esperarEnter();
               }
          }
     }
}

void menuInicial() {
     printf("PROJETO ESCOLA\n");
     printf("0 - Sair\n");
     printf("1 - Aluno\n");
     printf("2 - Professor\n");
     printf("3 - Disciplina\n");
}