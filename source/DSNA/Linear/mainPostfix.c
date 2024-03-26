// postfixNotation.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"
#include "includePostfix.h"


int main (int argc, char *argv[])
{
    const int nInfixSize = 9;
    int nPostfixSize = 0;
    double fResult = 0.0;

    TOKEN *pInfix = (TOKEN *)malloc(sizeof(TOKEN) * nInfixSize);
    TOKEN *pPostfix = NULL;

    if (ISNULL(pInfix))
        return -1;

    pInfix[0] = setToken(OPERAND, 2);
    pInfix[1] = setToken(MINUS, 0);
    pInfix[2] = setToken(LPAREN, 0);
    pInfix[3] = setToken(OPERAND, 3);
    pInfix[4] = setToken(PLUS, 0);
    pInfix[5] = setToken(OPERAND, 4);
    pInfix[6] = setToken(RPAREN, 0);
    pInfix[7] = setToken(MULTIPLY, 0);
    pInfix[8] = setToken(OPERAND, 5);
    printf("Infix Expression: \n\t> ");
    displayNotation(pInfix, nInfixSize);

    pPostfix = infix2postfix(pInfix, nInfixSize, &nPostfixSize);
    if (ISNULL(pPostfix))
        return -1;
    printf("Postfix Expression: \n\t> ");
    displayNotation(pPostfix, nPostfixSize);

    fResult = Calc(pPostfix, nPostfixSize);
    printf("Calc result: \n\t> %0.1f\n", fResult);
    free(pInfix);
    free(pPostfix);
    return 0;
}
/*
.\postfixNotation
Infix Expression:
        > 2.0 - ( 3.0 + 4.0 ) * 5.0
Postfix Expression:
        > 2.0 3.0 4.0 + 5.0 * -
Calc result:
        > -33.0
*/