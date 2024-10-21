#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
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

int buscarPessoaPorCPF(Pessoa pessoas[], int qtdPessoas, char cpf[12])
{
    int iCont, jCont;
    int existe = 0, diferente;
    int pos = -1;
    int qtdDigitosIguais;

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

    return pos;
}

void mostrarPessoa(Pessoa pessoa)
{
    printf("\n--------------------------------------\n");
    printf("Matricula: %d\n", pessoa.matricula);
    printf("Nome: %s", pessoa.nome);
    printf("Sexo: %c\n", pessoa.sexo);
    printf("Data de nascimento: ");
    //mostrarDataFormatada(pessoa.data);
    printf("\n");
    printf("CPF: %s\n", pessoa.cpf);
    printf("Quantidades de disciplinas associadas: %d", pessoa.qtdMaterias);
    printf("\n--------------------------------------\n");
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
}

void copiarArrayDePessoas(Pessoa arrayOriginal[], Pessoa arrayNovo[], int quantidade)
{
    for (int i = 0; i < quantidade && arrayOriginal[i].ativa; i++)
    {
        arrayNovo[i] = arrayOriginal[i];
    }
}