// Deque.c
/* deque: double-ended queue
- 양쪽 끝에서 데이터의 삽입과 반환이 모두 가능한 자료형
|            name |    input    |  output  | desc                         |
| --------------: | :---------: | :------: | :--------------------------- |
|   createDeque() |             |  deque   | 빈 덱 생성                   |
|   deleteDeque() |    deque    | 성공여부 | 덱 삭제(메모리 해제)         |
|       isEmpty() |    deque    |   bool   | 빈 덱인지 반환               |
| enqueue_Front() | deque, data | 성공여부 | 프런트에 새로운 데이터 추가  |
|  enqueue_Rear() | deque, data | 성공여부 | 리어에 새로운 데이터 추가    |
| dequeue_Front() |    deque    |   data   | 프런드에 데이터 반환 후 삭제 |
|  dequeue_Rear() |    deque    |   data   | 리어에 데이터 반환 후 삭제   |
|    peek_Front() |    deque    |   data   | 프런트에 데이터 반환         |
|     peek_Rear() |    deque    |   data   | 리어에 데이터 반환           |
|  displayDeque() |    deque    |          | 덱 저장된 데이터 전부 출력   |
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ISNULL(ptr) isNull((ptr), __func__)
#define ISEMPTY(ptr) isEmpty((ptr), __func__)

typedef enum Dir {FRONT = 0, REAR = 1} dir;

typedef struct DueueNode
{
    char cData;
    struct DueueNode *pNext;
} node;

typedef struct Deque
{
    int nCurrntCount;
    node *pFront;
    node *pRear;
} deque;

// Func declaration
bool isNull(const void *ptr, const char *funcName);
bool isEmpty(const deque *ptr, const char *funcName);
deque *createDeque(void);
bool deleteDeque(deque *ptr);
bool enqueue(deque *ptr, const char _cData_, const dir _dir_);
node *dequeue(deque *ptr, const dir _dir_);
node *peek(deque *ptr, const dir _dir_);
bool displayDeque(const deque *ptr);

int main(int argc, char *argv[])
{
    deque *pDeque = NULL;
    node *pNode = NULL;

    pDeque = createQueue();
    if (ISNULL(pDeque))
        return -1;

    enqueue(pDeque, 'A', REAR);
    enqueue(pDeque, 'B', REAR);
    enqueue(pDeque, 'C', REAR);
    enqueue(pDeque, 'D', REAR);
    displayQueue(pDeque);

    pNode = dequeue(pDeque, FRONT);
    if (!ISNULL(pNode))
    {
        printf("> Dequeue value from front - [%c]\n", pNode->cData);
        free(pNode);
    }
    displayQueue(pDeque);

    pNode = peek(pDeque, FRONT);
    if (!ISNULL(pNode))
        printf("> Peek value from front - [%c]\n", pNode->cData);
    displayQueue(pDeque);

    enqueue(pDeque, 'E', FRONT);
    enqueue(pDeque, 'F', FRONT);
    enqueue(pDeque, 'G', FRONT);
    displayQueue(pDeque);

    pNode = dequeue(pDeque, REAR);
    if (!ISNULL(pNode))
    {
        printf("> Dequeue value from rear - [%c]\n", pNode->cData);
        free(pNode);
    }
    displayQueue(pDeque);

    pNode = peek(pDeque, REAR);
    if (!ISNULL(pNode))
        printf("> Peek value from rear - [%c]\n", pNode->cData);
    displayQueue(pDeque);

    deleteQueue(pDeque);
    return 0;
}

// Func definition
bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

bool isEmpty(const deque *ptr, const char *funcName)
{
    if (ptr->nCurrntCount <= 0 && ptr->pFront == NULL && ptr->pRear == NULL)
        return true;
    return false;
}

deque *createDeque(void)
{
    deque *pResult = (deque *)malloc(sizeof(deque));
    if (ISNULL(pResult))
        return NULL;
    pResult->nCurrntCount = 0;
    pResult->pFront = NULL;
    pResult->pRear = NULL;
    return pResult;
}

bool deleteQueue(deque *ptr)
{
    if (ISNULL(ptr))
        return true;
    if (!ISEMPTY(ptr))
        deleteNode(ptr->pFront);
    free(ptr);
    return false;
}

// TODO: Implementation of a deque that extends the queue 
bool enqueue(deque *ptr, const char _cData_, const dir _dir_)
{
    node *pNode = NULL;
    if (ISNULL(ptr))
        return true;
    pNode = (node *)malloc(sizeof(node));
    if (ISNULL(pNode))
        return true;
    pNode->cData = _cData_;
    pNode->pNext = NULL;
    
    if (ISEMPTY(ptr))
    {
        ptr->pFront = pNode;
        ptr->pRear = pNode;
    }
    else if (_dir_ == REAR)
    {
    	ptr->pRear->pNext = pNode;
    	ptr->pRear = pNode;
    }
    else
    {
    	pNode->pNext = ptr->pFront;
        ptr->pFront = pNode;
    }
    ptr->nCurrntCount++;
    return false;
}

node *dequeue(deque *ptr, const dir _dir_)
{
    node *pNode = NULL;
    node *pPreNode = NULL;
    if (ISNULL(ptr) || ISEMPTY(ptr))
        return NULL;
    if (_dir_ == FRONT)
    {
        pNode = ptr->pFront;
    	ptr->pFront = ptr->pFront->pNext;
        pNode->pNext = NULL;
    }
    else
    {
        pPreNode = ptr->pFront;
        while (pPreNode->pNext != ptr->pRear)
            pPreNode = pPreNode->pNext;
        pNode = ptr->pRear;
        ptr->pRear = pPreNode;
        ptr->pRear->pNext = NULL;
    }
    ptr->nCurrntCount--;
    return pNode;
}

node *peek(deque *ptr, const dir _dir_)
{
    node *pPeek = NULL;
    if (ISNULL(ptr) || ISEMPTY(ptr))
        return NULL;

    pPeek = (node *)malloc(sizeof(node));
    if (_dir_ == FRONT)
	    pPeek->cData = ptr->pFront->cData;
    else
    	pPeek->cData = ptr->pRear->cData;
    pPeek->pNext = NULL;
    return pPeek;
}

bool displayDeque(const deque *ptr)
{
    node *pPrint = NULL;
    int nCount = 0;
    if (ISNULL(ptr) || ISEMPTY(ptr))
        return true;

    printf("Current node count: %d\n", ptr->nCurrntCount);
    for (pPrint = ptr->pFront; pPrint != NULL; nCount++)
    {
        printf("\t[%d]-[%c]\n", nCount, pPrint->cData);
        pPrint = pPrint->pNext;
    }
    return false;
}