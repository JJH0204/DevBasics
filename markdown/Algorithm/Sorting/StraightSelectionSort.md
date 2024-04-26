# 단순 선택 정렬: Straight Selection Sort
> 가장 작은 요소부터 선택해 알맞은 위치로 옮겨 순서대로 정렬하는 알고리즘   

# 정렬과정
- 아직 정렬하지 않은 부분에서 가장 작은 키의 값을 선택
- 아직 정렬하지 않은 값과 아직 정렬하지 않은 부분을 교환
- 위 과정을 n - 1 회 반복
```c
void selection(int *a, int n)
{
    int nLoop, nInLoop, nMin;
    if (a == NULL || n < 1)
        return;

    for (nLoop = 0; nLoop < n - 1; nLoop++)
    {
        nMin = nLoop;
        for (nInLoop = nLoop + 1; nInLoop < n; nInLoop++)
            if (a[nInLoop] < a[nMin])
                nMin = nInLoop;
        if (nLoop != nMin)
            swap(int, a[nLoop], a[nMin]);
    }
}
```
- 요소 비교 횟수는 $(n^2 - n)/2$회
- 서로 떨어진 요소를 교환하는 것이기 때문에 안정적이지 않다.   
(중복된 값이 있을 경우 중복된 두 요소의 순서가 바뀐다.)
