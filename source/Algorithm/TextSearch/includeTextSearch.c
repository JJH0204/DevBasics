#include "includeTextSearch.h"

/* 문자열 s에서 문자 c를 검색하는 함수 */
int str_chr(const char *s, int c)
{
    int i = 0;
    c = (char)c;

    while (s[i] != c)
    {
        if (s[i] == '\0') /* 검색 실패 */
            return -1;
        i++;
    }
    return i;
}