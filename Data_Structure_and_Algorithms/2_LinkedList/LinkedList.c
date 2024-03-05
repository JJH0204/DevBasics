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

int getListData(linkedList* _pList_, const int _nIndex_)
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

int addListData(linkedList* _pList_, int _nVal_, const int _nIndex_)
{
    int i = 0;
    // node* pCurrent = NULL;
    node** pPrevious = NULL;
    node* pNewNode = NULL;

    if (_pList_ == NULL)
        return 1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return 2;
    
    pNewNode = (node*)malloc(sizeof(node));
    pNewNode->nData = _nVal_;
    pNewNode->pNext = NULL;

    pPrevious = &(_pList_->pHeader);
    // pCurrent = pPrevious->pNext;
    while (i < _nIndex_)
    {
        pPrevious = &((*pPrevious)->pNext);
        // pCurrent = pCurrent->pNext;
        i++;
    }
    pNewNode->pNext = (*pPrevious)->pNext;
    (*pPrevious)->pNext = pNewNode;

    (_pList_->nCurrentCount)++;
    return 0;
}

int removeListData(linkedList* _pList_, const int _nIndex_)
{
    int i = 0;
    node* pCurrent = NULL;
    node** pPrevious = NULL;
    
    if (_pList_ == NULL)
        return 1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return 2;
    
    pPrevious = &(_pList_->pHeader);
    // pCurrent = pPrevious->pNext;

    while (i < _nIndex_)
    {
        pPrevious = &((*pPrevious)->pNext);
        // pCurrent = pCurrent->pNext;
        i++;
    }
    pCurrent = (*pPrevious)->pNext;
    (*pPrevious)->pNext = pCurrent->pNext;

    free(pCurrent);

    (_pList_->nCurrentCount)--;
    return 0;
}

int deleteList(linkedList* _pList_)
{
    node* pCurrent = NULL;
    node* pDelete = NULL;
    if (_pList_ == NULL)
        return 1;
    
    pCurrent = _pList_->pHeader;

    while (pCurrent != NULL)
    {
        pDelete = pCurrent;
        pCurrent = pCurrent->pNext;

        free(pDelete);
    }

    free(_pList_);
    return 0;
}

int getListLength(linkedList* _pList_)
{
    if (_pList_ == NULL || _pList_->pHeader == NULL)
        return 0;
    
    return _pList_->nCurrentCount;
}

int main(int argc, char* argv[])
{
    int val = 0;
    linkedList* LinkedList = createList();
    addListData(LinkedList, 10, 0);
    addListData(LinkedList, 20, 1);
    addListData(LinkedList, 30, 1);

    val = getListData(LinkedList, 1);
    printf("index: 1, val: %d\n", val);
    removeListData(LinkedList, 1);
    deleteList(LinkedList);
    return 0;
}