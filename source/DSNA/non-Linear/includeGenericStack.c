// include Generic Stack.c
// 제네릭 프로그래밍 기법을 활용한 스택 구현
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeGenericStack.h"

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

bool isEmpty(const stack *ptr, const char *funcName)
{
    if (ptr->nCurrentCount <= 0 && ptr->pTopNode == NULL)
    {
        printf("%s: Queue is Empty\n", funcName);
        return true;
    }
    return false;
}

stack *createStack(void)
{
    stack *pStack = (stack *)malloc(sizeof(stack));
    if (ISNULL_ERROR(pStack))
        return NULL;
    pStack->nCurrentCount = 0;
    pStack->pTopNode = NULL;
    return pStack;
}

bool push(stack *_pStack_, void *_data_)
{
    stackNode *pNode = NULL;
    if (ISNULL_ERROR(_pStack_))
        return true;
    pNode = (stackNode*)malloc(sizeof(stackNode));
    if (ISNULL_ERROR(_pStack_))
        return true;
    pNode->nodeData = _data_;
    pNode->pNextNode = _pStack_->pTopNode;
    _pStack_->pTopNode = pNode;
    _pStack_->nCurrentCount++;
    return false;
}

void *pop(stack *_pStack_)
{
    stackNode *pNode = NULL;
    void *pResult = NULL;
    if (ISNULL_ERROR(_pStack_) || ISEMPTY_ERROR(_pStack_))
        return NULL;
    pNode = _pStack_->pTopNode;
    _pStack_->pTopNode = pNode->pNextNode;
    pNode->pNextNode = NULL;
    _pStack_->nCurrentCount--;
    pResult = pNode->nodeData;
    free(pNode);
    return pResult;
}

void *peek(const stack *_pStack_)
{
    void *pResult = NULL;
    if (ISNULL_ERROR(_pStack_) || ISEMPTY_ERROR(_pStack_))
        return NULL;
    pResult = _pStack_->pTopNode->nodeData;
    return pResult;
}

bool deleteStack(stack *_pStack_)
{
    if (ISNULL_ERROR(_pStack_))
        return true;

    while (_pStack_->nCurrentCount > 0)
        free(pop(_pStack_));
    free(_pStack_);
    return false;
}
