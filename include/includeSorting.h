#ifndef __INCLUDESORTING__
#define __INCLUDESORTING__

/* 버블 내부 교환 매크로 함수 */
#define swapBubble(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

/* 버블 정렬 */
void bubble(int *a, int n);

#endif