// hanoi.c
#include <stdio.h>

int hanoi_recursion(int n, char from, char temp, char to)
{
    if (n == 1)
    {
        printf("���� 1�� %c���� %c�� �Ű���ϴ�.\n", from, to);
    }
    else
    {
        hanoi(n - 1, from, to, temp);
        printf("���� %i�� %c���� %c�� �Ű���ϴ�.\n", n, from, to);
        hanoi(n - 1, temp, from, to);
    }
}

int hanoi_loop(int n)
{
    // Tower of Hanoi problem using loops
    int move, from, to;

    // �� �̵��ؾ� �ϴ� Ƚ��: 2^n - 1
    for (int i = 0; i < (1 << n); i++)
    {
        move = i + 1; // ���� �̵� Ƚ��
        // �̵��� ������ ��ȣ ��� (0���� ����)
        move = (move & move - 1) % 3;
        // ������ ���� ��ġ
        from = (i & i + 1) % 3;
        // ������ ���� ��ġ
        to = (i | i + 1) % 3;

        printf("���� %d��(��) %c���� %c�� �ű�ϴ�.\n", move + 1, 'A' + from, 'A' + to);
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