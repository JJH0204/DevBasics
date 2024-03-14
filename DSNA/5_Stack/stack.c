// stack.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int initStack(stack *_pStack_)
{
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: initStack()\n");
        return -1;
    }
    _pStack_->nCurrentCount = 0;
    _pStack_->pTop = NULL;
    return 0;
}

stack *createStack()
{
    stack *pResult = (stack*)malloc(sizeof(stack));
    if (pResult == NULL)
    {
        printf("memory allocation error: createStack()\n");
        return NULL;
    }
    if (initStack(pResult) != 0)
    {
        printf("Memory initialization failed: createStack()\n");
        return NULL;
    }
    return pResult;
}

int initNode(node *_pNode_, const char _cData_)
{
    if (_pNode_ == NULL)
    {
        printf("Unallocated memory access error: initNode()\n");
        return -1;
    }
    _pNode_->cData = _cData_;
    _pNode_->pNext = NULL;
    return 0;
}

int push(stack *_pStack_, const char _cData_)
{
    node *pNewNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: push()\n");
        return -1;
    }
    
    pNewNode = (node*)malloc(sizeof(node));
    if (pNewNode == NULL)
    {
        printf("memory allocation error: push()\n");
        return -2;
    }
    if (initNode(pNewNode, _cData_) != 0)
    {
        printf("Memory initialization failed: createStack()\n");
        return -3;
    }
    pNewNode->pNext = _pStack_->pTop;
    _pStack_->pTop = pNewNode;
    _pStack_->nCurrentCount++;
    return 0;
}

node *pop(stack *_pStack_)
{
    node *pPopNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: pop()\n");
        return NULL;
    }
    if ((_pStack_->pTop == NULL) && (_pStack_->nCurrentCount == 0))
    {
        printf("Stack underflow error: pop()\n");
        return NULL;
    }
    pPopNode = _pStack_->pTop;
    _pStack_->pTop = pPopNode->pNext;
    pPopNode->pNext = NULL;
    _pStack_->nCurrentCount--;
    return pPopNode;
}

node *peek(const stack *_pStack_)
{
    node *pPeekNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: peek()\n");
        return NULL;
    }
    if ((_pStack_->pTop == NULL) && (_pStack_->nCurrentCount == 0))
    {
        printf("No data in stack: peek()\n");
        return NULL;
    }
    pPeekNode = (node*)malloc(sizeof(node));
    if (pPeekNode == NULL)
    {
        printf("memory allocation error: peek()\n");
        return NULL;
    }
    if (initNode(pPeekNode, _pStack_->pTop->cData) != 0)
    {
        printf("Memory initialization failed: peek()\n");
        return NULL;
    }
    return pPeekNode;
}

int displayStack(const stack *_pStack_)
{
    node *pNode = NULL;
    int nCount = 0;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: displayStack()\n");
        return -1;
    }

    printf("current stack: %d number\n", _pStack_->nCurrentCount);
    pNode = _pStack_->pTop;
    for ( ; pNode != NULL; pNode = pNode->pNext)
    {
        printf("[%d]-[%c]\n", _pStack_->nCurrentCount - nCount, pNode->cData);
        nCount++;
    }

    return 0;
}

int deleteStack(stack *_pStack_)
{
    node *delNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: deleteStack()\n");
        return -1;
    }
    
    while (_pStack_->pTop != NULL)
    {
        delNode = _pStack_->pTop;
        _pStack_->pTop = delNode->pNext;
        free(delNode);
    }
    free(_pStack_);
    return 0;
}

#ifndef _STACK_
int main(int argc, char *argv[])
{
    stack *pStack = NULL;
    node *pNode = NULL;

    pStack = createStack();
    if (pStack == NULL)
    {
        printf("Memory initialization failed: main()\n");
        return -1;
    }
    push(pStack, 'L');
    push(pStack, 'O');
    push(pStack, 'V');
    push(pStack, 'E');
    push(pStack, 'Y');
    push(pStack, 'O');
    push(pStack, 'U');
    displayStack(pStack);

    pNode = pop(pStack);
    if (pNode == NULL)
    {
        printf("Memory initialization failed: main()\n");
        return -2;
    }
    printf("Pop - [%c]\n", pNode->cData);
    free(pNode);

    displayStack(pStack);
    pNode = peek(pStack);
    if (pNode == NULL)
    {
        printf("Memory initialization failed: main()\n");
        return -3;
    }
    printf("Peek - [%c]\n", pNode->cData);
    free(pNode);

    displayStack(pStack);
    
    deleteStack(pStack);
    return 0;
}
#endif