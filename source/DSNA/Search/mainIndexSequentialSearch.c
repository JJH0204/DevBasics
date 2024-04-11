#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 인덱스 테이블 구조체
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

    pResult = (SimpleIndex *)malloc(sizeof(SimpleIndex) * _nIndexSize_); // 인덱스 사이즈 만큼 인덱스 테이블 생성
    if (pResult == NULL)
        return NULL;

    for (; nLoopCount < _nIndexSize_; nLoopCount++) // 인덱스 테이블 값 초기화
    {
        pResult[nLoopCount].nIndex = nLoopCount * nRatio;         // 인덱스 테이블[nLoopCount]에 배열의 인덱스 저장
        pResult[nLoopCount].nKey = _pArray_[nLoopCount * nRatio]; // 저장한 배열의 인덱스 값이 가리키는 배열 값 저장
    }
    return pResult;
}

// 범위 탐색 함수(탐색 성공 시 찾은 데이터 위치, 실패 시 -1 반환)
int sequentialRangeSearch(int _pArray_[], int _nStartIndex_, int _nEndIndex_, int _nKey_)
{
    int nLoopCount = 0;
    int nArraySize = sizeof(_pArray_) / sizeof(int);

    // 유효성 점검 (부분 탐색 시작, 종료 부분이 배열 범위 밖이면 종료)
    if ((_pArray_ == NULL) || (_nStartIndex_ < 0) || (_nStartIndex_ > nArraySize) || (_nEndIndex_ < 0) || (_nEndIndex_ > nArraySize))
        return -1;

    nLoopCount = _nStartIndex_;                                            // 탐색 시작 Index 저장
    while ((nLoopCount <= _nEndIndex_) && (_pArray_[nLoopCount] < _nKey_)) // Key 값을 찾으며 시작 인덱스에서 종료 인덱스 순으로 순차 탐색
        nLoopCount++;
    if (nLoopCount <= _nEndIndex_ && _pArray_[nLoopCount] == _nKey_) // 반복이 종료되고 nLoopCount 값을 인덱스로 배열에 저장된 값이 찾던 키 값인지 확인
        return nLoopCount;
    return -1;
}

// 색인 순차 검색 함수
int searchSequentialIndex(int _pArray_[], int _nSize_, SimpleIndex _pIndexTable_[], int _nIndexSize_, int _nKey_)
{
    int nLoopCount = 0, nStartIndex = 0, nEndIndex = 0;

    if (_nKey_ >= _pArray_[0] && _nKey_ <= _pArray_[_nSize_ - 1]) // 찾는 키 값이 배열의 범위에 속하는지 확인
    {
        for (nLoopCount = 0; nLoopCount < _nIndexSize_; nLoopCount++) // 인덱스 테이블을 순회하며 찾는 키 값 보다 큰 인덱스 번호를 찾는다.
        {
            if (_pIndexTable_[nLoopCount].nKey > _nKey_)
                break;
        }
        if (nLoopCount < _nIndexSize_) // 어디까지 탐색했는가? (인덱스 테이블을 끝까지 탐색하지 않았다면)
        {
            nStartIndex = _pIndexTable_[nLoopCount - 1].nIndex; // 시작 인덱스를 인덱스 테이블에서 찾은 인덱스의 이전 인덱스 값으로 지정
            nEndIndex = _pIndexTable_[nLoopCount].nIndex - 1;   // 종료 인덱스를 인덱스 테이블에서 찾은 인덱스로 하되 1감소
            // (왜? 종료 인덱스는 이미 찾는 키 값보다 큰 것을 알기 때문에 반복 횟수를 줄인다.)
        }
        else
        {
            nStartIndex = _pIndexTable_[nLoopCount - 1].nIndex; // 인덱스 테이블 끝까지 탐색했다면, 시작 인덱스를 인덱스 테이블의 마지막 인덱스 값으로
            nEndIndex = _nSize_ - 1;                            // 종료 인덱스를 원-데이터의 마지막 인덱스로 지정
        }
        return sequentialRangeSearch(_pArray_, nStartIndex, nEndIndex, _nKey_); // 지정된 시작, 종료 인덱스를 기준으로 부분 탐색 진행 후 결과 값 반환
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