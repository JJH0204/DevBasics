/* 체인법으로 구현한 해시 */
#ifndef __CHAINHASH__
#define __CHAINHASH__

#include "includeMember.h"

/* 버킷 구조체 */
typedef struct node
{
    Member mData;
    struct node *pNext;
} Node;

/* 해시 테이블 구조체 */
typedef struct
{
    int nSize;      /* 해시 테이블 크기 */
    Node **ppTable; /* 해시 테이블 첫 번째 요소를 가리키는 포인터 */
} ChainHash;

/*--- 해시 테이블 초기화 ---*/
int Initialize(ChainHash *h, int size);
/*--- 검색 ---*/
Node *Search(const ChainHash *h, const Member *x);
/*---데이터추가---*/
int Add(ChainHash *h, const Member *x);
/*--- 데이터 삭제---*/
int Remove(ChainHash *h, const Member *x);
/*--- 해시 테이블 덤프(dump) ---*/ 
void Dump(const ChainHash *h);
/*--- 모든 데이터 삭제 ---*/ 
void Clear(ChainHash *h);
/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash *h);

#endif