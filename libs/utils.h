#ifndef UTILS_H
#define UTILS_H

void limparBuffer();
void esperarEnter();
void limparTela();
void entradaInvalida();
void toUpper(char txt[]);
void toLower(char txt[]);
void copyStr(char txt1[], char txt2[]);
void tratarStr(char str[]);
void charToUpper(char *c);
void charToLower(char *c);
int charToNumber(char c);
int verificarLetrasEmUmaStr(char str[], char letras[]);
int strlen(char str[]);

#endif