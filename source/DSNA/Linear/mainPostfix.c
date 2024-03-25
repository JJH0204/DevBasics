// postfixNotation.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"
#include "includePostfix.h"


int main (int argc, char *argv[])
{
    int nSize = 9;

    TOKEN *pToken = (TOKEN *)malloc(sizeof(TOKEN) * nSize);

    pToken[0] = setToken(OPERAND, 2);
    pToken[1] = setToken(MINUS, 0);
    pToken[2] = setToken(LPAREN, 0);
    pToken[3] = setToken(OPERAND, 3);
    pToken[4] = setToken(PLUS, 0);
    pToken[5] = setToken(OPERAND, 4);
    pToken[6] = setToken(RPAREN, 0);
    pToken[7] = setToken(MULTIPLY, 0);
    pToken[8] = setToken(OPERAND, 5);

    printf("Infix Expression: ");
    displayNotation(pToken, nSize);
    pToken = infix2postfix(pToken, nSize);
    displayNotation(pToken, nSize);
    if (ISNULL(pToken)) return -1;
    Calc(pToken, nSize);

    free(pToken);
    return 0;
}