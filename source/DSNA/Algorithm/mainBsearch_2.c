#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char cName[10];
    int nHeight;
    int nWeight;
} Person;

/* Person형의 비교 함수(오름차순 이름 정렬) */
int npcmp(const Person *pPersonA, const Person *pPersonB)
{
    return strcmp(pPersonA->cName, pPersonB->cName);
}

/* 테스트용 배열 초기화 함수, 배열 인자 개수 반환*/
Person *initArray(int nArraySize)
{
    Person *pResult = (Person *)calloc(nArraySize, sizeof(Person));

    if (pResult == NULL)
        return NULL;

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
    pResult[10] = (Person){"홍연의", 172, 84};

    return pResult;
}

/* 리스트 출력 */
void printArray(Person *pArray, int nArraySize)
{
    int nLoopCount = 0;
    if (pArray == NULL)
        return;
    printf("|Name\t|Height\t|Weight\t|\n------------------------\n");
    for (nLoopCount = 0; nLoopCount < nArraySize; nLoopCount++)
        printf("|%s\t|%d\t|%d\t|\n", pArray[nLoopCount].cName, pArray[nLoopCount].nHeight, pArray[nLoopCount].nWeight);
    return;
}

/* 오름차순 정렬 검사(이름) */
int checkAscending_Name(Person *pArray, int nArraySize)
{
    int nLoopCount = 0;
    int nCondition = 0;
    int nCount = 0;
    for (nLoopCount = 0; nLoopCount < nArraySize - 1; nLoopCount++)
    {
        nCondition = strcmp((pArray + nLoopCount)->cName, (pArray + nLoopCount + 1)->cName);
        if (nCondition == -1)
        {
            printf("%s < %s\n", (pArray + nLoopCount)->cName, (pArray + nLoopCount + 1)->cName);
            nCount++;
        }
        else
        {
            printf("%d >= %d\n", (pArray + nLoopCount)->cName, (pArray + nLoopCount + 1)->cName);
        }
    }

    if (nCount == nArraySize - 1)
    {
        printf("Is Ascending\n");
        return 0;
    }
    else
    {
        printf("Is Descending\n");
        return 0;
    }
}

/* 입력 받는 값을 검색 */
int searchWithScanKey(Person *pArray, int nArraySize)
{
    Person PersonKey, *pResult;
    int nCriteria = 0;

    if (pArray == NULL || nArraySize < 1)
        return -1;

    printf("Please select your search criteria.\n(Name = 1, Height = 2, Weight = 3), After selecting, press enter\n> ");
    do
    {
        scanf("%d", &nCriteria);
        if (nCriteria < 1 || nCriteria > 3)
            printf("Please select one of the options above.\n");
    } while (nCriteria < 1 || nCriteria > 3);

    if (nCriteria == 1)
    {
        printf("Please enter the name you are looking for.\n> ");
        scanf("%s", &(PersonKey.cName));
        printf("%s", PersonKey.cName); /* 출력 안됨 */
        pResult = bsearch(&PersonKey, pArray, nArraySize, sizeof(Person),
                          (int (*)(const void *, const void *))npcmp);
        // TODO: 왜? 결과 값이 제대로 출력되지 않는지 확인하기
        printf("%s", pResult->cName);
        if (pResult == NULL)
            printf("No value found.\n");
        else
            printf("Index[%d]: %s, %dcm, %dkg\n",
                   (int)(pResult - pArray), pResult->cName, pResult->nHeight, pResult->nWeight);
    }
    /* TODO: 이하 / 이상 / 초과 / 미만 / 범위 다섯 종류의 검색 방식을 구현해보자*/
    else if (nCriteria == 2)
    {
        printf("Please enter the name you are looking for.\n> ");
    }
    else
    {
        printf("Please enter the name you are looking for.\n> ");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int nArraySize = 11;
    Person *pPersonList = initArray(nArraySize);
    Person *pSearchResult = NULL;
    printArray(pPersonList, nArraySize);
    // checkAscending_Name(pPersonList, nArraySize);
    searchWithScanKey(pPersonList, nArraySize);
    free(pPersonList);
    return 0;
}