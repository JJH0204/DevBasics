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

dList *createDoubleList (void)
{
    dList *pResult = (dList*)malloc(sizeof(dList));
    if (pResult == NULL)
        return NULL;
    return pResult;
}

int addData(dList *_pList_, int _nData_, unsigned int _nIndex_)
{
    node *pNewNode = NULL;
    int nCount;
    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;

    pNewNode = (node*)malloc(sizeof(node));
    pNewNode->nData = _nData_;
    // TODO: Create list node addition logic
    /* code's */

    return 0;
}

int main(int argc, char *argv[])
{

    return 0;
}