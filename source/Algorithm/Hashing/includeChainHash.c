#include <stdio.h>
#include <stdlib.h>
#include "includeMember.h"
#include "includeChainHash.h"

/* 해시 함수 */
static int hash(int key, int size)
{
    return key % size;
}

/* 노드의 각 멤버에 값을 설정 */
static void SetNode(Node *n, const Member *x, Node *pNext)
{
    n->mData = *x;    /* 데이터 */
    n->pNext = pNext; /* 다음 노드에 대한 포인터 */
}

/*--- 해시 테이블 초기화 ---*/
int Initialize(ChainHash *h, int size)
{
    int i;

    if ((h->ppTable = calloc(size, sizeof(Node *))) == NULL)
    {
        h->nSize = 0;
        return 0;
    }
    h->nSize = size;
    /* 모든 버킷을 공백(NULL)으로 만든다. */
    for (i = 0; i < size; i++)
        h->ppTable[i] = NULL;
    return 1;
}

/*--- 검색 ---*/
Node *Search(const ChainHash *h, const Member *x)
{
    int nKey = hash(x->no, h->nSize); /* 검색 데이터의 해시 값*/
    Node *p = h->ppTable[nKey];       /* 현재 선택한 노드 */

    while (p != NULL)
    {
        if (p->mData.no == x->no)   /* 검색 성공 */
            return p;
        p = p->pNext;               /* 다음 노드 선택 */
    }
    return NULL;                    /* 검색 실패 */
}

/*---데이터추가---*/
int Add(ChainHash *h, const Member *x)
{
    int nKey = hash(x->no, h->nSize); /* 추가하는 데이터의 해시 값 */
    Node *p = h->ppTable[nKey];       /* 현재 선택한 노드 */
    Node *pTemp;

    while (p != NULL)
    {
        if (p->mData.no == x->no)   /* 이미 등록 된 키 */
            return 1;               /* 등록 실패 */
        p = p->pNext;               /* 다음 노드로 이동 */
    }

    if ((pTemp = calloc(1, sizeof(Node))) == NULL)
        return 2;

    SetNode(pTemp, x, h->ppTable[nKey]);
    h->ppTable[nKey] = pTemp;
    return 0;
}
/*--- 데이터 삭제---*/
int Remove(ChainHash *h, const Member *x)
{
    int nKey = hash(x->no, h->nSize);   /* 삭제하는 데이터의 해시 값 */
    Node *p = h->ppTable[nKey];         /* 현재 선택한 노드 */
    Node **pp = &h->ppTable[nKey];      /* 현재 선택한 노드에 대한 포인터 */

    while (p != NULL)
    {
        if (p->mData.no == x->no)       /* 찾았다. */
        {
            *pp = p->pNext;             
            free(p);                    /* 해제 */
            return 0;                   /* 종료 */
        }
        pp = &p->pNext;                 
        p = p->pNext;                   /* 다음 노드 선택 */
    }
    return 1;                           /* 삭제 실패 */
}

/*--- 해시 테이블 덤프(dump) ---*/
void Dump(const ChainHash *h)
{
    int i;
    Node *p = NULL;

    for (i = 0; i < h->nSize; i++)
    {
        p = h->ppTable[i];

        printf("%02d ", i);

        while (p != NULL)
        {
            printf("-> %d :(%s) ", p->mData.no, p->mData.name);
            p = p->pNext;
        }
        putchar('\n');
    }
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash *h)
{
    int i;
    Node *p = NULL;
    Node *pNext = NULL;

    for (i = 0; i < h->nSize; i++)
    {
        p = h->ppTable[i];
        while (p != NULL)
        {
            pNext = p->pNext;
            free(p);
            p = pNext;
        }
        h->ppTable[i] = NULL;
    }
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash *h)
{
    Clear(h);
    free(h->ppTable);
    h->nSize = 0;
}

// TODO: 이름(문자열)을 키 값으로 설정하여 해싱하도록 수정