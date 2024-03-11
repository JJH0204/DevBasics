//DoubleLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoubleLink
{
    int nData;
    struct DoubleLink *pLeftLink;
    struct DoubleLink *pRightLink;
} node;

typedef struct DoubleLinkedList
{
    unsigned int nCurrentCount;
    node sHeader;
} dList;

dList *createList (void)
{
    dList *pResult = (dList*)malloc(sizeof(dList));
    if (pResult == NULL)
        return NULL;
    memset(pResult, 0, sizeof(dList));
    pResult->sHeader.pLeftLink = &(pResult->sHeader);
    pResult->sHeader.pRightLink = &(pResult->sHeader);
    return pResult;
}

int addData(dList *_pList_, int _nData_, unsigned int _nIndex_)
{
    node *pNewNode = NULL;
    node *pCurrentNode = NULL;
    node *pNextNode = NULL;
    int nCount = 0;
    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;

    pNewNode = (node*)malloc(sizeof(node));
    memset(pNewNode, 0, sizeof(node));
    pNewNode->nData = _nData_;

    pCurrentNode = &(_pList_->sHeader);

    for ( ; nCount < _nIndex_; nCount++)
        pCurrentNode = pCurrentNode->pRightLink;
    
    pNextNode = pCurrentNode->pRightLink;

    pNewNode->pRightLink = pNextNode;
    pNewNode->pLeftLink = pCurrentNode;

    pCurrentNode->pRightLink = pNewNode;
    pNextNode->pLeftLink = pNewNode;

    _pList_->nCurrentCount++;
    return 0;
}

int getData(dList *_pList_, int _nIndex_)
{
    int nBetter = 0;
    int nCount = 0;
    node *pCurrentNode = NULL;

    if (_pList_ == NULL)
        return -1;      // no list
    if (_pList_->nCurrentCount <= 0)
        return -2;      // no data
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -3;      // error Index
    
    pCurrentNode = &(_pList_->sHeader);
    nBetter = (_pList_->nCurrentCount - 1) - _nIndex_;

    // It is better to move to the right
    if (nBetter >= _nIndex_)
        for ( ; nCount <= _nIndex_; nCount++)
            pCurrentNode = pCurrentNode->pRightLink;
    // It is better to move to the left
    else
        for ( ; nCount <= nBetter; nCount++)
            pCurrentNode = pCurrentNode->pLeftLink;
    
    return pCurrentNode->nData;
}

int getLength (dList *_pList_)
{
    if (_pList_ == NULL)
        return -1;
    
    return _pList_->nCurrentCount;
}

int removeData(dList *_pList_, int _nIndex_)
{
    int nCount = 0;
    int nBetter = 0;
    node *pCurrentNode = NULL;
    node *pRemoveNode = NULL;

    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;
    
    pRemoveNode = &(_pList_->sHeader);
    nBetter = (_pList_->nCurrentCount - 1) - _nIndex_;

    if (nBetter >= _nIndex_)
        for ( ; nCount <= _nIndex_; nCount++)
            pRemoveNode = pRemoveNode->pRightLink;
    else
        for ( ; nCount <= nBetter; nCount++)
            pRemoveNode = pRemoveNode->pLeftLink;
    
    pRemoveNode->pRightLink->pLeftLink = pRemoveNode->pLeftLink;
    pRemoveNode->pLeftLink->pRightLink = pRemoveNode->pRightLink;

    pRemoveNode->pRightLink = NULL;
    pRemoveNode->pLeftLink == NULL;

    free(pRemoveNode);
    _pList_->nCurrentCount--;
    return 0;
}

int deleteList(dList *_pList_)
{
    if (_pList_ == NULL)
        return -1;
    
    while (_pList_->nCurrentCount > 0)
        removeData(_pList_, 0);
    
    free(_pList_);
}

int printList_R(dList *_pList_)
{
    int nCount = 0;
    node *pPrintNode = NULL;
    if (_pList_ == NULL)
        return -1;
    if (_pList_->nCurrentCount <= 0)
    {
        printf("No data\n");
        return -2;
    }
    printf("Node count: %d\n", _pList_->nCurrentCount);

    pPrintNode = _pList_->sHeader.pRightLink;
    for ( ; nCount < _pList_->nCurrentCount; nCount++)
    {
        printf("[%d]: %d\n", nCount, pPrintNode->nData);
        pPrintNode = pPrintNode->pRightLink;
    }
    return 0;
}

int printList_L(dList *_pList_)
{
    int nCount = 0;
    node *pPrintNode = NULL;
    if (_pList_ == NULL)
        return -1;
    if (_pList_->nCurrentCount <= 0)
    {
        printf("No data\n");
        return -2;
    }
    printf("Node count: %d\n", _pList_->nCurrentCount);

    pPrintNode = _pList_->sHeader.pLeftLink;
    for ( ; nCount < _pList_->nCurrentCount; nCount++)
    {
        printf("[%d]: %d\n", nCount, pPrintNode->nData);
        pPrintNode = pPrintNode->pLeftLink;
    }
    return 0;
}

int main(int argc, char *argv[])
{

    return 0;
}