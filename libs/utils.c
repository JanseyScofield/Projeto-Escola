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
}

void entradaInvalida() {
    limparTela();
    printf("Entrada inválida.");
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