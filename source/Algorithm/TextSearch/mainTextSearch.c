#include <stdio.h>
#include <string.h>
#include "includeTextSearch.h"

void ex_TextSearch_1(void);
void ex_TextSearch_2(void);
void ex_TextSearch_3(void);
void ex_TextSearch_4(void);

int main(int argc, char *argv[])
{
    // ex_TextSearch_1();
    // ex_TextSearch_2(); 
    // ex_TextSearch_3();
    ex_TextSearch_4();
    return 0;
}

void ex_TextSearch_1(void)
{
    char str[64] = "SURROUND";
    int ch = 'R';
    int idx;

    if ((idx = str_chr(str, ch)) == -1)
        printf("Not in text, %c\n", ch);
    else
        printf("'%c' is in text, number %d\n", ch, idx + 1);
}

void ex_TextSearch_2(void)
{
    int idx;
    char s1[256];
    char s2[256];
    puts("브루트-포스법");
    printf("텍스트: ");
    scanf("%s", s1);
    printf("패턴: ");
    scanf("%s", s2);
    idx = bf_match(s1, s2);
    if (idx == -1)
        puts("Text Search Fail\n");
    else
        printf("Match at %d.\n", idx + 1);
    return;
}

void ex_TextSearch_3(void)
{
    int idx;
    char s1[256] = "ABABCDEFGHA";
    char s2[256];
    puts("Boyer-Moore");
    printf("TEXT: %s\n", s1);
    printf("PATTERN: ");
    scanf("%s", s2);

    idx = bm_match(s1, s2);
    if (idx == -1)
        puts("Not in Text.");
    else
        printf("Match at %d.th character.\n", idx + 1);
    return;
}

void ex_TextSearch_4(void)
{
    char s1[256] = "ABABCDEFGHA";
    char s2[256];
    char *p;

    puts("function strstr");
    printf("TEXT: %s\n", s1);
    printf("PATTERN: ");
    scanf("%s", s2);

    p = strstr(s1, s2);

    if (p == NULL)
        printf("Not in text.\n");
    else
    {
        int ofs = p - s1;
        printf("\n%s\n", s1);
        printf("%*s|\n", ofs, "");
        printf("%*s%s\n", ofs, "", s2);
    }
    return;
}