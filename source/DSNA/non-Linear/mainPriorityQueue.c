// mainMaxHeap.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "includeHeap.h"

bool heapAscendingSort(int _arrayVal_[], const int count);
bool heapDescendingSort(int _arrayVal_[], const int _nCount_);
bool printArray(const int _arrayVal_[], const int _nCount_);

int main(int argc, char *argv[])
{
    int arrayVal[] = {10, 50, 70, 80, 60, 20, 40, 30};
    printf("[Before Sort]\n\t> ");
    printArray(arrayVal, 8);

    heapAscendingSort(arrayVal, 8);

    printf("[Ascending Sort]\n\t> ");
    printArray(arrayVal, 8);

    heapDescendingSort(arrayVal, 8);

    printf("[Descending Sort]\n\t> ");
    printArray(arrayVal, 8);

    return 0;
}
/*.\heap.exe
[Before Sort]
        > 10 50 70 80 60 20 40 30
[Ascending Sort]
        > 80 70 60 50 40 30 20 10
[Descending Sort]
        > 10 20 30 40 50 60 70 80
*/

bool heapAscendingSort(int _arrayVal_[], const int _nCount_)
{
    int nIndex = 0;
    arrayMaxHeap *pHeap = NULL;
    heapNode *pNode = NULL;

    pHeap = createArrayHeap(10); // 히프 할당하고 검증
    if (pHeap == NULL)
        return true;
    for (; nIndex < _nCount_; nIndex++) // 전달 받은 데이터를 히프에 최대 히프 형태로 저장
        insertArrayMaxHeap(pHeap, _arrayVal_[nIndex]);
    for (nIndex = 0; nIndex < _nCount_; nIndex++) // 전달 받은 데이터 수 만큼 최대 히프에서 제거 연산 실행
    {
        pNode = removeArrayMaxHeap(pHeap);
        if (pNode != NULL)
        {
            _arrayVal_[nIndex] = pNode->nData;
            free(pNode);
        }
    }
    deleteArrayHeap(pHeap); // 최대 히프 메모리 할당 해제
    return false;
}

bool heapDescendingSort(int _arrayVal_[], const int _nCount_)
{
    int nIndex = 0;
    arrayMinHeap *pHeap = NULL;
    heapNode *pNode = NULL;

    pHeap = createArrayHeap(10); // 히프 할당하고 검증
    if (pHeap == NULL)
        return true;
    for (; nIndex < _nCount_; nIndex++) // 전달 받은 데이터를 히프에 최대 히프 형태로 저장
        insertArrayMinHeap(pHeap, _arrayVal_[nIndex]);
    for (nIndex = 0; nIndex < _nCount_; nIndex++) // 전달 받은 데이터 수 만큼 최대 히프에서 제거 연산 실행
    {
        pNode = removeArrayMinHeap(pHeap);
        if (pNode != NULL)
        {
            _arrayVal_[nIndex] = pNode->nData;
            free(pNode);
        }
    }
    deleteArrayHeap(pHeap); // 최대 히프 메모리 할당 해제
    return false;
}

bool printArray(const int _arrayVal_[], const int _nCount_)
{
    int nIndex = 0;
    for (; nIndex < _nCount_; nIndex++)
        printf("%d ", _arrayVal_[nIndex]);
    printf("\n");
}