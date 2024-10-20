#include "utils.h"
#include <stdio.h>

void limparBuffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}