#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQNode
{
    char cData;
} node;

typedef struct ArrayQueue
{
    int nMaxCount;
    int nCurrentCount;
    int nRearIndex;
    int nFrontIndex;
    node *pQueue;
} queue;

int isFull(queue *_pQueue_);
int isEmpty(queue *_pQueue_);
queue *createQueue(const int _nSize_);
int initQueue(queue *_pQueue_, const int _nSize_);
int enqueue(queue *_pQueue_, const char _cData_);
node *dequeue(queue *_pQueue_);

int main(int argc, char *argv[])
{
    queue *pQueue = NULL;
    node *pNode = NULL;

    pQueue = createQueue(4);
    if (pQueue == NULL)
    {
        printf("Unallocated memory access error: main()");
        return -1;
    }
    
    enqueue(pQueue, 'A');
    enqueue(pQueue, 'B');
    enqueue(pQueue, 'C');
    enqueue(pQueue, 'D');
    displayQueue(pQueue);

    pNode = dequeue(pQueue);
    if (pNode == NULL)
    {
        printf("dequeue error: main()");
        return -2;
    }
    printf("Dequeue: [%c]\n", pNode->cData);
    free(pNode);
    displayQueue(pQueue);

    pNode = peek(pQueue);
    if (pNode == NULL)
    {
        printf("Peek error: main()");
        return -2;
    }
    printf("Peek: [%c]\n", pNode->cData);
    displayQueue(pQueue);

    enqueue(pQueue, 'E');
    displayQueue(pQueue);

    return 0;
}

queue *createQueue(const int _nSize_)
{
    queue *pResult = NULL;
    if (_nSize_ <= 0)
    {
        printf("Array creation minimum size error: createQueue()");
        return NULL;
    }
    
    pResult = (queue*)malloc(sizeof(queue));
    if (pResult == NULL)
    {
        printf("Memory allocation error: createQueue()");
        return NULL;
    }
    if (initQueue(pResult, _nSize_) != 0)
    {
        printf("Memory initialization error: createQueue()");
        return NULL;
    }
    pResult->pQueue = (node *)malloc(sizeof(node) * pResult->nMaxCount);

    return pResult;
}

int initQueue(queue *_pQueue_, const int _nSize_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: initQueue()");
        return -1;
    }
    _pQueue_->nMaxCount = _nSize_;
    _pQueue_->nCurrentCount = 0;
    _pQueue_->nFrontIndex = -1;
    _pQueue_->nRearIndex = -1;
    _pQueue_->pQueue = NULL;
    return 0;
}

int enqueue(queue * _pQueue_, const char _cData_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: enqueue()");
        return -1;
    }
    if (isFull(_pQueue_) != 0)
    {
        printf("The queue is full.: enqueue()");
        return -2;
    }
    _pQueue_->nRearIndex++;
    _pQueue_->pQueue[_pQueue_->nRearIndex].cData = _cData_;
    _pQueue_->nCurrentCount++;
    return 0;
}

int isFull(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: isFull()");
        return -1;
    }
    
    if ((_pQueue_->nCurrentCount == _pQueue_->nMaxCount) || (_pQueue_->nRearIndex == _pQueue_->nMaxCount - 1))
    {
        printf("Queue is full: isFull()");
        return -2;
    }
    return 0;
}

node *dequeue(queue *_pQueue_)
{
    node *pResult = NULL;
    /* code */
    return pResult;
}

int isEmpty(queue *_pQueue_)
{
    /* code */
    return 0;
}

int displayQueue(queue *_pQueue_)
{
    /* code */
    return 0;
}

int peek(queue *_pQueue_)
{
    /* code */
    return 0;
}