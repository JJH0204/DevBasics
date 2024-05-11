#ifndef __INCLUDESORTING__
#define __INCLUDESORTING__

#include "includeGenericStructure.h"
#include "includeHeap.h"
#include <time.h>
#include <string.h>

#define FUNC() printf("run \"%s\"\n", __func__)

/* 교환 매크로 함수 */
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

/* 버블 정렬 */
void bubble(int *a, int n);
/* 버블 정렬 과정 출력 */
void COBubble(int *a, int n);
/* 배열 출력 함수 */
void printArrayA2B(int *a, int *b);
/* 배열 정렬 여부 확인*/
int is_sorted(const int *a, int n);
/* 양뱡향 버블 정렬*/
void cocktail(int *a, int n);

/* 단순 선택 정렬 */
void selection(int *a, int n);
/* 단순 삽입 정렬 */
void insertion(int *a, int n);
/* 단순 선택 정렬 과정 출력 */
void COselection(int *a, int n);
/* 단순 삽입 정렬 과정 출력 */
void COinsertion(int *a, int n);

/* 배열 복사 함수*/
int copy(int *nFrom, int *nTo, int nSize);
/* 단순 삽입 정렬 */
void insertion_V2(int *a, int n);
/* 이진 삽입 정렬: 이진 탐색을 활용한 삽입 정렬*/
void binInsertion(int *a, int n);
/* 이진 탐색 알고리즘 */
int binSearch(const int *a, const int n, const int nVal);

/* 쉘 정렬 */
void shell(int *a, int n);
/* Quick 정렬 알고리즘: 배열 나누기 */
void partition(int *a, int n);
/* 퀵 정렬: 재귀 함수*/
void quick_RE(int *a, int left, int right);
/* 퀵 정렬: 재귀 함수, 과정 출력*/
void quick_RE_Po(int *a, int left, int right);
/* 퀵 정렬 */
void quickSort(int *a, int n);
/* 하이브리드 정렬*/
void hybrid(int *a, int n);
/* 하이브리드 정렬 개선 2*/
void hybrid_2(int *a, int n);
/* 하이브리드 정렬 개선 3*/
void hybrid_3(int *a, int n);
/* int 형 비교 함수: 오름차순 */
int int_cmp(const int *a, const int *b);
/* int 형 비교 함수: 내림차순 */
int int_cmpr(const int *a, const int *b);
/* qsort() 사용 예제 */
void EX_qsort(int *a, int n);
/* 직접 만든 qsort() */
void q_sort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
/* 바이트 단위 교환 함수 */
void MSWAP(size_t size, char *a, char *b);
/* 바이트 단위 복사 */
void MCOPY(size_t size, char *a, char *b);

/* 배열 병합 함수 */
int *mergeArray(int *arrayA, int nmembA, int *arrayB, int nmembB);
/* 병합 정렬 함수 */
void mergeSort(int *a, int n);
/* 병합 정렬 함수(재귀)*/
static void MergeSortByIndex(int *a, int left, int right);

static int *buff = NULL; /* 병합 정렬용 배열 */

/* 힙 정렬 */
void heapSort(int *a, int n);

/* array[left] ~ array[right] 를 최대 힙으로 만드는 함수 */
static void maxHeap (int * array, int left, int right);
/* 배열 자체를 힙으로 만드는 함수 응용 */
void _heapSort(int *a, int n);
// TODO: qsort() 형식으로 호출하는 mergesort 구현하기
void m_sort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

#endif