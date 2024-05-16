#ifndef __TEXTSEARCH__
#define __TEXTSEARCH__

/* 문자열 s에서 문자 c를 검색하는 함수 */
int str_chr(const char *s, int c);

/* 브루트-포스법 */
int bf_match(const char txt[], const char pat[]);

/* KMP법 */
int kmp_match(const char text[], const char pat[]);

/* Boyer-Moore법으로 문자열 검색 */
int bm_match(const char txt[], const char pat[]);

#endif