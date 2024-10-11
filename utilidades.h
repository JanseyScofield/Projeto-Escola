#ifndef UTILIDADES
#define UTILIDADES

int validarSexo(char sexo);
int validarNumerosVerificadores(char cpf[11], int limite);
int validarCPF(char cpf[11]);

int validarSexo(char sexo){
    if(sexo  == '\n'){
        return 0;
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
        printf("%c", cpf[iCont]);
        verificador += (cpf[iCont] - 48) * pesosDigitos[jCont];
    }

    restoDiv = verificador % 11;
    verificador = restoDiv >= 2? 11 - restoDiv : 0;
    valorRecebido = (cpf[posicaoVerificador + 8] - 48);

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