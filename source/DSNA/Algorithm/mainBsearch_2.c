#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct
{
    char cName[10];
    int nHeight;
    int nWeight;
} Person;

/* 문자열 공백 제거 */
void trimWhitespace(char *str)
{
    char *end;

    // 앞쪽 공백 제거
    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0) // 모든 공백인 경우
        return;

    // 뒤쪽 공백 제거
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    // 문자열 끝 처리
    *(end + 1) = 0;
}

/* Person형의 비교 함수(이름 오름차순 정렬) */
int personName_cmp(const void *pA, const void *pB)
{
    const Person *pPersonA = (const Person *)pA;
    const Person *pPersonB = (const Person *)pB;
    return strcmp(pPersonA->cName, pPersonB->cName);
    /* strcmp(A, B): 두 문자열이 같을 때 0, A가 B보다 사전 순서가 앞일 때 -1, 뒤에 있으면 1 반환*/
    /* -1 이외 다른 음수 값을 반환 할 수 있다.*/
}

/* Person형의 비교 함수(키 오름차순 정렬)*/
int personHeight_cmp(const void *pA, const void *pB)
{
    const Person *pPersonA = (const Person *)pA;
    const Person *pPersonB = (const Person *)pB;
    
    if (pPersonA->nHeight == pPersonB->nHeight)
        return 0;
    else if (pPersonA->nHeight < pPersonB->nHeight)
        return -1;
    else
        return 1;
}

/* Person형의 비교 함수(몸무게 오름차순 정렬)*/
int personWeight_cmp(const void *pA, const void *pB)
{
    const Person *pPersonA = (const Person *)pA;
    const Person *pPersonB = (const Person *)pB;
    
    if (pPersonA->nWeight == pPersonB->nWeight)
        return 0;
    else if (pPersonA->nWeight < pPersonB->nWeight)
        return -1;
    else
        return 1;
}

/* 테스트용 배열 초기화 함수(이름 오름차순 정렬)*/
Person *initArray(int nArraySize)
{
    /* 배열 할당 */
    Person *pResult = (Person *)calloc(nArraySize, sizeof(Person));

    if (pResult == NULL)
        return NULL;
    
    /* 값 초기화 */
    pResult[0] = (Person){"김영준", 179, 79};
    pResult[1] = (Person){"김현진", 175, 81};
    pResult[2] = (Person){"박현규", 172, 63};
    pResult[3] = (Person){"우준혁", 173, 56};
    pResult[4] = (Person){"이수진", 176, 53};
    pResult[5] = (Person){"이재구", 182, 87};
    pResult[6] = (Person){"정재호", 172, 74};
    pResult[7] = (Person){"조광재", 174, 76};
    pResult[8] = (Person){"최윤미", 156, 51};
    pResult[9] = (Person){"함진아", 181, 73};
    pResult[10] = (Person){"박진우", 172, 84};

    /* 배열 정렬(이름 오름차순) */
    qsort(pResult, nArraySize, sizeof(Person), personName_cmp);
    
    return pResult;
}

/* 표 형식 배열 출력 */
void printTableFormat(Person *pArray, int nArraySize)
{
    int nLoopCount = 0;
    if (pArray == NULL)
        return;
    printf("|Name\t|Height\t|Weight\t|\n------------------------\n");
    for (nLoopCount = 0; nLoopCount < nArraySize; nLoopCount++)
        printf("|%s\t|%d\t|%d\t|\n", pArray[nLoopCount].cName, pArray[nLoopCount].nHeight, pArray[nLoopCount].nWeight);
    return;
}

/* 오름차순 정렬 검사(함수형 포인터 인자 활용) */
int checkAscending(Person *pArray, int nArraySize, int(*compare)(const void *key, const void *element))
{
    int nLoopCount = 0;
    int nCondition = 0;
    int nCount = 0;

    if (pArray == NULL || nArraySize < 1)
        return -1;

    for (nLoopCount = 0; nLoopCount < nArraySize - 1; nLoopCount++)
    {
        /* 함수 포인터 이렇게 쓰는게 맞나? */
        nCondition = compare(pArray + nLoopCount, pArray + nLoopCount + 1);
        if (nCondition < 0)
            nCount++;
    }

    if (nCount == nArraySize - 1)
        return 0;
    else
        return 1;
}

int main(int argc, char *argv[])
{
    int nArraySize = 11;
    
    Person *pPersonList = initArray(nArraySize);
    Person *pSearchResult = NULL, *pResult = NULL;
    Person personKey = {"정재호", 176, 84};

    printArray(pPersonList, nArraySize);
    /* 이름 기준 오름차순 정렬인지 확인*/
    if (checkAscending(pPersonList, nArraySize, personName_cmp) == 0)
    {
        pResult = bsearch(&PersonKey, pPersonList, nArraySize, sizeof(Person), personName_cmp);
        if (pResult != NULL)
            printf("[%d] - %s\t|%d\t|%d\t|\n", pResult - pPersonList, pResult->cName, pResult->);
        else
            printf("데이터를 찾지 못했습니다.\n");
    }
    else
    {
        /* 배열 정렬 (이름 오름차순) */
        qsort(pPersonList, nArraySize, sizeof(Person), personName_cmp);
        searchWithKey(pPersonList, nArraySize, personKey);
    }


    free(pPersonList);
    return 0;
}
// TODO: 정렬 기준 함수 (키, 몸무게) 구현하고 사용하는 예제 작성 _ qsort()를 사용하는 함수형 포인터 예제