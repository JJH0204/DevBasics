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

int main(int argc, char *argv[])
{
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

// TODO: enqueue() code implementation
int enqueue(queue * _pQueue_, const char _cData_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: enqueue()");
        return -1;
    }
    if (isFull(_pQueue_) != 0)
    {
        printf(": enqueue()");
        return -1;
    }
    
    return 0;
}