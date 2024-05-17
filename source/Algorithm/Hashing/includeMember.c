#include <stdio.h>
#include <string.h>
#include "includeMember.h"

/*----회원 번호 비교 함수----*/
int MemberNoCmp(const Member *x, const Member *y)
{
    if (x->no < y->no)
        return -1;
    else if (x->no > y->no)
        return 1;
    else
        return 0;
}

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCmp(const Member *x, const Member *y)
{
    return strcmp(x->name, y->name);
}

/*--- 회원 데이터를 출력(줄 바꿈 없음) ---*/
void PrintMember(const Member *x)
{
    printf("%d %s", x->no, x->name);
}

/*-- -회원 데이터를 출력(줄 바꿈 있음)-- --*/
void PrintLnMember(const Member *x)
{
    printf("%d %s\n", x->no, x->name);
}

/*--- 회원 데이터를 읽어 들임 ---*/
Member ScanMember(const char *message, int sw)
{
    Member temp;
    printf("%s, Please enter the data.\n", message);
    if (sw & MEMBER_NO)
    {
        printf("No: ");
        scanf("%d", &temp.no);
    }
    if (sw & MEMBER_NAME)
    {
        printf("Name: ");
        scanf("%s", temp.name);
    }
    return temp;
}