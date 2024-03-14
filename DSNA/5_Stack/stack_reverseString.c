// stack_reverseString.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char *reverseString(char *pSource)
{
    char *pResult = NULL;
    // TODO: Implementing string flipping
    /* code */
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