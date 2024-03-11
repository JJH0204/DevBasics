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
    pNewNode->nData = _nData_;
    // TODO: Create list node addition logic
    /* code */
    pCurrentNode = &(_pList_->sHeader);
    if ((pCurrentNode->pRightLink == NULL) && (pCurrentNode->pLeftLink == NULL))
    {
        _pList_->sHeader.pRightLink = pNewNode;
        _pList_->sHeader.pLeftLink = pNewNode;
        pNewNode->pRightLink = pCurrentNode;
        pNewNode->pLeftLink = pCurrentNode;
    }
    else
    {
        for ( ; nCount < _nIndex_; nCount++)
            pCurrentNode = pCurrentNode->pRightLink;
        
        pNextNode = pCurrentNode->pRightLink;
        pCurrentNode->pRightLink = pNewNode;
        pNewNode->pLeftLink = pCurrentNode;
        pNextNode->pLeftLink = pNewNode;
        pNewNode->pRightLink = pNextNode;
    }
    _pList_->nCurrentCount++;
    return 0;
}

int getListData(dList *_pList_, int _nIndex_)
{
    int nBetter = 0;
    int nCount = 0;
    node *pCurrentNode = NULL;

    if (_pList_ == NULL)
        return -1;      // no list
    if (_pList_->sHeader.pRightLink == NULL)
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


int main(int argc, char *argv[])
{

    return 0;
}