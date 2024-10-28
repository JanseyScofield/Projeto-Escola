#include "Modulo_Relatorio_Pessoa.h"
#include "utils.h"
#include "pessoa/db.h"

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
        limparTela();
        char entrada;
        int opcao;

        menuRelatorio(titulo);

        scanf(" %c", &entrada);
        limparBuffer();
        opcao = charToNumber(entrada);

        limparTela();

        if(opcao == 0)
        {
            sair = 1;
        }
        else {
            if(*qtdPessoa > 0)
            {
                switch(opcao)
                {
                    case 1: {
                        printf("LISTANDO %s", titulo);
                        mostrarPessoas(lstPessoa, *qtdPessoa);
                        break;
                    }
                    case 2: {
                        printf("LISTANDO %s POR SEXO\n", titulo);
                        listarPessoasOrdenadasPorSexo(lstPessoa, *qtdPessoa, 'F');
                        break;
                    }
                    case 3: {
                        printf("LISTANDO %s POR NOME", titulo);
                        listarPessoasOrdenadasPorNome(lstPessoa, *qtdPessoa);
                        break;
                    }
                    case 4: {
                        printf("LISTANDO %s POR DATA", titulo);
                        listarPessoasOrdenadasPorData(lstPessoa, *qtdPessoa);
                        break;
                    }
                    case 5: {
                        printf("BUSCAR %s", titulo);
                        break;
                    }
                    case 6: {
                        if(tipo[0] == 'A')
                        {
                            printf("LISTANDO %s CADASTRADOS EM MENOS DE 3 DISCIPLINAS", titulo);
                            break;
                        }
                    }
                    default: {
                        entradaInvalida();
                    }
                }
            }
            else
            {
                printf("\nNAO HA %s CADASTRADOS\n", titulo);
            }
            esperarEnter();
        }
    }
}