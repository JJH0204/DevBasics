// hanoi.c
#include <stdio.h>

#define RECURSION
#ifdef RECURSION
int hanoi(int n, char from, char temp, char to)
{
    if (n == 1)
    {
        printf("원판 1을 %c에서 %c로 옮겼습니다.\n", from, to);
    }
    else
    {
        hanoi(n - 1, from, to, temp);
        printf("원판 %i을 %c에서 %c로 옮겼습니다.\n", n, from, to);
        hanoi(n - 1, temp, from, to);
    }
}
#endif
#ifndef RECURSION
int hanoi(int n, char from, char temp, char to)
{
    // TODO: Solving the Tower of Hanoi problem using loops

}
#endif
int main(int argc, char *argv[])
{
    char from = 'A';
    char temp = 'B';
    char to = 'C';

    hanoi(4, from, temp, to);
    
    return 0;
}