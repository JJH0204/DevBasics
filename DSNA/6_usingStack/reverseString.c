// reverseString.c
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

char *reverseString(char *pSource)
{
    char *pResult = NULL;
    // TODO: Implementing string flipping
    int nCount = 0;
    stack *pStack = NULL;
    node *pNode = NULL;

    if (pSource == NULL)
    {
        printf("Unallocated memory reference error: reverseString()");
        return NULL;
    }
    pStack = createStack();
    if (pStack == NULL)
    {
        printf("memory allocation error: reverseString()");
        return NULL;
    }

    for ( ; &(pSource[nCount]) != NULL; nCount++)
        push(pStack, pSource[nCount]);
    
    pResult = (char*)malloc(sizeof(char) * (nCount + 1));

    for (nCount = 0; pStack->pTop != NULL; nCount++)
    {
        pNode = pop(pStack);
        pResult[nCount] = pNode->cData;
        free(pNode);
    }
    pResult[nCount] = '\n';

    return pResult;
}

int main(int argc, char *argv[])
{
    char szSource[] = "ABCD";
    char *pszReverse = reverseString(szSource);
    if (pszReverse == NULL)
    {
        printf("memory allocation error\n");
        return -1;
    }
    printf("[%s] -> [%s]\n", szSource, pszReverse);
    free(pszReverse);
    return 0;
}