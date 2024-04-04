이전 문서 > [그래프(Graph)](Graph.md)

# 1. 그래프의 추상 자료형
| 이름          | INPUT                           | OUTPUT | DESC                                                            |
| :------------ | :------------------------------ | :----- | :-------------------------------------------------------------- |
| createGraph() | 최대 노드 개수 n                | Graph  | n 개의 노드를 가지는 공백(Empty) Graph 생성                     |
| deleteGraph() | Graph                           | N/A    | Graph의 모든 노드(V)와 모든 간선(E)를 제거하고,<br/>그래프 제거 |
| addEdge()     | Graph, <br/>노드 A, <br/>노드 B | N/A    | 그래프에 노드 A와 B를 연결하는 새로운 간선 e를 추가             |
| removeEdge()  | Graph, <br/>노드 A, <br/>노드 B | N/A    | 그래프의 간선 (A, B) 혹은 (B, A)를 제거                         |

# 2. 인접 행렬로 구현한 그래프
## 2.1. 인접 행렬이란?
- 그래프 구현에 사용하는 2차원 배열을 인접 행렬(Adjacency matrix)이라 한다.
- 두 개의 노드가 간선으로 서로 연결되어 있으면 '인접'한다고 한다.
- 그래프에서 '인접'은 '노드의 연결'을 의미한다.
- 인접 행렬이란 **노드들 사이의 연결 정보(간선 정보)를 저장하는 행렬(2차원 배열)** 을 의미한다.
- 여기서 간선 정보란 '간선의 존재 여부' 또는 '가중치 값' 등을 의미한다.
- 간선 존재 여부를 저장하는 행렬(방향 그래프)
  - <0, 1> 간선 표현

  |       |   0   |   1   |
  | :---: | :---: | :---: |
  |   0   |   0   |   1   |
  |   1   |   0   |   0   |

    - 노드 0에서 1을 연결하는 간선 <0, 1>이 존재하기 때문에 원소[0][1] 값은 1
    - <1, 0>는 존재하지 않기 때문에 원소 [1][0] 값은 0
    - 행(Row) = 시작 노드(꼬리), 열(Column) = 종료 노드(머리)
    - 간선<i, j>가 있다면, [i][j] = 1
    - 간선<i, j>가 없다면, [i][j] = 0
- 노드 개수 n 개 일때 행렬 원소 개수는 n*n
- 모든 노드가 서로 간선으로 연결되지 않는다면 낭비되는 공간이 많아진다.

## 2.2. 인접 행렬 구조
```c
typedef struct DirectArrayGraph
{
    int nNodeCount;         // 노드 개수 정보
    int **ppEdge;          // 노드 개수 만큼 2차원 배열 할당할 이중 포인터 변수
} DirectArrayGraph;
```

## 2.3. 그래프 생성: createDirectArrayGraph()
```c
DirectArrayGraph *createDirectArrayGraph(const int _nNodeCount_)
{
    int nLoopCount = 0;
    int nSupLoopCount = 0;
    DirectArrayGraph *pResult = NULL;

    // DirectArrayGraph 메모리 할당 및 검증
    for (nLoopCount = 0; (pResult == NULL) && (nLoopCount < 6); nLoopCount++)
        pResult = (DirectArrayGraph *)malloc(sizeof(DirectArrayGraph));
    if (pResult == NULL)
    {
        printf("Memory Allocate Error: createDirectArrayGraph()\n");
        return NULL;
    }

    // 1차원 배열을 저장할 포인터 변수를 할당 및 검증
    pResult->nNodeCount = _nNodeCount_;
    for (nLoopCount = 0; (pResult->ppEdge == NULL) && (nLoopCount < 6); nLoopCount++)
        pResult->ppEdge = (int **)malloc(sizeof(int *) * _nNodeCount_);
    if (pResult->ppEdge == NULL)
    {
        printf("Memory Allocate Error: createDirectArrayGraph()\n");
        free(pResult);
        return NULL;
    }

    // 행 별로 메모리를 할당하고 검증
    for (nLoopCount = 0; nLoopCount < _nNodeCount_; nLoopCount++)
    {
        for (nSupLoopCount = 0; (pResult->ppEdge[nLoopCount] == NULL) && (nSupLoopCount < 6); nSupLoopCount++)
            pResult->ppEdge[nLoopCount] = (int *)malloc(sizeof(int) * _nNodeCount_);
        if (pResult->ppEdge[nLoopCount] == NULL)
        {
            printf("Memory Allocate Error: createDirectArrayGraph()\n");
            for (nLoopCount = nLoopCount - 1; nLoopCount >= 0; nLoopCount--)
                free(pResult->ppEdge[nLoopCount]);
            free(pResult);
            return NULL;
        }
        memset(pResult->ppEdge[nLoopCount], 0, sizeof(nLoopCount) * _nNodeCount_);
    } 
    return pResult;
}
```

## 2.4. 간선 추가: addEdge()
```c
bool addEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) && checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    // 간선 정보 저장
    _pGraph_->ppEdge[_nFrom_][_nTo_] = 1;
    return false;
}

int checkVertexValid_ERROR(DirectArrayGraph *_pGraph_, int nNode)
{
    // 유효성 점검 || 노드가 노드 최대 보다 큰 위치 || 노드가 0 보다 낮은 위치
    if (ISNULL_ERROR(_pGraph_) || nNode >= _pGraph_->nNodeCount || nNode < 0)
        return true;

    return false;
}
```

## 2.5. 간선 삭제: removeEdge()
```c
int removeEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) && checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;
    
    // 간선 정보 삭제
    _pGraph_->ppEdge[_nFrom_][_nTo_] = 0;
    return false;
}
```

## 2.6. 기타
```c
int getEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) && checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    return _pGraph_->ppEdge[_nFrom_][_nTo_];
}

void displayGraph(DirectArrayGraph *_pGraph_)
{
    int nRow = 0, nColumn = 0;

    if (ISNULL_ERROR(_pGraph_))
        return;

    for (nRow = 0; nRow < _pGraph_->nNodeCount; nRow++)
    {
        for (nColumn = 0; nColumn < _pGraph_->nNodeCount; nColumn++)
            printf("%d ", getEdge(_pGraph_, nRow, nColumn));
        printf("\n");
    }
    return;
}

bool deleteGraph(DirectArrayGraph *_pGraph_)
{
    int nLoopCount = 0;

    if (ISNULL_ERROR(_pGraph_))
        return true;

    for (nLoopCount = 0; nLoopCount < _pGraph_->nNodeCount; nLoopCount++)
        free(_pGraph_->ppEdge[nLoopCount]);
    free(_pGraph_->ppEdge);
    free(_pGraph_);
    return false;
}
```
# 3. 인접 리스트로 구현한 그래프
## 3.1. 인접 리스트란?
- 인접 정보(간선의 존애 여부) 혹은 가중치 정보 등를 저장하는 리스트를 이용하는 그래프
- 리스트를 이용하기 때문에 인접 행렬보다 메모리 활용이 더 효율적이지만 간선 정보를 확인하는 데 다소 시간을 소요한다.
- 노드의 개수가 동적으로 정해진다면 보통 연결 리스트(linked list)로 구현한다. (연결 리스트의 1차원 배열)
- 시작 노드를 기준으로 연결 리스트가 저장된다. (초기에 모두 내용이 없는 빈 연결 리스트다. = 간선 정보가 없기 때문)
## 3.2. 인접 리스트와 인접 행렬의 비교
|      -      |    인접 행렬     |   인접 리스트    |
| :---------: | :--------------: | :--------------: |
| 희소 그래프 | 메모리 효율 낮음 | 메모리 효율 높음 |
| 밀집 그래프 | 메모리 효율 높음 | 메모리 효율 낮음 |
- 인접 행렬은 실제 간선의 개수와는 상관없이 모든 간선의 정보를 2차원 배열에 저장한다.
- 희소 그래프(sparse graph): 노드의 개수는 많은데 비해 상대적으로 간선의 개수가 적은 그래프, 인접 리스트로 구현했을 때 효율이 좋다.
- 밀집 그래프(dense graph): 노드의 개수가 많은 노드, 인접 리스트로 구현할 경우 노드 사이의 포인터 정보 같은 것들을 추가로 저장해야 하기에 더 효율이 떨어진다.
| 인접 행렬 | 인접 리스트 |
| :-------: | :---------: |
|  $O(1)$   |   $O(n)$    |
- 인접 행렬은 배열을 통해 간선에 바로 접근할 수 있다. O(1)의 시간 복잡도
- 인접 리스트는 간선 접근을 위해 리스트를 순회해야 하기 때문에 느리다. O(n)의 시간 복잡도
## 3.3. 인접 리스트 구조
```c
typedef struct DirectLinkedGraph
{
    int nNodeCount;   // 노드 개수 정보
    list **ppAdjEdge; // 노드 개수 만큼 연결 리스트의 배열을 할당할 이중 포인터
} DirectLinkedGraph;
```
- ppAdjEdge: 연결 리스트를 저장하는 1차원 배열의 시작 주소를 가리키지만, 1차원 배열의 원소 타입이 포인터(list *)이기 때문에 이중 포인터 타입으로 선언

## 3.4. 그래프 생성
```c
DirectLinkedGraph *createDirectLinkedGraph(const int _nNodeCount_)
{
    int nLoopCount = 0;
    DirectLinkedGraph *pResult = NULL;

    // DirectArrayGraph 메모리 할당 및 검증
    pResult = (DirectLinkedGraph *)malloc(sizeof(DirectLinkedGraph));
    if (ISNULL_ERROR(pResult))
        return NULL;

    if (_nNodeCount_ <= 0)
    {
        printf("The maximum number of nodes must be greater than 0.\n");
        free(pResult);
        return NULL;
    }
    

    // 1차원 배열을 저장할 포인터 변수를 할당 및 검증
    pResult->nNodeCount = _nNodeCount_;
    pResult->ppAdjEdge = (list **)malloc(sizeof(list *) * _nNodeCount_);
    if (ISNULL_ERROR(pResult->ppAdjEdge))
    {
        free(pResult);
        return NULL;
    }
    
    // 노드 별로 메모리를 할당하고 검증
    for (nLoopCount = 0; nLoopCount < _nNodeCount_; nLoopCount++)
    {
        // 메모리 할당 시도
        pResult->ppAdjEdge[nLoopCount] = list_Create();
        // 메모리 할당 실패
        if (ISNULL_ERROR(pResult->ppAdjEdge[nLoopCount]))
        {
            free(pResult->ppAdjEdge);
            free(pResult);
            return NULL;
        }
    }
    return pResult;
}
```
## 3.5. 간선 추가
```c
bool addEdge(DirectLinkedGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;
    
    // 간선 정보 저장
    list_Add(_pGraph_->ppAdjEdge[_nFrom_], _nTo_);
    return false;
}

bool checkVertexValid_ERROR(DirectLinkedGraph *_pGraph_, int nNode)
{
    // 유효성 점검 || 노드가 노드 최대 보다 큰 위치 || 노드가 0 보다 낮은 위치
    if (ISNULL_ERROR(_pGraph_) || nNode >= _pGraph_->nNodeCount || nNode < 0)
        return true;

    return false;
}
```

## 3.6. 간선 제거
```c
bool removeEdge(DirectLinkedGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    list *pList = NULL;
    int nCount = 0, nLoopCount = 0;
    // 유효성 점검 // 두 노드가 안전한 위치에 있는지 점검
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    pList = _pGraph_->ppAdjEdge[_nFrom_];
    nCount = pList->nCurrentCount;

    for (; nLoopCount < nCount; nLoopCount++)
    {
        if ((int *)list_Get(pList, nLoopCount) == _nTo_)
        {
            // 간선 정보 삭제
            list_Remove(pList, nLoopCount);
            break;
        }
    }

    return false;
}
```

## 3.7. 그 외 함수들
```c
int getEdge(DirectLinkedGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    list *pList = NULL;
    int nCount = 0, nLoopCount = 0;
    // 유효성 점검 // 두 노드가 안전한 위치에 있는지 점검
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return 0;

    pList = _pGraph_->ppAdjEdge[_nFrom_];
    nCount = pList->nCurrentCount;

    for (; nLoopCount < nCount; nLoopCount++)
    {
        if ((int *)list_Get(pList, nLoopCount) == _nTo_)
        {
            return 1;
        }
        
    }
    return 0;
}

void displayGraph(DirectLinkedGraph *_pGraph_)
{
    int nLoopCount = 0, nRow = 0, nColumn = 0;

    if (ISNULL_ERROR(_pGraph_))
        return;

    nLoopCount = _pGraph_->nNodeCount;

    for (nRow = 0; nRow < nLoopCount; nRow++)
    {
        for (nColumn = 0; nColumn < nLoopCount; nColumn++)
        {
            if (getEdge(_pGraph_, nRow, nColumn))
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    return;
}

bool deleteGraph(DirectLinkedGraph *_pGraph_)
{
    int nLoopCount = 0;

    if (ISNULL_ERROR(_pGraph_))
        return true;

    for (nLoopCount = 0; nLoopCount < _pGraph_->nNodeCount; nLoopCount++)
        list_Delete(_pGraph_->ppAdjEdge[nLoopCount]);
    if (_pGraph_->ppAdjEdge != NULL)
        free(_pGraph_->ppAdjEdge);
    free(_pGraph_);
    return false;
}
```
# 4. 무방향 그래프 구현
- **간선의 대칭성(symmetry)** 이라는 고유 특성을 갖고 있다. (방향성이 없는 간선이기 때문)
- 인접 행렬에서 간선을 보았을 때 대칭 위치에 간선이 배치된다.
- 행, 열이 서로 바뀐다.

※ 인접 행렬로 구현한 그래프의 소스코드 일부를 수정해서 구현한다.

## 4.1. 그래프 구조
```c
#define DIRECT_TYPE     0
#define UNDIRECT_TYPE   1

typedef struct ArrayGraph
{
    int nGraphType; // 그래프 종류: 방향 / 무방향
    int nNodeCount; // 노드 개수 정보
    int **ppEdge;   // 노드 개수 만큼 2차원 배열 할당할 포인터 변수
} ArrayGraph;
```

## 4.2. 그래프 생성
```c
ArrayGraph *createArrayGraph(const int _nGraphType_, const int _nNodeCount_)
{
    int nLoopCount = 0;
    ArrayGraph *pResult = NULL;

    pResult = (ArrayGraph *)malloc(sizeof(ArrayGraph));
    if (ISNULL_ERROR(pResult))
        return NULL;
    
    pResult->nGraphType = _nGraphType_;     // 추가 사항
    pResult->nNodeCount = _nNodeCount_;
    pResult->ppEdge = (int **)malloc(sizeof(int *) * _nNodeCount_);
    if (ISNULL_ERROR(pResult->ppEdge))
    {
        free(pResult);
        return NULL;
    }
    
    for (nLoopCount = 0; nLoopCount < _nNodeCount_; nLoopCount++)
    {
        pResult->ppEdge[nLoopCount] = (int *)malloc(sizeof(int) * _nNodeCount_);

        if (ISNULL_ERROR(pResult->ppEdge[nLoopCount]))
        {
            for (nLoopCount = nLoopCount - 1; nLoopCount >= 0; nLoopCount--)
                free(pResult->ppEdge[nLoopCount]);
            free(pResult);
            return NULL;
        }

        memset(pResult->ppEdge[nLoopCount], 0, sizeof(int) * _nNodeCount_);
    }
    return pResult;
}
```
## 4.3. 간선 추가
```c
bool addEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    bool bResult = true;
    if (ISNULL_ERROR(_pGraph_))
        return true;

    bResult = addEdgeInternal(_pGraph_, _nFrom_, _nTo_);
    if (false == bResult && UNDIRECT_TYPE == _pGraph_->nGraphType)  // 무방향 그래프 일 경우 대칭 위치에 간선 추가
    {
        bResult = addEdgeInternal(_pGraph_, _nTo_, _nFrom_);
    }
    return bResult;
}

bool addEdgeInternal(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    _pGraph_->ppEdge[_nFrom_][_nTo_] = 1;
    return false;
}
```

## 4.4. 간선 삭제
```C
bool removeEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    bool bResult = true;
    if (ISNULL_ERROR(_pGraph_))
        return bResult;
    
    bResult = removeEdgeInternal(_pGraph_, _nFrom_, _nTo_);
    if (false == bResult && UNDIRECT_TYPE == _pGraph_->nGraphType)
        bResult = removeEdgeInternal(_pGraph_, _nTo_, _nFrom_);
    return bResult;
}

bool removeEdgeInternal(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    _pGraph_->ppEdge[_nFrom_][_nTo_] = 0;
    return false;
}
```
## 4.5. 정리
> 구조체의 정의에 간선의 종류를 추가, 
> 간선 추가/삭제 시 간선 종류에 따라 반대 방향의 간선을 추가할지 여부를 결정한다.
- 인접 연결 그래프에서 무방향 그래프를 구현하는 방법은 위와 동일하기 때문에 별도의 설명을 추가하지 않는다.