#include "includeSorting.h"

void bubble(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--) /* 배열 끝 부터 패스 */
            if (a[j - 1] > a[j])
                swapBubble(int, a[j - 1], a[j]);
}