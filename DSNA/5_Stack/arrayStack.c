// arrayStack.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arrayNode
{
    char data;
} node;

typedef struct ArrayStack
{
    int nMaxCount;
    int nCurrentCount;
    node *pHeader;
} stack;

stack *createStack(const int nSize)
{
    stack *pResult = (stack*)malloc(sizeof(stack));
    if (pResult == NULL)
    {
        printf("memory allocation error: createStack()");
        return NULL;
    }
    if (nSize <= 0)
    {
        printf("memory allocation error: createStack()");
        return NULL;
    }
    
    pResult->nCurrentCount = 0;
    pResult->nMaxCount = nSize;
    pResult->pHeader = (node*)malloc(sizeof(node) * nSize);
    if (pResult->pHeader == NULL)
    {
        printf("memory allocation error: createStack()");
        return NULL;
    }
    memset(pResult->pHeader, 0, sizeof(node) * nSize);      // Risk of memory initialization error
    return pResult;
}

int isArrayStackFull(const stack *_pStack_)
{
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: isArrayStackFull()");
        return -1;
    }
    if (_pStack_->nCurrentCount == _pStack_->nMaxCount)
    {
        return 1;
    }
    return 0;
}

int push(stack *_pStack_, const char nData)
{
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: push()");
        return -1;
    }
    if (isArrayStackFull(_pStack_) != 0)
    {
        printf("stack overflow: push()");
        return -2;
    }

    _pStack_->pHeader[_pStack_->nCurrentCount].data = nData;
    _pStack_->nCurrentCount++;

    return 0;
}

int isEmpty(const stack *_pStack_)
{
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: isEmpty()");
        return -1;
    }
    if (_pStack_->nCurrentCount == 0)
    {
        return 1;
    }
    return 0;
}

node *pop(stack *_pStack_)
{
    node *pResult = NULL;

    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: pop()");
        return NULL;
    }
    if (isEmpty(_pStack_) != 0)
    {
        printf("stack underflow: pop()");
        return NULL;
    }
    
    pResult = (node*)malloc(sizeof(node));
    if (pResult == NULL)
    {
        printf("memory allocation error: pop()");
        return NULL;
    }
    pResult->data = _pStack_->pHeader[_pStack_->nCurrentCount - 1].data;
    _pStack_->nCurrentCount--;

    return pResult;
}

node *peek(stack *_pStack_)
{
    node *pResult = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: peek()");
        return NULL;
    }
    if (isEmpty(_pStack_) != 0)
    {
        printf("stack underflow: pop()");
        return NULL;
    }

    pResult = (node *)malloc(sizeof(node));
    if (pResult == NULL)
    {
        printf("memory allocation error: pop()");
        return NULL;
    }
    pResult->data = _pStack_->pHeader[_pStack_->nCurrentCount - 1].data;
    
    return pResult;
}

int deleteStack(stack *_pStack_)
{
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: deleteStack()");
        return -1;
    }
    if (_pStack_->pHeader != NULL)
    {
        free(_pStack_->pHeader);
    }
    free(_pStack_);
    return 0;
}

int displayStack(stack *_pStack_)
{
    int i = 0;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: displayStack()");
        return -1;
    }

    printf("Stack size: %d, Current count: %d\n", _pStack_->nMaxCount, _pStack_->nCurrentCount);

    for (i = _pStack_->nMaxCount - 1; i >= _pStack_->nCurrentCount; i--)
        printf("[%d]-[Empty]\n", i);
    
    for (i = _pStack_->nCurrentCount - 1; i >= 0; i--)
        printf("[%d]-[%c]\n", i, _pStack_->pHeader[i].data);

    return 0;
}

int main(int argc, char *argv[])
{
    stack *pStack = NULL;
    node *pNode = NULL;

    pStack = createStack(6);
    if (pStack == NULL)
    {
        printf("memory allocation error: main()");
        return -1;
    }
    
    push(pStack, 'A');
    push(pStack, 'B');
    push(pStack, 'C');
    push(pStack, 'D');

    displayStack(pStack);

    pNode = pop(pStack);

    if (pNode == NULL)
    {
        printf("Unallocated memory access error: main()");
        return -2;
    }
    printf("Pop: [%c]\n", pNode->data);
    free(pNode);

    displayStack(pStack);

    pNode = peek(pStack);

    if (pNode == NULL)
    {
        printf("Unallocated memory access error: main()");
        return -2;
    }

    printf("Peek: [%c]\n", pNode->data);
    displayStack(pStack);
    free(pNode);
    deleteStack(pStack);
    return 0;
}

/* execution result
Stack size: 6, Current count: 4
[5]-[Empty]
[4]-[Empty]
[3]-[D]
[2]-[C]
[1]-[B]
[0]-[A]
Pop: [D]
Stack size: 6, Current count: 3
[5]-[Empty]
[4]-[Empty]
[3]-[Empty]
[2]-[C]
[1]-[B]
[0]-[A]
Peek: [C]
Stack size: 6, Current count: 3
[5]-[Empty]
[4]-[Empty]
[3]-[Empty]
[2]-[C]
[1]-[B]
[0]-[A]
*/