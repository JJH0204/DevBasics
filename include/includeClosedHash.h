/* 오픈 주소법으로 구현한 해시 */
#ifndef __ClosedHash__
#define __ClosedHash__

#include "includeMember.h"

/* --- 요소의 상태 --- */ 
typedef enum
{
    Occupied,
    Empty,
    Deleted
} Status;
/*.......요소--- */ 
typedef struct
{
    Member data;    /* 데이터 */
    Status stat;    /* 버킷 상태 */
} Bucket;
/* --- 해시 테이블 --- */ 
typedef struct
{
    int size;       /* 해시 테이블 크기 */
    Bucket *table;  /* 해시 테이블 첫 번째 요소의 포인터 */
} ClosedHash;

/* --- 해시 테이블 초기화 --- */
int ClosedHash_Initialize(ClosedHash *h, int size);
/* --- 검색 --- */
Bucket *ClosedHash_Search(const ClosedHash *h, const Member *x);
/* --- 데이터 추가 --- */
int ClosedHash_Add(ClosedHash *h, const Member *x);
/* --- 데이터 삭제 --- */
int ClosedHash_Remove(ClosedHash *h, const Member *x);
/* --- 해시 테이블 덤프 --- */
void ClosedHash_Dump(const ClosedHash *h);
/* --- 모든 데이터 삭제 --- */
void ClosedHash_Clear(ClosedHash *h);
/* --- 해시 테이블 종료 --- */
void ClosedHash_Terminate(ClosedHash *h);

#endif