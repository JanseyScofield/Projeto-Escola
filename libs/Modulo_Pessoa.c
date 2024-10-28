#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "Modulo_Pessoa.h"
#include "Modulo_Relatorio_Pessoa.h"
#include "pessoa/db.h"

void menuPessoa(char tipo[]) {
    char txt[20];
    copyStr(tipo, txt);
    toLower(txt);
    printf("MODULO %s\n", tipo);
    printf("0 - Voltar\n");
    printf("1 - Cadastrar %s\n", txt);
    printf("2 - Atualizar %s\n", txt);
    printf("3 - Excluir %s\n", txt);
    printf("4 - Relatorios\n", txt);
}


void ModuloPessoa(Pessoa lstPessoa[], int *qtdPessoas, char tipo[])
{
    int sair = 0;

    while(!sair)
    {
        int opcao;
        limparTela();
        menuPessoa(tipo);

        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao)
        {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                cadastrarPessoa(lstPessoa, qtdPessoas, tipo);
                break;
            }
            case 2: {
                atualizarPessoa(lstPessoa, qtdPessoas, tipo);
                break;
            }
            case 3: {
                excluirPessoa(lstPessoa, qtdPessoas, tipo);
                break;
            }
            case 4: {
                moduloRelatorioPessoa(lstPessoa, qtdPessoas, tipo);
                break;
            }
            default: {
                entradaInvalida();
            }
        }
    }
}