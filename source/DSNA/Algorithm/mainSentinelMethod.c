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

// main
int main(int argc, char *argv[])
{
    int nArraySize = 5;
    int *pArray = initArrayRand(nArraySize);
    printAllArrayWithHighlight(pArray, nArraySize, SearchSentinel(pArray, 5, 5));
    free(pArray);
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