#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "utils.h"
#include "Pessoa.h"

int validarSexo(char sexo)
{
    if (sexo >= 'a' && sexo <= 'z')
    {
        sexo = 'A' + sexo - 'a';
    }

    if (sexo != 'F' && sexo != 'M')
    {
        return 0;
    }

    return 1;
}

int validarNumerosVerificadores(char cpf[TAM_CPF], int posicaoVerificador)
{
    int iCont, jCont;
    int limite = posicaoVerificador + 8;
    int pesosDigitos[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int verificador = 0, valorRecebido;
    int restoDiv;

    for (iCont = 0, jCont = limite - 1; iCont < limite; iCont++, jCont--)
    {
        verificador += (cpf[iCont] - '0') * pesosDigitos[jCont];
    }

    restoDiv = verificador % 11;
    verificador = restoDiv >= 2 ? 11 - restoDiv : 0;
    valorRecebido = (cpf[posicaoVerificador + 8] - '0');

    if (verificador != valorRecebido)
    {
        return 0;
    }
    return 1;
}

int validarCPF(char cpf[TAM_CPF])
{
    int iCont;
    int qtdCaracteres = 0;
    int numerosIguais = 1;

    for (iCont = 0; iCont < TAM_CPF - 1; iCont++)
    {
        if (cpf[iCont] == '\n' || (cpf[iCont] < '0' && cpf[iCont] > '9'))
        {
            return 0;
        }
        qtdCaracteres++;
    }

    if (qtdCaracteres != TAM_CPF - 1)
    {
        return 0;
    }

    for (iCont = 1; iCont < TAM_CPF - 1; iCont++)
    {
        if (cpf[0] == cpf[iCont])
        {
            numerosIguais++;
        }
    }

    if (numerosIguais == TAM_CPF - 1)
    {
        return 0;
    }

    if (validarNumerosVerificadores(cpf, 1))
    {
        return validarNumerosVerificadores(cpf, 2);
    }

    return 0;
}

void cadastrarPessoa(Pessoa lstPessoa[], int *quantidade)
{
    Pessoa pessoa;
    int validar = 0;
    char op;

    while (!validar && op != 'n')
    {
        op = 'a'; // Essa atribuição existe somente para o caso de existir lixo em tipos CHARS. (Evitar erro no while)
        pessoa.matricula = *quantidade + 1;
        printf("Informe o nome: ");
        fgets(pessoa.nome, tam, stdin);
        printf("Informe o cpf (somente números): ");
        fgets(pessoa.cpf, TAM_CPF, stdin);
        printf("Informe a data de nascimento: ");
        pessoa.data = inserirData();
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &pessoa.sexo);
        pessoa.qtdMaterias = 0;
        int cpfCadastrado = intBuscarPessoaPorCPF(lstPessoa, *quantidade, pessoa.cpf);
        limparBuffer();
        if (validarCPF(pessoa.cpf) && validarData(pessoa.data) && validarSexo(pessoa.sexo) && cpfCadastrado == -1)
        {
            validar = 1;
            mostrarPessoa(pessoa);
        }
        else
        {
            printf("\nAlguma informacao incorreta.\n");
            printf("Deseja tentar realizar o cadastro novamente? (s/n)\n");
            while (op != 's' && op != 'n')
            {
                scanf(" %c", &op);
            }
            limparBuffer();
        }
    }

    if (op != 'n')
    {
        lstPessoa[*quantidade] = pessoa;
        *quantidade += 1;
    }

    return;
}

void atualizarPessoa(Pessoa lstPessoa[], int *quantidade)
{
    int validar = 0;
    char op = 'a';
    char cpf[TAM_CPF];

    printf("Informe o CPF do cadastrado que deseja alterar: ");
    fgets(cpf, TAM_CPF, stdin);

    int posicao = intBuscarPessoaPorCPF(lstPessoa, *quantidade, cpf);

    if (posicao >= 0)
    {
        Pessoa pessoa = lstPessoa[posicao];
        mostrarPessoa(pessoa);

        while (!validar && op != 'n')
        {
            limparBuffer();
            printf("Informe o nome: ");
            fgets(pessoa.nome, tam, stdin);
            printf("Informe a data de nascimento: ");
            pessoa.data = inserirData();
            printf("Informe o sexo (M/F): ");
            scanf(" %c", &pessoa.sexo);
            pessoa.qtdMaterias = 0;

            if (validarData(pessoa.data) && validarSexo(pessoa.sexo))
            {
                validar = 1;
            }
            else
            {
                limparBuffer();
                printf("Alguma informacao incorreta.\n");
                printf("Deseja tentar atualizar o cadastrado novamente? (s/n)\n");
                while (op != 's' && op != 'n')
                    op = getchar();
            }
            limparBuffer();
        }

        if (op != 'n')
            lstPessoa[*quantidade] = pessoa;
    }
    else
    {
        printf("\nEsse usuario nao foi encontrado.\n");
    }
}

int intBuscarPessoaPorCPF(Pessoa pessoas[], int qtdPessoas, char cpf[12])
{
    int iCont, jCont;
    int existe = 0, diferente;
    int pos = -1;
    int qtdDigitosIguais;

    printf("QUANTIDADE: %d", qtdPessoas);
    for (iCont = 0; iCont < qtdPessoas && pos == -1; iCont++)
    {
        diferente = 0;
        qtdDigitosIguais = 0;
        for (jCont = 0; pessoas[iCont].cpf[jCont] && !diferente; jCont++)
        {
            if (pessoas[iCont].cpf[jCont] == cpf[jCont])
            {
                qtdDigitosIguais++;
            }
            else
            {
                diferente = 1;
            }
        }
        if (qtdDigitosIguais == 11)
        {
            pos = iCont;
        }
    }
    printf("\n-----------(%d)(%d)---------\n", pos, qtdDigitosIguais);
    return pos;
}

Pessoa buscarPessoaPorCPF(Pessoa *pessoas, int qtdPessoas, char cpf[12])
{
    int iCont, jCont;
    int qtdDigitosIguais;

    for (iCont = 0; iCont < qtdPessoas; iCont++)
    {
        qtdDigitosIguais = 0;
        for (jCont = 0; jCont < 11; jCont++)
        {
            if (pessoas[iCont].cpf[jCont] == cpf[jCont])
            {
                qtdDigitosIguais++;
            }
            else
            {
                break;
            }
        }
        if (qtdDigitosIguais == 11)
        {
            return pessoas[iCont];
        }
    }

    Pessoa null;
    null.matricula = 0;
    null.ativa = 0;
    null.qtdMaterias = 0;
    return null;
}

void mostrarPessoa(Pessoa pessoa)
{
    printf("--------------------------------------\n");
    printf("Matricula: %d\n", pessoa.matricula);
    printf("Nome: %s", pessoa.nome);
    printf("Sexo: %c\n", pessoa.sexo);
    printf("Data de nascimento: ");
    mostrarDataFormatada(pessoa.data);
    printf("\n");
    printf("CPF: %s\n", pessoa.cpf);
    printf("Quantidades de disciplinas associadas: %d\n", pessoa.qtdMaterias);
    printf("--------------------------------------\n");
}

void mostrarPessoas(Pessoa pessoas[], int qtdPessoas)
{
    int iCont;

    for (iCont = 0; iCont < qtdPessoas; iCont++)
    {
        mostrarPessoa(pessoas[iCont]);
    }
}

void ordenandoPessoasPorSexo(Pessoa *pessoas, int quantidade, char sexo)
{
    int j;
    for (j = 1; j < quantidade; j++)
    {
        Pessoa key = pessoas[j];
        int i = j - 1;
        while (i > -1 && pessoas[i].sexo != sexo)
        {
            pessoas[i + 1] = pessoas[i];
            i = i - 1;
        }
        pessoas[i + 1] = key;
    }
}

void ordenandoPessoasAtivas(Pessoa ListaPessoas[], int quantidade)
{
    int j;
    Pessoa pessoas[quantidade];
    copiarArrayDePessoas(ListaPessoas, pessoas, quantidade);
    for (j = 1; j < quantidade; j++)
    {
        Pessoa key = pessoas[j];
        int i = j - 1;
        while (i > -1 && !pessoas[i].ativa)
        {
            pessoas[i + 1] = pessoas[i];
            i = i - 1;
        }
        pessoas[i + 1] = key;
    }
    mostrarPessoas(pessoas, quantidade);
}

void copiarArrayDePessoas(Pessoa arrayOriginal[], Pessoa arrayNovo[], int quantidade)
{
    for (int i = 0; i < quantidade && arrayOriginal[i].ativa; i++)
    {
        arrayNovo[i] = arrayOriginal[i];
    }
}