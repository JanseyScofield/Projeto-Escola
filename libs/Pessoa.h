#include <stdio.h>
#include "Data.h"
#ifndef PESSOA
#define PESSOA
#define tam 256
#define TAM_LISTAS 1000
#define TAM_CPF 12

typedef struct {
    int matricula; 
    char nome[tam];
    char sexo;
    Data data;
    char cpf[TAM_CPF];
    int ativa;
    int qtdMaterias;
} Pessoa;

int validarSexo(char sexo);
int validarNumerosVerificadores(char cpf[TAM_CPF], int limite);
int validarCPF(char cpf[TAM_CPF]);
Pessoa buscarPessoaPorCPF(Pessoa *pessoas, int qtdPessoas, char cpf[12]);
Pessoa cadastrarPessoa(int matricula);
void mostrarPessoas(Pessoa *pessoas, int qtdPessoas);

int validarSexo(char sexo){
    if(sexo >= 'a' && sexo <= 'z'){
        sexo = 'A' + sexo - 'a';
    }

    if(sexo != 'F' && sexo != 'M'){
        return 0;
    }

    return 1;
}

int validarNumerosVerificadores(char cpf[TAM_CPF], int posicaoVerificador){
    int iCont, jCont;
    int limite = posicaoVerificador + 8;
    int pesosDigitos[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int verificador = 0, valorRecebido;
    int restoDiv;

    for(iCont = 0, jCont = limite - 1; iCont < limite; iCont++, jCont--){
        verificador += (cpf[iCont] - '0') * pesosDigitos[jCont];
    }

    restoDiv = verificador % 11;
    verificador = restoDiv >= 2 ? 11 - restoDiv : 0;
    valorRecebido = (cpf[posicaoVerificador + 8] - '0');

    if(verificador != valorRecebido){
        return 0;
    }
    return 1;
}

int validarCPF(char cpf[TAM_CPF]){
    int iCont;
    int qtdCaracteres = 0;
    int numerosIguais = 1;

    for(iCont = 0; iCont < TAM_CPF - 1; iCont++){
        if(cpf[iCont] == '\n' || (cpf[iCont] < '0' && cpf[iCont] > '9')){
           return 0;
        }
        qtdCaracteres++;
    }

    if(qtdCaracteres != TAM_CPF - 1){
        return 0;
    }

    for(iCont = 1; iCont < TAM_CPF -  1; iCont++){
        if(cpf[0] == cpf[iCont]){
            numerosIguais++;
        }
    }

    if(numerosIguais == TAM_CPF - 1){
        return  0;
    }

    if(validarNumerosVerificadores(cpf, 1)){
        return validarNumerosVerificadores(cpf, 2);
    }

    return 0;
}

Pessoa cadastrarPessoa(int matricula) {
    Pessoa pessoa;
    int validar = 0;

    while(!validar) {
        pessoa.matricula = matricula;
        printf("Informe o nome: ");
        fgets(pessoa.nome, tam, stdin);
        printf("Informe o cpf (somente números): ");
        fgets(pessoa.cpf, TAM_CPF, stdin);
        printf("Informe a data de nascimento: ");
        pessoa.data = inserirData();
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &pessoa.sexo);
        pessoa.qtdMaterias = 0;
        
        if (validarCPF(pessoa.cpf) && validarData(pessoa.data) && validarSexo(pessoa.sexo)){
            validar = 1;
        }
        else {
            printf("Alguma informacao incorreta. Repita o processo.\n");
        }
        int ch;
            do {
                ch = fgetc(stdin);
            } while (ch != EOF && ch != '\n');
    }
    
    return pessoa;
}

Pessoa buscarPessoaPorCPF(Pessoa *pessoas, int qtdPessoas, char cpf[12]){
    int iCont, jCont;
    int qtdDigitosIguais;

    for(iCont = 0; iCont < qtdPessoas; iCont++){
        qtdDigitosIguais = 0;
        for(jCont = 0; jCont < 11; jCont++){
            if(pessoas[iCont].cpf[jCont] == cpf[jCont]){
                qtdDigitosIguais ++;
            }
            else{
                break;
            }
        }
        if(qtdDigitosIguais == 11){
            return pessoas[iCont];
        }
    }

    Pessoa null;
    null.matricula = 0;
    null.ativa = 0;
    null.qtdMaterias = 0;
    return null;
}

void mostrarPessoas(Pessoa *pessoas, int qtdPessoas){
    int iCont;

    for(iCont = 0; iCont < qtdPessoas; iCont++){
        printf("--------------------------------------\n");
        printf("Matricula: %d\n", pessoas[iCont].matricula);
        printf("Nome: %s", pessoas[iCont].nome);
        printf("Sexo: %c\n", pessoas[iCont].sexo);
        printf("Data de nascimento: ");
        mostrarDataFormatada(pessoas[iCont].data);
        printf("\n");
        printf("CPF: %s\n", pessoas[iCont].cpf);
        printf("Quantidades de disciplinas associadas: %d\n", pessoas[iCont].qtdMaterias);
        printf("--------------------------------------\n");
    }
}

void ordenandoPessoasPorSexo(Pessoa *pessoas, int quantidade, char sexo)
{
    int j;
    for(j = 1; j < quantidade; j++) {
        Pessoa key = pessoas[j];
        int i = j - 1;
        while(i > -1 && pessoas[i].sexo != sexo) {
            pessoas[i + 1] = pessoas[i];
            i = i - 1;
        }
        pessoas[i + 1] = key;
    }
}

void ordenandoPessoasAtivas(Pessoa *pessoas, int quantidade, char sexo)
{
    int j;
    for(j = 1; j < quantidade; j++) {
        Pessoa key = pessoas[j];
        int i = j - 1;
        while(i > -1 && !pessoas[i].ativa) {
            pessoas[i + 1] = pessoas[i];
            i = i - 1;
        }
        pessoas[i + 1] = key;
    }
}

#endif
