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

/* 집합 초기화 함수 */
int Sorted_Initialize(SortedIntSet *s, int max);

/* 비교 함수 */
int Sorted_comp(const void *a, const void *b);

/* 집합 s에 n의 포함 여부 확인 */
int Sorted_IsMember(const SortedIntSet *s, int n);

/* 집합 s에 n 추가 */
void Sorted_Add(SortedIntSet *s, int n);

/* 집합 s에 n 제거 */
void Sorted_Remove(SortedIntSet *s, int n);

/* 집합 s의 모든 원소 출력 */
void Sorted_Print(const SortedIntSet *s);

/* 집합 s의 모든 원소 출력(줄 바꿈 문자 포함) */
void Sorted_PrintLn(const SortedIntSet *s);

/* 집합 삭제 */
void Sorted_Terminate(SortedIntSet *s);

/* 집합 s2를 s1에 대입 */
void Sorted_Assign(SortedIntSet *s1, const SortedIntSet *s2);

/* 집합 s에 추가 가능한 최대 원소 개수 반환 */
int Sorted_Capacity(const SortedIntSet *s);

/* 집합 s의 원소 개수 */
int Sorted_Size(const SortedIntSet *s);

/* 두 집합이 같은지 확인 */
int Sorted_Equal(const SortedIntSet *s1, const SortedIntSet *s2);

/* 집합 s2와 s3의 합집합을 s1에 대입 */
SortedIntSet *Sorted_Union(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3);

/* 집합 s2와 s3의 교집합을 s1에 대입 */
SortedIntSet *Sorted_Intersection(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3);

/* 집합 s2와 s3의 차집합을 s1에 대입 */
SortedIntSet *Sorted_Difference(SortedIntSet *s1, const SortedIntSet *s2, const SortedIntSet *s3);
#endif