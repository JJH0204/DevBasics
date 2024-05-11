#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

bool isEmpty(const STACK *ptr, const char *funcName)
{
    if (ptr->nCurrentCount <= 0 && ptr->pTOP == NULL)
    {
        // printf("%s: Queue is Empty\n", funcName);
        return true;
    }
    return false;
}

STACK *createStack(void)
{
    STACK *pStack = (STACK*)malloc(sizeof(STACK));
    if (ISNULL(pStack))
        return NULL;
    pStack->nCurrentCount = 0;
    pStack->pTOP = NULL;
    return pStack;
}

bool push(STACK *_pStack_, const TOKEN _tData_)
{
    NODE *pNode = NULL;

    if (ISNULL(_pStack_))
        return true;

    pNode = (NODE *)malloc(sizeof(NODE));
    if (ISNULL(pNode))
        return true;

    pNode->tData = _tData_;
    pNode->pNext = _pStack_->pTOP;
    _pStack_->pTOP = pNode;
    _pStack_->nCurrentCount++;

    return false;
}

NODE *pop(STACK *_pStack_)
{
    NODE *pNode = NULL;
    if (ISNULL(_pStack_) || ISEMPTY(_pStack_))
        return NULL;
    pNode = _pStack_->pTOP;
    _pStack_->pTOP = pNode->pNext;
    pNode->pNext = NULL;
    _pStack_->nCurrentCount--;
    return pNode;
}

NODE *peek(const STACK *_pStack_)
{
    if (ISNULL(_pStack_) || ISEMPTY(_pStack_))
        return NULL;
    return _pStack_->pTOP;
}

bool deleteStack(STACK *_pStack_)
{
    if (ISNULL(_pStack_))
        return true;

    while (!ISEMPTY(_pStack_))
        free(pop(_pStack_));
    free(_pStack_);
    return false;
}

TOKEN setToken(const TYPE _type_, const double _val_)
{
    TOKEN newToken;
    newToken.dValue = _val_;
    newToken.operType = _type_;
    return newToken;
}