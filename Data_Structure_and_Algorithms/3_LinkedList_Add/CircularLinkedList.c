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

int addCircularList(CircularList *_pList_, int _nData_, int _nIndex_)
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

int circularIterateList(const CircularList *_pList_)
{
    int nCount = 0;
    node *pCurrent = NULL;
    if (_pList_ == NULL)
        return -1;
    if (_pList_->nCurrentCount <= 0)
    {
        printf("No list data\n");
        return -2;
    }
    pCurrent = _pList_->sHeader.pNext;
    for (; nCount < _pList_->nCurrentCount; nCount++)
    {
        printf("%d [%d]\n", pCurrent->nData, nCount);
        pCurrent = pCurrent->pNext;
    }
    printf("Node's: %d\n", nCount);
    return 0;
}

int getCircularListLength(const CircularList *_pList_)
{
    if (_pList_ == NULL)
        return -1;
    return _pList_->nCurrentCount;
}

int concatCircularList(CircularList *_pListA_, CircularList *_pListB_)
{
    node* pCurrent = NULL;
    if((_pListA_ == NULL) && (_pListB_ == NULL))
        return -1;
    if (_pListB_->sHeader.pNext == NULL)
        return -2;
    
    pCurrent = &(_pListA_->sHeader);
    // 2) TODO: 무한 루프 발생
    while (pCurrent->pNext != NULL)
        pCurrent = pCurrent->pNext;
    pCurrent->pNext = _pListB_->sHeader.pNext;
    // 3) TODO: _pListB_의 마지막을 _pListA_의 첫 노드와 연결을 해야됨
    _pListA_->nCurrentCount = _pListA_->nCurrentCount + _pListB_->nCurrentCount;
    
    memset(_pListB_, 0, sizeof(CircularList));
    return 0;
}

int deleteCircularList(CircularList * _pList_)
{
    int i = 0;
    node* pCurrent = NULL;
    node* pDelete = NULL;
    if (_pList_ == NULL)
        return 1;
    
    pCurrent = (_pList_->sHeader).pNext;

    // 무한 루프 방지
    for (; i < _pList_->nCurrentCount; i++)
    {
        pDelete = pCurrent;
        pCurrent = pCurrent->pNext;

        free(pDelete);
    }

    free(_pList_);
    return 0;
}

int removeCircularListData(CircularList *_pList_, const int _nIndex_)
{
    int i = 0;
    node *pCurrent = NULL;
    node *pPrevious = NULL;

    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;
    
    pPrevious = &(_pList_->sHeader);
    for (; i < _nIndex_; i++)
        pPrevious = pPrevious->pNext;
    
    pCurrent = pPrevious->pNext;
    pPrevious->pNext = pCurrent->pNext;
    // TODO: 리스트의 요소가 1개 뿐일 경우 에러 발생
    if (1 == _pList_->nCurrentCount)
        _pList_->sHeader.pNext = NULL;
    
    free(pCurrent);
    _pList_->nCurrentCount--;
    return 0;
}

int main(int argc, char *argv[])
{
    int val = 0;

    CircularList *pListA = createCircularList();
    CircularList *pListB = createCircularList();

    addCircularList(pListA, 10, 0);
    addCircularList(pListA, 20, 1);
    addCircularList(pListA, 30, 1);

    addCircularList(pListB, 40, 0);
    addCircularList(pListB, 50, 1);

    printf("->concat list before<------------\n");
    printf("List A: \n");
    circularIterateList(pListA);
    printf("List B: \n");
    circularIterateList(pListB);

    val = getCircularListData(pListA, 1);
    printf("print 'pListA' -> index: 1, val: %d\n", val);
    val = getCircularListLength(pListA);
    printf("data count: %d\n", val);

    // concatCircularList(pListA, pListB);
    // printf("->concat list after<------------\n");
    // printf("List A: \n");
    // circularIterateList(pListA);
    // printf("List B: \n");
    // circularIterateList(pListB);

    deleteCircularList(pListB);

    removeCircularListData(pListA, 2);
    printf("ListA index %d data remove: \n", 2);
    circularIterateList(pListA);

    deleteCircularList(pListA);
    
    return 0;
}
