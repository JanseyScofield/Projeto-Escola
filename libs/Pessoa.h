#include <stdio.h>
#include "Data.h"
#ifndef PESSOA
#define PESSOA
#define tam 256

typedef struct {
    int matricula; 
    char nome[tam];
    char sexo;
    Data data;
    char cpf[12];
} Pessoa;

Pessoa cadastrarPessoa();
int validarSexo(char sexo);
int validarNumerosVerificadores(char cpf[12], int limite);
int validarCPF(char cpf[12]);

Pessoa cadastrarPessoa() {
    Pessoa pessoa;
    int validar = 0;

    while(!validar) {
        printf("Informe o nome: ");
        fgets(pessoa.nome, tam, stdin);
        printf("Informe o cpf (somente números): ");
        fgets(pessoa.cpf, 12, stdin);
        printf("Informe a data de nascimento: ");
        pessoa.data = inserirData();
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &pessoa.sexo);
        
        if (validarCPF(pessoa.cpf) && validarData(pessoa.data) && validarSexo(pessoa.sexo))
            validar = 1;
        else {
            printf("Alguma informacao incorreta. Repita o processo.\n");
            int ch;
            do {
                ch = fgetc(stdin);
            } while (ch != EOF && ch != '\n');
        }
    }
    
    return pessoa;
}

int validarSexo(char sexo){
    if(sexo >= 'a' && sexo <= 'z'){
        sexo = 'A' + sexo - 'a';
    }

    if(sexo != 'F' && sexo != 'M'){
        return 0;
    }

    return 1;
}

int validarNumerosVerificadores(char cpf[12], int posicaoVerificador){
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

int validarCPF(char cpf[12]){
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