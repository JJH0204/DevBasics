// arrayGraph.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "includeArrayGraph.h"

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

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