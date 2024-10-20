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
          system("clear||cls");
          printf("Projeto Escola\n");
          menuInicial();
          
          scanf("%d", &opcao);
          limparBuffer();

          switch(opcao) {
               case 0: {
                    system("clear||cls");
                    sair = 1;
                    break;
               }
               case 2: {
                    int sairProfessor = 0;
                    system("clear||cls");
                    ModuloProfessor(lstProfessores, &qtdProfessores);

                    break;
               }
               default: {
                    system("clear||cls");
                    printf("Entrada invalida. Aperte um botao para continuar.\n");
                    getc(stdin);
               }
          }
     }
}

void menuInicial() {
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
}