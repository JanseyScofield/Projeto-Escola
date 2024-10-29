#include "Modulo_Relatorio_Pessoa.h"
#include "utils.h"
#include "pessoa/db.h"

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
                        char op[3];

                        printf("Escolha o mes:");
                        menuMeses();
                        fgets(op, 3, stdin);
                        tratarStr(op);

                        int num = strToPositiveNumber(op, strlen(op));
                        if(num >= 0 && num <= 12)
                        {
                            limparTela();
                            printf("ANIVERSARIANTES DO MES\n");
                            int qtd = 0;
                            for(int i = 0; i < *qtdPessoa; i++)
                                if(lstPessoa[i].ativa && lstPessoa[i].data.mes == num)
                                {
                                    mostrarPessoa(lstPessoa[i]);
                                    qtd += 1;
                                }
                            if(qtd == 0) {
                                printf("NAO HA %s QUE FAZEM ANIVERSARIO ESTE MES", titulo);
                            }
                        }
                        else
                        {
                            printf("Entrada invalida.\n");
                        }

                        break;
                    }
                    case 6: {
                        int len;
                        char letras[26];
                        printf("BUSCAR %s\n", titulo);

                        printf("Informe as letras para busca: ");
                        fgets(letras, 26, stdin);
                        printf("\n");
                        
                        tratarStr(letras);
                        toUpper(letras);
                        len = strlen(letras);

                        if(len >= 3) {
                            Pessoa encontrados[*qtdPessoa];
                            buscarPessoasAtravesDeStr(lstPessoa, encontrados, *qtdPessoa, letras);
                        }
                        else
                            printf("Digite ao menos 3 letras para realizar a busca.\n");

                        break;
                    }
                    case 7: {
                        if(tipo[0] == 'A')
                        {
                            int qtd = 0;
                            
                            printf("LISTANDO %s CADASTRADOS EM MENOS DE 3 DISCIPLINAS", titulo);

                            for(int i = 0; i < *qtdPessoa; i++) {
                                if(lstPessoa[i].ativa && lstPessoa[i].qtdMaterias < 3) {
                                    mostrarPessoa(lstPessoa[i]);
                                    qtd++;
                                }
                            }

                            if(qtd == 0)
                                printf("\nNAO HA ALUNOS CADASTRADOS EM MENOS DE 3 DISCIPLINAS\n");
                            
                            break;
                        }
                    }
                    default: {
                        printf("Entrada inválida.\n");
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

void menuRelatorio(char tipo[]) {
    char txt[20];
    copyStr(tipo, txt);
    toLower(txt);
    printf("MODULO RELATORIO DE %s\n", tipo);
    printf("\n0 - Voltar\n");
    printf("1 - Listar %s\n", txt);
    printf("2 - Listar %s por sexo\n", txt);
    printf("3 - Listar %s por nome\n", txt);
    printf("4 - Listar %s por data de nascimento\n", txt);
    printf("5 - Aniversariantes do mes (%s)\n", txt);
    printf("6 - Procurar %s\n", txt);
    if(tipo[0] == 'A')
        printf("7 - Listar alunos matriculados em menos de 3 disciplinas\n");
}

void menuMeses() {
    printf("\n1 - Janeiro\n");
    printf("2 - Fevereiro\n");
    printf("3 - Março\n");
    printf("4 - Abril\n");
    printf("5 - Maio\n");
    printf("6 - Junho\n");
    printf("7 - Julho\n");
    printf("8 - Agosto\n");
    printf("9 - Setembro\n");
    printf("10 - Outubro\n");
    printf("11 - Novembro\n");
    printf("12 - Dezembro\n");
}