#include <stdio.h>
#ifndef DATA
#define DATA

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

Data inserirData(); 
void mostrarDataFormatada(Data data);
int validarDia(Data data);
int validarData(Data data);

#endif