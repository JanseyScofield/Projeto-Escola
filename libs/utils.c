#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void limparBuffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void esperarEnter() {
    char ch;
    printf("\nPressione ENTER para continuar...\n");
    do {
        ch = getchar();
    } while(ch != '\n' && ch != EOF); // Isso é literalmente um "limparBuffer". Isso foi retirado do chat gpt.
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    setbuf(stdin, NULL);
}

void entradaInvalida() {
    limparTela();
    printf("Entrada invalida.\n");
    esperarEnter();
}

void toUpper(char txt[]) {
    for(int iCont = 0; txt[iCont]; iCont++)
        if(txt[iCont] >= 'a' && txt[iCont] <= 'z')
            txt[iCont] = txt[iCont] - 'a' + 'A';
}

void toLower(char txt[]) {
    for(int iCont = 0; txt[iCont]; iCont++)
        if(txt[iCont] >= 'A' && txt[iCont] <= 'Z')
            txt[iCont] = txt[iCont] - 'A' + 'a';
}

void copyStr(char txt1[], char txt2[]) {
    int iCont;
    for(iCont = 0; txt1[iCont]; iCont++) {
        txt2[iCont] = txt1[iCont];
    }
    txt2[iCont] = '\0';
}

void tratarStr(char str[]) {
    for(int iCont = 0; str[iCont]; iCont++) {
        if(str[iCont] == '\n')
            str[iCont] = '\0';
    }
}

void charToUpper(char *c) {
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 'a' + 'A';
}

void charToLower(char *c) {
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 'A' + 'a';
}

int charToNumber(char c) {
    int number;

    if(c >= '0' && c <= '9')
        number = c - '0';
    else
        number = -1;

    return number;
}

int verificarLetrasEmUmaStr(char str[], char letras[]) {
    int i = 0;
    int contem;
    
    do {
        contem = 0;
        for(int j = 0; str[j] && !contem; j++) {
            if(str[j] == letras[i])
                contem = 1;
        }
        i += 1;
    } while(letras[i] && contem);

    return contem;
}

int strlen(char str[]) {
    int i;
    for(i = 0; str[i]; i++);
    return i;
}