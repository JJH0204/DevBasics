#include "includeSorting.h"

/* 배열 중복 없는 랜덤 정수값으로 초기화 */
int *initRanArray(const int _nElements_);

/* 배열 전체 출력 */
bool printArray(const int *_pArray_, const int _nElements_);

/* 정렬 함수 */
void sortArray(int *_pArray_, const int _nElements_, void (*Sorting)(int *_pArray_, int _nElements_));

/* 정렬 함수 예제 */
void EX_main_Sorting();

/* 병합 정렬 예제 */
void EX_main_MargeSort();


/* 정렬 예제 */
int main(int argc, char *argv[])
{
    EX_main_Sorting();
    // EX_main_MargeSort();
    return 0;
}

/* 배열 중복 없는 랜덤 정수값으로 초기화 */
int *initRanArray(const int _nElements_)
{
    int nLoopCount = 0;
    int nInLoopCount = 0;
    int nRanElements = 0;
    int *pResult = NULL;

    /* 유효성 점검 */
    if (_nElements_ < 1)
        return NULL;

    /* 시드 설정 */
    srand(time(NULL));

    pResult = (int *)calloc(_nElements_, sizeof(int));

    if (pResult == NULL)
        return NULL;

    /* 중복되지 않은 정수 값으로 배열을 초기화 하는 과정 */
    for (nLoopCount = 0; nLoopCount < _nElements_; nLoopCount++)
    {
        nRanElements = 1 + rand() % _nElements_;
        for (nInLoopCount = 0; nInLoopCount < nLoopCount; nInLoopCount++)
        {
            if (pResult[nInLoopCount] == nRanElements)
            {
                nInLoopCount = -1;
                nRanElements = 1 + rand() % _nElements_;
            }
        }
        pResult[nLoopCount] = nRanElements;
    }

    return pResult;
}

/* 배열 전체 출력 */
bool printArray(const int *_pArray_, const int _nElements_)
{
    int nLoopCount = 0;

    if (_pArray_ == NULL || _nElements_ < 1)
        return true;

    /* 인덱스 출력 */
    printf("Index:\t");
    for (nLoopCount = 0; nLoopCount < _nElements_; nLoopCount++)
        printf("%02d\t", nLoopCount);
    printf("\n");

    /* 배열 요소 출력 */
    printf("Array:\t");
    for (nLoopCount = 0; nLoopCount < _nElements_; nLoopCount++)
        printf("%02d\t", _pArray_[nLoopCount]);
    printf("\n");

    return false;
}

/* 정렬 함수 */
void sortArray(int *_pArray_, const int _nElements_, void (*Sorting)(int *_pArray_, int _nElements_))
{
    if (_pArray_ == NULL || _nElements_ < 1)
        return;
    Sorting(_pArray_, _nElements_);
    // quick_RE(_pArray_, 0, _nElements_ - 1); /* 퀵 정렬 테스트를 위한 임시 코드 */
    return;
}

/* 정렬 함수 예제 */
void EX_main_Sorting()
{
    int *pArray = NULL;
    int nElements = 20; /* 배열 요소 개수 */

    printf("<Before> \n");
    pArray = initRanArray(nElements);
    printArray(pArray, nElements);

    printf("<After> \n");
    sortArray(pArray, nElements, mergeSort);   /* 정렬 함수 실행 */
    printArray(pArray, nElements);

    free(pArray);
}

/* 병합 정렬 예제 */
void EX_main_MargeSort()
{
    int *pArrayA = NULL, *pArrayB = NULL, *pArrayC = NULL;
    int nmembA = 10, nmembB = 5;

    printf("Array A:\n");
    pArrayA = initRanArray(nmembA);
    sortArray(pArrayA, nmembA, EX_qsort);
    printArray(pArrayA, nmembA);

    printf("Array B:\n");
    pArrayB = initRanArray(nmembB);
    sortArray(pArrayB, nmembB, EX_qsort);
    printArray(pArrayB, nmembB);

    printf("After Merge:\n");
    pArrayC = mergeArray(pArrayA, nmembA, pArrayB, nmembB);
    printArray(pArrayC, nmembA + nmembB);

    free(pArrayA);
    free(pArrayB);
    free(pArrayC);
    return;
}