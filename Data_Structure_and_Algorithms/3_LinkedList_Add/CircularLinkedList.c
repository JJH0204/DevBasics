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

// TODO: main 함수가 정상 작동할 수 있도록 함수 구현 및 코드 수정
int iterateList()
{

}

int getCircularListLength()
{

}

int concatList()
{

}

int deleteList()
{

}
int removeListData()
{

}

int flipIterateList()
{

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
    iterateList(pListA);
    printf("List B: \n");
    iterateList(pListB);

    val = getCircularListData(pListA, 1);
    printf("print 'pListA' -> index: 1, val: %d\n", val);
    val = getCircularListLength(pListA);
    printf("data count: %d\n", val);

    concatList(pListA, pListB);
    printf("->concat list after<------------\n");
    printf("List A: \n");
    iterateList(pListA);
    printf("List B: \n");
    iterateList(pListB);

    deleteList(pListB);

    removeListData(pListA, 2);
    printf("ListA index %d data remove: \n", 2);
    iterateList(pListA);
    
    printf("ListA flip: \n");
    flipIterateList(pListA);

    deleteList(pListA);
    
    return 0;
}
