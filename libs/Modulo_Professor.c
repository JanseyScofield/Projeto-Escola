#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "Modulo_Professor.h"

void menuProfessor() {
    printf("MODULO PROFESSOR\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastro de Professor\n");
    printf("2 - Atualizar Professor\n");
    printf("3 - Excluir Professor\n");
    printf("4 - Relatorios de Professores\n");
}


void ModuloProfessor(Pessoa lstProfessor[], int *qtdProfessores)
{
    int sair = 0;

    while(!sair)
    {
        int opcao;
        menuProfessor();

        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao)
        {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                cadastrarPessoa(lstProfessor, qtdProfessores);
                printf("\nqtd: %d\n", *qtdProfessores);
                break;
            }
            case 2: {
                atualizarPessoa(lstProfessor, qtdProfessores);
                break;
            }
        }
    }
}