#include <stdio.h>
#include <stdlib.h>

// 비교 함수
int int_cmp(const int *pA, const int *pB)
{
    if (*pA < *pB)
        return -1;
    else if (*pA > *pB)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    int nArraySize = 10;
    int pArray[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int nKey = 10;
    int *pResult = bsearch(&nKey, pArray, nArraySize, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
    /*
    함수 원형 void *__cdecl bsearch(
        const void *_Key,                                               찾는 키 데이터
        const void *_Base,                                              찾는 기준 배열 시작 포인터
        size_t _NumOfElements,                                          배열 요소 개수
        size_t _SizeOfElements,                                         한 요소 당 할당한 메모리 사이즈
        int (__cdecl *_PtFuncCompare)(const void *,const void *));      검사 조건 함수 (포인터 함수로 실행할 함수 전달)
    */
    // (int(*)(const void*, const void*)) int_cmp : 함수형 포인터 사용

    if (pResult == NULL)
        printf("Not Found\n");
    else
        printf("[%02d] - %d\n", (int)(pResult - pArray), nKey);
    free(pResult);
    return 0;
}
/*build\build_win\algorithmTest.exe
[00] - 10
*/