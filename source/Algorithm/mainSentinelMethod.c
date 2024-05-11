#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 0~10 범위의 의사 난수로 배열 초기화
int *initArrayRand(int _nArraySize_);

// 배열 전체를 출력하며 강조할 요소를 강조, 강조할 요소가 없다면 -1
bool printAllArrayWithHighlight(int *_pArray_, int _nArraySize_, int _nHighlighting_);

// 보초법탐색
int SearchSentinel(int *_pArray_, int _nArraySize_, int _nKey_);

// 탐색 과정 출력
int SearchSentinelDetail(int *_pArray_, int _nArraySize_, int _nKey_);

// 배열 출력
bool printArray(int *_pArray_, int _nArraySize_);

// 배열 스캔과정 출력
bool printScanProcedure(int _nArraySize_, int _nHighlighting_);

// 키 값이 같은 인덱스 번호를 배열에 저장하고 그 수량을 반환
int checkDuplicate(const int *_pArray_, int _nArraySize_, int _nKey_, int *_pIndexArray_);

// main
int main(int argc, char *argv[])
{
    int nArraySize = 10;
    int nDuplicateCount = 0;
    int *pIndexArray = (int *)calloc(nArraySize, sizeof(int));
    int *pArray = initArrayRand(nArraySize);
    printAllArrayWithHighlight(pArray, nArraySize, SearchSentinelDetail(pArray, nArraySize, 5));
    nDuplicateCount = checkDuplicate(pArray, nArraySize, 5, pIndexArray);
    printf("duplicate: %02d\n", nDuplicateCount);
    printArray(pIndexArray, nDuplicateCount - 1);
    free(pArray);
    free(pIndexArray);
    return 0;
}

int *initArrayRand(int _nArraySize_)
{
    int nLoopCount = 0;
    int *pResult = NULL;

    if (_nArraySize_ < 1)
        return NULL;

    pResult = (int *)calloc(_nArraySize_ + 1, sizeof(int)); // 보초법을 위해 배열 사이즈 + 1 만큼 메모리 할당

    if (pResult == NULL)
        return NULL;

    srand(time(NULL));
    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
        pResult[nLoopCount] = rand() % 11;

    return pResult;
}

bool printAllArrayWithHighlight(int *_pArray_, int _nArraySize_, int _nHighlighting_)
{
    int nLoopCount = 0;
    if (_pArray_ == NULL)
        return true;

    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
    {
        printf("[%02d]-%02d ", nLoopCount, _pArray_[nLoopCount]);
        if (nLoopCount == _nHighlighting_)
            printf("(twinkle~)");
        printf("\n");
    }
    return false;
}

int SearchSentinel(int *_pArray_, int _nArraySize_, int _nKey_)
{
    int nLoopCount = 0;
    if (_pArray_ == NULL)
        return -1;

    _pArray_[_nArraySize_] = _nKey_; // 보초 설정

    while (_pArray_[nLoopCount] != _nKey_)
        nLoopCount++;

    if (nLoopCount == _nArraySize_) // 보초인지 검사
        return -1;
    return nLoopCount;
}

int SearchSentinelDetail(int *_pArray_, int _nArraySize_, int _nKey_)
{
    int nLoopCount = 0;
    if (_pArray_ == NULL)
        return -1;

    _pArray_[_nArraySize_] = _nKey_; // 보초 설정

    printf("\t|");
    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
        printf("%02d\t", nLoopCount);
    printf("(Sentinel)\n");
    printf("-----------------------------------------------------\n");

    nLoopCount = -1;
    do
    {
        nLoopCount++;
        printf("\t|");
        printScanProcedure(_nArraySize_, nLoopCount);
        printf("%02d\t|", nLoopCount);
        printArray(_pArray_, _nArraySize_);
        printf("\n");
    } while (_pArray_[nLoopCount] != _nKey_);

    if (nLoopCount == _nArraySize_) // 보초인지 검사
        return -1;
    return nLoopCount;
}

bool printScanProcedure(int _nArraySize_, int _nHighlighting_)
{
    int nLoopCount = 0;

    if (_nArraySize_ < 1)
        return true;

    for (nLoopCount = 0; nLoopCount <= _nArraySize_; nLoopCount++)
    {
        if (nLoopCount == _nHighlighting_)
            printf("*");
        printf("\t");
    }
    printf("\n");
    return false;
}

bool printArray(int *_pArray_, int _nArraySize_)
{
    int nLoopCount = 0;

    if (_pArray_ == NULL || _nArraySize_ < 1)
        return true;

    for (nLoopCount = 0; nLoopCount <= _nArraySize_; nLoopCount++)
        printf("%02d\t", _pArray_[nLoopCount]);
    printf("\n");
    return false;
}

int checkDuplicate(const int *_pArray_, int _nArraySize_, int _nKey_, int *_pIndexArray_)
{
    int nLoopCount = 0;
    int nIndexArrayPos = 0;

    if (_pArray_ == NULL || _pIndexArray_ == NULL || _nArraySize_ < 1)
        return -1;

    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
    {
        if (_pArray_[nLoopCount] == _nKey_)
        {
            _pIndexArray_[nIndexArrayPos] = nLoopCount;
            nIndexArrayPos++;
        }
    }
    return nIndexArrayPos;
}