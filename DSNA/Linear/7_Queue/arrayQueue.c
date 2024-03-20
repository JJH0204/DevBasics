#include <stdio.h>
#include <stdlib.h>

#define __ArrayQueue__

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
node *peek(queue *_pQueue_);
int displayQueue(queue *_pQueue_);
int deleteQueue(queue *_pQueue_);

int main(int argc, char *argv[])
{
    queue *pQueue = NULL;
    node *pNode = NULL;

    pQueue = createQueue(4);
    if (pQueue == NULL)
    {
        printf("Unallocated memory access error: main()\n");
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
        printf("dequeue error: main()\n");
        return -2;
    }
    printf("Dequeue: [%c]\n", pNode->cData);
    free(pNode);
    displayQueue(pQueue);

    pNode = peek(pQueue);
    if (pNode == NULL)
    {
        printf("Peek error: main()\n");
        return -2;
    }
    printf("Peek: [%c]\n", pNode->cData);
    displayQueue(pQueue);

    enqueue(pQueue, 'E');
    displayQueue(pQueue);

    deleteQueue(pQueue);

    return 0;
}

queue *createQueue(const int _nSize_)
{
    queue *pResult = NULL;
    if (_nSize_ <= 0)
    {
        printf("Array creation minimum size error: createQueue()\n");
        return NULL;
    }
    
    pResult = (queue*)malloc(sizeof(queue));
    if (pResult == NULL)
    {
        printf("Memory allocation error: createQueue()\n");
        return NULL;
    }
    if (initQueue(pResult, _nSize_) != 0)
    {
        printf("Memory initialization error: createQueue()\n");
        return NULL;
    }
    pResult->pQueue = (node *)malloc(sizeof(node) * pResult->nMaxCount);

    return pResult;
}

int initQueue(queue *_pQueue_, const int _nSize_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: initQueue()\n");
        return -1;
    }
    _pQueue_->nMaxCount = _nSize_;
    _pQueue_->nCurrentCount = 0;
    _pQueue_->nFrontIndex = -1;
    _pQueue_->nRearIndex = -1;
    _pQueue_->pQueue = NULL;
    return 0;
}

int isEmpty(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: isEmpty()\n");
        return -1;
    }
    if ((_pQueue_->nFrontIndex == _pQueue_->nRearIndex) || (_pQueue_->nCurrentCount <= 0))
    {
        printf("Queue is empty: isEmpty()\n");
        return -2;
    }
    return 0;
}

int deleteQueue(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: deleteQueue()\n");
        return -1;
    }
    if (_pQueue_->pQueue != NULL)
        free(_pQueue_->pQueue);
    free(_pQueue_);
    return 0;
}

node *peek(queue *_pQueue_)
{
    node *pResult = NULL;
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: peek()\n");
        return NULL;
    }
    if (isEmpty(_pQueue_) != 0)
    {
        printf("The queue is empty: peek()\n");
        return NULL;
    }
    return &(_pQueue_->pQueue[_pQueue_->nFrontIndex + 1]);
}

#ifndef __ArrayQueue__

int isFull(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: isFull()\n");
        return -1;
    }
    
    if ((_pQueue_->nCurrentCount == _pQueue_->nMaxCount) || (_pQueue_->nRearIndex == _pQueue_->nMaxCount - 1))
    {
        printf("Queue is full: isFull()\n");
        return -2;
    }
    return 0;
}

int enqueue(queue * _pQueue_, const char _cData_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: enqueue()\n");
        return -1;
    }
    if (isFull(_pQueue_) != 0)
    {
        printf("The queue is full.: enqueue()\n");
        return -2;
    }
    _pQueue_->nRearIndex++;
    _pQueue_->pQueue[_pQueue_->nRearIndex].cData = _cData_;
    _pQueue_->nCurrentCount++;
    return 0;
}

node *dequeue(queue *_pQueue_)
{
    node *pResult = NULL;
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: dequeue()\n");
        return NULL;
    }
    if (isEmpty(_pQueue_) != 0)
    {
        printf("The queue is empty: dequeue()\n");
        return NULL;
    }
    pResult = (node*)malloc(sizeof(node));
    _pQueue_->nFrontIndex++;
    pResult->cData = _pQueue_->pQueue[_pQueue_->nFrontIndex].cData;
    _pQueue_->pQueue[_pQueue_->nFrontIndex].cData = ' ';
    _pQueue_->nCurrentCount--;

    return pResult;
}

int displayQueue(queue *_pQueue_)
{
    int nCount = 0;
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: displayQueue()\n");
        return -1;
    }
    printf("Queue size: %d, node count's: %d\n", _pQueue_->nMaxCount, _pQueue_->nCurrentCount);
    for (nCount = _pQueue_->nFrontIndex + 1; nCount <= _pQueue_->nRearIndex; nCount++)
        printf("[%d]-[%c]\n", nCount, _pQueue_->pQueue[nCount].cData);
    return 0;
}
#endif

#ifdef __ArrayQueue__
int isFull(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: isFull()\n");
        return -1;
    }
    
    if (_pQueue_->nCurrentCount == _pQueue_->nMaxCount)
    {
        printf("Queue is full: isFull()\n");
        return -2;
    }
    return 0;
}

int enqueue(queue *_pQueue_, const char _cData_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: enqueue()\n");
        return -1;
    }
    if (isFull(_pQueue_) != 0)
    {
        printf("Queue is full: enqueue()");
        return -2;
    }
    _pQueue_->nRearIndex = (_pQueue_->nRearIndex + 1) % _pQueue_->nMaxCount;
    _pQueue_->pQueue[_pQueue_->nRearIndex].cData = _cData_;
    _pQueue_->nCurrentCount++;

    return 0;
}

node *dequeue(queue *_pQueue_)
{
    node * pNode = NULL;
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: dequeue()\n");
        return NULL;
    }
    if (isEmpty(_pQueue_) != 0)
    {
        printf("Queue is empty: dequeue()");
        return NULL;
    }
    
    pNode = (node *)malloc(sizeof(node));
    if (pNode == NULL)
    {
        printf("Memory allocation error: dequeue()\n");
        return NULL;
    }
    _pQueue_->nFrontIndex = (_pQueue_->nFrontIndex +1) % _pQueue_->nMaxCount;
    pNode->cData = _pQueue_->pQueue[_pQueue_->nFrontIndex].cData;
    _pQueue_->pQueue[_pQueue_->nFrontIndex].cData = ' ';
    _pQueue_->nCurrentCount--;
    return pNode;
}

int displayQueue(queue *_pQueue_)
{
    int nCount = 0;
    int nPosition = 0;

    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: displayQueue()\n");
        return -1;
    }
    printf("Queue size: %d, Current Node Count: %d\n", _pQueue_->nMaxCount, _pQueue_->nCurrentCount);

    for (nCount = _pQueue_->nFrontIndex + 1; nCount <= _pQueue_->nFrontIndex + _pQueue_->nCurrentCount; nCount++)
    {
        nPosition = nCount % _pQueue_->nMaxCount;
        printf("[%d]-[%c]\n", nPosition, _pQueue_->pQueue[nPosition].cData);
    }
    return 0;
}

#endif