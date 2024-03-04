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
    return pResult;
}

int getListData(linkedList* _pList_, int _nIndex_)
{
    int i = 0;
    node* pCurrent = NULL;
    if (_pList_ == NULL)
        return 1;
    if (_nIndex_ >= _pList_->nCurrentCount)
        return 2;
    
    pCurrent = _pList_->pHeader;

    while (i < _nIndex_)
    {
        pCurrent = pCurrent->pNext;
        i++;
    }
    return pCurrent->nData;
}

int addListData(linkedList* _pList_, int _nVal_, int _nIndex_)
{
    int i = 0;
    node* pCurrent = NULL;
    node* pPrevious = NULL;
    node* pNewNode = NULL;

    if (_pList_ == NULL)
        return 1;
    if (_nIndex_ > _pList_->nCurrentCount)
        return 2;
    
    pNewNode = (node*)malloc(sizeof(node));
    pNewNode->nData = _nVal_;
    pNewNode->pNext = NULL;

    pPrevious = &(_pList_->pHeader);
    pCurrent = pPrevious->pNext;
    while (i < _nIndex_)
    {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
        i++;
    }
    pNewNode->pNext = pCurrent;
    pPrevious->pNext = pNewNode;
    
    return 0;
}

int main(int argc, char* argv[])
{

    return 0;
}