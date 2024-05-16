#include <stdio.h>
#include "includeTextSearch.h"

void ex_TextSearch_1(void);

int main(int argc, char *argv[])
{
    ex_TextSearch_1();
    
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