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

DirectArrayGraph *createDirectArrayGraph(int _nNodeCount_)
{
    int nLoopCount = 0;
    DirectArrayGraph *pResult = NULL;

    // DirectArrayGraph 메모리 할당 및 검증
	pResult = (DirectArrayGraph *)malloc(sizeof(DirectArrayGraph));
    if (ISNULL_ERROR(pResult))
        return NULL;
    
    // 1차원 배열을 저장할 포인터 변수를 할당 및 검증
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
    /*
    Function: createDirectArrayGraph, Line: 50
    Function: createDirectArrayGraph, Line: 60
    Function: createDirectArrayGraph, Line: 50
    Function: createDirectArrayGraph, Line: 60
    Function: createDirectArrayGraph, Line: 50
    Function: createDirectArrayGraph, Line: 60
    Function: createDirectArrayGraph, Line: 50
    Function: createDirectArrayGraph, Line: 60
    */
    return pResult;
}

bool addEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;
    
    // 간선 정보 저장
    _pGraph_->ppEdge[_nFrom_][_nTo_] = 1;
    return false;
}

bool checkVertexValid_ERROR(DirectArrayGraph *_pGraph_, int nNode)
{
    // 유효성 점검 || 노드가 노드 최대 보다 큰 위치 || 노드가 0 보다 낮은 위치
    if (ISNULL_ERROR(_pGraph_) || nNode >= _pGraph_->nNodeCount || nNode < 0)
        return true;

    return false;
}

bool removeEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_))
        return true;

    // 두 노드가 안전한 위치에 있는지 점검
    if (checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    // 간선 정보 삭제
    _pGraph_->ppEdge[_nFrom_][_nTo_] = 0;
    return false;
}

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