// postfixNotation.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "notationStack.h"
#include "postfixCalc.h"

// TODO: 후위 표기법을 이해하고 스택으로 계산하는 코드를 작성
int main (int argc, char *argv[])
{
    int i = 0, size = 7;

    TOKEN *pToken = (TOKEN *)malloc(sizeof(TOKEN) * size);
    pToken[0] = setToken(OPERAND, 2);
    // printf("%lf, %d", pToken[0].dValue, pToken[0].operType);
    pToken[1] = setToken(OPERAND, 3);
    pToken[2] = setToken(OPERAND, 4);
    pToken[3] = setToken(PLUS, 0);
    pToken[4] = setToken(OPERAND, 5);
    pToken[5] = setToken(MULTIPLY, 0);
    pToken[6] = setToken(MINUS, 0);

    printf("Expression: 2 3 4 + 5 * -\n");
    Calc(pToken, size);

    free(pToken);
    return 0;
}