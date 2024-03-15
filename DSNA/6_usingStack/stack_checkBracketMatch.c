// stack_checkBracketMatch.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int checkBracketMatch(char *pSource)
{
    // TODO: Implementing checkBracketMatch()
    /* code */
    return 0;
}

int main(int argc, char *argv[])
{
    int checkResult = 0;
    int i = 0;
    char szExpressionStr[][50] = {
        "( A + B ) * C",
        "{ ( A + B ) * C } * D",
        "( A + B ) * C )",
        "( ( A + B ) * C",
        "{ ( A + B } ) * C * D"
    };

    for (i = 0; i < sizeof(szExpressionStr)/sizeof(szExpressionStr[0]); i++)
    {
        checkResult = checkBracketMatch(szExpressionStr[i]);
        if(checkResult == 0)
            printf("SUCCESS, %s\n", szExpressionStr[i]);
        else
            printf("FAIL-[%d], %s\n", checkResult, szExpressionStr[i]);
    }
    return 0;
}