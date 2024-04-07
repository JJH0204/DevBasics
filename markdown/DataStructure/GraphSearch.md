# 그래프 탐색
- 그래프 탐색(traversal 또는 search)은 그래프 상의 모든 노드를 한 번씩 방문하는 것을 의미
- 대표적으로 두 방법을 사용한다. 깊이-우선 탐색(DFS: Depth-first search), 넓이-우선 탐색(BFS: breadth-first search)

| 구분                                      | 다음 노드 선택 기준               |
| :---------------------------------------- | :-------------------------------- |
| 깊이-우선 탐색(DFS: Depth-first search)   | "현재 노드 기준" -> "더 깊은 노드" |
| 넓이-우선 탐색(BFS: breadth-first search) | "이전 노드 기준" -> "더 넓은 노드" |

## 1. 깊이와 넓이
- 현재 노드(Current Node)는 1, 1과 연결된 노드는 0과 3이 있고 0은 이전 노드라고 가정
- 0은 1노드 외에도 2와도 연결중인 상태
> 3 - 1(Current) - 0(previous) - 2   
- 이때 1 노드 방문 후 어디를 방문할지 결정할 때 깊이와 넓이 개념이 필요
- 그래프 탐색 기준이 깊이라면 노드 3 방문
- 그래프 탐색 기준이 넓이라면 노드 2 방문 

## 2. 깊이-우선 탐색
- 다음에 방문할 노드를 선택할때 현재 방문한 노드와 연결된 노드를 먼저 선택하는 방법
- 이때 선택하는 노드는 연결된 노드 중 아직 방문하지 않는 노드여야 한다.

### 2.1. 재귀함수 활용
- 탐색 전 설정
```C
void ex_DFS(void)
{
    int nNodeCount = 4;
    ArrayGraph *pGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);
    int *pVisitNodes = (int *)malloc(sizeof(int) * nNodeCount);     // 노드 방문여부 체크용 배열 변수

    if (ISNULL_ERROR(pGraph) || ISNULL_ERROR(pVisitNodes))
        return;
    
    addEdge(pGraph, 0, 1);
    addEdge(pGraph, 0, 2);
    addEdge(pGraph, 1, 3);
    
    memset(pVisitNodes, 0, sizeof(int) * nNodeCount);

    printf("pGraph's DFS\n");
    traversalDFS(pGraph, 0, pVisitNodes);       // 시작 노드를 0으로 깊이 우선 탐색(재귀함수) 호출(실행)

    deleteGraph(pGraph);
    free(pVisitNodes);
    return;
}
```
```c
bool traversalDFS(ArrayGraph *_pGraph_, int _nStartNode_, int *_pVisitNodes_)
{
    int nLoopCount = 0;
    if (ISNULL_ERROR(_pGraph_) || ISNULL_ERROR(_pVisitNodes_))
        return true;

    if ((_nStartNode_ > _pGraph_->nNodeCount) || (_nStartNode_ < 0))
        return true;

    _pVisitNodes_[_nStartNode_] = 1;
    printf("Node - [%d] (visit)\n", _nStartNode_);
    for (; nLoopCount < _pGraph_->nNodeCount; nLoopCount++)
    {
        // nLoopCount != _nStartNode_ : 현재 방문 중인 노드는 검색 대상에서 제외
        // 0 != getEdge(_pGraph_, _nStartNode_, nLoopCount) : _nStartNode_와 nLoopCount 노드가 연결되었는지 확인
        // 0 == _pVisitNodes_[nLoopCount]) : _nStartNode_와 연결된 nLoopCount 노드가 방문한적 있는 노드인지 확인
        // 위 조건 모두 충족할 때 탐색 함수 실행
        if ((nLoopCount != _nStartNode_) && (0 != getEdge(_pGraph_, _nStartNode_, nLoopCount)) && (0 == _pVisitNodes_[nLoopCount]))
        {
            traversalDFS(_pGraph_, nLoopCount, _pVisitNodes_);
        }
    }
    return false;
}
```
### 2.2. 깊이-우선 탐색의 알고리즘 성능
- 노드의 수가 n, 간선의 수가 m개인 그래프의 시간 복잡도
- 인접 행렬이냐 인접 리스트냐에 다라 성능이 달라진다.
- 인접 행렬인 경우 n개 노드를 방문하기 위해 n번 함수를 호출해야 하고,
- 함수 호출마다 n개의 다음 방문 노드를 찾기 때문에 $O(n^2)$의 성능을 보인다.
- 반면 인접 리스트로 구현된 경우 n개의 노드를 방문하는 동안 각 노드에 연결된 간선 정보만 확인하기 때문에 $O(m+n)$라고 한다.

## 3. 넓이-우선 탐색
- 다음 방문할 노드 선택 기준이 현재 방문한 노드가 아닌 이전에 방문했던 노드와 연결된 노드를 선택하는 알고리즘
- 선입선출(FIFO)방식의 큐(queue)를 이용해 구현할 수 있다.
### 3.1. 큐(queue) 활용
- 탐색 전 초기 설정
```c
void ex_BFS(void)
{
    int nNodeCount = 4;
    ArrayGraph *pGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);

    if (ISNULL_ERROR(pGraph))
        return;
    
    addEdge(pGraph, 0, 1);
    addEdge(pGraph, 0, 2);
    addEdge(pGraph, 1, 3);

    printf("pGraph: BFS\n");
    traversalBFS(pGraph, 0);    // 넓이-우선 탐색 함수 호출

    deleteGraph(pGraph);

    return;
}
```
- 넓이 우선 탐색 함수
```c
// 넓이 우선 탐색 그래프
bool traversalDFS(ArrayGraph *_pGraph_, int _nStartNode_)
{
    int nLoopCount = 0;
    int nNodeIndex = 0;
    queue *pQueue = NULL;
    node *pQueueNode = NULL;
    int *pVisitNode = NULL;

    if (ISNULL_ERROR(_pGraph_))     // 함수 인자가 NULL이면 함수 종료
        return true;

    pQueue = queue_Create();        // 넓이 우선 탐색을 위한 대기열 (queue) 생성
    pVisitNode = (int *)malloc(sizeof(int) * _pGraph_->nNodeCount);     // 노드 방문 여부 저장할 int 배열 동적 할당(노드 개수만큼 배열 생성)

    if (ISNULL_ERROR(pQueue) || ISNULL_ERROR(pVisitNode))               // 위 Queue 나 int 배열이 NULL (메모리 할당 실패)이면 함수 종료
        return;
    memset(pVisitNode, 0, sizeof(int) * _pGraph_->nNodeCount);          // int 배열 0으로 초기화

    pVisitNode[_nStartNode_] = 1;               // 시작 노드를 첫 방문 정보로 저장
    queue_enqueue(pQueue, (int)_nStartNode_);   // 시작 노드를 대기열에 추가

    while (pQueue->nCurrentCount > 0)           // 대기열에 값이 있으면 반복
    {
        pQueueNode = queue_dequeue(pQueue);     // 대기열에서 디큐(dequeue), pQueueNode에 저장

        if (pQueueNode != NULL)                 // pQueueNode에 값이 있으면
        {
            nNodeIndex = (int)pQueueNode->nodeData;         // 노드 방문 정보 출력
            printf("Node - [%d] (visit)\n", nNodeIndex);

            for (nLoopCount = 0; nLoopCount < _pGraph_->nNodeCount; nLoopCount++)       // 그래프의 노드 전체를 순회하도록 반복 설정
            {
                // nLoopCount != nNodeIndex : 순회 중인 노드가 현재 노드와 다른 노드이면 "참"
                // 0 != getEdge(_pGraph_, nNodeIndex, nLoopCount) : 순회 중인 노드와 현재 노드가 연결되어있으면 "참"
                // 0 == pVisitNode[nLoopCount] : 순회 중인 노드가 방문한적 없다면 "참"
                // 위 세 조건이 모두 "참"이면 조건 충족
                if ((nLoopCount != nNodeIndex) && (0 != getEdge(_pGraph_, nNodeIndex, nLoopCount)) && (0 == pVisitNode[nLoopCount]))
                {
                    pVisitNode[nLoopCount] = 1;             // 순회 중인 노드 방문 확인
                    queue_enqueue(pQueue, nLoopCount);      // 순회 중인 노드 대기열 추가
                }
            }
            free(pQueueNode);                   // 대기열에서 디큐(dequeue)한 노드 할당 해제
        }
    }
    queue_Delete(pQueue);       // 탐색 종료 후 사용 끝난 queue 할당 해제
    free(pVisitNode);           // 동적 할당한 int 배열 할당 해제

    return false;
}
```