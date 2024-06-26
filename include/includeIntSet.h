/* int 데이터 타입 집합 IntSet의 헤더 */
#ifndef __INTSET__
#define __INTSET__

#include <stdio.h>
#include <stdlib.h>

/* 정수 집합 구조체 */
typedef struct intSet
{
    int nMaxSize; /* 집합의 최대 크기 */
    int nCount;   /* 집합의 현재 원소 개수 */
    int *pSet;    /* 집합 */
} IntSet;

/* 집합 초기화 함수 */
int Initialize(IntSet *s, int max);

/* 집합 s에 n의 포함 여부 확인 */
int IsMember(const IntSet *s, int n);

/* 집합 s에 n 추가 */
void Add(IntSet *s, int n);

/* 집합 s에 n 제거 */
void Remove(IntSet *s, int n);

/* 집합 s에 추가 가능한 최대 원소 개수 반환 */
int Capacity(const IntSet *s);

/* 집합 s의 원소 개수 */
int Size(const IntSet *s);

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

/* 집합이 가득 찼다면 1. 아니면 0을 반환 */
int IsFull(const IntSet *s);

/* 집합의 모든 원소를 삭제하는 함수 */
void Clear(IntSet *s);

/* 집합 s2, s3의 대칭 차를 s1에 대입하는 함수 */
IntSet *symmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 집합 51에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환) */
IntSet *ToUnion(IntSet *s1, const IntSet *s2);

/* 집합 s1에서 2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환) */
IntSet *ToIntersection(IntSet *s1, const IntSet *s2);

/* 집합 s1에서 2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환) */
IntSet *ToDifference(IntSet *s1, const IntSet *s2);

/* 집합 s1이 s2의 부분집합이면 1.아니면 0을 반환 */
int IsSubset(const IntSet *s1, const IntSet *s2);

/* 집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환 */
int IsProperSubset(const IntSet *s1, const IntSet *s2);

#endif