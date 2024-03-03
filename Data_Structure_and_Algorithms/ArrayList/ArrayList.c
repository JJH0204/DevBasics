//ArrayList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 정의
typedef struct ArrayNode
{
    int maxCount;       // 배열 크기
    int currentCount;   // 현재 데이터 수
    Node *pNode;        // 1차원 배열 포인터
} Node;

// 리스트 생성: createList()
Node *createList(int count)
{
    Node *pResult = (Node*)malloc(sizeof(Node));            // 리스트 헤더 할당
    pResult->maxCount = count;                              // 리스트 최대 개수
    pResult->currentCount = 0;                              // 리스트 현재 개수
    pResult->pNode = (Node*)malloc(sizeof(Node) * count);   // 배열 할당
    memset(pResult->pNode, 0, sizeof(Node) * count);        // ??
} 
int main(void)
{

    return 0;
}