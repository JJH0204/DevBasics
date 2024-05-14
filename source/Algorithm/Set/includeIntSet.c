#include "includeIntSet.h"
/* 집합 초기화 함수 */
int Initialize(IntSet *s, int max)
{
    if (s == NULL || max < 1)
        return -1;

    s->nCount = 0;
    s->pSet = (int *)calloc(max, sizeof(int));
    if (s->pSet == NULL)
    {
        s->nMaxSize = 0;
        return -1;
    }
    s->nMaxSize = max;

    return 0;
}

/* 집합 s에 n의 포함 여부 확인 */
int IsMember(const IntSet *s, int n)
{
    int nLoop;
    if (s != NULL)
        for (nLoop = 0; nLoop < s->nCount; nLoop++)
            if (s->pSet[nLoop] == n)
                return nLoop;
    return -1;
}

/* 집합 s에 n 추가 */
void Add(IntSet *s, int n)
{
    if (s == NULL)
        return;
    if (Capacity(s) > 0 && IsMember(s, n) == -1)
        s->pSet[s->nCount++] = n;
}

/* 집합 s에 n 제거 */
void Remove(IntSet *s, int n)
{
    int index;
    if (s == NULL)
        return;
    if ((index = IsMember(s, n)) != -1)
        s->pSet[index] = s->pSet[--s->nCount];
}

/* 집합 s에 추가 가능한 최대 원소 개수 반환 */
int Capacity(const IntSet *s)
{
    if (s == NULL)
        return -1;
    return s->nMaxSize - Size(s);
}

/* 집합 s의 원소 개수 */
int Size(const IntSet *s)
{
    if (s == NULL)
        return -1;
    return s->nCount;
}

/* 집합 s2를 s1에 대입 */
void Assign(IntSet *s1, const IntSet *s2)
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
        s1->pSet[nLoop] = s2->pSet[nLoop];
    s1->nCount = nCopySize;
    return;
}

/* 두 집합이 같은지 확인 */
int Equal(const IntSet *s1, const IntSet *s2)
{
    int nLoop, nInLoop;

    if (s1 == NULL || s2 == NULL)
        return -1;
    if (Size(s1) != Size(s2))
        return 0;

    for (nLoop = 0; nLoop < s1->nCount; nLoop++)
    {
        for (nInLoop = 0; nInLoop < s2->nCount; nInLoop++)
            if (s1->pSet[nLoop] == s2->pSet[nInLoop])
                break;
        if (nInLoop == s2->nCount)
            return 0;
    }
    return -1;
}

/* 집합 s2와 s3의 합집합을 s1에 대입 */
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
    int nLoop;

    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;
    Assign(s1, s2);
    for (nLoop = 0; nLoop < s3->nCount; nLoop++)
        Add(s1, s3->pSet[nLoop]);
    return s1;
}

/* 집합 s2와 s3의 교집합을 s1에 대입 */
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
    int nLoop, nInLoop;
    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;

    s1->nCount = 0;

    for (nLoop = 0; nLoop < s2->nCount; nLoop++)
        for (nInLoop = 0; nInLoop < s3->nCount; nInLoop++)
            if (s2->pSet[nLoop] == s3->pSet[nInLoop])
                Add(s1, s2->pSet[nLoop]);
    return s1;
}

/* 집합 s2와 s3의 차집합을 s1에 대입 */
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
    int nLoop, nInLoop;
    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;

    s1->nCount = 0;
    for (nLoop = 0; nLoop < s2->nCount; nLoop++)
    {
        for (nInLoop = 0; nInLoop < s3->nCount; nInLoop++)
            if (s2->pSet[nLoop] == s3->pSet[nInLoop])
                break;

        if (nInLoop == s3->nCount)
            Add(s1, s2->pSet[nLoop]);
    }
    return s1;
}

/* 집합 s의 모든 원소 출력 */
void Print(const IntSet *s)
{
    int nLoop;
    if (s == NULL)
        return;

    printf("{ ");
    for (nLoop = 0; nLoop < s->nCount; nLoop++)
        printf("%d ", s->pSet[nLoop]);
    printf("}");
}

/* 집합 s의 모든 원소 출력(줄 바꿈 문자 포함) */
void PrintLn(const IntSet *s)
{
    Print(s);
    putchar('\n');
}

/* 집합 삭제 */
void Terminate(IntSet *s)
{
    if (s->pSet != NULL)
    {
        free(s->pSet);
        s->nMaxSize = s->nCount = 0;
    }
}

/* 집합이 가득 찼다면 1. 아니면 0을 반환 */
int IsFull(const IntSet *s)
{
    if (s == NULL)
        return -1;
    if (s->nMaxSize == s->nCount)
        return 1;
    return 0;
}

/* 집합의 모든 원소를 삭제하는 함수 */
void Clear(IntSet *s)
{
    int nLoop;
    if (s == NULL)
        return;

    for (nLoop = s->nCount - 1; nLoop >= 0; nLoop--)
        s->pSet[nLoop] = 0;

    s->nCount = nLoop + 1;
    return;
}

/* 집합 s2, s3의 대칭 차를 s1에 대입하는 함수 */
IntSet *symmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
    /* 대칭차: 두 집합 가운데 정확히 하나에만 속하는 원소들의 집합 */
    int nLoop, nInLoop;

    if (s1 == NULL || s2 == NULL || s3 == NULL)
        return NULL;

    for (nLoop = 0; nLoop < s2->nCount; nLoop++)
    {
        for (nInLoop = 0; nInLoop < s3->nCount; nInLoop++)
            if (s2->pSet[nLoop] == s3->pSet[nInLoop])
                break;
        if (nInLoop == s3->nCount)
            Add(s1, s2->pSet[nLoop]);
    }

    for (nLoop = 0; nLoop < s3->nCount; nLoop++)
    {
        for (nInLoop = 0; nInLoop < s2->nCount; nInLoop++)
            if (s3->pSet[nLoop] == s2->pSet[nInLoop])
                break;
        if (nInLoop == s2->nCount)
            Add(s1, s3->pSet[nLoop]);
    }

    return s1;
}

/* 집합 s1에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환) */
IntSet *ToUnion(IntSet *s1, const IntSet *s2)
{
    // int *buff = NULL;
    int nLoop, nILoop;

    if (s1 == NULL || s2 == NULL)
        return NULL;

    /* 합집합을 넣자 */
    // s1->nMaxSize += s2->nMaxSize;
    // buff = (int *)calloc(s1->nMaxSize, sizeof(int));
    // for (nLoop= 0; nLoop < s1->nCount; nLoop++)
    // {
    //     for (nILoop = 0; nILoop < s2->nCount; nILoop++)
    //         if (s1->pSet[nLoop] == s2->pSet[nILoop])
    //             break;
    //     if (nILoop == s2->nCount)
    //         buff[nLoop] = s1->pSet[nLoop];
    // }
    for (nLoop = 0; nLoop < s2->nCount; nLoop++)
        Add(s1, s2->pSet[nLoop]);

    return s1;
}

/* 집합 s1에서 s2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환) */
IntSet *ToIntersection(IntSet *s1, const IntSet *s2)
{
    int nLoop, nILoop;

    if (s1 == NULL || s2 == NULL)
        return NULL;

    for (nLoop = 0; nLoop < s1->nCount; nLoop++)
    {
        for (nILoop = 0; nILoop < s2->nCount; nILoop++)
            if (s1->pSet[nLoop] == s2->pSet[nILoop])    /* 들어 있다면? */
                break;
        if (nILoop == s2->nCount) /* 들어 있지 않다면 */
            Remove(s1, s1->pSet[nLoop]);
    }
    return s1;
}

/* 집합 s1에서 s2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환) */
IntSet *ToDifference(IntSet *s1, const IntSet *s2)
{
    int nLoop, nILoop;

    if (s1 == NULL || s2 == NULL)
        return NULL;

    for (nLoop = 0; nLoop < s1->nCount; nLoop++)
    {
        for (nILoop = 0; nILoop < s2->nCount; nILoop++)
            if (s1->pSet[nLoop] == s2->pSet[nILoop]) /* 들어 있다면? */
            {
                Remove(s1, s1->pSet[nLoop]);
                nLoop--;
                break;
            }
    }
    return s1;
}

/* 집합 s1이 s2의 부분집합이면 1.아니면 0을 반환 */
int IsSubset(const IntSet *s1, const IntSet *s2)
{
    int nLoop;

    if (s1 == NULL || s2 == NULL)
        return -1;

    for (nLoop = 0; nLoop < s1->nCount; nLoop++)
        if (IsMember(s2, s1->pSet[nLoop]) == -1)
            return 0;
    return 1;
}

/* 집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환 */
int IsProperSubset(const IntSet *s1, const IntSet *s2)
{
    int nLoop;

    if (s1 == NULL || s2 == NULL)
        return -1;

    if (IsSubset(s1, s2) == 1) /* 부분집합 이면 */
    {
        if (IsSubset(s2, s1) == 1)
            return 0;
        else
            return 1;
    }
    return 0;
}
