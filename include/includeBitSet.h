/* includeBitSet.h */
#ifndef __BITSET__
#define __BITSET__

#include <stdio.h>

typedef unsigned long BitSet;

#define BitSetNull  (BitSet)0
#define BitSetBits 32
#define SetOf(no) ((BitSet)1 << (no))

/* 집합 s에 n의 포함 여부 확인 */
int BitSet_IsMember(BitSet s, int n);

/* 집합 s에 n 추가 */
void BitSet_Add(BitSet *s, int n);

/* 집합 s에 n 제거 */
void BitSet_Remove(BitSet *s, int n);

/* 집합 s의 원소 개수 */
int BitSet_Size(BitSet s);

/* 집합 s의 모든 원소 출력 */
void BitSet_Print(BitSet s);

/* 집합 s의 모든 원소 출력(줄 바꿈 문자 포함) */
void BitSet_PrintLn(BitSet s);

/* s1와 s2의 대칭차를 구하는 함수 */
BitSet BitSet_SyDifference(BitSet s1, BitSet s2);
#endif