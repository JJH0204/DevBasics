# 보초법
- 배열의 선형 검색 로직에서 종료 조건을 검사하는 리소스를 절약하는 방법
```C
// 선형 검색 예제 로직
int searchSequential_NotSort(int _nList_[], int _nSize_, int _nKey_)
{
    int nLoopCount = 0;

    // 배열 전체를 순회하며 _nList_[nLoopCount] 값이 찾는 데이터(_nKey_) 와 같으면 반복을 종료
    for (nLoopCount = 0; nLoopCount < _nSize_; nLoopCount++)
        if (_nList_[nLoopCount] == _nKey_)
            return nLoopCount; // 찾은 데이터의 배열 인덱스 값을 반환
    return -1;                 // 못 찾았기 때문에 -1 반환
}
```
- 선형 검색은 정렬되지 않은 배열 형태의 데이터 구조에서 원하는 데이터를 찾는 가장 효율적인 방법
- 하지만, 두 종료 조건을 검사하는 비용은 무시하지 못할 비용임으로 하나의 종료조건만 사용할 수 있도록 환경을 조성

## 소스코드 ([링크](../../source/DSNA/Algorithm/mainSentinelMethod.c))

## 실행결과
```shell
[00]-10 
[01]-09 
[02]-05 (twinkle~)
[03]-04 
[04]-06 
```

## 스캐닝 과정
```
        |00     01      02      03      04      (Sentinel)
-----------------------------------------------------
        |*
00      |10     09      05      04      06      05

        |       *
01      |10     09      05      04      06      05

        |               *
02      |10     09      05      04      06      05
```
