# 1. 도수 정렬
- 대소 관계를 판단하지 않고 빠르게 정렬할 수 있는 알고리즘
- 도수분포표 작성 > 누적도수분포표 작성 > 목적 배열 만들기 > 배열 복사 순으로 이뤄진다.

# 2. [소스 코드](../../../source/DSNA/Sorting/includeSorting.c#L1038)

# 3. 코드 분석
## 3.1. 변수 할당 및 유효성 점검
```c
    int *buff = NULL, *copyPtr = NULL;
    int i = 0;

    if (ptr == NULL || nmemb < 1 || max < 1)
        return;

    buff = (int *)calloc(max, sizeof(int));
    copyPtr = (int *)calloc(nmemb, sizeof(int));
    
    if (buff == NULL || copyPtr == NULL)
    {
        free(buff);
        return;
    }
```
## 3.2. 도수분포표 작성
```c
for (i = 0; i < nmemb; i++)
    buff[ptr[i]]++;
```
## 3.3. 누적도수분포표 작성
```c
for (i = 1; i <= max; i++)
    buff[i] += buff[i - 1];
```
## 3.4. 목적 배열 작성
```c
for (i = nmemb - 1; i >= 0; i--)
    copyPtr[--buff[ptr[i]]] = ptr[i];
```
## 3.5. 배열 복사
```c
for (i = 0; i < nmemb; i++)
    ptr[i] = copyPtr[i];
```
## 3.6. 함수 종료
```c
free(buff);
free(copyPtr);
return;
```