# 1. 병합 정렬

- 배열을 앞과 뒤로 나누어 각각 정렬 후 병합하는 정렬 방식을 의미

# 2. 이미 정렬을 마친 두 배열의 병합

- [소스코드](../../../source/DSNA/Sorting/includeSorting.c#L900)
- 두 배열을 시작을 커서(배열의 요소를 가리키는 변수)로 두어 순차적으로 배열을 탐색하여 대소 관계를 비교한다.
- 단순 반복문의 정렬임으로 시간 복잡도는 $O(n)$이다.
- 커서 값으로 배열의 요소에 접근할 때 잘못된 메모리 참조(세그멘테이션 에러)를 유의하여 접근을 시도해야 한다.

# 3. 병합 정렬(Merge Sort)이란?

- "[2. 이미 정렬을 마친 두 배열의 병합](#2-이미-정렬을-마친-두-배열의-병합)"의 아이디어를 응용, 분할 정복법에 따라 정렬하는 알고리즘을 의미한다.
- 배열을 우선 앞과 뒤로 구분하여 분리 후 각각 따로 정렬을 시작한다.
- 정렬이 끝난 두 배열을 다시 하나로 합치는 과정에서 "[2. 이미 정렬을 마친 두 배열의 병합](#2-이미-정렬을-마친-두-배열의-병합)"의 아이디어를 사용해 요소의 대소 관계를 비교하며 합친다.

## 3.1. [소스코드](../../../source/DSNA/Sorting/includeSorting.c#L926)

## 3.2. 코드 리뷰

```c
// includeSorting.h

void mergeSort(int *a, int n);                              /* 병합 정렬 함수 */
static void MergeSortByIndex(int *a, int left, int right);  /* 병합 정렬 함수(재귀)*/
static int *buff = NULL;                                    /* 병합 정렬용 배열 */

// includeSorting.c
void mergeSort(int *a, int n)
{
    if (a == NULL || (buff = (int *)calloc(n, sizeof(int))) == NULL)
        return;
    MergeSortByIndex(a, 0, n - 1);
    free(buff);
    return;
}

static void MergeSortByIndex(int *a, int left, int right)
{
    int center;        // 배열의 좌측(left)과 우측(right) 범위에서 중앙을 가리킨다.
    int LoopCount;     // 병합 정렬 함수의 배열 참조 횟수를 제어
    int buffSize = 0;  // 버퍼에 복사한 요소의 수량 저장
    int buffIndex = 0; // 참조 중인 버퍼의 요소 위치
    int arrayIndex = left;
    /* 유효성 점검 */
    if (a == NULL || left > right)
        return;

    if (left < right)
    {
        /* 변수 초기화 */
        center = (left + right) / 2;
        LoopCount = left;

        /* 재귀 호출 */
        MergeSortByIndex(a, left, center);
        MergeSortByIndex(a, center + 1, right);

        /* 센터를 포함한 센터 기준 좌측 배열의 요소를 버퍼에 복사 */
        while (LoopCount <= center)
            buff[buffSize++] = a[LoopCount++];

        /* 버퍼에 복사한 배열 요소와 센터 기준 우측 배열 요소를 차례로 비교하여 기존 배열에 저장 */
        while (LoopCount <= right && buffIndex < buffSize)
            // {
            //     if (buff[j] <= a[i])
            //         a[k++] = buff[j++];
            //     else
            //         a[k++] = a[i++];
            // }
            a[arrayIndex++] = (buff[buffIndex] <= a[LoopCount]) ? buff[buffIndex++] : a[LoopCount++];

        /* 버퍼에 데이터가 남은 경우 기존 배열에 모두 옮겨 저장한다. */
        while (buffIndex < buffSize)
            a[arrayIndex++] = buff[buffIndex++];
    }
}
```

- 병합 정렬 로직 수행을 위해 전역 변수(이하 **버퍼** )를 선언해 사용한다. [(코드)](../../../include/includeSorting.h#L84)
- **mergeSort()** 함수가 호출되면 인자로 받은 배열의 존재여부 확인과 동시에 버퍼의 메모리를 동적할당하고 검사한다. [(코드)](../../../source/DSNA/Sorting/includeSorting.c#L928)
- 버퍼의 할당을 완료하면 본격적으로 병합정렬을 수행하는 함수 **MergeSortByIndex()** 를 호출한다.
- 배열을 center를 기준으로 좌측과 우측으로 나눠 [(코드1)](../../../source/DSNA/Sorting/includeSorting.c#L949) 자신을 호출 한다. [(코드 2)](../../../source/DSNA/Sorting/includeSorting.c#L953)
- 재귀 호출한 두 함수 (같은 함수지만 따로 처리되기에 다른 함수로 가정하고 진행)가 종료되면 병합 정렬 로직을 수행 한다.
  - 버퍼에 센터 기준 좌측 배열의 요소를 복사 [(코드)](../../../source/DSNA/Sorting/includeSorting.c#L957)
  - 버퍼의 값과 배열의 우측 요소를 비교해 더 작은 값을 기존 배열에 저장 [(코드)](../../../source/DSNA/Sorting/includeSorting.c#L961)
  - 버퍼에 남은 값은 배열의 후미에 복사 저장 [(코드)](../../../source/DSNA/Sorting/includeSorting.c#L971)