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
    {
        s->pSet[index] = s->pSet[s->nCount];
        s->nCount--;
    }
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
void Assign(IntSet *s1, const IntSet *s2);

/* 두 집합이 같은지 확인 */
int Equal(const IntSet *s1, const IntSet *s2);

/* 집합 s2와 s3의 합집합을 s1에 대입 */
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 집합 s2와 s3의 교집합을 s1에 대입 */
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 집합 s2와 s3의 차집합을 s1에 대입 */
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 집합 s의 모든 원소 출력 */
void Print(const IntSet *s);

/* 집합 s의 모든 원소 출력(줄 바꿈 문자 포함) */
void PrintLn(const IntSet *s);

/* 집합 삭제 */
void Terminate(IntSet *s);