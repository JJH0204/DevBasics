#include "includeSorting.h"
#include <stdio.h>

void bubble(int *a, int n)
{
    int i, j, k, last;
    int nExchange = 0;

    k = n - 1; /* 패스 종료 지점 초기화 */
    /* 배열 시작부터 패스 */
    for (i = 0; i < n - 1; i++)
    {
        nExchange = 0;          /* 교환 횟수 체크를 위한 변수 초기화 */
        for (j = 0; j < k; j++) /* 패스 종료 지점 k까지 패스 진행*/
            if (a[j] > a[j + 1])
            {
                swapBubble(int, a[j], a[j + 1]);
                nExchange++; /* 교환 후 체크 */
                last = j;    /* 가장 최근에 교환이 이뤄진 인덱스 위치를 기억 */
            }
        k = last;           /* 기억하고 있던 위치를 패스 종료 지점으로 설정 */
        if (nExchange == 0) /* 교환이 이뤄지지 않으면 루프 탈출 */
            break;
    }

    // for (j = n - 1; j > i; j--) /* 배열 끝부터 패스 */
    //     if (a[j - 1] > a[j])
    //         swapBubble(int, a[j - 1], a[j]);
}

void COBubble(int *a, int n)
{
    int i, j;
    int exchange = 0, comparison = 0;
    int condition = 0;
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
                swapBubble(int, a[j], a[j + 1]);
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
/* PASE_01
08  -  10     09     03     04     02     05     07     01     06
08     10  +  09     03     04     02     05     07     01     06
08     09     10  +  03     04     02     05     07     01     06
08     09     03     10  +  04     02     05     07     01     06
08     09     03     04     10  +  02     05     07     01     06
08     09     03     04     02     10  +  05     07     01     06
08     09     03     04     02     05     10  +  07     01     06
08     09     03     04     02     05     07     10  +  01     06
08     09     03     04     02     05     07     01     10  +  06
08     09     03     04     02     05     07     01     06     10
PASE_02
08  -  09     03     04     02     05     07     01     06     10
08     09  +  03     04     02     05     07     01     06     10
08     03     09  +  04     02     05     07     01     06     10
08     03     04     09  +  02     05     07     01     06     10
08     03     04     02     09  +  05     07     01     06     10
08     03     04     02     05     09  +  07     01     06     10
08     03     04     02     05     07     09  +  01     06     10
08     03     04     02     05     07     01     09  +  06     10
08     03     04     02     05     07     01     06     09     10
PASE_03
08  +  03     04     02     05     07     01     06     09     10
03     08  +  04     02     05     07     01     06     09     10
03     04     08  +  02     05     07     01     06     09     10
03     04     02     08  +  05     07     01     06     09     10
03     04     02     05     08  +  07     01     06     09     10
03     04     02     05     07     08  +  01     06     09     10
03     04     02     05     07     01     08  +  06     09     10
03     04     02     05     07     01     06     08     09     10
PASE_04
03  -  04     02     05     07     01     06     08     09     10
03     04  +  02     05     07     01     06     08     09     10
03     02     04  -  05     07     01     06     08     09     10
03     02     04     05  -  07     01     06     08     09     10
03     02     04     05     07  +  01     06     08     09     10
03     02     04     05     01     07  +  06     08     09     10
03     02     04     05     01     06     07     08     09     10
PASE_05
03  +  02     04     05     01     06     07     08     09     10
02     03  -  04     05     01     06     07     08     09     10
02     03     04  -  05     01     06     07     08     09     10
02     03     04     05  +  01     06     07     08     09     10
02     03     04     01     05  -  06     07     08     09     10
02     03     04     01     05     06     07     08     09     10
PASE_06
02  -  03     04     01     05     06     07     08     09     10
02     03  -  04     01     05     06     07     08     09     10
02     03     04  +  01     05     06     07     08     09     10
02     03     01     04  -  05     06     07     08     09     10
02     03     01     04     05     06     07     08     09     10
PASE_07
02  -  03     01     04     05     06     07     08     09     10
02     03  +  01     04     05     06     07     08     09     10
02     01     03  -  04     05     06     07     08     09     10
02     01     03     04     05     06     07     08     09     10
PASE_08
02  +  01     03     04     05     06     07     08     09     10
01     02  -  03     04     05     06     07     08     09     10
01     02     03     04     05     06     07     08     09     10
PASE_09
01  -  02     03     04     05     06     07     08     09     10
01     02     03     04     05     06     07     08     09     10
Number of comparisons: 45
Number of exchanges: 30*/

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
                    swapBubble(int, a[nLoopCount - 1], a[nLoopCount]);
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
                    swapBubble(int, a[nLoopCount], a[nLoopCount + 1]);
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
