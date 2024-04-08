// arrayGraph.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "includeArrayGraph.h"

// bool isNull(const void *ptr, const char *funcName)
// {
//     if (ptr == NULL)
//     {
//         printf("%s: Null Memory Access Error\n", funcName);
//         return true;
//     }
//     return false;
// }

ArrayGraph *createArrayGraph(const int _nGraphType_, const int _nNodeCount_)
{
    int nLoopCount = 0;
    ArrayGraph *pResult = NULL;

    // DirectArrayGraph 메모리 할당 및 검증
    pResult = (ArrayGraph *)malloc(sizeof(ArrayGraph));
    if (ISNULL_ERROR(pResult))
        return NULL;

    // 1차원 배열을 저장할 포인터 변수를 할당 및 검증
    pResult->nGraphType = _nGraphType_; // 추가 사항
    pResult->nNodeCount = _nNodeCount_;
    pResult->ppEdge = (int **)malloc(sizeof(int *) * _nNodeCount_);
    if (ISNULL_ERROR(pResult->ppEdge))
    {
        free(pResult);
        return NULL;
    }

    // 행 별로 메모리를 할당하고 검증
    for (nLoopCount = 0; nLoopCount < _nNodeCount_; nLoopCount++)
    {
        // 메모리 할당 시도
        pResult->ppEdge[nLoopCount] = (int *)malloc(sizeof(int) * _nNodeCount_);
        // 메모리 할당 실패
        if (ISNULL_ERROR(pResult->ppEdge[nLoopCount]))
        {
            for (nLoopCount = nLoopCount - 1; nLoopCount >= 0; nLoopCount--)
                free(pResult->ppEdge[nLoopCount]);
            free(pResult);
            return NULL;
        }

        // 할당 성공 시 0으로 초기화: 간선정보가 없는 상태로 세팅
        memset(pResult->ppEdge[nLoopCount], 0, sizeof(int) * _nNodeCount_);
    }
    return pResult;
}

bool addEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    bool bResult = true;
    if (ISNULL_ERROR(_pGraph_))
        return true;

    bResult = addEdgeInternal(_pGraph_, _nFrom_, _nTo_);
    if (false == bResult && UNDIRECT_TYPE == _pGraph_->nGraphType) // 무방향 그래프 일 경우 대칭 위치에 간선 추가
        bResult = addEdgeInternal(_pGraph_, _nTo_, _nFrom_);
    return bResult;
}

bool addEdgeInternal(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    _pGraph_->ppEdge[_nFrom_][_nTo_] = 1;
    return false;
}

bool checkVertexValid_ERROR(ArrayGraph *_pGraph_, int nNode)
{
    // 유효성 점검 || 노드가 노드 최대 보다 큰 위치 || 노드가 0 보다 낮은 위치
    if (ISNULL_ERROR(_pGraph_) || nNode >= _pGraph_->nNodeCount || nNode < 0)
        return true;

    return false;
}

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

int getEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) && checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    return _pGraph_->ppEdge[_nFrom_][_nTo_];
}

void displayGraph(ArrayGraph *_pGraph_)
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

bool deleteGraph(ArrayGraph *_pGraph_)
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

// 깊이 우선 탐색 그래프
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
// 깊이 우선 탐색 알고리즘 반복문으로 구현
bool traversalDFS_Loop(ArrayGraph *_pGraph_, int _nStartNode_)
{
    int nLoopCount = 0;
    stack *pStack = NULL;
    intptr_t nNodeData = 0;
    int *pVisitList = NULL;

    if (ISNULL_ERROR(_pGraph_) || (_nStartNode_ > _pGraph_->nNodeCount) || (_nStartNode_ < 0))
        return true;

    pStack = stack_Create();
    pVisitList = (int *)malloc(sizeof(int) * _pGraph_->nNodeCount);
    if (ISNULL_ERROR(pStack) || ISNULL_ERROR(pVisitList))
        return true;
    memset(pVisitList, 0, sizeof(int) * _pGraph_->nNodeCount);
    stack_Push(pStack, (void *)(intptr_t)_nStartNode_);
    pVisitList[_nStartNode_] = 1;

    while (pStack->nCurrentCount > 0)
    {
        nNodeData = (intptr_t)stack_Pop(pStack);
        if (nNodeData > -1)
        {
            printf("Node - [%d] (visit)\n", nNodeData);

            for (nLoopCount = _pGraph_->nNodeCount - 1; nLoopCount > -1; nLoopCount--)      // 스텍에 push하는 순서를 역순으로 한다.
            {
                if ((nLoopCount != nNodeData) && (0 != getEdge(_pGraph_, nNodeData, nLoopCount)) && (0 == pVisitList[nLoopCount]))
                {
                    pVisitList[nLoopCount] = 1;                          // 순회 중인 노드 방문 확인
                    stack_Push(pStack, (void *)(intptr_t)nLoopCount);    // 순회 중인 노드 추가
                }
            }
        }
    }
    stack_Delete(pStack);
    free(pVisitList);

    return false;
}

// 넓이 우선 탐색 그래프
bool traversalBFS(ArrayGraph *_pGraph_, int _nStartNode_)
{
    int nLoopCount = 0;
    intptr_t nNodeData = 0;
    queue *pQueue = NULL;
    int *pVisitNode = NULL;

    if (ISNULL_ERROR(_pGraph_)) // 함수 인자가 NULL이면 함수 종료
        return true;

    pQueue = queue_Create();                                        // 넓이 우선 탐색을 위한 대기열 (queue) 생성
    pVisitNode = (int *)malloc(sizeof(int) * _pGraph_->nNodeCount); // 노드 방문 여부 저장할 int 배열 동적 할당(노드 개수만큼 배열 생성)

    if (ISNULL_ERROR(pQueue) || ISNULL_ERROR(pVisitNode)) // 위 Queue 나 int 배열이 NULL (메모리 할당 실패)이면 함수 종료
        return true;
    memset(pVisitNode, 0, sizeof(int) * _pGraph_->nNodeCount); // int 배열 0으로 초기화

    pVisitNode[_nStartNode_] = 1;                          // 시작 노드를 첫 방문 정보로 저장
    queue_enqueue(pQueue, (void *)(intptr_t)_nStartNode_); // 시작 노드를 대기열에 추가

    while (pQueue->nCurrentCount > 0) // 대기열에 값이 있으면 반복
    {
        nNodeData = (intptr_t)queue_dequeue(pQueue); // 대기열에서 디큐(dequeue)

        if (nNodeData > -1) // 대기열에 가져온 값이 음수가 아니면 진행
        {
            printf("Node - [%d] (visit)\n", nNodeData); // 노드 방문 정보 출력

            for (nLoopCount = 0; nLoopCount < _pGraph_->nNodeCount; nLoopCount++) // 그래프의 노드 전체를 순회하도록 반복 설정
            {
                // nLoopCount != nNodeData : 순회 중인 노드가 현재 노드와 다른 노드이면 "참"
                // 0 != getEdge(_pGraph_, nNodeData, nLoopCount) : 순회 중인 노드와 현재 노드가 연결되어있으면 "참"
                // 0 == pVisitNode[nLoopCount] : 순회 중인 노드가 방문한적 없다면 "참"
                // 위 세 조건이 모두 "참"이면 조건 충족
                if ((nLoopCount != nNodeData) && (0 != getEdge(_pGraph_, nNodeData, nLoopCount)) && (0 == pVisitNode[nLoopCount]))
                {
                    pVisitNode[nLoopCount] = 1;                          // 순회 중인 노드 방문 확인
                    queue_enqueue(pQueue, (void *)(intptr_t)nLoopCount); // 순회 중인 노드 대기열 추가
                }
            }
        }
    }
    queue_Delete(pQueue); // 탐색 종료 후 사용 끝난 queue 할당 해제
    free(pVisitNode);     // 동적 할당한 int 배열 할당 해제

    return false;
}