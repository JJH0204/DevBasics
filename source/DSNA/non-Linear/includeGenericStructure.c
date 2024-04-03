// include Generic Stack.c
// 제네릭 프로그래밍 기법을 활용한 스택 구현
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeGenericStructure.h"

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}
bool isEmptyStack(const stack *ptr, const char *funcName)
{
    if (ptr->nCurrentCount <= 0 && ptr->pTopNode == NULL)
    {
        printf("%s: Stack is Empty\n", funcName);
        return true;
    }
    return false;
}
bool isEmptyQueue(const queue *ptr, const char *funcName)
{
    if (ptr->nCurrentCount <= 0 && ptr->pFront == NULL)
    {
        printf("%s: Queue is Empty\n", funcName);
        return true;
    }
    return false;
}
bool isEmptyList(const list *ptr, const char *funcName)
{
    if (ptr->nCurrentCount <= 0 && ptr->pHead == NULL)
    {
        printf("%s: Linked List is Empty\n", funcName);
        return true;
    }
    return false;
}

stack *stack_Create(void)
{
    stack *pStack = (stack *)malloc(sizeof(stack));
    if (ISNULL_ERROR(pStack))
        return NULL;
    pStack->nCurrentCount = 0;
    pStack->pTopNode = NULL;
    return pStack;
}
bool stack_Push(stack *_pStack_, void *_data_)
{
    node *pCurrentNode = NULL;
    if (ISNULL_ERROR(_pStack_))
        return true;
    pCurrentNode = (node *)malloc(sizeof(node));
    if (ISNULL_ERROR(_pStack_))
        return true;
    pCurrentNode->nodeData = _data_;
    pCurrentNode->pNextNode = _pStack_->pTopNode;
    _pStack_->pTopNode = pCurrentNode;
    _pStack_->nCurrentCount++;
    return false;
}
void *stack_Pop(stack *_pStack_)
{
    node *pCurrentNode = NULL;
    void *pResult = NULL;
    if (ISNULL_ERROR(_pStack_) || ISEMPTY_STACK(_pStack_))
        return NULL;
    pCurrentNode = _pStack_->pTopNode;
    _pStack_->pTopNode = pCurrentNode->pNextNode;
    pCurrentNode->pNextNode = NULL;
    _pStack_->nCurrentCount--;
    pResult = pCurrentNode->nodeData;
    free(pCurrentNode);
    return pResult;
}
void *stack_Peek(const stack *_pStack_)
{
    void *pResult = NULL;
    if (ISNULL_ERROR(_pStack_) || ISEMPTY_STACK(_pStack_))
        return NULL;
    pResult = _pStack_->pTopNode->nodeData;
    return pResult;
}
bool stack_Delete(stack *_pStack_)
{
    if (ISNULL_ERROR(_pStack_))
        return true;

    while (_pStack_->nCurrentCount > 0)
        free(stack_Pop(_pStack_));
    free(_pStack_);
    return false;
}

queue *queue_Create(void)
{
    queue *pResult = (queue *)malloc(sizeof(queue));
    if (ISNULL_ERROR(pResult))
        return NULL;
    pResult->nCurrentCount = 0;
    pResult->pFront = NULL;
    pResult->pRear = NULL;
    return pResult;
}
bool queue_enqueue(queue *_pQueue_, void *_data_)
{
    node *pCurrentNode = NULL;
    if (ISNULL_ERROR(_pQueue_))
        return true;
    pCurrentNode = (node *)malloc(sizeof(node));
    if (ISNULL_ERROR(pCurrentNode))
        return true;
    pCurrentNode->nodeData = _data_;
    pCurrentNode->pNextNode = NULL;
    if (_pQueue_->nCurrentCount <= 0)
        _pQueue_->pFront = pCurrentNode;
    else
        _pQueue_->pRear->pNextNode = pCurrentNode;
    _pQueue_->pRear = pCurrentNode;
    _pQueue_->nCurrentCount++;
    return false;
}
void *queue_dequeue(queue *_pQueue_)
{
    node *pCurrentNode = NULL;
    void *pResult = NULL;
    if (ISNULL_ERROR(_pQueue_) || ISEMPTY_QUEUE(_pQueue_))
        return NULL;
    pCurrentNode = _pQueue_->pFront;
    _pQueue_->pFront = _pQueue_->pFront->pNextNode;
    pCurrentNode->pNextNode = NULL;
    _pQueue_->nCurrentCount--;
    pResult = pCurrentNode->nodeData;
    free(pCurrentNode);
    return pResult;
}
bool queue_Delete(queue *_pQueue_)
{
    if (ISNULL_ERROR(_pQueue_))
        return true;
    while (_pQueue_->nCurrentCount > 0)
        queue_dequeue(_pQueue_);
    free(_pQueue_);
    return false;
}

list *list_Create(void)
{
    list *pResult = (list *)malloc(sizeof(list));
    if (ISNULL_ERROR(pResult))
        return NULL;
    pResult->nCurrentCount = 0;
    pResult->pHead = NULL;
    return pResult;
}
bool list_Add(list *_pList_, int _data_)
{
    int nLoopCount = 0;
    int_node *pNode = NULL;
    int_node *pPreNode = NULL;

    if (ISNULL_ERROR(_pList_))
        return true;

    pNode = (int_node *)malloc(sizeof(int_node));
    if (ISNULL_ERROR(pNode))
        return true;

    pNode->nData = _data_;
    pNode->pNextNode = NULL;

    if (_pList_->pHead == NULL)
    {
        _pList_->pHead = pNode;
    }
    else
    {
        pPreNode = _pList_->pHead;
        while (pPreNode->pNextNode != NULL)
            pPreNode = pPreNode->pNextNode;
        pPreNode->pNextNode = pNode;
    }
    _pList_->nCurrentCount++;
    return false;
}
int list_Get(list *_pList_, const int _nIndex_)
{
    int nLoopCount = 0;
    int_node *pResult = NULL;

    if (ISNULL_ERROR(_pList_) || ISEMPTY_List(_pList_))
        return -1;

    if (_nIndex_ >= _pList_->nCurrentCount || _nIndex_ < 0)
    {
        printf("%s: Memory access error.\n", __func__);
        return -1;
    }

    pResult = _pList_->pHead;
    for (; nLoopCount < _nIndex_; nLoopCount++)
        pResult = pResult->pNextNode;
    return pResult->nData;
}
bool list_Remove(list *_pList_, const int _nIndex_)
{
    int nLoopCount = 0;
    int_node *pCurrentNode = NULL;
    int_node *pPreviousNode = NULL;

    if (ISNULL_ERROR(_pList_) || ISEMPTY_List(_pList_))
        return true;
    if (_nIndex_ >= _pList_->nCurrentCount || _nIndex_ < 0)
    {
        printf("%s: Memory access error.\n", __func__);
        return true;
    }

    pPreviousNode = _pList_->pHead;

    for (; nLoopCount < _nIndex_ - 1; nLoopCount++)
        pPreviousNode = pPreviousNode->pNextNode;

    pCurrentNode = pPreviousNode->pNextNode;
    pPreviousNode->pNextNode = pCurrentNode->pNextNode;

    free(pCurrentNode);
    _pList_->nCurrentCount--;
    return false;
}
bool list_Delete(list *_pList_)
{
    int_node *pTempNode = NULL;
    if (ISNULL_ERROR(_pList_))
        return true;

    while (_pList_->pHead != NULL)
    {
        pTempNode = _pList_->pHead->pNextNode;
        free(_pList_->pHead);
        _pList_->pHead = pTempNode;
    }
    free(_pList_);
    return false;
}