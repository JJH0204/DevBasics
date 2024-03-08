//CircularLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CircularLinked
{
    int nData;
    struct CircularLinked *pNext;
} node;

typedef struct CircularLinkedList
{
    int nCurrentCount;
    node sHeader;
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
    node *pCurrent = NULL;

    if (_pList_ == NULL)
        return -1;
    
    if ((_nIndex_ < 0) || (_nIndex_>_pList_->nCurrentCount))
        return -2;
    
    pCurrent = &(_pList_->sHeader);
    for (; i <= _nIndex_; i++)
        pCurrent = pCurrent->pNext;
    
    return pCurrent->nData;
}

int addCircularList(CircularList *_pList_, int _nIndex_, int _nData_)
{
    int i = 0;
    node *pPrevious = NULL;
    node *pNewNode = NULL;

    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;

    pNewNode = (node *)malloc(sizeof(node));
    if (pNewNode == NULL)
        return -3;

    pNewNode->nData = _nData_;
    pNewNode->pNext = NULL;

    pPrevious = &(_pList_->sHeader);
    while (i < _nIndex_)
    {
        pPrevious = pPrevious->pNext;
        i++;
    }
    pNewNode->pNext = pPrevious->pNext;
    pPrevious->pNext = pNewNode;

    _pList_->nCurrentCount++;

    if (pNewNode->pNext == NULL)
        pNewNode->pNext = pNewNode;
    
    return 0;
}

int main(int argc, char *argv[])
{

    return 0;
}