/* includeBitSet.c */
#include "includeBitSet.h"

/* 집합 s에 n의 포함 여부 확인 */
int BitSet_IsMember(BitSet s, int n)
{
    return s & SetOf(n);
}

/* 집합 s에 n 추가 */
void BitSet_Add(BitSet *s, int n)
{
    *s |= SetOf(n);
}

/* 집합 s에 n 제거 */
void BitSet_Remove(BitSet *s, int n)
{
    *s &= ~SetOf(n);
}

/* 집합 s의 원소 개수 */
int BitSet_Size(BitSet s)
{
    int n = 0;
    for (; s != BitSetNull; n++)
        s &= s - 1;
    return n;
}

/* 집합 s의 모든 원소 출력 */
void BitSet_Print(BitSet s)
{
    int i;
    printf("{ ");
    for (i = 0; i < BitSetBits; i++)
        if (BitSet_IsMember(s, i))
            printf("%d ", i);
    printf("}");
}

/* 집합 s의 모든 원소 출력(줄 바꿈 문자 포함) */
void BitSet_PrintLn(BitSet s)
{
    BitSet_Print(s);
    putchar('\n');
}