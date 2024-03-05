// LinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADERNODE

// node definition
typedef struct LinkedListNodeType
{
    int nData;
    struct LinkedListNodeType* pNext;
} node;

#ifdef HEADERNODE
// 헤더 노드를 활용한 연결리스트 구현
typedef struct LinkedList
{
    int nCurrentCount;
    node nodeHeader;
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
    
    pCurrent = &(_pList_->nodeHeader);

    while (i <= _nIndex_)
    {
        pCurrent = pCurrent->pNext;
        i++;
    }
    return pCurrent->nData;
}

int addListData(linkedList* _pList_, int _nVal_, const int _nIndex_)
{
    int i = 0;
    node* pPrevious = NULL;
    node* pNewNode = NULL;

    if (_pList_ == NULL)
        return 1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return 2;
    
    pNewNode = (node*)malloc(sizeof(node));
    pNewNode->nData = _nVal_;
    pNewNode->pNext = NULL;

    pPrevious = &(_pList_->nodeHeader);
    while (i < _nIndex_)
    {
        pPrevious = pPrevious->pNext;
        // pCurrent = pCurrent->pNext;
        i++;
    }
    pNewNode->pNext = pPrevious->pNext;
    pPrevious->pNext = pNewNode;

    (_pList_->nCurrentCount)++;
    return 0;
}

int removeListData(linkedList* _pList_, const int _nIndex_)
{
    int i = 0;
    node* pCurrent = NULL;
    node* pPrevious = NULL;
    
    if (_pList_ == NULL)
        return 1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return 2;
    
    pPrevious = &(_pList_->nodeHeader);

    for (; i < _nIndex_; i++)
        pPrevious = pPrevious->pNext;
    
    pCurrent = pPrevious->pNext;
    pPrevious->pNext = pCurrent->pNext;

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
    
    pCurrent = (_pList_->nodeHeader).pNext;
    /* error correction
    LinkedList(89647,0x1dea25000) malloc: *** error for object 0x12a605f28: pointer being freed was not allocated
    LinkedList(89647,0x1dea25000) malloc: *** set a breakpoint in malloc_error_break to debug
    */

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
    if (_pList_ == NULL)
        return 0;
    
    return _pList_->nCurrentCount;
}

int displayList(linkedList* _pList_)
{
    int i = 0;
    if (_pList_ == NULL)
        return 0;
    for (; i < _pList_->nCurrentCount; i++)
        printf("[%d] %d\n", i, getListData(_pList_, i));
    
}

#endif

#ifdef HEADERPOINT
// TODO: 헤더 포인터를 활용한 연결리스트 구현
typedef struct LinkedList
{
    int nCurrentCount;
    node* nodeHeader;
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
    
}

int addListData(linkedList* _pList_, int _nVal_, const int _nIndex_)
{
    
}

int removeListData(linkedList* _pList_, const int _nIndex_)
{
    
}

int deleteList(linkedList* _pList_)
{
    
}

int getListLength(linkedList* _pList_)
{
    
}
#endif

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