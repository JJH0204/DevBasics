# Stack.md
## 스택이란?
> - 쌓이는 특성을 가진 데이터 더미  
> - LIFO (Last-In-First_Out), **후입선출**  
> - 수치 해석 및 계산, 길찾기 알고리즘 등 **후입선출** 특성이 필요한 분야에서 사용
> - 데이터 추가와 제거가 스택의 한쪽 끝(맨 위, TOP)에서 진행  

## 사용 시나리오
### 데이터 추가: Push()  
> 새로운 데이터는 기존 자료의 위에...  

### 데이터 가져오기: Pop()
> 저장한 순서의 역순으로...  
> 단, 가져온 데이터는 삭제  

### 데이터 삭제 없이 가져오기: Peek()
> 데이터 가져오기(Pop())과 달리 가져온 데이터를 삭제하지 않고 가져옴  
> 데이터 삭제 여부 외 데이터 가져오기(Pop())와 다른 점이 없음

## 추상 자료형
|        함수명 |     입력      |      출력      | 설명                                                              |
| ------------: | :-----------: | :------------: | :---------------------------------------------------------------- |
| createStack() | 스택의 크기 n |      스택      | 빈 스택을 생성                                                    |
| deleteStack() |     스택      |      N/A       | 스택의 메모리를 해제                                              |
|      isFull() |     스택      |      bool      | 스택에 푸시를 수행할 수 있는지를 반환,  배열 스택인 경우에만 가능 |
|     isEmpty() |     스택      |      bool      | 빈 스택인지를 반환                                                |
|        push() |     스택      | 성공/실패 여부 | 스택의 맨 위에 새로운 데이터를 추가                               |
|         pop() |     Data      |      Data      | 스택의 맨 위에 있는 데이터를 제거한 뒤 이를 반환                  |
|        peek() |     스택      |      Data      | 스택의 맨 위에 있는 데이터를 반환(스택에서 제거하지 않음)         |

## 배열 스택
### 노드 구조
```C
typedef struct arrayNode
{
    char data;
} node;
```
### 스택 구조
```C
typedef struct ArrayStack
{
    int nMaxCount;
    int nCurrentCount;
    node *pHeader;
} stack;
```
### 스택 생성: createStack()
```C
stack *createStack(const int nSize)
{
    stack *pResult = (stack*)malloc(sizeof(stack));
    if (pResult == NULL)
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
```
### 푸시: push()
```C
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
```
```C
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
```
### 팝: pop()
```C
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
```
```C
int isEmpty (const stack *_pStack_)
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
```
### 피크: peek()
```C
node *peek(stack *_pStack_)
{
    node *pResult = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: peek()");
        return -1;
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
```
### 스택 삭제: deleteStack()
```C
int deleteStack(stack *_pStack_)
    {
        if (_pStack_ == NULL)
        {
            printf("Unallocated memory access error: peek()");
            return -1;
        }
        if (_pStack_->pHeader != NULL)
        {
            free(_pStack_->pHeader);
        }
        free(_pStack_);
        return 0;
    }
```

### 스택 출력: displayStack()
```C
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
```
## 포인터 스택
> "연결 스택(Linked Stack)" 또는 "연결 리스트로 구현한 스택" 이라 한다.  
> 배열 스택과 달리 스택의 크기를 미리 지정하지 않아도 된다. = 메모리 동적 할당의 장점  

### 노드 구조
```C
typedef struct StackNode
{
    char cData;
    struct StackNode *pNext;
} node;
```

### 스택 구조
```C
typedef struct LinkedStack
{
    node *pTop;
    int nCurrentCount;
} stack;
```
### 스택 생성: createStack()
```C
stack *createStack()
{
    stack *pResult = (stack*)malloc(sizeof(stack));
    if (pResult == NULL)
    {
        printf("memory allocation error: createStack()\n");
        return NULL;
    }
    if (initStack(pResult) != 0)
    {
        printf("Memory initialization failed: createStack()\n");
        return NULL;
    }
    return pResult;
}

int initStack(stack *_pStack_)
{
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: initStack()\n");
        return -1;
    }
    _pStack_->nCurrentCount = 0;
    _pStack_->pTop = NULL;
    return 0;
}
```
### 데이터 추가: push()
```C
int push(stack *_pStack_, const char _cData_)
{
    node *pNewNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: push()\n");
        return -1;
    }
    
    pNewNode = (node*)malloc(sizeof(node));
    if (pNewNode == NULL)
    {
        printf("memory allocation error: push()\n");
        return -2;
    }
    if (initNode(pNewNode, _cData_) != 0)
    {
        printf("Memory initialization failed: createStack()\n");
        return -3;
    }
    pNewNode->pNext = _pStack_->pTop;
    _pStack_->pTop = pNewNode;
    _pStack_->nCurrentCount++;
    return 0;
}

int initNode(node *_pNode_, const char _cData_)
{
    if (_pNode_ == NULL)
    {
        printf("Unallocated memory access error: initNode()\n");
        return -1;
    }
    _pNode_->cData = _cData_;
    _pNode_->pNext = NULL;
    return 0;
}
```

### 팝, 피크 연산: pop(), peek()
```C
node *pop(stack *_pStack_)
{
    node *pPopNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: pop()\n");
        return NULL;
    }
    if ((_pStack_->pTop == NULL) && (_pStack_->nCurrentCount == 0))
    {
        printf("Stack underflow error: pop()\n");
        return NULL;
    }
    pPopNode = _pStack_->pTop;
    _pStack_->pTop = pPopNode->pNext;
    pPopNode->pNext = NULL;
    _pStack_->nCurrentCount--;
    return pPopNode;
}

node *peek(const stack *_pStack_)
{
    node *pPeekNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: peek()\n");
        return NULL;
    }
    if ((_pStack_->pTop == NULL) && (_pStack_->nCurrentCount == 0))
    {
        printf("No data in stack: peek()\n");
        return NULL;
    }
    pPeekNode = (node*)malloc(sizeof(node));
    if (pPeekNode == NULL)
    {
        printf("memory allocation error: peek()\n");
        return NULL;
    }
    if (initNode(pPeekNode, _pStack_->pTop->cData) != 0)
    {
        printf("Memory initialization failed: peek()\n");
        return NULL;
    }
    return pPeekNode;
}
```

### 스택 출력: displayStack()
```C
int displayStack(const stack *_pStack_)
{
    node *pNode = NULL;
    int nCount = 0;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: displayStack()\n");
        return -1;
    }

    printf("current stack: %d number\n", _pStack_->nCurrentCount);
    pNode = _pStack_->pTop;
    for ( ; pNode != NULL; pNode = pNode->pNext)
    {
        printf("[%d]-[%c]\n", _pStack_->nCurrentCount - nCount, pNode->cData);
        nCount++;
    }

    return 0;
}
```

### 스택 삭제: deleteStack()
```C
int deleteStack(stack *_pStack_)
{
    node *delNode = NULL;
    if (_pStack_ == NULL)
    {
        printf("Unallocated memory access error: deleteStack()\n");
        return -1;
    }
    
    while (_pStack_->pTop != NULL)
    {
        delNode = _pStack_->pTop;
        _pStack_->pTop = delNode->pNext;
        free(delNode);
    }
    free(_pStack_);
    return 0;
}
```