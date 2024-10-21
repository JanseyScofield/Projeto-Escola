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
    } while(ch != '\n' && ch != EOF);
}

void limparTela() {
    system("clear||cls");
}

void entradaInvalida() {
    limparTela();
    printf("Entrada inválida.");
    esperarEnter();
}