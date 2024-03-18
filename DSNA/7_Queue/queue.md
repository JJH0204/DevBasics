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
```