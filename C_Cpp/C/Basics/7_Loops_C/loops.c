//loops.c
#include <stdio.h>

void ForLoops(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int factorial = 1;
    int i;

    /* calculate the factorial using a for loop  here*/
    for (i = 0; i < 10; i++)
    {
        factorial *= array[i];
    }

    printf("10! is %d.\n", factorial);
}

void WhileLoops(void)
{
    /*인쇄를 앞둔 현재 개수가 5개 미만이면 인쇄하지 마십시오.
    인쇄하려는 현재 번호가 10보다 크면 인쇄하지 말고 루프를 중지하십시오.*/
    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    while (i < 10)
    {
       /* your code goes here */
        if (array[i] < 5)
        {
            i++;
            continue;
        }
        else if (array[i] > 10)
        {
            break;
        }
        printf("%d\n", array[i]);
        i++;
    }
}

int main(void)
{
    // ForLoops();
    WhileLoops();
    return 0;
}