#ifndef __INCLUDESORTING__
#define __INCLUDESORTING__

/* 버블 내부 교환 매크로 함수 */
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

/* 버블 정렬 */
void bubble(int *a, int n);
/* 버블 정렬 과정 출력 */
void COBubble(int *a, int n);
/* 배열 출력 함수 */
void printArrayA2B(int *a, int *b);
/* 배열 정렬 여부 확인*/
int is_sorted(const int *a, int n);
/* 양뱡향 버블 정렬*/
void cocktail(int *a, int n);

/* 단순 선택 정렬 */
void selection(int *a, int n);
/* 단순 삽입 정렬 */
void insertion(int *a, int n);
#endif