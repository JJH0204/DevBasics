//CircularLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CircularLinked
{
    int nData;
    struct CircularLinked *pNext;
} Node;

typedef struct CircularLinkedList
{
    int nCurrentCount;
    Node sHeader;
} CircularList;

CircularList *createCircularList()
{
    CircularList *pResult = (CircularList *)malloc(sizeof(CircularList));
    if (pResult == NULL)
        return NULL;
    memset(pResult, 0, sizeof(CircularList));
    return pResult;
}

int getCircularListData(CircularList* _pList_, int _nIndex_)
{
    int i = 0;
    Node* pCurrent = NULL;

    if (_pList_ == NULL)
        return -1;
    
    if ((_nIndex_ < 0) || (_nIndex_>_pList_->nCurrentCount))
        return -2;
    
    pCurrent = &(_pList_->sHeader);
    for (; i <= _nIndex_; i++)
        pCurrent = pCurrent->pNext;
    
    return pCurrent->nData;
}

int main (int argc, char* argv[])
{

    return 0;
}