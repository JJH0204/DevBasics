#include <stdio.h>
#include <stdlib.h>

/* 실행 예제 1*/
void Ex_Func_1(void);
/* 요소 값이 long 형으로 정의되고 내림차순으로 정렬된 배열에서 bsearch함수를 사용한 검색을 구현 */
long *searchLongTypeKey(long *pArray, int nSize, long nKey);
/*long형 내림차순 비교 함수*/
int longTypecmp(const void *pA, const void *pB);

/* 실행 예제 2*/
void Ex_Func_2(void);
/* 선형 검색 알고리즘으로 정렬되지 않은 배열에서 값을 찾는 함수 구현 */
void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
/* 선형 검색 알고리즘 조건 함수 */
int lincmp(const void *A, const void *B);

/* TODO: 이진 검색 알고리즘으로 값을 찾는 함수 */
void *binsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

// TODO: 이진 검색 알고리즘으로 값을 찾되 찾은 값의 중복된 값들 중 가장 앞 순서의 포인터를 반환하는 함수
void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

int main(int argc, char *argv[])
{
    Ex_Func_1();
    
    Ex_Func_2();
    return 0;
}

long *searchLongTypeKey(long *pArray, int nSize, long nKey)
{
    long *pResult = NULL;
    if (pArray == NULL || nSize < 1)
        return NULL;

    pResult = bsearch(&nKey, pArray, nSize, sizeof(long), longTypecmp);
    if (pResult != NULL)
        return pResult;
    else
        return NULL;
}

void Ex_Func_1(void)
{
    long array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int loopCount = 0;
    long *result = NULL;
    long searchKey = 4;

    printf("[예제 1]요소 값이 long 형으로 정의되고 내림차순으로 정렬된 배열에서 bsearch함수를 사용한 검색을 구현\n");

    qsort(array, size, sizeof(long), longTypecmp);
    result = searchLongTypeKey(array, size, searchKey);

    printf("찾는 값 %02ld, 결과: ", searchKey);

    if (result == NULL)
        printf("찾지 못 했습니다.");
    else
        for (loopCount = 0; loopCount < size; loopCount++)
        {
            if (&array[loopCount] == result)
                printf("찾았다 >");
            printf("%02ld\t", array[loopCount]);
        }
    printf("\n");
    return;
}

int longTypecmp(const void *pA, const void *pB)
{
    const long *A = (const long *)pA;
    const long *B = (const long *)pB;

    if (*A == *B)
        return 0;
    else if (*A > *B)
        return -1;
    else
        return 1;
}

void Ex_Func_2(void)
{
    int array[] = {5, 2, 7, 4, 3, 10, 1, 8, 9, 6};
    int size = 10;
    int loopCount = 0;
    int *result = NULL;
    int searchKey = 10;

    printf("[예제 2]선형 검색 알고리즘으로 정렬되지 않은 배열에서 값을 찾는 함수 구현\n");

    result = seqsearch(&searchKey, array, size, sizeof(int), lincmp);

    printf("찾는 값 %d, 결과: ", searchKey);
    
    if (result == NULL)
        printf("찾지 못 했습니다.");
    else
        for (loopCount = 0; loopCount < size; loopCount++)
        {
            if (&array[loopCount] == result)
                printf("찾았다 >");
            printf("%02d\t", array[loopCount]);
        }
    printf("\n");
    return;
}

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    int nLoopCount = 0;
    int nCondition = 0;

    if (base == NULL)
        return NULL;
    for (nLoopCount = 0; nLoopCount < nmemb; nLoopCount++)
    {
        nCondition = compar(key, base + (nLoopCount * size));
        if (nCondition == 0)
            return (void *)(base + (nLoopCount * size));
    }
    return NULL;
}

int lincmp(const void *A, const void *B)
{
    const int *a = (const int *)A;
    const int *b = (const int *)B;

    if (*a == *b)
        return 0;
    else
        return -1;
}