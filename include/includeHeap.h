// includeHeap.h
#ifndef _HEAP_
#define _HEAP_

typedef struct HEAPNODE
{
    int nData;
} heapNode;

typedef struct ARRAYHEAP
{
    int nMaxCount;          // 배열 리스트에 최대 저장 가능한 데이터 수 
    int nCurrentCount;      // 현재 배열에 저장된 원소의 개수를 저장, 배열의 마지막 원소의 인덱스 위치 = nMaxCount
    heapNode *pArray;       // 배열 첫 시작
} arrayMaxHeap, arrayMinHeap;

arrayMaxHeap *createArrayMaxHeap(const int _nMaxCount_);
bool insertArrayMaxHeap(arrayMaxHeap *_pHeap_, const int _nVal_);
heapNode *removeArrayMaxHeap(arrayMaxHeap *_pHeap_);
bool deleteArrayMaxHeap(arrayMaxHeap *_pHeap_);
bool displayArrayHeap(arrayMaxHeap *_pHeap_);
#endif