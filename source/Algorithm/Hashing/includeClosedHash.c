/* 오픈 주소법으로 구현한 해시 */
#include <stdio.h>
#include <stdlib.h>
#include "includeClosedHash.h"

/* --- 해시 함수 (key의 해시 값을 반환) --- */
static int hash(int key, int size)
{
    return key % size;
}

/* --- 재해시 함수 --- */
static int rehash(int key, int size)
{
    return (key + 1) % size;
}

/* --- 노드의 각 맴버에 값을 설정 --- */
static void SetBucket(Bucket *n, const Member *x, Status stat)
{
    n->data = *x;
    n->stat = stat;
}

/* --- 해시 테이블 초기화 --- */
int ClosedHash_Initialize(ClosedHash *h, int size)
{
    int i;
    /* 해시 테이블 할당 시도 -> 실패시 처리 */
    if ((h->table = calloc(size, sizeof(Bucket))) == NULL)
    {
        h->size = 0;
        return 0;
    }
    h->size = size;

    for (i = 0; i < size; i++)      /* 해시 테이블의 모든 버킷을 순회 */
        h->table[i].stat = Empty;   /* 접근한 버킷의 상태를 'Empty' 상태로 바꾼다. */
    return 1;
}

/* --- 검색 --- */
Bucket *ClosedHash_Search(const ClosedHash *h, const Member *x)
{
    int i;
    int key = hash(x->no, h->size); /* 검색할 데이터의 해시 값 */
    Bucket *p = &h->table[key];     /* 현재 선택한 노드 */

    /* 버킷의 상태가 비었거나 해시 테이블을 순회하는 i의 값이 테이블 사이즈를 벗어나면 반복 종료 */
    for (i = 0; p->stat != Empty && i < h->size; i++)
    {
        /* 버킷의 상태가 사용중 이며 저장 중인 데이터가 찾는 데이터면 포인터 반환 */
        if (p->stat == Occupied && p->data.no == x->no)
            return p;   /* 찾기 성공 */
        /* 그렇지 않으면, 버킷의 상태가 Deleted라 가정 */
        /* 키를 재해시 한 후 */
        key = rehash(key, h->size);
        /* 키를 기준으로 해시 테이블의 버킷에 재 참조 */
        p = &h->table[key];
    }
    /* 찾기 실패 */
    return NULL;
}

/* --- 데이터 추가 --- */
int ClosedHash_Add(ClosedHash *h, const Member *x)
{
    int i;
    int key = hash(x->no, h->size); /* 추가할 데이터의 해시 값 */
    Bucket *p = &h->table[key];     /* 현재 선택한 노드 */

    if (ClosedHash_Search(h, x)) /* 이미 데이터를 저장한 경우 */
        return 1;

    /* 해시 테이블을 순회 */
    for (i = 0; i < h->size; i++)
    {
        /* 버킷의 상태가 사용 가능한 상태라면 */
        if (p->stat == Empty || p->stat == Deleted)
        {
            SetBucket(p, x, Occupied);
            return 0;
        }
        /* 사용 가능한 상태가 아니라면 */
        key = rehash(key, h->size); /* 재해시를 통해 사용 가능한 버킷을 찾는다. */
        p = &h->table[key];
    }
    /* 해시 테이블이 가득차 이용 불가능 */
    return 2;
}

/* --- 데이터 삭제 --- */
int ClosedHash_Remove(ClosedHash *h, const Member *x)
{
    Bucket *p = ClosedHash_Search(h, x);
    if(p == NULL)   /* 삭제할 버킷을 찾지 못함 */
        return 1;
    p->stat = Deleted; /* 삭제한 상태로 바꿈 */
    return 0;
}

/* --- 해시 테이블 덤프 --- */
void ClosedHash_Dump(const ClosedHash *h)
{
    int i;

    /* 해시 테이블 순회 */
    for (i = 0; i < h->size; i++)
    {
        printf("%02d: ", i);    /* 버킷의 인덱스 번호 출력 */

        /* 버킷의 상태에 따라 출력 방식 다르게 진행 */
        switch (h->table[i].stat)
        {
        case Occupied:
            printf("%d(%s)\n", h->table[i].data.no, h->table[i].data.name);
            break;
        case Empty:
            printf("--미등록 버킷--\n");
            break;
        case Deleted:
            printf("--삭제된 버킷--\n");
            break;
        }
    }
}
/* --- 모든 데이터 삭제 --- */
void ClosedHash_Clear(ClosedHash *h)
{
    int i;

    for (i = 0; i < h->size; i++)   /* 모든 버킷을 순회 */
        h->table[i].stat = Empty;   /* 공백으로 만든다. */
}

/* --- 해시 테이블 종료 --- */
void ClosedHash_Terminate(ClosedHash *h)
{
    ClosedHash_Clear(h);       /* 모든 데이터를 삭제 */
    free(h->table); /* 해시 테이블 배열의 메모리 해제 */
    h->size = 0;    /* 해시 테이블 크기를 초기화 */
}

// TODO: 이름을 키 값으로 하는 프로그램 작성