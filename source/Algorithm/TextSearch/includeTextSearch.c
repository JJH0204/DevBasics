#include <string.h>
#include <limits.h>
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

/* 브루트-포스법 */
int bf_match(const char txt[], const char pat[])
{
    int pt = 0, pp = 0;

    while (txt[pt] != '\0' && pat[pp] != '\0')
    {
        if (txt[pt] == pat[pp])
        {
            pt++;
            pp++;
        }
        else
        {
            pt = pt - pp + 1;
            pp = 0;
        }
    }

    if (pat[pp] == '\0')
        return pt - pp;
    return -1;
}

/* KMP법 */
int kmp_match(const char text[], const char pat[])
{
    int pt = 1, pp = 0;
    int skip[1024];

    skip[pt] = 0;

    /* 스킵 표 만들기 */
    while (pat[pt] != '\0')
    {
        if (pat[pt] == pat[pp])
            skip[++pt] = ++pp;
        else if (pp == 0)
            skip[++pt] = pp;
        else
            pp = skip[pp];
    }

    /* 검색 */
    pt = pp = 0;
    while (text[pt] != '\0' && pat[pp] != '\0')
    {
        if (text[pt] == pat[pp])
        {
            pt++;
            pp++;
        }
        else if (pp == 0)
            pt++;
        else
            pp = skip[pp];
    }

    /* 결과 출력 */
    if(pat[pp] == '\0')
        return pt - pp;
    return -1;
}

/* Boyer-Moore법으로 문자열 검색 */
int bm_match(const char txt[], const char pat[])
{
    int pt, pp;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int skip[UCHAR_MAX + 1];

    for (pt = 0; pt <= UCHAR_MAX; pt++)
        skip[pt] = pat_len;
    for (pt = 0; pt < pat_len - 1; pt++)
        skip[pat[pt]] = pat_len - pt - 1;

    while (pt < txt_len)
    {
        pp = pat_len - 1;
        while (txt[pt] == pat[pp])
        {
            if(pp == 0)
                return pt;
            pp--;
            pt--;
        }
        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
    }

    return -1;
}