# 히프(Heap)
- [배열로 이진 트리를 구현](ArrayBinaryTree.md)하는 것은 완전 이진 트리 같이 빈 노드가 적은 구조일 경우가 적합했다.
- "히프"는 완전 이진 트리의 한 종류로 배열로 구현한 이진 트리를 사용하는 대표적인 사례가 된다.
## 1. 히프란?
- 히프는 완전 이진 트리 뿐 아니라 최대 트리, 최소 트리의 특징을 갖고 있다.
- 우선순위 큐(priority queue)와 히프 정렬의 구현 도구로 사용된다
- 히프의 루트 노드는 그 트리의 최댓값 혹은 최솟값을 가진다. (최대값을 가지면 최대 트리, 최소값을 가지면 최소 트리)
### 1.1. 최대 트리
- 각 노드의 값이 자식 노드의 값보다 크거나 같은 트리
- 최대 트리의 예시
```
         20
       /    \
      6      12
     / \    /  \
    2   6  10   8
```
### 1.2. 최소 트리
- 각 노드의 값이 자식 노드의 값보다 작거나 같은 트리
- 최소 트리의 예시
```
          10
       /     \
      15     12
     /  \   /  \
    15  20 16  18
```
### 1.3. [완전 이진 트리](CompleteBinaryTree.md)
> 히프는 최대(최소) 트리의 속성 외 완전 이진 트리의 속성을 꼭 가져야 히프로 정의된다.   
- 마지막 레벨에서는 중간에 빈 노드가 없는 점이 핵심
```
        9                  9
       / \                / \
      8   5              8   5
     / \                    / \
    8   2                  5   3
```
- (좌)완전 이진 트리의 예, (우)완전 이진 트리가 아닌 예
### 1.4. 정리
- 히프(heap) = 완전 이진 트리 + 최대(또는 최소)트리
- 최대 히프 = 완전 이진 트리 + 최대 트리 (루트 노드의 값이 트리의 전체 노드 값들 중 가장 큰 값)
- 최소 히프 = 완전 이진 트리 + 최소 트리 (루트 노드의 값이 트리의 전체 노드 값들 중 가장 작은 값)

> [Tip. 느슨한 정렬 상태]
> - 최대 트리의 경우 각 노드 별로 부모 노드가 자식 노드의 키 값 보다 크거나 같다.
> - 반면, 각 노드가 모든 하위 레벨의 노드에 대해서 조건을 만족하지는 않는다.
> - 이를 "느슨한 정렬 상태"라고 하며 히프의 특징 중 하나이다.
> - 또한, 히프의 경우 중복된 키 값을 허용한다.

## 2. 히프의 추상 자료형
| 이름         | INPUT       | OUTPUT     | DESC                                          |
| :----------- | :---------- | :--------- | :-------------------------------------------- |
| createHeap() | Heap size n | Heap       | 최대 n개의 원소를 가질 수 있는 공백 히프 생성 |
| deleteHeap() | Heap        | N/A        | 히프 제거(메모리 할당 해제)                   |
| insertHeap() | Heap, data  | true/false | 히프에 데이터 추가                            |
| removeHeap() | Heap        | Node       | **히프의 루트 노드를 제거한 뒤 반환**         |
- 최대 히프의 경우 루트 노드에 히프 내 가장 큰 값이 저장되어 있기 때문에 최대 히프에서 데이터를 제거하면 가장 큰 데이터가 반환된다.
- 루트 노드가 제거되면 그 다음 큰 값을 가진 노드가 새로운 루트 노드가 된다.
- 최소 히프의 경우에도 위와 유사(값만 다름)
- 배열을 이용해 구현하는 것이 일반적이지만, 경우에 따라 연결리스트로 구현하기도 한다.

## 3. 최대 히프에서의 데이터 추가: insertHeap()
### 3.1. 트리의 마지막 자리에 임시 저장
- 새로운 노드는 트리의 가장 마지막 자리에 임시로 저장한다.
- 완전 이진 트리이기 때문에 가장 큰 레벨의 가장 오른쪽에 추가한다.
```
        9                    9
       / \                /     \
      8   5              8       5
     / \                / \     /
    8   2              8   2  [10] <- 10 추가 
```
### 3.2. 부모 노드와 키 값 비교, 이동
- 최대 또는 최소 트리 조건을 충족하기 위해 추가된 값과 부모 노드 키 값을 비교한다.
- 최대 트리의 경우 (추가된 값 >= 부모 노드의 값)의 조건을 충족하게 되면 부모 노드와 추가된 노드의 위치를 서로 바꾼다.
```
          9                      9
       /     \                /     \
      8       5              8      10 <- 위치 이동
     / \     /              / \     /
    8   2   10             8   2   5
```
- 최대 또는 최소 트리 조건을 만족할 때까지 위 과정을 반복한다.
- (최대 트리의 경우 추가된 노드 보다 큰 값을 가진 부모 노드를 만날때까지 반복)
```
          9                      10  <- 최종 위치
       /     \                /     \
      8      10              8       9
     / \     /              / \     /
    8   2   5              8   2   5
```

## 4. 최대 히프에서의 데이터 제거: removeHeap()
- 최댓값의 반환 연산, 현재 루트 노드만 제거하기 때문
- 최소 히프의 경우에도 동일
- 제거된 루트 노드를 대체하는 새로운 루트 노드를 만드는 후처리 과정(post processing)이 필요
### 4.1. 루트 노드 제거
```
        9                 [] <- 9 제거
       / \                / \
      8   5              8   5
     / \                / \ 
    8   2              8   2
```
### 4.2. 트리의 마지막 노드 임시 이동
```
        []                 2
       / \                / \
      8   5              8   5
     / \                /
    8   2              8
```
### 4.3. 자식 노드들과 값 비교 후 이동
- 루트 노드를 기준으로 자식 노드에 더 큰 값의 노드가 있는지 확인
- 3 노드 중 가장 값이 큰 값의 노드를 루트로 이동한다.
```
        2                  8
       / \                / \
      8   5              2   5
     /                  /
    8                  8
```
- 최대(또는 최소)히프 조건을 충족하기 위해 이동을 반복한다.
```
        8                  8
       / \                / \
      2   5              8   5
     /                  /
    8                  2
```
> [Tip.]
> - 히프에 저장되는 데이터의 개수 = n, 히프에 새로운 데이터를 추가하는 함수의 시간 복잡도 $O(logn)$
> - $logn$히프에서 최대(또는 최소) 데이터를 제거(반환)하는 함수의 시간 복잡도 $O(logn)$
> - 왜냐? 히프는 추가되는 데이터를 완전 이진 트리 형태로 저장하기 때문
> - 완전 이진 트리 형태로 데이터를 저장하기 때문에 데이터의 개수가 $n$개인 경우 트리의 높이가 $logn$이기 때문
> - 따라서 다른 자료구조에 비해 비교적 빠른 성능을 가진다.   

## 5. 히프 구현
- 배열 이용해 구현하면 삽입, 삭제 연산을 더 빨리 할 수 있다.
- 주소값을 직접 계산해 원하는 노드를 직접 접근할 수 있기 때문
- 히프는 완전 이진 트리기 때문에 중간에 낭비되는 빈 노드가 적다. = 공간 낭비 문제가 적다.
```
        9           배열 인덱스: | 0 | 1 | 2 | 3 | 4 | 5 |
       / \          배열 데이터: | 0 | 9 | 8 | 5 | 2 | 6 |
      8   5
     / \
    2   6
```
> [노드 구하기 공식]
> - 노드 i 의 왼쪽 자식 = i * 2
> - 노드 i 의 오른쪽 자식 = i * 2 + 1
> - 노드 i 의 부모 = |i/2| (단, i > 1)   

### 5.1. 구조
```c
typedef struct HEAPNODE
{
    int nData;
} heapNode;

typedef struct ARRAYHEAP
{
    int nMaxCount;
    int nCurrentCount;
    heapNode *pArray;
} arrayHeap;

```
### 5.2. 생성
```c
arrayMaxHeap *createArrayMaxHeap(const int _nMaxCount_)
{
    arrayMaxHeap *pResult = NULL;
    if (_nMaxCount_<=0)                                                         // 인자 유효성 점검
    {
        printf("최대 원소 개수는 0보다 커야 한다.\n");
        return pResult;
    }
    pResult = (arrayMaxHeap *)malloc(sizeof(arrayMaxHeap));                     // 최대 히프 생성(메모리 할당)
    if (pResult == NULL)
        return pResult;
    
    pResult->nMaxCount = _nMaxCount_;                                           // 값 초기화
    pResult->nCurrentCount = 0;
    pResult->pArray = (heapNode *)malloc(sizeof(heapNode) * (_nMaxCount_ + 1)); // 인자 값 + 1 배열 생성
    if (pResult->pArray == NULL)
    {
        free(pResult);
        return NULL;
    }
    
    return pResult;
}
```
### 5.3. 추가
```c
bool insertArrayMaxHeap(arrayMaxHeap *_pHeap_, int _nVal_)
{
    int i = 0;

    if (_pHeap_ == NULL) // 유효성 점검, NULL 인지
        return true;

    if (_pHeap_->nCurrentCount == _pHeap_->nMaxCount) // 유효성 점검, 배열이 가득 찼는지
    {
        printf("error, 가득 찼습니다.[%d], insertArrayMaxHeap()\n", _pHeap_->nMaxCount);
        return true;
    }

    _pHeap_->nCurrentCount++;
    i = _pHeap_->nCurrentCount;                             // 배열(트리)의 데이터 수량 + 1, 배열 인덱스를 마지막 노드로 접근
    while (i != 1 && _nVal_ > _pHeap_->pArray[i / 2].nData) // 가리키는 노드가 루트인지 확인하고, 부모 노드의 데이터가 현재 데이터보다 작은지 확인
    {
        _pHeap_->pArray[i] = _pHeap_->pArray[i / 2]; // 부모 노드의 데이터를 지금 가리키는 노드로 옮긴다.
        i /= 2;                                      // 부모 노드로 이동한다.
    }
    _pHeap_->pArray[i].nData = _nVal_; // 가리키는 노드에 데이터 저장

    return false;
}
```
### 5.4. 제거
```c
heapNode *removeArrayMaxHeap(arrayMaxHeap *_pHeap_)
{
    heapNode *pResult = NULL;
    heapNode *pTemp = NULL;
    int nParentIndex = 1; // 부모 노드 인덱스 : 초기에 루트 노드를 가리킨다.
    int nChildIndex = 2;  // 자식 노드 인덱스 : 초기에 루트의 왼쪽 자식 노드를 가리킨다.

    if (_pHeap_ == NULL && _pHeap_->nCurrentCount <= 0)
    {
        printf("Heap Access Error: removeArrayMaxHeap()\n");
        return NULL;
    }

    pResult = (heapNode *)malloc(sizeof(heapNode));
    if (pResult == NULL)
    {
        printf("Memory Allocate Error: removeArrayMaxHeap()\n");
        return NULL;
    }

    pResult->nData = _pHeap_->pArray[1].nData;          // 루트 노드를 뽑는다.
    pTemp = &(_pHeap_->pArray[_pHeap_->nCurrentCount]); // 가장 마지막 노드를 루트 노드로 임시 이동 한다.
    _pHeap_->nCurrentCount--;                           // 노스 수량 -1 카운트 한다.

    while (nChildIndex <= _pHeap_->nCurrentCount) // 가리키는 자식 노드가 히프의 마지막 노드의 위치보다 낮거나 같으면 반복
    {
        // | 0 | 1 | 2 | 3 | 4 |
        // | 0 | 6 | 8 | 5 | 2 |
        //           |   |
        // nChildIndex   nChildIndex + 1

        // if ((2 < 5)&&([2]8 < [3]5)) 아래 조건문 예시
        if (nChildIndex < _pHeap_->nCurrentCount && _pHeap_->pArray[nChildIndex].nData < _pHeap_->pArray[nChildIndex + 1].nData)
            nChildIndex++;
        if (pTemp->nData >= _pHeap_->pArray[nChildIndex].nData)         // (A)"임시 이동한 노드"와 (B)"현재 가리키는 자식 노드"의 데이터 비교
            break;                                                      // A가 B 보다 크면 반복을 종료
        _pHeap_->pArray[nParentIndex] = _pHeap_->pArray[nChildIndex];   // A가 B 보다 작으면 반복을 종료하지 않고 부모 자리에 비교한 자식 데이터 저장
        nParentIndex = nChildIndex;                 // 부모 자리로 옮긴 자식 데이터의 본래 위치 인덱스로 부모 인덱스 갱신
        nChildIndex *= 2;                           // 갱신한 부모 인덱스에 맞춰 가리킬 자식 인덱스 갱신 (부모 인덱스 * 2 = 왼쪽 자식)
    }
    _pHeap_->pArray[nParentIndex] = *pTemp;     // 반복 종료되면 가리키던 부모 자리에 임시 저장 중이던 데이터 저장
    return pResult;
}
```
### 5.5. 기타 
```c
bool deleteArrayMaxHeap(arrayMaxHeap *_pHeap_)
{
    if (_pHeap_ != NULL)
    {
        if (_pHeap_->pArray != NULL)
            free(_pHeap_->pArray);
        free(_pHeap_);
    }

    return false;
}

bool displayArrayHeap(arrayMaxHeap *_pHeap_)
{
    int i = 0;
    if (_pHeap_ != NULL)
        for (i = 1; i <= _pHeap_->nCurrentCount; i++)
            printf("\t[%d], %d\n", i, _pHeap_->pArray[i].nData);

    return false;
}
```