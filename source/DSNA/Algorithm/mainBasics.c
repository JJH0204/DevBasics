#include <stdio.h>

int scanfMaximum(void)
{
    int nA, nB, nC;
    int nMax;
    printf("Input nA: ");
    scanf("%d", &nA);
    printf("Input nB: ");
    scanf("%d", &nB);
    printf("Input nC: ");
    scanf("%d", &nC);

    nMax = nA;
    if (nMax < nB)
        nMax = nB;
    if (nMax < nC)
        nMax = nC;

    return nMax;
}

int Maximum_3(const int _nA_, const int _nB_, const int _nC_)
{
    int nMax = _nA_;

    if (nMax < _nB_)
        nMax = _nB_;
    if (nMax < _nC_)
        nMax = _nC_;

    return nMax;
}

int Maximum_4(const int _nA_, const int _nB_, const int _nC_, const int _nD_)
{
    int nMax = _nA_;

    if (nMax < _nB_)
        nMax = _nB_;
    if (nMax < _nC_)
        nMax = _nC_;
    if (nMax < _nD_)
        nMax = _nD_;

    return nMax;
}

int Minimum_3(const int _nA_, const int _nB_, const int _nC_)
{
    int nMax = _nA_;

    if (nMax > _nB_)
        nMax = _nB_;
    if (nMax > _nC_)
        nMax = _nC_;

    return nMax;
}

int Minimum_4(const int _nA_, const int _nB_, const int _nC_, const int _nD_)
{
    int nMax = _nA_;

    if (nMax > _nB_)
        nMax = _nB_;
    if (nMax > _nC_)
        nMax = _nC_;
    if (nMax > _nD_)
        nMax = _nD_;

    return nMax;
}

int Middle_3(const int _nA_, const int _nB_, const int _nC_)
{
    // if (((_nA_ >= _nB_) && (_nB_ >= _nC_)) || ((_nC_ >= _nB_) && (_nB_ >= _nA_)))
    //     return _nB_;
    // if (((_nB_ >= _nA_) && (_nA_ >= _nC_)) || ((_nC_ >= _nA_) && (_nA_ >= _nB_)))
    //     return _nA_;
    // if (((_nB_ >= _nC_) && (_nC_ >= _nA_)) || ((_nA_ >= _nC_) && (_nC_ >= _nB_)))
    //     return _nC_;
    if (_nA_ >= _nB_)
    {
        if (_nB_ >= _nC_)
            return _nB_;
        else if (_nA_ > _nC_)
            return _nC_;
        else
            return _nA_;
    }
    else
    {
        if (_nA_ >= _nC_)
            return _nA_;
        else if (_nB_ >= _nC_)
            return _nC_;
        else
            return _nB_;
    }
}

void Ex_MiddleValCases(void)
{
    printf("> 세 값의 대소 관계 13종류의 모든 조합에 대해 중앙값을 출력하는 예제\n");

    printf("case_1(3, 2, 1): %d\n", Middle_3(3, 2, 1));
    printf("case_2(3, 2, 2): %d\n", Middle_3(3, 2, 1));
    printf("case_3(3, 1, 2): %d\n", Middle_3(3, 2, 1));
    printf("case_4(3, 2, 3): %d\n", Middle_3(3, 2, 1));
    printf("case_5(2, 1, 3): %d\n", Middle_3(3, 2, 1));
    printf("case_6(3, 3, 2): %d\n", Middle_3(3, 2, 1));
    printf("case_7(3, 3, 3): %d\n", Middle_3(3, 2, 1));
    printf("case_8(2, 2, 3): %d\n", Middle_3(3, 2, 1));
    printf("case_9(2, 3, 1): %d\n", Middle_3(3, 2, 1));
    printf("case_10(2, 3, 2): %d\n", Middle_3(3, 2, 1));
    printf("case_11(1, 3, 2): %d\n", Middle_3(3, 2, 1));
    printf("case_12(2, 3, 3): %d\n", Middle_3(3, 2, 1));
    printf("case_13(1, 2, 3): %d\n", Middle_3(3, 2, 1));
}

void signCheck(void)
{
    int n = -1;

    if (n < 0)
        printf("n = %d, (negative)\n", n);
    else if (n > 0)
        printf("n = %d, (positive)\n", n);
    else
        printf("n = %d, (Zero)\n", n);
}

// 1~n 정수 합 구하기
int n_Sum_Loop(int _nA_)
{
    int nLoopCount = 1;
    int nResult = 0;
    for (; nLoopCount <= _nA_; nLoopCount++)
        nResult += nLoopCount;
    return nResult;
}

int n_Sum(int _nA_)
{
    return ((_nA_ + 1) * _nA_) / 2;
}

// 정수 a, b를 포함하여 그 사이 모든 정수의 합을 구하는 함수
int Sum_A2B(int A, int B)
{
    // A, B의 대소 관계에 상관없이 합을 구하는 함수
    int nSumA = n_Sum(A);
    int nSumB = n_Sum(B);
    if (nSumA > nSumB)
        return nSumA - nSumB + B;
    else
        return nSumB - nSumA + A;
}

int B_Minus_A(void)
{
    int A = 0;
    int B = 0;

    do
    {
        printf("A: > ");
        scanf("%d", &A);
    } while (A < 0);

    do
    {
        printf("B: > ");
        scanf("%d", &B);
        if (B <= A)
            printf("A 보다 큰 값을 입력하세요!\n");
    } while (B <= A);

    return B - A;
}

int digitCalc(int A)
{
    int nLoopCount = 0;
    for (; A > 0; nLoopCount++)
        A /= 10;
    return nLoopCount;
}

void Multiple_Table(void)
{
    int nLoopRow = 1;
    int nLoopCulm = 1;

    for (nLoopRow = 1; nLoopRow < 10; nLoopRow++)
        printf("\t|%d", nLoopRow);
    printf("\n--------+-----------------------------------------------------------------------\n");
    for (nLoopRow = 1; nLoopRow < 10; nLoopRow++)
    {
        printf("%d\t", nLoopRow);
        for (nLoopCulm = 1; nLoopCulm < 10; nLoopCulm++)
            printf("|%d\t", nLoopRow * nLoopCulm);
        printf("\n");
    }
    return;
}

void Add_Table(void)
{
    int nLoopRow = 1;
    int nLoopCulm = 1;

    for (nLoopRow = 1; nLoopRow < 10; nLoopRow++)
        printf("\t|%d", nLoopRow);
    printf("\n--------+-----------------------------------------------------------------------\n");
    for (nLoopRow = 1; nLoopRow < 10; nLoopRow++)
    {
        printf("%d\t", nLoopRow);
        for (nLoopCulm = 1; nLoopCulm < 10; nLoopCulm++)
            printf("|%d\t", nLoopRow + nLoopCulm);
        printf("\n");
    }
    return;
}

void Draw_Square(int n)
{
    int nLoopRow = 0;
    int nLoopCulm = 0;

    for (; nLoopRow < n; nLoopRow++)
    {
        for (nLoopCulm = 0; nLoopCulm < n; nLoopCulm++)
        {
            printf("*  ");
        }
        printf("\n");
    }
    return;
}

void Draw_Rectangle(int nHight, int nArea)
{
    int nLength = nArea / nHight;

    int nLoopHight = 0, nLoopLength = 0;

    for (; nLoopHight < nHight; nLoopHight++)
    {
        for (nLoopLength = 0; nLoopLength < nLength; nLoopLength++)
        {
            printf("*  ");
        }
        printf("\n");
    }
    return;
}

void triangleLB(int n)
{
    int nLoopLength = 0;
    int nLoopWidth = 0;

    for (nLoopLength = 0; nLoopLength < n; nLoopLength++)
    {
        for (nLoopWidth = 0; nLoopWidth <= nLoopLength; nLoopWidth++)
            printf("*  ");
        printf("\n");
    }

    return;
}

void triangleLU(int n)
{
    int nLoopLength = 0;
    int nLoopWidth = 0;

    for (nLoopLength = 0; nLoopLength < n; nLoopLength++)
    {
        for (nLoopWidth = 0; nLoopWidth < n - nLoopLength; nLoopWidth++)
            printf("*  ");
        printf("\n");
    }

    return;
}

void triangleRU(int n)
{
    int nLoopLength = 0;
    int nLoopWidth = 0;
    int nPrintSpace = 0;

    for (nLoopLength = 0; nLoopLength < n; nLoopLength++)
    {
        for (nPrintSpace = 0; nPrintSpace < nLoopLength; nPrintSpace++)
            printf("   ");

        for (nLoopWidth = 0; nLoopWidth < n - nLoopLength; nLoopWidth++)
            printf("*  ");
        printf("\n");
    }
    return;
}

void triangleRB(int n)
{
    int nLoopLength = 0;
    int nLoopWidth = 0;
    int nPrintSpace = 0;

    for (nLoopLength = 0; nLoopLength < n; nLoopLength++)
    {
        for (nPrintSpace = 0; nPrintSpace < n - nLoopLength - 1; nPrintSpace++)
            printf("   ");

        for (nLoopWidth = 0; nLoopWidth <= nLoopLength; nLoopWidth++)
            printf("*  ");
        printf("\n");
    }
    return;
}

void spira(int n)
{
    int nLoopLength = 0;
    int nLoopWidth = 0;
    int nPrintStar = 0;
    int nPrintSpace = 0;
    int nLoopPrintSpace = 0;

    for (nLoopLength = 1; nLoopLength <= n; nLoopLength++)
    {
        nPrintStar = (nLoopLength - 1) * 2 + 1;

        nPrintSpace = (n * 2 - 1 - nPrintStar) / 2;
        for (nLoopPrintSpace = 0; nLoopPrintSpace < nPrintSpace; nLoopPrintSpace++)
            printf("   ");

        for (nLoopWidth = 0; nLoopWidth < nPrintStar; nLoopWidth++)
            printf("*  ");
        printf("\n");
    }
    return;
}

void nrpira(int n)
{
    int nLoopLength = 0;
    int nLoopWidth = 0;
    int nPrintStar = 0;
    int nPrintSpace = 0;
    int nLoopPrintSpace = 0;

    for (nLoopLength = n; nLoopLength > 0; nLoopLength--)
    {
        nPrintStar = (nLoopLength - 1) * 2 + 1;

        nPrintSpace = (n * 2 - 1 - nPrintStar) / 2;
        for (nLoopPrintSpace = 0; nLoopPrintSpace < nPrintSpace; nLoopPrintSpace++)
            printf("   ");

        for (nLoopWidth = 0; nLoopWidth < nPrintStar; nLoopWidth++)
            printf("%d  ", n - (nLoopLength % 10) + 1);
        printf("\n");
    }
    return;
}

int main(int argc, char **argv)
{
    // // EX_1
    // printf("Maximum: %d\n", scanfMaximum());

    // // EX_2
    // printf("Maximum_3(30, 40, 50): %d\n", Maximum_3(30, 40, 50));

    // // EX_3
    // printf("Maximum_4(30, 40, 50, 60): %d\n", Maximum_4(30, 40, 50, 60));

    // // EX_4
    // printf("Minimum_3(30, 40, 50): %d\n", Minimum_3(30, 40, 50));

    // // EX_5
    // printf("Minimum_4(30, 40, 50, 60): %d\n", Minimum_4(30, 40, 50, 60));

    // // EX_6
    // printf("Middle_3(30, 40, 50): %d\n", Middle_3(30, 40, 50));

    // // EX_7
    // Ex_MiddleValCases();

    // // EX_8
    // signCheck();

    // // EX_9: 1~n 정수 합 구하기
    // printf("n_Sum_Loop(100): %d\n", n_Sum_Loop(100));
    // printf("n_Sum(100): %d\n", n_Sum(100));

    // // EX_10: 정수 a, b를 포함하여 그 사이 모든 정수의 합을 구하는 함수
    // printf("Sum_A2B(3, 5): %d\n", Sum_A2B(3, 5));

    // // EX_11: Do~while() B - A
    // printf("B - A = %d\n", B_Minus_A());

    // // EX_12: 정수 자릿수 계산
    // printf("1314는 %d자리입니다.\n", digitCalc(1314));

    // // EX_13: 곱셈표 출력
    // Multiple_Table();

    // // EX_14: 덧셈표 출력
    // Add_Table();

    // // EX_15: 정사각형 출력
    // Draw_Square(4);
    // // EX_16: 높이, 넓이를 입력 받아 사각형 출력
    // Draw_Rectangle(3, 7);

    // // EX_17: 좌측 아래가 직각인 이등변 삼각형
    // triangleLB(7);
    // // EX_18: 좌측 위가 직각인 이등변 삼각형
    // triangleLU(7);
    // // EX_19: 우측 위가 직각인 이등변 삼각형
    // triangleRU(7);
    // // EX_20: 우측 아래가가 직각인 이등변 삼각형
    // triangleRB(7);

    // EX_21: 별 피라미드
    spira(7);
    // EX_22: 역 피라미드 숫자
    nrpira(7);
    return 0;
}