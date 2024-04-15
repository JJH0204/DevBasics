#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#define Debug() printf("Func: %s, Line: %d\n", __func__, __LINE__)

void randomTest_1(void)
{
    /* 시드 값 설정 안함 */
    int x = rand();
    int y = rand();
    printf("x: %d, y: %d\n", x, y);
    return;
}

void randomTest_2(void)
{
    srand(50); /* 시드를 50(상수)으로 설정 */
    int x = rand();
    int y = rand();
    printf("x: %d, y: %d\n", x, y);
    return;
}

void randomTest_3(void)
{
    srand(time(NULL)); /* 시드를 시간변수(time(NULL))로 설정 */
    int x = rand();
    int y = rand();
    printf("x: %d, y: %d\n", x, y);
    return;
}
/*
E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 41, y: 18467
x: 201, y: 20851
x: 22301, y: 14232

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 41, y: 18467
x: 201, y: 20851
x: 22611, y: 19522

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 41, y: 18467
x: 201, y: 20851
x: 22631, y: 18477

마지막에 호출되는 randomTest_3()의 출력값만 매번 바뀌는 걸 확인
*/
#define RANDOM() 101 + rand() % 100 /*101 ~ 200 까지 랜덤 숫자 생성하도록 메크로 함수 선언*/
void randomTest_4(void)
{
    srand(time(NULL)); /* 시드를 시간변수(time(NULL))로 설정 */
    int x = RANDOM();
    int y = RANDOM();
    printf("x: %d, y: %d\n", x, y);
    return;
}
/*
E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 172, y: 165

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 179, y: 162

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 182, y: 142

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 188, y: 139

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 195, y: 168

E:\Document\GitHub\DevBasics>build\build_win\algorithmTest.exe
x: 198, y: 116
*/

// 1~200 사이 랜덤 값으로 배열 초기화
void initArray(int *pArray, int nArraySize)
{
    int nLoopCount = 0;

    if (pArray == NULL)
        return;

    srand(time(NULL));

    for (; nLoopCount < nArraySize; nLoopCount++)
        pArray[nLoopCount] = 1 + rand() % 200;
    return;
}

// 배열 출력
void scanArray(int *pArray, int nArraySize)
{
    int nLoopCount = 0;

    if (pArray == NULL)
        return;

    for (; nLoopCount < nArraySize; nLoopCount++)
        printf("Index[%d],Data[%d]\n", nLoopCount, pArray[nLoopCount]);
    return;
}

// 배열 뒤집기
void flipArray(int *pArray, int nArraySize)
{
    int nLoopCount = 0;
    int nTemp = 0;

    if (pArray == NULL)
        return;

    for (nLoopCount = 0; nLoopCount < nArraySize / 2; nLoopCount++)
    {
        nTemp = pArray[nLoopCount];
        pArray[nLoopCount] = pArray[nArraySize - nLoopCount - 1];
        pArray[nArraySize - nLoopCount - 1] = nTemp;
    }
    return;
}

// 배열 테스트 함수
void arrayTest_2(void)
{
    int nArraySize = 10;
    int *pArray = (int *)calloc(nArraySize, sizeof(int));
    if (pArray == NULL)
        return;
    printf("> Array Data:\n");
    initArray(pArray, nArraySize);
    scanArray(pArray, nArraySize);
    printf("> Array Data after flip:\n");
    flipArray(pArray, nArraySize);
    scanArray(pArray, nArraySize);
    free(pArray);
    return;
}
/*
Index[0],Data[78]
Index[1],Data[144]
Index[2],Data[87]
Index[3],Data[90]
Index[4],Data[130]
Index[5],Data[59]
Index[6],Data[15]
Index[7],Data[113]
Index[8],Data[60]
Index[9],Data[38]

Index[0],Data[38]
Index[1],Data[60]
Index[2],Data[113]
Index[3],Data[15]
Index[4],Data[59]
Index[5],Data[130]
Index[6],Data[90]
Index[7],Data[87]
Index[8],Data[144]
Index[9],Data[78]
*/

// 포인터 변수를 이용해 배열의 사이즈를 계산할 수 없는 이유
void arrayTest_1(void)
{
    int *pArray = (int *)malloc(sizeof(int) * 10);

    printf("sizeof(pArray): %d\n", sizeof(pArray));
    printf("sizeof(pArray) / sizeof(pArray[0]): %d\n", sizeof(pArray) / sizeof(pArray[0]));
    printf("sizeof(pArray) / sizeof(int): %d\n", sizeof(pArray) / sizeof(int));
    printf("sizeof(*pArray): %d\n", sizeof(*pArray));
    printf("sizeof(&pArray): %d\n", sizeof(&pArray));
    free(pArray);
}
/*
sizeof(pArray): 8 <- 배열 전체 사이즈를 가지지 않음
sizeof(pArray) / sizeof(pArray[0]): 2
sizeof(pArray) / sizeof(int): 2 <- 배열 요소의 사이즈로 나눴을 때 배열 요소의 개수를 구할 수 없게 되었다.
sizeof(*pArray): 4
sizeof(&pArray): 8
*/

// 기수 변환의 예시
void Conversion(int nTarget, int nWay)
{
    int nLoopCount = 0;
    int nFormation = 0;

    int *pArray = NULL;

    pArray = (int *)calloc(sizeof(int) * 8, sizeof(int));
    if (pArray == NULL)
        return;

    for (nLoopCount = 0; nTarget >= 1; nLoopCount++)
    {
        pArray[nLoopCount] = nTarget % nWay;
        nTarget /= nWay;
    }

    printf("Result: ");
    for (nLoopCount -= 1; nLoopCount >= 0; nLoopCount--)
    {
        if (pArray[nLoopCount] > 9)
        {
            nFormation = pArray[nLoopCount] - 9;
            if (nFormation == 1)
                printf("%c", 'A');
            else if (nFormation == 2)
                printf("%c", 'B');
            else if (nFormation == 3)
                printf("%c", 'C');
            else if (nFormation == 4)
                printf("%c", 'D');
            else if (nFormation == 5)
                printf("%c", 'E');
            else
                printf("%c", 'F');
        }
        else
            printf("%d", pArray[nLoopCount]);
    }
    printf("\n");
    return;
}

// 배열 복사
int *copyArray(int pArray[], int nArraySize)
{
    int *pResult = NULL;
    int nLoopCount = 0;
    if (pArray == NULL || nArraySize < 1)
        return NULL;

    pResult = (int *)calloc(nArraySize, sizeof(int));

    if (pResult == NULL)
        return NULL;

    for (nLoopCount = 0; nLoopCount < nArraySize; nLoopCount++)
        pResult[nLoopCount] = pArray[nLoopCount];

    return pResult;
}

// 중복 검사
int checkDuplicate(int pArray[], int nArraySize, int nKey)
{
    int nLoopCount = 0;

    if (pArray == NULL || nArraySize < 1)
        return 0;
    
    for (nLoopCount = 0; nLoopCount < nArraySize; nLoopCount++)
        if (pArray[nLoopCount] == nKey)
            return 1;
    return 0;
}

// 배열pArray의 모든 요소의 순서를 뒤섞는 함수
void shuffleArray(int pArray[], int nArraySize)
{
    int nLoopCount = 0;
    int nRandomIndex = 0;
    int nDuplicateCheck = 0; 
    int *pCopyArray = NULL;
    int *pDuplicateCheck = NULL;

    if (pArray == NULL || nArraySize < 1)
        return;
    
    srand(time(NULL));

    pCopyArray = copyArray(pArray, nArraySize);
    if (pCopyArray == NULL)
        return;

    pDuplicateCheck = (int *)calloc(nArraySize, sizeof(int));
    if (pDuplicateCheck == NULL)
        return;
    
    for (nLoopCount = 0; nLoopCount < nArraySize; nLoopCount++)
    {
        do
        {
            nRandomIndex = rand() % nArraySize;
            nDuplicateCheck = checkDuplicate(pDuplicateCheck, nLoopCount, nRandomIndex);
        } while (nDuplicateCheck > 0);

        pDuplicateCheck[nLoopCount] = nRandomIndex;

        pArray[nRandomIndex] = pCopyArray[nLoopCount];
    }

    free(pCopyArray);
    free(pDuplicateCheck);
    return;
}

// 날짜 데이터 구조체
typedef struct {
    int nYear;
    int nMonth;
    int nDay;
} date;

// 구조체 초기화
date dateOf(int nYear, int nMonth, int nDay)
{
    date result = {.nYear = nYear, .nMonth = nMonth, .nDay = nDay};
    return result;
}

// 윤년 계산기
int isLeap(int nYear)
{
    // 4배수 년도 중 100의 배수 년도를 제외하고 400의 배수 년도를 포함한 조건의 년도가 윤년에 해당한다.
    return nYear % 4 == 0 && nYear % 100 != 0 || nYear % 400 == 0;
}

// n일 후 date
date afterDate(date x, int n)
{
    int ppMonthData[][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    x.nDay += n;
    while (x.nDay > ppMonthData[isLeap(x.nYear)][x.nMonth])
    {
        x.nDay -= ppMonthData[isLeap(x.nYear)][x.nMonth];
        x.nMonth++;

        if (x.nMonth > 12)
        {
            x.nMonth = 1;
            x.nYear++;
        }
    }
    
    return x;
}

// n일 전 date
date beforeDate(date x, int n)
{
    int ppMonthData[][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    while (n > 0)
    {
        if (n >= x.nDay)
        {
            n -= x.nDay;
            x.nMonth--;
            if (x.nMonth < 1)
            {
                x.nMonth = 12;
                x.nYear--;
            }
            x.nDay = ppMonthData[isLeap(x.nYear)][x.nMonth];
        }
        else
        {
            x.nDay -= n;
            n = 0;
        }
    }

    return x;
}

void printExDate(void)
{
    date dateData = dateOf(2024, 4, 15);
    int nDay = 100;

    date afterDay = afterDate(dateData, nDay);
    date beforeDay = beforeDate(dateData, nDay);
    printf("%d년 / %02d월 / %02d일\n", dateData.nYear, dateData.nMonth, dateData.nDay);
    printf("%d년 / %02d월 / %02d일 + %d일 = %d년 / %02d월 / %02d일\n", dateData.nYear, dateData.nMonth, dateData.nDay, nDay, afterDay.nYear, afterDay.nMonth, afterDay.nDay);
    printf("%d년 / %02d월 / %02d일 - %d일 = %d년 / %02d월 / %02d일\n", dateData.nYear, dateData.nMonth, dateData.nDay, nDay, beforeDay.nYear, beforeDay.nMonth, beforeDay.nDay);
}

int main(int argc, char *argv[])
{
    // randomTest_1();
    // randomTest_2();
    // randomTest_3();
    // randomTest_4();
    // arrayTest_1();
    // arrayTest_2();

    // // 59를 2, 8, 16 진법으로 변환
    // printf("59 > Binary:");
    // Conversion(59, 2);
    // printf("59 > Octal:");
    // Conversion(59, 8);
    // printf("59 > Hexadecimal:");
    // Conversion(59, 16);

    // // 배열 무작위 섞기
    // int nSize = 10;
    // int pArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // printf("> Before: \n");
    // scanArray(pArray, nSize);

    // shuffleArray(pArray, nSize);
    // printf("> After: \n");
    // scanArray(pArray, nSize);

    //날짜 표시 예제
    printExDate();

    return 0;
}