// postfixNotation.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"
#include "includePostfix.h"


int main (int argc, char *argv[])
{
    int nSize = 9;
    double dResult = 0.0;

    TOKEN *pInfixToken = (TOKEN *)malloc(sizeof(TOKEN) * nSize);
    TOKEN *pPostfixToken = NULL;
	
    if (ISNULL(pInfixToken)) return -1;
    
    pInfixToken[0] = setToken(OPERAND, 2);
    pInfixToken[1] = setToken(MINUS, 0);
    pInfixToken[2] = setToken(LPAREN, 0);
    pInfixToken[3] = setToken(OPERAND, 3);
    pInfixToken[4] = setToken(PLUS, 0);
    pInfixToken[5] = setToken(OPERAND, 4);
    pInfixToken[6] = setToken(RPAREN, 0);
    pInfixToken[7] = setToken(MULTIPLY, 0);
    pInfixToken[8] = setToken(OPERAND, 5);
    printf("Infix Expression: \n\t> ");
    displayNotation(pInfixToken, nSize);
    
    pPostfixToken = infix2postfix(pToken, nSize);
    if (ISNULL(pPostfixToken)) return -1;
    printf("Postfix Expression: \n\t> ");
    displayNotation(pPostfixToken, nSize);
    
    dResult = Calc(pPostfixToken, nSize);
	printf("Calc result: \n\t> %0.1f\n", dResult);
    free(pToken);
    return 0;
}