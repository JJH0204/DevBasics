# Sorting (정렬)
> ### **핵심 항목(Key)의 대소 관계에 따라 데이터 집합을 일정한 순서로 줄지어 늘어서도록 바꾸는 작업**   
- 검색을 더 쉽게 하기 위한 사전 작업에 속함

## 1. 정렬 알고리즘의 안정성 (stable)
- 정렬 알고리즘은 안정된(stable) 알고리즘과 그렇지 않은 알고리즘으로 나눌 수 있다.
- 안정된 정렬이란 같은 값의 키를 가진 요소의 순서가 정렬 전후에도 유지되는 것을 의미한다.
> 예) 학번과 학점을 나타낸 표에서 학점을 기준으로 오름차순으로 정렬 시 동일한 학점일 경우 낮은 학번이 앞쪽에 배치되도록 한 것을 "안정된 정렬"이라 한다.   

## 2. 내부 정렬과 외부 정렬
- 책상에서 30장의 카드를 정리할 수 있지만 500장의 카드는 정리할 수 없듯,
- 하나의 배열에서 작업할 수 있는 경우 내부(internal) 정렬, 하나의 배열에서 작업할 수 없을 사이즈의 경우 외부(external) 정렬을 사용한다.
> **내부 정렬(Internal Sorting)**: 정렬할 모든 데이터를 하나의 배열에 저장할 수 있는 경우 사용되는 알고리즘   
> **외부 정렬(External Sorting)**: 정렬할 데이터가 많아 하나의 배열에 저장할 수 없는 경우 사용되는 알고리즘   
- 외부 정렬은 내부 정렬을 응용한 것으로, 외부 정렬을 구현하려변 작업을 위한 파일 등이 필요하고 알고리즘도 복잡하다.   
※ 모든 내부 정렬에 대한 것을 탐구한 후 외부 정렬 방법이 궁금하다면 그때 탐구해보자

## 3. 정렬 알고리즘의 핵심 요소
- [**교환**, **선택**, **삽입**] 이 세가지 이며 대부분의 정렬 알고리즘은 이 세가지 요소를 활용한다.

## 4. 정렬 알고리즘 테스트 환경
```C
// mainSortingArray.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeSorting.h"

/* 배열 중복 없는 랜덤 정수값으로 초기화 */
int *initRanArray(const int _nElements_);

/* 배열 전체 출력 */
bool printArray(const int *_pArray_, const int _nElements_);

/* 정렬 함수 */
void sortArray(int *_pArray_, const int _nElements_, void (*Sorting)(int *_pArray_, int _nElements_));

/* 정렬 예제 */
int main(int argc, char *argv[])
{
    int *pArray = NULL;
    int nElements = 10;

    printf("<Before> \n");
    pArray = initRanArray(nElements);
    printArray(pArray, nElements);

    printf("<After> \n");
    sortArray(pArray, nElements, bubble);
    printArray(pArray, nElements);

    free(pArray);
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
    return;
}
```
- main()에서 실행할 정렬 함수의 이름만 바꿔서 즉시 테스트가 가능하도록 함수 포인터로 구현

## 5. 단순 정렬 알고리즘([소스코드](../../source/DSNA/Sorting/includeSorting.c#L6))

|알고리즘(설명링크)|소스 링크|
|:--|:--|
|버블 정렬([링크](/markdown/Algorithm/Sorting/BubbleSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L6)
|단순 선택 정렬([링크](/markdown/Algorithm/Sorting/StraightSelectionSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L134)
|단순 삽입 정렬([링크](/markdown/Algorithm/Sorting/StraightInsertionSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L191)


### 5.1. 단순 정렬의 시간 복잡도
- 세가지 정렬(버블 정렬, 단순 선택 정렬, 단순 삽입 정렬)은 시간 복잡도가 $O(n^2)$로 효율이 좋지 않다.
- 아래 알고리즘은 위 세 정렬 알고리즘의 단점을 개선한 새로운 알고리즘을 서술한다.

## 6. 개선된 정렬 알고리즘([소스코드](../../source/DSNA/Sorting/includeSorting.c#L334))

|알고리즘(설명링크)|소스 링크|
|:--|:--|
|셸 정렬([링크](/markdown/Algorithm/Sorting/ShellSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L342)
|퀵 정렬([링크](/markdown/Algorithm/Sorting/QuickSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L395)
|병합 정렬([링크](/markdown/Algorithm/Sorting/MergeSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L926)
|힙 정렬([링크](/markdown/Algorithm/Sorting/HeapSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L342)
|도수 정렬([링크](/markdown/Algorithm/Sorting/FSort.md))|[소스코드 링크](../../source/DSNA/Sorting/includeSorting.c#L342)
