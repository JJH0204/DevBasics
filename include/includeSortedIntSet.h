/* int 데이터 타입의 집합 IntSet의 헤더 */
/* Point. 항상 오름차순으로 정렬을 유지한다. */
#ifndef __SORTEDINTSET__
#define __SORTEDINTSET__

#include <stdio.h>
#include <stdlib.h>

typedef struct intSet
{
    int nMaxSize;
    int nCount;
    int *Set;
} SortedIntSet;


#endif