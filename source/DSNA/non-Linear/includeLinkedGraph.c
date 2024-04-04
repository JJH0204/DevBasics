// arrayGraph.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "includeLinkedGraph.h"
#include "includeGenericStructure.h"

LinkedGraph *createLinkedGraph(int _nGraphType_, const int _nNodeCount_)
{
    int nLoopCount = 0;
    LinkedGraph *pResult = NULL;

    // DirectArrayGraph 메모리 할당 및 검증
    pResult = (LinkedGraph *)malloc(sizeof(LinkedGraph));
    if (ISNULL_ERROR(pResult))
        return NULL;

    if (_nNodeCount_ <= 0)
    {
        printf("The maximum number of nodes must be greater than 0.\n");
        free(pResult);
        return NULL;
    }

    // 1차원 배열을 저장할 포인터 변수를 할당 및 검증
    pResult->nGraphType = _nGraphType_;
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

bool addEdge(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    bool bResult = true;
    // 유효성 점검
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return bResult;

    // 간선 정보 저장
    bResult = list_Add(_pGraph_->ppAdjEdge[_nFrom_], _nTo_);
    if (false == bResult && UNDIRECT_TYPE == _pGraph_->nGraphType)
        bResult = list_Add(_pGraph_->ppAdjEdge[_nTo_], _nFrom_);

    return bResult;
}

bool checkVertexValid_ERROR(LinkedGraph *_pGraph_, int nNode)
{
    // 유효성 점검 || 노드가 노드 최대 보다 큰 위치 || 노드가 0 보다 낮은 위치
    if (ISNULL_ERROR(_pGraph_) || nNode >= _pGraph_->nNodeCount || nNode < 0)
        return true;

    return false;
}

bool removeEdge(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_)
{
    list *pList = NULL;
    bool bResult = true;
    int nCount = 0, nLoopCount = 0;
    // 유효성 점검 // 두 노드가 안전한 위치에 있는지 점검
    if (ISNULL_ERROR(_pGraph_) || checkVertexValid_ERROR(_pGraph_, _nFrom_) || checkVertexValid_ERROR(_pGraph_, _nTo_))
        return true;

    pList = _pGraph_->ppAdjEdge[_nFrom_];
    nCount = pList->nCurrentCount;

    for (nLoopCount = 0; nLoopCount < nCount; nLoopCount++)
    {
        if (list_Get(pList, nLoopCount) == _nTo_)
        {
            // 간선 정보 삭제
            list_Remove(pList, nLoopCount);
            break;
        }
    }
    if (_pGraph_->nGraphType == UNDIRECT_TYPE)
    {
        pList = _pGraph_->ppAdjEdge[_nTo_];
        nCount = pList->nCurrentCount;

        for (nLoopCount = 0; nLoopCount < nCount; nLoopCount++)
        {
            if (list_Get(pList, nLoopCount) == _nFrom_)
            {
                // 간선 정보 삭제
                list_Remove(pList, nLoopCount);
                break;
            }
        }
    }

    return false;
}

int getEdge(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_)
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
        if (list_Get(pList, nLoopCount) == _nTo_)
        {
            return 1;
        }
    }
    return 0;
}

void displayGraph(LinkedGraph *_pGraph_)
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

bool deleteGraph(LinkedGraph *_pGraph_)
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