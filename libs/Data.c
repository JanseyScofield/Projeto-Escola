#include <stdio.h>
#include "Data.h"

Data inserirData()
{
    Data data;
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
    return data;
}

void mostrarDataFormatada(Data data)
{
    printf("%02d/%02d/%04d", data.dia, data.mes, data.ano);
}

int validarDia(Data data)
{
    int diaValido = 1;

    if (data.dia <= 0 || data.dia > 31)
    {
        diaValido = 0;
    }
    else
    {
        if (data.dia == 30 && data.mes == 2)
        {
            if (data.ano % 4 == 0)
            {
                if (data.ano % 100 == 0 && !(data.ano % 400 == 0))
                {
                    diaValido = 0;
                }
            }
            else
            {
                diaValido = 0;
            }
        }
        else if (data.dia == 31 && !(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12))
        {
            diaValido = 0;
        }
    }

    return diaValido;
}

int validarData(Data data)
{
    if (data.mes <= 0 || data.mes > 12)
    {
        return 0;
    }
    else if (!validarDia(data))
    {
        return 0;
    }
    return 1;
}