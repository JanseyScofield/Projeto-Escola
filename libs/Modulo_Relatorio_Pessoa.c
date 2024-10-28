#include "Modulo_Relatorio_Pessoa.h"
#include "utils.h"
void menuRelatorio(char tipo[]) {
    char txt[20];
    copyStr(tipo, txt);
    toLower(txt);
    printf("MODULO RELATORIO DE %s\n", tipo);
    printf("0 - Voltar\n");
    printf("1 - Listar %s\n", txt);
    printf("2 - Listar %s por sexo\n", txt);
    printf("3 - Listar %s por nome\n", txt);
    printf("4 - Listar %s por data de nascimento\n", txt);
    printf("5 - Procurar %s\n", txt);
    if(tipo[0] == 'A')
        printf("6 - Listar alunos matriculados em menos de 3 disciplinas\n");
}


void moduloRelatorioPessoa(Pessoa lstPessoa[], int *qtdPessoa, char tipo[]) {
    int sair = 0;
    char titulo[12];

    if(tipo[0] == 'A')
    {
        char txt[12] = "ALUNOS";
        copyStr(txt, titulo);
    }
    else 
    {
        char txt[12] = "PROFESSORES";
        copyStr(txt, titulo);
    }
    
    limparTela();

    while(!sair)
    {
        char entrada;
        int opcao;

        limparTela();
        menuRelatorio(titulo);

        scanf(" %c", &entrada);
        limparBuffer();
        opcao = charToNumber(entrada);

        limparTela();

        switch(opcao)
        {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                if(*qtdPessoa > 0)
                    mostrarPessoas(lstPessoa, *qtdPessoa);
                else
                    printf("NAO HA %s CADASTRADOS", titulo);

                esperarEnter();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                if(tipo[0] == 'A')
                {
                    limparTela();
                    printf("ALUNO!!");
                    esperarEnter();
                    break;
                }
            }
            default: {
                entradaInvalida();
            }
        }
    }


}