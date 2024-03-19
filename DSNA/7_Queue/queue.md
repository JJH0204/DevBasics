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
int peek(queue *_pQueue_)
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
    /* code */
    // ?? dequeue 에서 아무 조건 없이 FrontIndex 값을 늘린다.
    // 조건을 걸어야 피크 연산에 안정성이 올라 갈 수 있다.
    return 0;
}
```

## 출력: displayQueue()
```c
int displayQueue(queue *_pQueue_)
{
    /* code */
    return 0;
}
```