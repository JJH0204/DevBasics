// queue.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ISNULL(ptr) isNull((ptr), __func__)
#define ISEMPTY(ptr) isEmpty((ptr), __func__)

typedef struct QueueNode
{
    char cData;
    struct QueueNode *pNext;
} node;

typedef struct Queue
{
    int nCurrentCount;
    node *pFront;
    node *pRear;
} queue;

queue *createQueue(void);
bool enqueue(queue *_pQueue_, const char _cData_);
node *dequeue(queue *_pQueue_);
bool deleteQueue(queue *_pQueue_);
bool displayQueue(const queue *_pQueue_);
bool isNull(const void *ptr, const char *funcName);
bool isEmpty(const queue *ptr, const char *funcName);
void deleteNode(node *_pNode_);
node *peek(const queue *_pQueue_);

int main(int argc, char *argv[])
{
    queue *pQueue = NULL;
    node *pNode = NULL;

    pQueue = createQueue();
    if (ISNULL(pQueue))
        return -1;
    
    enqueue(pQueue, 'A');
    enqueue(pQueue, 'B');
    enqueue(pQueue, 'C');
    enqueue(pQueue, 'D');
    displayQueue(pQueue);

    pNode = dequeue(pQueue);
    if (!ISNULL(pNode))
    {
        printf("> Dequeue value - [%c]\n", pNode->cData);
        free(pNode);
    }
    displayQueue(pQueue);

    pNode = peek(pQueue);
    if (!ISNULL(pNode))
        printf("> Peek value - [%c]\n", pNode->cData);
    displayQueue(pQueue);

    enqueue(pQueue, 'E');
    displayQueue(pQueue);
    
    deleteQueue(pQueue);
    return 0;
}
/* Target output result
Current node count: 4
    [0]-[A]
    [1]-[B]
    [2]-[C]
    [3]-[D]
> Dequeue value - [A]
Current node count: 3
    [0]-[B]
    [1]-[C]
    [2]-[D]
> Peek value - [B]
Current node count: 3
    [0]-[B]
    [1]-[C]
    [2]-[D]
Current node count: 4
    [0]-[B]
    [1]-[C]
    [2]-[D]
    [3]-[E]
*/

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

bool isEmpty(const queue *ptr, const char *funcName)
{
    if(ptr->nCurrentCount <= 0 && ptr->pFront == NULL && ptr->pRear == NULL)
    {
        // printf("%s: Queue is Empty\n", funcName);
        return true;
    }
    return false;
}

queue *createQueue(void)
{
    queue *pResult = (queue*)malloc(sizeof(queue));
    if (ISNULL(pResult))
        return NULL;
    pResult->nCurrentCount = 0;
    pResult->pFront = NULL;
    pResult->pRear = NULL;
    return pResult;
}

bool enqueue(queue *_pQueue_, const char _cData_)
{
    node *pNode = NULL;
    if (ISNULL(_pQueue_))
        return true;
    pNode = (node*)malloc(sizeof(node));
    if (ISNULL(pNode))
        return true;
    pNode->cData = _cData_;
    pNode->pNext = NULL;
    if (ISEMPTY(_pQueue_))
        _pQueue_->pFront = pNode;
    else
        _pQueue_->pRear->pNext = pNode;
    _pQueue_->pRear = pNode;
    _pQueue_->nCurrentCount++;
    return false;
}

node *dequeue(queue *_pQueue_)
{
    node *pNode = NULL;
    if (ISNULL(_pQueue_) || ISEMPTY(_pQueue_))
        return NULL;
    pNode = _pQueue_->pFront;
    _pQueue_->pFront = _pQueue_->pFront->pNext;
    pNode->pNext = NULL;
    _pQueue_->nCurrentCount--;
    return pNode;
}

bool deleteQueue(queue *_pQueue_)
{
    if (ISNULL(_pQueue_))
        return true;
    if (!ISEMPTY(_pQueue_))
    {
        deleteNode(_pQueue_->pFront);
    }
    free(_pQueue_);
    return false;
}

void deleteNode(node *_pNode_)
{
    if (_pNode_ == NULL)
        return;
    deleteNode(_pNode_->pNext);
    free(_pNode_);
    return;
}

bool displayQueue(const queue *_pQueue_)
{
    node *pPrint = NULL;
    int nCount = 0;
    if (ISNULL(_pQueue_) || ISEMPTY(_pQueue_))
        return true;

    printf("Current node count: %d\n", _pQueue_->nCurrentCount);
    for (pPrint = _pQueue_->pFront ; pPrint != NULL; nCount++)
    {
        printf("\t[%d]-[%c]\n", nCount, pPrint->cData);
        pPrint = pPrint->pNext;
    }
    return false;
}

node *peek(const queue *_pQueue_)
{
    node *pPeek = NULL;
    if (ISNULL(_pQueue_) || ISEMPTY(_pQueue_))
        return NULL;
    
    pPeek = (node*)malloc(sizeof(node));
    pPeek->cData = _pQueue_->pFront->cData;
    pPeek->pNext = NULL;
    return pPeek;
}