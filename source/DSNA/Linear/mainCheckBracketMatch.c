// checkBracketMatch.c
#include <string.h>
#include "includeStack.h"

int checkBracketMatch(char *pSource, int nSize)
{
    int nCount = 0;
    stack *pStack = createStack();
    node *pNode = NULL;
    if (pSource == NULL)
        return -1;          // NULL Memory Accece Error
    if (nSize < 1)
        return -2;          // Argument value error
    

    for (nCount = 0; nCount < nSize; nCount++)
    {
        if ((pSource[nCount] == '(') || (pSource[nCount] == '[') || (pSource[nCount] == '{'))
            push(pStack, pSource[nCount]);
        else if ((pSource[nCount] == ')') || (pSource[nCount] == ']') || (pSource[nCount] == '}'))
        {
            if (pStack->nCurrentCount <= 0)
            {
                deleteStack(pStack);
                return 1; // 닫는 괄호가 더 많다.
            }
            
            pNode = pop(pStack);
            
            if (pNode == NULL)
            {
                deleteStack(pStack);
                return 1;           // 닫는 괄호가 더 많다.
            }

            if (((pSource[nCount] == ')') && (pNode->cData == '(')) || ((pSource[nCount] == ']') && (pNode->cData == '[')) || ((pSource[nCount] == '}') && (pNode->cData == '{')))
            {
                free(pNode);
            }
            else
            {
                free(pNode);
                deleteStack(pStack);
                return 2;           // 괄호 쌍이 맞지 않다.
            }
        }
    }
    if (pStack->nCurrentCount > 0)
    {
        deleteStack(pStack);
        return 3; // 여는 괄호가 남았다.
    }
    deleteStack(pStack);
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
        checkResult = checkBracketMatch(szExpressionStr[i], 22);
        if(checkResult == 0)
            printf("SUCCESS, %s\n", szExpressionStr[i]);
        else
            printf("FAIL-[%d], %s\n", checkResult, szExpressionStr[i]);
    }
    return 0;
}