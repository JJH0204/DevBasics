#include "includeSorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----- 단순 정렬 알고리즘 ----- */

void bubble(int *a, int n)
{
    int i, j, k, last;
    int nExchange = 0;
    FUNC();
    k = n - 1; /* 패스 종료 지점 초기화 */
    /* 배열 시작부터 패스 */
    for (i = 0; i < n - 1; i++)
    {
        nExchange = 0;          /* 교환 횟수 체크를 위한 변수 초기화 */
        for (j = 0; j < k; j++) /* 패스 종료 지점 k까지 패스 진행*/
            if (a[j] > a[j + 1])
            {
                swap(int, a[j], a[j + 1]);
                nExchange++; /* 교환 후 체크 */
                last = j;    /* 가장 최근에 교환이 이뤄진 인덱스 위치를 기억 */
            }
        k = last;           /* 기억하고 있던 위치를 패스 종료 지점으로 설정 */
        if (nExchange == 0) /* 교환이 이뤄지지 않으면 루프 탈출 */
            break;
    }

    // for (j = n - 1; j > i; j--) /* 배열 끝부터 패스 */
    //     if (a[j - 1] > a[j])
    //         swap(int, a[j - 1], a[j]);
}

void COBubble(int *a, int n)
{
    int i, j;
    int exchange = 0, comparison = 0;
    int condition = 0;
    FUNC();

    for (i = 0; i < n - 1; i++)
    {
        printf("PASE_%02d\n", i + 1);
        condition = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            comparison++;
            printArrayA2B(a, &a[j]);
            printf("%02d  ", a[j]);
            if (a[j] > a[j + 1])
            {
                condition++;
                exchange++;
                printf("+  %02d     ", a[j + 1]);
                swap(int, a[j], a[j + 1]);
            }
            else
                printf("-  %02d     ", a[j + 1]);
            printArrayA2B(a + (j + 2), &a[n]);
            printf("\n");

            if (condition == 0)
                break;
        }
        printArrayA2B(a, &a[n]);
        printf("\n");
    }
    printf("Number of comparisons: %02d\nNumber of exchanges: %02d\n", comparison, exchange);
}

void printArrayA2B(int *a, int *b)
{
    int nLoopCount = 0;
    while (&a[nLoopCount] != b)
    {
        printf("%02d     ", a[nLoopCount]);
        nLoopCount++;
    }
}

/* 배열 정렬 여부 확인*/
int is_sorted(const int *a, int n)
{
    int nLoopCount = 0;
    if (a == NULL || n < 2)
        return 0;

    for (; nLoopCount < n - 1; nLoopCount++)
        if (a[nLoopCount] > a[nLoopCount + 1])
            return 0;
    return 1;
}

/* 양뱡향 버블 정렬*/
void cocktail(int *a, int n)
{
    int nPase = 0, nStart = 0, nEnd = n - 1, nLoopCount = 0, nLast = 0, nExchange = 0;

    FUNC();
    for (nPase = 0; nPase < n - 1; nPase++)
    {
        nExchange = 0;

        if ((nPase % 2) == 0) /* pase가 "짝수"라면*/
        {
            /* 배열의 끝부터 가장 작은 값을 찾아 앞으로 이동 */
            for (nLoopCount = nEnd; nLoopCount > nStart; nLoopCount--)
            {
                if (a[nLoopCount - 1] > a[nLoopCount])
                {
                    swap(int, a[nLoopCount - 1], a[nLoopCount]);
                    nLast = nLoopCount;
                    nExchange++;
                }
            }
            nStart = nLast;
        }
        else /* pase가 "홀수"라면*/
        {
            /* 배열의 시작부터 가장 큰은 값을 찾아 뒤으로 이동 */
            for (nLoopCount = nStart; nLoopCount < nEnd; nLoopCount++)
            {
                if (a[nLoopCount] > a[nLoopCount + 1])
                {
                    swap(int, a[nLoopCount], a[nLoopCount + 1]);
                    nLast = nLoopCount;
                    nExchange++;
                }
            }
            nEnd = nLast;
        }
        if (nExchange == 0)
            break;
    }
    return;
}

void selection(int *a, int n)
{
    int nLoop, nInLoop, nMin;
    if (a == NULL || n < 1)
        return;

    FUNC();

    for (nLoop = 0; nLoop < n - 1; nLoop++)
    {
        nMin = nLoop;
        for (nInLoop = nLoop + 1; nInLoop < n; nInLoop++)
            if (a[nInLoop] < a[nMin])
                nMin = nInLoop;
        if (nLoop != nMin)
            swap(int, a[nLoop], a[nMin]);
    }
}

void COselection(int *a, int n)
{
    /* 단순 선택 정렬 과정을 출력하며 정렬을 수행하는 함수*/
    int nLoop, nInLoop, nMin;

    int nCOLoopCount = 0;

    FUNC();
    /* 유효성 검사 */
    if (a == NULL || n < 1)
        return;

    /* 정렬 순회 루프 */
    for (nLoop = 0; nLoop < n - 1; nLoop++)
    {
        /* 가장 작은 값을 찾기 위해 순회 시작 인덱스를 시작으로 설정*/
        nMin = nLoop;

        for (nInLoop = nLoop + 1; nInLoop < n; nInLoop++)
            if (a[nInLoop] < a[nMin])
                nMin = nInLoop;

        /* 패스 과정 출력 */
        for (nCOLoopCount = 0; nCOLoopCount < n; nCOLoopCount++)
        {
            if (nLoop == nCOLoopCount)
                printf("*");
            else if (nMin == nCOLoopCount)
                printf("+");
            printf("\t");
        }
        printf("\n");
        for (nCOLoopCount = 0; nCOLoopCount < n; nCOLoopCount++)
            printf("%02d\t", a[nCOLoopCount]);
        printf("\n");

        /* 선택한 정렬되지 않은 배열의 가장 작은 값과 정렬되지 않은 배열의 가장 앞과 교환. 단, 서로 다른 인덱스일 때만*/
        if (nLoop != nMin)
            swap(int, a[nLoop], a[nMin]);
    }
}

void insertion(int *a, int n)
{
    int nLoop, nInLoop, nTemp;

    FUNC();
    for (nLoop = 1; nLoop < n; nLoop++)
    {
        /* 정렬할 값 선택 */
        nTemp = a[nLoop];

        /* 정렬할 위치 찾기(배열 시작 ~ 선택한 값 사이에서) */
        for (nInLoop = nLoop; nInLoop > 0 && a[nInLoop - 1] > nTemp; nInLoop--)
            a[nInLoop] = a[nInLoop - 1];
        a[nInLoop] = nTemp;
    }
}

void COinsertion(int *a, int n)
{
    int nLoop, nInLoop, nTemp;
    int nArrayPrint = 0;

    FUNC();
    for (nLoop = 1; nLoop < n; nLoop++)
    {
        /* 배열 출력 */
        for (nArrayPrint = 0; nArrayPrint < n; nArrayPrint++)
            printf("%02d\t", a[nArrayPrint]);
        printf("\n");

        /* 정렬할 값 선택 */
        nTemp = a[nLoop];

        /* 정렬할 위치 찾기(배열 시작 ~ 선택한 값 사이에서) */
        for (nInLoop = nLoop; nInLoop > 0 && a[nInLoop - 1] > nTemp; nInLoop--)
            a[nInLoop] = a[nInLoop - 1];

        if (nInLoop != nLoop)
            a[nInLoop] = nTemp;

        /* 과정 출력 */
        for (nArrayPrint = 0; nArrayPrint < n; nArrayPrint++)
        {
            if (nArrayPrint == nLoop)
                printf("+\t");
            else if (nArrayPrint == nInLoop)
                printf("^-------");
            else if (nArrayPrint < nLoop && nArrayPrint > nInLoop)
                printf("--------");
            else
                printf("\t");
        }
        printf("\n");
    }
}

int copy(int *pFrom, int *pTo, int nSize)
{
    int nLoop = 0;
    if (pFrom == NULL || pTo == NULL || nSize < 0)
        return -1;

    for (; nLoop < nSize; nLoop++)
        pTo[nLoop] = pFrom[nLoop];

    return 0;
}

void insertion_V2(int *a, int n)
{
    int nLoop, nInLoop, nTemp;
    FUNC();
    /* 보초 법을 위한 배열 복사 */
    int *pCapArray = NULL;

    if (a == NULL || n < 0)
        return;
    pCapArray = (int *)calloc(n + 1, sizeof(int));

    if (copy(a, pCapArray + 1, n) != 0)
        return;

    for (nLoop = 1; nLoop < n + 1; nLoop++)
    {
        /* 정렬할 값 선택 */
        nTemp = pCapArray[nLoop];
        pCapArray[0] = nTemp;

        /* 정렬할 위치 찾기(배열 시작 ~ 선택한 값 사이에서) */
        for (nInLoop = nLoop; pCapArray[nInLoop - 1] > nTemp; nInLoop--)
            pCapArray[nInLoop] = pCapArray[nInLoop - 1];

        if (nInLoop != nLoop)
            pCapArray[nInLoop] = nTemp;
    }

    copy(pCapArray + 1, a, n);
    free(pCapArray);
    return;
}
/*  정석은 대치법을 사용하기 위한 메모리 할당을 미리 끝낸 상태에서 위 함수를 호출하는 것이지,
    함수 내부에서 대치법을 위한 새로운 배열 할당을 실행하는 것은 알고리즘 성능을 저해한다.*/

/* 이진 삽입 정렬 */
void binInsertion(int *a, int n)
{
    int nTarget, nTemp, nSwapLoop, nBinSearchResult;
    if (a == NULL || n < 1)
        return;
    FUNC();
    for (nTarget = 1; nTarget < n; nTarget++)
    {
        nTemp = a[nTarget];
        nBinSearchResult = binSearch(a, nTarget, nTemp);

        // for (nSwapLoop = nTarget; nSwapLoop > 0 && nSwapLoop > nBinSearchResult; nSwapLoop--)
        //     a[nSwapLoop] = a[nSwapLoop - 1];

        /* 재정렬의 효율성 증가를 위해 표준 라이브러리 함수 memmove()사용 */
        if (nTarget > nBinSearchResult && nBinSearchResult >= 0)
        {
            memmove(a + nBinSearchResult + 1, a + nBinSearchResult, (nTarget - nBinSearchResult) * sizeof(int));
            a[nBinSearchResult] = nTemp;
        }
    }
    return;
}

int binSearch(const int *a, const int n, const int nVal)
{
    int nMiddle = 0, nStart = 0, nEnd = n;
    while (nStart <= nEnd)
    {
        nMiddle = (nStart + nEnd + 1) / 2;

        if (a[nMiddle] >= nVal && (a[nMiddle - 1] < nVal || nMiddle - 1 < 0))
            return nMiddle;
        else if (a[nMiddle] > nVal)
            nEnd = nMiddle - 1;
        else
            nStart = nMiddle + 1;
    }
    return -1;
}

/* ----- 개선 정렬 알고리즘 ----- */
/* 쉘 정렬 */
void shell(int *a, int n)
{
    int i, j, h, nTemp;

    FUNC();

    /* 증분값(h)이 서로 배수가 되지 않도록 초기값을 계산 */
    for (h = 1; h < n / 9; h = h * 3 + 1)
        ;

    /* 배열의 요소를 나눠 정렬*/
    for (; h > 0; h /= 3)
    {
        for (i = h; i < n; i++)
        {
            nTemp = a[i];

            /* 단순 삽입 정렬 수행, 선택한 요소와 비교하는 요소가 서로 이웃하지 않고 h만큼 떨어져 있다.*/
            for (j = i - h; j >= 0 && a[j] > nTemp; j -= h)
                a[j + h] = a[j];
            a[j + h] = nTemp;
        }
    }
    return;
}

