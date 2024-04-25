#ifndef __INCLUDESORTING__
#define __INCLUDESORTING__

// TIP. 여러 줄에 걸쳐 매크로를 작성하고자 할 때는 \ (역슬래시)를 사용

/* 버블 내부 교환 매크로 함수*/
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