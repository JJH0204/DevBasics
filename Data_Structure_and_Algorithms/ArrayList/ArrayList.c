//ArrayList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 정의
typedef struct Node
{
    int data;
} Node;

typedef struct ArrayList
{
    int maxCount;       // 배열 크기
    int currentCount;   // 현재 데이터 수
    Node *pNode;        // 1차원 배열 포인터
} ArrayList;

// 리스트 생성: createList()
ArrayList *createList(int count)
{
    ArrayList *pResult = (ArrayList*)malloc(sizeof(ArrayList));            // 리스트 헤더 할당
    pResult->maxCount = count;                              // 리스트 최대 개수
    pResult->currentCount = 0;                              // 리스트 현재 개수
    pResult->pNode = (Node*)malloc(sizeof(Node) * count);   // 배열 할당
    memset(pResult->pNode, 0, sizeof(Node) * count);        // ??
}

// 데이터 추가: addListData()
/*시나리오
1. 리스트 마지막에 데이터 추가 -> 저장 중인 데이터 마지막 인덱스를 인자로 데이터 추가 (간단)
2. 리스트 중간에 데이터 추가 -> 저장할 위치 인덱스 입력
    -> 저장할 위치를 시작으로 이후 데이터들의 한 인덱스 씩 뒤로 옮긴다. -> 원하는 인덱스에 데이터 저장
*/
/*로직
1. position <- data를 추가하는 인덱스, i <- 마지막 데이터의 인덱스
2. while (i>=position)
    2.1. Yes -> 인덱스 i에 있는 data를 i + 1 에 복사 -> i-- -> 반복
    2.2. No -> 반복 종료
3. Position에 새로운 데이터 추가
*/
int addListData(ArrayList* _pList_, int _position_, int _date_)
{
    int i = 0;
    for (i = _pList_->currentCount-1; i >= _position_; i--)
    {
        _pList_->pNode[i+1] = _pList_->pNode[i];
    }
    _pList_->pNode[_position_].data = _date_;
    _pList_->currentCount++;
    return 0;
}

// 데이터 삭제: removeListData()
/*시나리오
1. 
*/

int main(void)
{

    return 0;
}