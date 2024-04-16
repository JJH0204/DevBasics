#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 배열의 시작 주소, 배열의 크기, 찾는 값을 인자로 찾는 값이 저장된 배열의 인덱스 값 반환
int searchSequential_NotSort(int _nList_[], int _nSize_, int _nKey_)
{
    int nLoopCount = 0;

    // 배열 전체를 순회하며 _nList_[nLoopCount] 값이 찾는 데이터(_nKey_) 와 같으면 반복을 종료
    for (nLoopCount = 0; nLoopCount < _nSize_; nLoopCount++)
        if (_nList_[nLoopCount] == _nKey_)
            return nLoopCount; // 찾은 데이터의 배열 인덱스 값을 반환
    return -1;                 // 못 찾았기 때문에 -1 반환
}

// 배열의 시작 주소, 배열의 크기, 찾는 값을 인자로 찾는 값이 저장된 배열의 인덱스 값 반환
int searchSequential_AscendingSort(int _nList_[], int _nSize_, int _nKey_)
{
    int nLoopCount = 0;
    // (_nList_[nLoopCount] < _nKey_): _nList_[nLoopCount] 값이 _nKey_ 값과 같거나 크다면 반복 종료
    while ((nLoopCount < _nSize_) && (_nList_[nLoopCount] < _nKey_))
        nLoopCount++;

    // _nList_[nLoopCount] 값이 _nKey_ 값과 같은지 확인
    if ((nLoopCount < _nSize_) && (_nList_[nLoopCount] == _nKey_))
        return nLoopCount; // 찾는 데이터라 인덱스 값 반환
    return -1;             // 못찾아 -1 반환
}

// 배열 내용 출력
bool printArray(int _nList_[], int _nSize_)
{
    int nLoopCount = 0;
    if ((_nList_ == NULL) || (_nSize_ < 0))
        return true;

    printf("Index\t|Key\n-------------------------\n");
    for (; nLoopCount < _nSize_; nLoopCount++)
        printf("%d\t,%d\n", nLoopCount, _nList_[nLoopCount]);
    return false;
}

// 키 값과 인덱스 값을 받아 검색을 성공했는지 확인
bool showSearchResult(int _nKey_, int _nIndex_)
{
    if (_nIndex_ >= 0)
        printf("key-%d, index-%d\n", _nKey_, _nIndex_);
    else
        printf("key-%d, Search Fail\n", _nKey_);
    return false;
}

int main(int argc, char *argv[])
{
    int nIndex = 0, nCount = 0;
    int notSortArray[] = {80, 20, 70, 50};
    int ascSortArray[] = {20, 50, 70, 80};

    // 1. 정렬되지 않은 경우
    printf("1. 정렬되지 않은 경우\n");
    nCount = sizeof(notSortArray) / sizeof(int);
    printArray(notSortArray, nCount);

    // 1-1. 검색에 성공한 경우: key = 70
    printf("1-1. 검색에 성공한 경우: key = 70\n");
    nIndex = searchSequential_NotSort(notSortArray, nCount, 70);
    showSearchResult(70, nIndex);

    // 1-2. 검색에 실패한 경우: key = 25
    printf("1-2. 검색에 실패한 경우: key = 25\n");
    nIndex = searchSequential_NotSort(notSortArray, nCount, 25);
    showSearchResult(25, nIndex);

    // 2. 정렬된 경우
    printf("2. 정렬된 경우\n");
    nCount = sizeof(ascSortArray) / sizeof(int);
    printArray(ascSortArray, nCount);

    // 2-1. 검색에 성공한 경우: key = 70
    printf("2-1. 검색에 성공한 경우: key = 70\n");
    nIndex = searchSequential_AscendingSort(ascSortArray, nCount, 70);
    showSearchResult(70, nIndex);

    // 2-2. 검색에 실패한 경우: key = 25
    printf("2-2. 검색에 실패한 경우: key = 25\n");
    nIndex = searchSequential_AscendingSort(ascSortArray, nCount, 25);
    showSearchResult(25, nIndex);

    return 0;
}
/*.\SequentialSearch.exe
1. 정렬되지 않은 경우
Index   |Key
-------------------------
0       ,80
1       ,20
2       ,70
3       ,50
1-1. 검색에 성공한 경우: key = 70
key-70, index-2
1-2. 검색에 실패한 경우: key = 25
key-25, Search Fail
2. 정렬된 경우
Index   |Key
-------------------------
0       ,20
1       ,50
2       ,70
3       ,80
2-1. 검색에 성공한 경우: key = 70
key-70, index-2
2-2. 검색에 실패한 경우: key = 25
key-25, Search Fail*/