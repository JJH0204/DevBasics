# 단순 삽입 정렬: Straight Insertion Sort
> 선택한 요소를 그보다 더 앞쪽의 알맞은 위치에 '삽입'하는 작업을 반복해 정렬하는 알고리즘   
> 단순 선택 정렬은 가장 작은 요소를 선택하는 점에서 차이가 있다.
   
```c
void insertion(int *a, int n)
{
    int nLoop, nInLoop, nTemp;
    for (nLoop = 0; nLoop < n; nLoop++)
    {
        /* 정렬할 값 선택 */
        nTemp = a[nLoop];

        /* 정렬할 위치 찾기(배열 시작 ~ 선택한 값 사이에서) */
        for (nInLoop = nLoop; nInLoop > 0 && a[nInLoop - 1] > nTemp; nInLoop--)
            a[nInLoop] = a[nInLoop - 1];
        a[nInLoop] = nTemp;
    }
}
```
- 떨어진 요소들이 서로 뒤바뀌지 않아 안정적이다.
- 요소 비교 횟수: $n^2 / 2$회
- 단순 삽입 정렬을 "셔틀 정렬(shuttle sort)"라고 함

# 알고리즘 개선 1
- 대치법을 활용하면 삽입을 마치는 종료 조건을 줄일 수 있다.

```c
void insertion_V2(int *a, int n)
{
    int nLoop, nInLoop, nTemp;
    /* 보초 법을 위한 배열 복사 */
    int *pCapArray = NULL;

    if (a == NULL || n < 0)
        return;
    pCapArray = (int *)calloc(n + 1, sizeof(int));

    if (copy(a, pCapArray + 1, n) != 0)
        return;

    for (nLoop = 1; nLoop < n + 1; nLoop++)
    {
        /* 정렬할 값 선택 */
        nTemp = pCapArray[nLoop];
        pCapArray[0] = nTemp;

        /* 정렬할 위치 찾기(배열 시작 ~ 선택한 값 사이에서) */
        for (nInLoop = nLoop; pCapArray[nInLoop - 1] > nTemp; nInLoop--)
            pCapArray[nInLoop] = pCapArray[nInLoop - 1];

        if (nInLoop != nLoop)
            pCapArray[nInLoop] = nTemp;
    }

    copy(pCapArray + 1, a, n);
    free(pCapArray);
    return;
}
```

# 알고리즘 개선 2
- 단순 삽입 정렬은 요소 개수가 많아지면 요소를 삽입하는데 필요한 비교 연산의 수가 증가한다.
- 이미 정렬된 부분은 "이진 탐색"을 이용해 삽입 위치를 더 빨리 찾을 수 있다.

```c
/* 이진 다중 조건 탐색 예제 */
int binSearch(const int *a, const int n, const int nVal)
{
    int nMiddle = 0, nStart = 0, nEnd = n;
    while (nStart <= nEnd)
    {
        nMiddle = (nStart + nEnd + 1) / 2;

        /*  1) 가리키는 값이 찾는 값과 같거나 크고 
            2) 이전 위치의 요소 값이 찾는 값 보다 작거나 배열의 밖인 경우
            -> 찾던 위치라 판단하고 가리키는 위치 반환 */
        if (a[nMiddle] >= nVal && (a[nMiddle - 1] < nVal || nMiddle - 1 < 0))
            return nMiddle;
        else if (a[nMiddle] > nVal)
            nEnd = nMiddle - 1;
        else
            nStart = nMiddle + 1;
    }
    return -1;
}

/* 이진 삽입 정렬 */
void binInsertion(int *a, int n)
{
    int nTarget, nTemp, nSwapLoop, nBinSearchResult;
    if (a == NULL || n < 1)
        return;

    for (nTarget = 1; nTarget < n; nTarget++)
    {
        nTemp = a[nTarget];
        /* 이진 탐색의 결과, 지정된 위치에 선택한 값을 삽입하기 위해 교환 과정을 거친다. */
        nBinSearchResult = binSearch(a, nTarget, nTemp);

        for (nSwapLoop = nTarget; nSwapLoop > 0 && nSwapLoop > nBinSearchResult; nSwapLoop--)
            a[nSwapLoop] = a[nSwapLoop - 1];
        a[nSwapLoop] = nTemp;
    }
    return;
}
```

# 알고리즘 개선 3
- 이진 탐색을 사용해 알고리즘을 개선했지만, 값을 교환하는 과정은 요소의 수량에 따라 부하량이 높아지는 것은 여전하다.
- 표준 라이브러리 함수 중 memmove() 를 사용해 최적화를 진행할 수 있다.

```c
void binInsertion(int *a, int n)
{
    int nTarget, nTemp, nSwapLoop, nBinSearchResult;
    if (a == NULL || n < 1)
        return;

    for (nTarget = 1; nTarget < n; nTarget++)
    {
        nTemp = a[nTarget];
        /* 이진 탐색 함수는 기존의 함수를 그대로 사용 */
        nBinSearchResult = binSearch(a, nTarget, nTemp);

        /* 재정렬의 효율성 증가를 위해 표준 라이브러리 함수 memmove()사용 */
        if (nTarget > nBinSearchResult && nBinSearchResult >= 0)
        {
            memmove(a + nBinSearchResult + 1, a + nBinSearchResult, (nTarget - nBinSearchResult) * sizeof(int));
            a[nBinSearchResult] = nTemp;
        }
    }
    return;
}

```

# 실행 결과
```shell
<Before>
Index:  00      01      02      03      04      05      06      07      08      09
Array:  03      06      05      08      09      04      07      10      01      02
<After>
Index:  00      01      02      03      04      05      06      07      08      09
Array:  01      02      03      04      05      06      07      08      09      10
```
