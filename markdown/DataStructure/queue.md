# Queue 란?
- 대기열을 뜻하며, 일상에서 가장 흔하게 접할 수 있는 규칙중 하나
- FIFO(First-In-First-Out), 선입선출, 가장 먼저 들어간 자료가 가장 먼저 나오는 형태
- 새로운 데이터를 맨 뒤 "리어(rear)"에 추가하며, 맨 앞 "프런트(front)"에서 데이터를 제거한다.
- 새로운 데이터를 추가하는 연산을 인큐(enqueue)라 하며, 기존 데이터를 반환하는 연산을 디큐(dequeue)라 한다.

# Queue 추상 자료형
|          이름 |  입력  |      출력      | 설명                                                  |
| ------------: | :----: | :------------: | :---------------------------------------------------- |
| createQueue() | size n |     Queue      | 빈 큐를 생성                                          |
| deleteQueue() | Queue  |      N/A       | 큐를 메모리에서 해제                                  |
|      isFull() | Queue  |      bool      | 인큐 수행가능 여부를 반환, 배열로 큐를 구현할 때 필요 |
|     isEmpty() | Queue  |      bool      | 빈 큐인지 반환                                        |
|     enqueue() | Queue  | 성공/실패 여부 | 큐의 맨 뒤에 새로운 데이터 추가                       |
|     dequeue() |  data  |      data      | 큐 맨 앞의 데이터 반환 후 제거                        |
|        peek() | Queue  |      data      | 큐 맨 앞의 데이터를 제거하지 않고 반환                |

# Array Linear Queue
- 1차원 배열을 이용하기 때문에 미리 크기를 지정해야 함
- 비교적 쉽게 구현할 수 있다.
- 인큐(enqueue)와 디큐(dequeue) 연산을 반복하다 보면, 배열 앞부분부터 사용할 수 없는 빈 곳이 생긴다.
- 배열 선형 큐를 기본으로 하고 문제를 해결한 자료구조가 "배열 원형 큐" > 이름이 배열 선형 큐 인 이유

## 노드
```c
typedef struct ArrayQNode
{
    char cData;
} node;
```
## 배열 선형 큐
```c
typedef struct ArrayQueue
{
    int nMaxCount;
    int nCurrentCount;
    int nRearIndex;
    int nFrontIndex;
    node *pQueue;
} queue;
```
## 큐 생성
```c
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
```
## 인큐: enqueue()
```c
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
```
### 큐가 가득 찬 것을 어떻게 알 수 있을까?
> 리어 인덱스 값의 역할이 크다.  
> 리어 인덱스 값이 배열의 사이즈 값과 같거나 큰 경우 배열에 더 이상 값을 저장할 수 없는 가득 찬 상태라는 것을 알 수 있다.  
> 하지만 이 방식은 배열 선형 큐의 구조적 특징 때문에 가능한 것이지 배열 선형 큐 외 다른 구조의 큐는 가능한 방법이 아니다.  
> 배열 큐(배열 원형 큐)는 위 방법이 아닌 현재 배열의 저장 중인 데이터 수와 최대 사이즈를 검증하는 것이 옳다.

## 디큐: dequeue()
```c
node *dequeue(queue *_pQueue_)
{
    node *pResult = NULL;
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: dequeue()");
        return NULL;
    }
    if (isEmpty(_pQueue_) != 0)
    {
        printf("The queue is empty: dequeue()");
        return NULL;
    }
    pResult = (node*)malloc(sizeof(node));
    _pQueue_->nFrontIndex++;
    pResult->cData = _pQueue_->pQueue[_pQueue_->nFrontIndex].cData;
    _pQueue_->pQueue[_pQueue_->nFrontIndex].cData = ' ';
    _pQueue_->nCurrentCount--;

    return pResult;
}

int isEmpty(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: isEmpty()");
        return -1;
    }
    if ((_pQueue_->nFrontIndex == _pQueue_->nRearIndex) || (_pQueue_->nCurrentCount <= 0))
    {
        printf("Queue is empty: isEmpty()");
        return -2;
    }
    return 0;
}
```
### 큐가 빈 것을 어떻게 알까?
> 큐가 비어 있음을 어떻게 알 수 있을까?  
> - 프론트와 리어가 같다면 -> 큐가 비었다고 할 수 있다.  
> - 현재 저장 중인 데이터 수가 0과 같거나 이하라면 -> 큐가 비었다고 할 수 있다.

## 피크: peek()
```c
node *peek(queue *_pQueue_)
{
    node *pResult = NULL;
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: peek()");
        return NULL;
    }
    if (isEmpty(_pQueue_) != 0)
    {
        printf("The queue is empty: peek()");
        return NULL;
    }
    return &(_pQueue_->pQueue[_pQueue_->nFrontIndex + 1]);
}
```

## 출력: displayQueue()
```c
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
```

## 큐 삭제: deleteQueue()
```c
int deleteQueue(queue *_pQueue_)
{
    if (_pQueue_ == NULL)
    {
        printf("Unallocated memory access error: deleteQueue()");
        return -1;
    }
    if (_pQueue_->pQueue != NULL)
        free(_pQueue_->pQueue);
    free(_pQueue_);
    return 0;
}
```

## main()
```c
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
```
### 실행 결과
```
Queue size: 4, node count's: 4
[-1]-[]
[0]-[A]
[1]-[B]
[2]-[C]
[3]-[D]
Dequeue: [A]
Queue size: 4, node count's: 3
[0]-[ ]
[1]-[B]
[2]-[C]
[3]-[D]
Peek: [B]
Queue size: 4, node count's: 3
[0]-[ ]
[1]-[B]
[2]-[C]
[3]-[D]
Queue is full: isFull()
The queue is full.: enqueue()
Queue size: 4, node count's: 3
[0]-[ ]
[1]-[B]
[2]-[C]
[3]-[D]
```

### 왜? 첫 출력 값에 -1 인덱스의 값이 출력된 걸까?
- 출력 함수는 프론트 인덱스 값을 기준으로 리어 인덱스까지 값을 출력한다.
- 첫 출력 시 초기값으로 프론트 인덱스를 -1로 설정한 덕분에 출력을 위한 for()문을 -1 인덱스부터 순서대로 참조하기 시작한다.
- 이는 안전하지 않는 메모리 접근으로 간주되어 보안의 안정성을 떨어뜨린다.
- 그렇기 때문에 프론트 인덱스 값에 +1 을 하여 참조를 진행한다.

### 왜? 대기열에 자리가 있음에도 데이터를 추가할 수 없을까?
- 배열 선형 큐의 근본 문제로, 앞 인덱스에 자리가 있음에도 활용할 수 없는 문제가 있다.
- 이 문제를 해결하기 위해 배열 원형 큐(배열 큐) 또는 포인터를 활용해 큐를 구현해야 한다.

# Array Circular Queue(배열 원형 큐)
> 일반적으로 배열로 구현한 큐를 사용할 경우 배열 선형 큐가 아니라 배열 원형 큐를 주로 사용  
> 배열 선형 큐에 빈 노드가 있음에도 사용할 수 없던 문제를 배열 원형 큐에서 개선

## 배열 선형 큐에서 문제를 개선하지 못하는 이유
- 프런트의 노드를 무조건 인덱스 번호 0 의 위치에 둘 수 있지만, 그렇게 할 경우 배열의 노드들을 앞으로 한칸 씩 당겨 저장해야 한다.
- 배렬에서 데이터를 옮기는 방법을 사용할 경우 배열 크기에 따라 시간 비용이 많이 들게 된다. O(n)

## 배열 원형 큐의 구조적 특징
- 배열의 마지막 노드와 첫 노드를 논리적으로 연결해 배열이 연속되도록 했다.
- [rear = (rear + 1) % maxCount] 공식을 이용해 리어가 배열의 마지막에서 다음 노드로 이동을 시도할 때 이동할 리어 위치 인덱스 값을 첫 노드로 변경하도록 했다. (% = 나머지 연산자)
- 위 공식은 front 에도 동일하게 적용되나.

## 코드 변경 사항
```c
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
```
### 출력 결과
```
Queue size: 4, Current Node Count: 4
[0]-[A]
[1]-[B]
[2]-[C]
[3]-[D]
Dequeue: [A]
Queue size: 4, Current Node Count: 3
[1]-[B]                                 //<--- 프론트 인덱스 값이 1 이 되었다.
[2]-[C]
[3]-[D]
Peek: [B]
Queue size: 4, Current Node Count: 3
[1]-[B]
[2]-[C]
[3]-[D]
Queue size: 4, Current Node Count: 4
[1]-[B]
[2]-[C]
[3]-[D]
[0]-[E]                                 //<--- 리어의 인덱스 값이 프론트 인덱스 값 보다 낮다.
```

# Queue: Using Pointer Queue
```c
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
    int nCurrntCount;
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
    if(ptr->nCurrntCount <= 0 && ptr->pFront == NULL && ptr->pRear == NULL)
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
    pResult->nCurrntCount = 0;
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
    _pQueue_->nCurrntCount++;
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
    _pQueue_->nCurrntCount--;
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

    printf("Current node count: %d\n", _pQueue_->nCurrntCount);
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
```
## 출력 결과
```
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
```

# deque: 덱 구현
```c
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
void deleteNode(node *_pNode_);

int main(int argc, char *argv[])
{
    deque *pDeque = NULL;
    node *pNode = NULL;

    pDeque = createDeque();
    if (ISNULL(pDeque))
        return -1;

    enqueue(pDeque, 'A', REAR);
    enqueue(pDeque, 'B', REAR);
    enqueue(pDeque, 'C', REAR);
    enqueue(pDeque, 'D', REAR);
    displayDeque(pDeque);

    pNode = dequeue(pDeque, FRONT);
    if (!ISNULL(pNode))
    {
        printf("> Dequeue value from front - [%c]\n", pNode->cData);
        free(pNode);
    }
    displayDeque(pDeque);

    pNode = peek(pDeque, FRONT);
    if (!ISNULL(pNode))
        printf("> Peek value from front - [%c]\n", pNode->cData);
    displayDeque(pDeque);

    enqueue(pDeque, 'E', FRONT);
    enqueue(pDeque, 'F', FRONT);
    enqueue(pDeque, 'G', FRONT);
    displayDeque(pDeque);

    pNode = dequeue(pDeque, REAR);
    if (!ISNULL(pNode))
    {
        printf("> Dequeue value from rear - [%c]\n", pNode->cData);
        free(pNode);
    }
    displayDeque(pDeque);

    pNode = peek(pDeque, REAR);
    if (!ISNULL(pNode))
        printf("> Peek value from rear - [%c]\n", pNode->cData);
    displayDeque(pDeque);

    deleteDeque(pDeque);
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

bool deleteDeque(deque *ptr)
{
    if (ISNULL(ptr))
        return true;
    if (!ISEMPTY(ptr))
        deleteNode(ptr->pFront);
    free(ptr);
    return false;
}

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

void deleteNode(node *_pNode_)
{
    if (_pNode_ == NULL)
        return;
    deleteNode(_pNode_->pNext);
    free(_pNode_);
    return;
}
```

## 출력 결과
```
Current node count: 4
    [0]-[A]
    [1]-[B]
    [2]-[C]
    [3]-[D]
> Dequeue value from front - [A]
Current node count: 3
    [0]-[B]
    [1]-[C]
    [2]-[D]
> Peek value from front - [B]
Current node count: 3
    [0]-[B]
    [1]-[C]
    [2]-[D]
Current node count: 6
    [0]-[G]
    [1]-[F]
    [2]-[E]
    [3]-[B]
    [4]-[C]
    [5]-[D]
> Dequeue value from rear - [D]
Current node count: 5
    [0]-[G]
    [1]-[F]
    [2]-[E]
    [3]-[B]
    [4]-[C]
> Peek value from rear - [C]
Current node count: 5
    [0]-[G]
    [1]-[F]
    [2]-[E]
    [3]-[B]
    [4]-[C]
```