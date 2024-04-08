#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct SimpleIndex
{
    int nIndex;
    int nKey;
} SimpleIndex;

// 인덱스 테이블 생성
SimpleIndex *createIndexTable(int _pArray_[], int _nSize_, int _nIndexSize_)
{
    SimpleIndex *pResult = NULL;
    int nLoopCount = 0, nRatio = 0;

    if ((_pArray_ == NULL) || (_nSize_ < 0) || (_nIndexSize_ < 0))
        return NULL;

    nRatio = _nSize_ / _nIndexSize_; // 인덱스 1개가 다뤄야 하는 평균적인 데이터 개수
    if (_nSize_ % _nIndexSize_ > 0)  // 나머지가 있는 경우 + 1
        nRatio += 1;

    pResult = (SimpleIndex *)malloc(sizeof(SimpleIndex) * _nIndexSize_);
    if (pResult == NULL)
        return NULL;

    for (; nLoopCount < _nIndexSize_; nLoopCount++)
    {
        pResult[nLoopCount].nIndex = nLoopCount * nRatio;
        pResult[nLoopCount].nKey = _pArray_[nLoopCount * nRatio];
    }
    return pResult;
}

// 범위 탐색 함수(탐색 성공 시 찾은 데이터 위치, 실패 시 -1 반환)
int sequentialRangeSearch(int _pArray_[], int _nStartIndex_, int _nEndIndex_, int _nKey_)
{
    int nLoopCount = 0;
    for (nLoopCount = _nStartIndex_; (nLoopCount <= _nEndIndex_) && (_pArray_[nLoopCount] < _nKey_); nLoopCount++)
    {
        /* do nothing */
    }
    if (nLoopCount <= _nEndIndex_ && _pArray_[nLoopCount] == _nKey_)
        return nLoopCount;
    return -1;
}

// 색인 순차 검색 함수
int searchSequentialIndex(int _pArray_[], int _nSize_, SimpleIndex _pIndexTable_[], int _nIndexSize_, int _nKey_)
{
    int nLoopCount = 0, nStartIndex = 0, nEndIndex = 0;

    if (_nKey_ >= _pArray_[0] && _nKey_ <= _pArray_[_nSize_ - 1])
    {
        for (nLoopCount = 0; nLoopCount < _nIndexSize_; nLoopCount++)
        {
            if (_pIndexTable_[nLoopCount].nKey > _nKey_)
                break;
        }
        if (nLoopCount < _nIndexSize_)
        {
            nStartIndex = _pIndexTable_[nLoopCount - 1].nIndex;
            nEndIndex = _pIndexTable_[nLoopCount].nIndex - 1;
        }
        else
        {
            nStartIndex = _pIndexTable_[nLoopCount - 1].nIndex;
            nEndIndex = _nSize_ - 1;
        }
        return sequentialRangeSearch(_pArray_, nStartIndex, nEndIndex, _nKey_);
    }
    return -1;
}

// 인덱스 테이블 출력
bool printIndexTable(SimpleIndex *_pIndexTable_, int _nIndexSize_)
{
    int nLoopCount = 0;
    if (_pIndexTable_ == NULL || _nIndexSize_ < 0)
        return true;

    printf("> Index Table\n");
    printf("Index\t|Key\n");
    printf("---------------\n");
    for (nLoopCount = 0; nLoopCount < _nIndexSize_; nLoopCount++)
        printf("%d\t|%d\n", _pIndexTable_[nLoopCount].nIndex, _pIndexTable_[nLoopCount].nKey);
    return false;
}

// 배열 출력
bool printArray(int _pArray_[], int _nSize_)
{
    int nLoopCount = 0;

    if (_pArray_ == NULL || _nSize_ < 0)
        return true;

    printf("Index\t|Key\n");
    printf("---------------\n");
    for (nLoopCount = 0; nLoopCount < _nSize_; nLoopCount++)
        printf("%d\t|%d\n", nLoopCount, _pArray_[nLoopCount]);
    return false;
}

int main(int argc, char *argv[])
{
    SimpleIndex *pIndexTable = NULL;
    int nIndex = 0, nKey = 0;
    int ascSortArray[] = {10, 20, 50, 60, 70, 80};
    int nArraySize = sizeof(ascSortArray) / sizeof(int);
    int nIndexSize = nArraySize / 2;

    printArray(ascSortArray, nArraySize);
    pIndexTable = createIndexTable(ascSortArray, nArraySize, nIndexSize);
    if (pIndexTable == NULL)
        return -1;
    
    printIndexTable(pIndexTable, nIndexSize);
    nKey = 60;
    nIndex = searchSequentialIndex(ascSortArray, nArraySize, pIndexTable, nIndexSize, nKey);
    if (nIndex >= 0)
        printf("Key-%d, Index-%d\n", nKey, nIndex);
    else
        printf("Key-%d, Search Fail\n", nKey);

    nKey = 65;
    nIndex = searchSequentialIndex(ascSortArray, nArraySize, pIndexTable, nIndexSize, nKey);
    if (nIndex >= 0)
        printf("Key-%d, Index-%d\n", nKey, nIndex);
    else
        printf("Key-%d, Search Fail\n", nKey);

    free(pIndexTable);
    return 0;
}
/*.\SequentialIndexSearch.exe
Index   |Key
---------------
0       |10
1       |20
2       |50
3       |60
4       |70
5       |80
> Index Table
Index   |Key
---------------
0       |10
2       |50
4       |70
Key-60, Index-3
Key-65, Search Fail*/