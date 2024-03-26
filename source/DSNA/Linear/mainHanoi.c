// hanoi.c
#include <stdio.h>

int hanoi_recursion(int n, char from, char temp, char to)
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

int hanoi_loop(int n)
{
    // Tower of Hanoi problem using loops
    int move, from, to;

    // 총 이동해야 하는 횟수: 2^n - 1
    for (int i = 0; i < (1 << n); i++)
    {
        move = i + 1; // 현재 이동 횟수
        // 이동할 원판의 번호 계산 (0부터 시작)
        move = (move & move - 1) % 3;
        // 원판의 시작 위치
        from = (i & i + 1) % 3;
        // 원판의 도착 위치
        to = (i | i + 1) % 3;

        printf("원판 %d을(를) %c에서 %c로 옮깁니다.\n", move + 1, 'A' + from, 'A' + to);
    }
}

int hanoi_stack(int n)
{
    // TODO: Tower of Hanoi problem using stack
    
}

int main(int argc, char *argv[])
{
    // char from = 'A';
    // char temp = 'B';
    // char to = 'C';

    // hanoi_recursion(4, from, temp, to);
    // hanoi_loop(4);
    hanoi_stack(4);

    return 0;
}