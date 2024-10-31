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
    printf("4 - Relatorios %s\n", txt);
}


void ModuloPessoa(Pessoa lstPessoa[], int *qtdPessoasCadastradas, int *qtdPessoasAtivas, char tipo[])
{
    int sair = 0;

    while(!sair)
    {   
        char entrada;
        int opcao;
        
        limparTela();
        menuPessoa(tipo);

        scanf(" %c", &entrada);
        limparBuffer();
        opcao = charToNumber(entrada);
        
        switch(opcao)
        {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                cadastrarPessoa(lstPessoa, qtdPessoasCadastradas, qtdPessoasAtivas, tipo);
                break;
            }
            case 2: {
                atualizarPessoa(lstPessoa, qtdPessoasAtivas, tipo);
                break;
            }
            case 3: {
                excluirPessoa(lstPessoa, qtdPessoasAtivas, tipo);
                break;
            }
            case 4: {
                moduloRelatorioPessoa(lstPessoa, qtdPessoasAtivas, tipo);
                break;
            }
            default: {
                entradaInvalida();
            }
        }
    }
}