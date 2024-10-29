#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
#include "Pessoa.h"

int validarSexo(char sexo)
{
    int valido = 1;

    if (sexo != 'F' && sexo != 'M')
    {
        valido = 0;
    }

    return valido;
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
        if (qtdDigitosIguais == 11){
            pos = iCont;
        }
    }

    return pos;
}

void mostrarPessoa(Pessoa pessoa)
{
    printf("\n--------------------------------------\n");
    printf("Matricula: %d\n", pessoa.matricula);
    printf("Ativo : %d\n", pessoa.ativa);
    printf("Nome: %s", pessoa.nome);
    printf("\n");
    printf("Sexo: %c\n", pessoa.sexo);
    printf("Data de nascimento: ");
    mostrarDataFormatada(pessoa.data);
    printf("\n");
    printf("CPF: %s\n", pessoa.cpf);
    printf("Quantidades de disciplinas associadas: %d", pessoa.qtdMaterias);
    printf("\n--------------------------------------\n");
}

void mostrarPessoas(Pessoa pessoa[], int qtdPessoas)
{
    int iCont;

    for (iCont = 0; iCont < qtdPessoas; iCont++)
    {
        if(pessoa[iCont].ativa)
            mostrarPessoa(pessoa[iCont]);
    }
}

void ordenandoPessoasPorSexo(Pessoa pessoa[], int quantidade, char sexo)
{
    int j;
    for (j = 1; j < quantidade; j++)
    {
        Pessoa key = pessoa[j];
        int i = j - 1;
        while (i > -1 && pessoa[i].sexo != sexo)
        {
            pessoa[i + 1] = pessoa[i];
            i = i - 1;
        }
        pessoa[i + 1] = key;
    }
}

void ordenandoPessoasPorNome(Pessoa pessoa[], int quantidade) {
    for(int j = 1; j < quantidade; j++) {
        int atual = 0;
        int i = j - 1;
        Pessoa key = pessoa[j];
        while(i > -1 && pessoa[i].nome[atual] >= key.nome[atual]) {
            while(pessoa[i].nome[atual] == key.nome[atual]) {
                atual++;
            }
            if(pessoa[i].nome[atual] > key.nome[atual])
            {
                pessoa[i+1] = pessoa[i];
                i = i - 1;
            }
        }
        pessoa[i + 1] = key;
    }
}

void ordenandoPessoasAtivas(Pessoa pessoa[], int quantidade)
{
    int j;
    for (j = 1; j < quantidade; j++) {
        int i = j - 1;
        Pessoa key = pessoa[j];
        while (i > -1 && !pessoa[i].ativa)
        {
            pessoa[i + 1] = pessoa[i];
            i = i - 1;
        }
        pessoa[i + 1] = key;
    }
}


void ordenandoPessoasPorData(Pessoa pessoa[], int qtdPessoas) {
    ordenandoPessoasPorAno(pessoa, qtdPessoas);
    ordenandoPessoasPorMes(pessoa, qtdPessoas);
    ordenandoPessoasPorDia(pessoa, qtdPessoas);
}

void ordenandoPessoasPorAno(Pessoa pessoa[], int qtdPessoas) {
    for(int j = 0; j < qtdPessoas; j++) {
        int i = j - 1;
        Pessoa key = pessoa[j];
        while(i > -1 && pessoa[i].data.ano > key.data.ano) {
            pessoa[i + 1] = pessoa[i];
            i = i - 1;
        }
        pessoa[i + 1] = key;
    }
}
void ordenandoPessoasPorMes(Pessoa pessoa[], int qtdPessoas) {
    for(int j = 0; j < qtdPessoas; j++) {
        int i = j - 1;
        Pessoa key = pessoa[j];
        while(i > -1 && pessoa[i].data.mes > key.data.mes && pessoa[i].data.ano == key.data.ano) {
            pessoa[i + 1] = pessoa[i];
            i = i - 1;
        }
        pessoa[i + 1] = key;
    }
}
void ordenandoPessoasPorDia(Pessoa pessoa[], int qtdPessoas) {
    for(int j = 0; j < qtdPessoas; j++) {
        int i = j - 1;
        Pessoa key = pessoa[j];
        while( i > -1 && pessoa[i].data.dia > key.data.dia 
        && pessoa[i].data.ano == key.data.ano 
        && pessoa[i].data.mes == key.data.mes) 
        {
            pessoa[i + 1] = pessoa[i];
            i = i - 1;
        }
        pessoa[i + 1] = key;
    }
}

void copiarArrayDePessoas(Pessoa arrayOriginal[], Pessoa arrayNovo[], int quantidade)
{
    for (int i = 0; i < quantidade && arrayOriginal[i].ativa; i++)
    {
        arrayNovo[i] = arrayOriginal[i];
    }
}