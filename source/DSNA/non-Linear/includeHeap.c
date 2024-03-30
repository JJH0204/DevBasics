// includeHeap.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeHeap.h"

arrayMaxHeap *createArrayMaxHeap(const int _nMaxCount_)
{
    arrayMaxHeap *pResult = NULL;
    if (_nMaxCount_ <= 0) // 인자 유효성 점검
    {
        printf("최대 원소 개수는 0보다 커야 한다.\n");
        return pResult;
    }
    pResult = (arrayMaxHeap *)malloc(sizeof(arrayMaxHeap)); // 최대 히프 생성(메모리 할당)
    if (pResult == NULL)
        return pResult;

    pResult->nMaxCount = _nMaxCount_; // 값 초기화
    pResult->nCurrentCount = 0;
    pResult->pArray = (heapNode *)malloc(sizeof(heapNode) * (_nMaxCount_ + 1)); // 인자 값 + 1 배열 생성
    if (pResult->pArray == NULL)
    {
        free(pResult);
        return NULL;
    }

    return pResult;
}

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
        if (nChildIndex < _pHeap_->nCurrentCount && _pHeap_->pArray[nChildIndex].nData < _pHeap_->pArray[nChildIndex + 1].nData)
            nChildIndex++;
        if (pTemp->nData >= _pHeap_->pArray[nChildIndex].nData)
            break;
        _pHeap_->pArray[nParentIndex] = _pHeap_->pArray[nChildIndex];
        nParentIndex = nChildIndex;
        nChildIndex *= 2;
    }
    _pHeap_->pArray[nParentIndex] = *pTemp;
    return pResult;
}

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