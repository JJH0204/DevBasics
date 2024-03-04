// LinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node definition
typedef struct LinkedListNodeType
{
    int nData;
    struct LinkedListNodeType* pNext;
} node;

typedef struct LinkedList
{
    int nCurrentCount;
    node* pHeader;
} linkedList;

linkedList* createList()
{
    linkedList* pResult = (linkedList*)malloc(sizeof(linkedList));
    if (pResult == NULL)
        return NULL;
    
    memset(pResult, 0, sizeof(linkedList));
    
}

int main(int argc, char* argv[])
{

    return 0;
}