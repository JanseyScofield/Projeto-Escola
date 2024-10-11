#include <stdio.h>
#include "Data.h"
#ifndef PESSOA
#define PESSOA
#define tam 256

typedef struct {
    char nome[tam];
    char sexo;
    Data data;
    char cpf[11]
} Pessoa;

Pessoa cadastrarPessoa();
int validarSexo(char sexo);
int validarNumerosVerificadores(char cpf[11], int limite);
int validarCPF(char cpf[11]);

Pessoa cadastrarPessoa() {
    Pessoa pessoa;

    fgets(pessoa.nome, tam, stdin);
    pessoa.data = inserirData();
    scanf("%c", &pessoa.sexo);
    scanf("%s", &pessoa.cpf);

    return pessoa;
}

int validarSexo(char sexo){
    if(sexo >= 'a' && sexo <= 'z'){
        sexo -= ' ';
    }

    if(sexo != 'F' && sexo != 'M'){
        return 0;
    }

    return 1;
}

int validarNumerosVerificadores(char cpf[11], int posicaoVerificador){
    int iCont, jCont;
    int limite = posicaoVerificador + 8;
    int pesosDigitos[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int verificador = 0, valorRecebido;
    int restoDiv;

    for(iCont = 0, jCont = limite - 1; iCont < limite; iCont++, jCont--){
        verificador += (cpf[iCont] - '0') * pesosDigitos[jCont];
    }

    restoDiv = verificador % 11;
    verificador = restoDiv >= 2? 11 - restoDiv : 0;
    valorRecebido = (cpf[posicaoVerificador + 8] - '0');

    if(verificador != valorRecebido){
        return 0;
    }
    return 1;
}

int validarCPF(char cpf[11]){
    int iCont;
    
    for(iCont = 0; iCont < 11; iCont++){
        if(cpf[iCont] == '\n'){
           return 0;
        }
    }

    if(validarNumerosVerificadores(cpf, 1)){
        return validarNumerosVerificadores(cpf, 2);
    }

    return 0;
}



#endif