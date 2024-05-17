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
static void SetNode(Node *n, const Member *x, const Node *pNext)
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
int Remove(ChainHash *h, const Member *x);
/*--- 해시 테이블 덤프(dump) ---*/
void Dump(const ChainHash *h);
/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash *h);
/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash *h);