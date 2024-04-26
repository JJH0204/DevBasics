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