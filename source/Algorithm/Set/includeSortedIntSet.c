/*
배열 안의 원소가 항상 오름차순을 유지하는 집합.
*/
#include "includeSortedIntSet.h"

/* 집합 초기화 함수 */
int Sorted_Initialize(SortedIntSet *s, int max)
{
    if (s == NULL || max < 1)
        return -1;

    s->nCount = 0;
    s->Set = (int *)calloc(max, sizeof(int));
    if (s->Set == NULL)
    {
        s->nMaxSize = 0;
        return -1;
    }
    s->nMaxSize = max;

    return 0;
}

int Sorted_IsMember(const SortedIntSet *s, int n)
{
    /* 배열이 오름차순으로 정렬되어 있음으로
    이를 활용해 탐색을 효율적으로 진행한다.*/
    int *pResult;
    
    if (s == NULL)
        return -2;
    pResult = (int *)bsearch(&n, s->Set, s->nCount, sizeof(int), Sorted_comp);
    if (pResult == NULL)
        return -1;
    return pResult - s->Set;
}

/* 비교 함수 */
int Sorted_comp(const void *a, const void *b)
{
    const int *pA = (const int *)a;
    const int *pB = (const int *)b;

    if (*pA == *pB)
        return 0;
    else if (*pA < *pB)
        return -1;
    else
        return 1;
}

/* 집합 s에 n 추가 */
void Sorted_Add(SortedIntSet *s, int n)
{
    if (s == NULL)
        return;
    if (Sorted_Capacity(s) > 0 && Sorted_IsMember(s, n) == -1)
        s->Set[s->nCount++] = n;
    qsort(s->Set, s->nCount, sizeof(int), Sorted_comp);
}

/* 집합 s에 n 제거 */
void Sorted_Remove(SortedIntSet *s, int n)
{
    int index;
    if (s == NULL)
        return;
    if ((index = Sorted_IsMember(s, n)) > -1)
    {
        s->Set[index] = s->Set[--s->nCount];
        qsort(s->Set, s->nCount, sizeof(int), Sorted_comp);
    }
}

/* 집합 s의 모든 원소 출력 */
void Sorted_Print(const SortedIntSet *s)
{
    int nLoop;
    if (s == NULL)
        return;

    printf("{ ");
    for (nLoop = 0; nLoop < s->nCount; nLoop++)
        printf("%d ", s->Set[nLoop]);
    printf("}");
}

/* 집합 s의 모든 원소 출력(줄 바꿈 문자 포함) */
void Sorted_PrintLn(const SortedIntSet *s)
{
    Sorted_Print(s);
    putchar('\n');
}

/* 집합 삭제 */
void Sorted_Terminate(SortedIntSet *s)
{
    if (s->Set != NULL)
    {
        free(s->Set);
        s->nMaxSize = s->nCount = 0;
    }
}

/* 집합 s2를 s1에 대입 */
void Sorted_Assign(SortedIntSet *s1, const SortedIntSet *s2)
{
    int nLoop;
    int nCopySize;
    if (s1 == NULL || s2 == NULL)
        return;
    if (s1->nMaxSize < s2->nCount)
        nCopySize = s1->nMaxSize;
    else
        nCopySize = s2->nCount;
    for (nLoop = 0; nLoop < nCopySize; nLoop++)
        s1->Set[nLoop] = s2->Set[nLoop];
    s1->nCount = nCopySize;
    return;
}

/* 집합 s에 추가 가능한 최대 원소 개수 반환 */
int Sorted_Capacity(const SortedIntSet *s)
{
    if (s == NULL)
        return -1;
    return s->nMaxSize - Sorted_Size(s);
}

/* 집합 s의 원소 개수 */
int Sorted_Size(const SortedIntSet *s)
{
    if (s == NULL)
        return -1;
    return s->nCount;
}

/* 두 집합이 같은지 확인 */
int Sorted_Equal(const SortedIntSet *s1, const SortedIntSet *s2)
{
    int nLoop;

    int *pSearch;

    if (s1 == NULL || s2 == NULL)
        return -1;
    if (Sorted_Size(s1) != Sorted_Size(s2))
        return 0;

    for (nLoop = 0; nLoop < s1->nCount; nLoop++)
    {
        pSearch = bsearch(s1->Set + nLoop, s2->Set, s2->nCount, sizeof(int), Sorted_comp);
        if (pSearch == NULL)
            return 0;
    }
    return 1;
}

/* 집합 s2와 s3의 합집합을 s1에 대입 */
SortedIntSet *Sorted_Union(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int nLoop;

    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;
    Sorted_Assign(s1, s2);
    for (nLoop = 0; nLoop < s3->nCount; nLoop++)
        Sorted_Add(s1, s3->Set[nLoop]);
    return s1;
}

/* 집합 s2와 s3의 교집합을 s1에 대입 */
SortedIntSet *Sorted_Intersection(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int nLoop;
    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;

    s1->nCount = 0;

    for (nLoop = 0; nLoop < s2->nCount; nLoop++)
        if (Sorted_IsMember(s3, s2->Set[nLoop]) > -1)
            Sorted_Add(s1, s2->Set[nLoop]);

    return s1;
}

/* 집합 s2와 s3의 차집합을 s1에 대입 */
SortedIntSet *Sorted_Difference(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3)
{
    int nLoop, nInLoop;
    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;

    s1->nCount = 0;
    for (nLoop = 0; nLoop < s2->nCount; nLoop++)
        if (Sorted_IsMember(s3, s2->Set[nLoop]) == -1)
            Sorted_Add(s1, s2->Set[nLoop]);
    return s1;
}