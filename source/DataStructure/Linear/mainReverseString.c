// reverseString.c
#include "includeStack.h"

char *reverseString(char *pSource, int nSize)
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

    for (nCount = 0; nCount< nSize; nCount++)
        push(pStack, pSource[nCount]);
    
    pResult = (char*)malloc(sizeof(char) * (nCount + 1));

    for (nCount = 0; pStack->pTop != NULL; nCount++)
    {
        pNode = pop(pStack);
        pResult[nCount] = pNode->cData;
        free(pNode);
    }
    return pResult;
}

int main(int argc, char *argv[])
{
    char szSource[] = "ABCD";
    char *pszReverse = reverseString(szSource, 4);
    if (pszReverse == NULL)
    {
        printf("memory allocation error\n");
        return -1;
    }
    printf("[%s] -> [%s]\n", szSource, pszReverse);
    free(pszReverse);
    return 0;
}