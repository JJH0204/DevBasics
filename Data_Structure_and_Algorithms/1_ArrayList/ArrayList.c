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
ArrayList* createList(int count)
{
    ArrayList *pResult = NULL;

    if (count < 1)
        return NULL;

    ArrayList *pResult = (ArrayList *)malloc(sizeof(ArrayList));    // 리스트 헤더 할당

    if (pResult == NULL)
        return NULL;

    pResult->maxCount = count;                                      // 리스트 최대 개수
    pResult->currentCount = 0;                                      // 리스트 현재 개수
    pResult->pNode = (Node *)malloc(sizeof(Node) * count);          // 배열 할당

    if (pResult->pNode == NULL)
        return NULL;
    
    memset(pResult->pNode, 0, sizeof(Node) * count);                // 메모리 초기화 함수
    return pResult;
}

// 데이터 추가: addListData()
int addListData(ArrayList* _pList_, int _position_, int _date_)
{
    int i = 0;

    if (_pList_ == NULL)
        return 1;
    if ((_position_ > _pList_->currentCount) || (_position_ > _pList_->maxCount - 1))
        return 2;
    
    for (i = _pList_->currentCount-1; i >= _position_; i--)
        _pList_->pNode[i+1] = _pList_->pNode[i];
    
    _pList_->pNode[_position_].data = _date_;
    _pList_->currentCount++;

    return 0;
}

// 데이터 삭제: removeListData()
int removeListData(ArrayList* _pList_, int _position_)
{
    if (_pList_ == NULL)
        return 1;
    if (_position_ >= _pList_->currentCount)
        return 2;
    
    int i = _position_;
    for (; i < _pList_->currentCount - 1; i++)
    {
        _pList_->pNode[i] = _pList_->pNode[i+1];
    }
    _pList_->currentCount--;

    return 0;
}

// 데이터 반환: getListData()
int getListData(ArrayList* _pList_, int _position_)
{
    if (_pList_ == NULL)
        return 1;
    if (_position_ >= _pList_->currentCount)
        return 2;
    return _pList_->pNode[_position_].data;
}

// 리스트 삭제: deleteList()
void deleteList(ArrayList* _pList_)
{
    if (_pList_ == NULL)
        return 1;
    if (_pList_->pNode != NULL)
        free(_pList_->pNode);
    free(_pList_);
}

// 리스트 데이터 저장 개수 반환: getListLength()
int getListLength(ArrayList *_pList_)
{
    if (_pList_ == NULL)
        return 1;

    return _pList_->currentCount;
}

int main(int argc, char *argv[])
{
    int val;
    // 크기가 5인 배열 리스트를 생성한다.
    ArrayList* _ArrayList_ = createList(5);
    // 자료 10과 20을 배열 리스트 첫 번째와 두 번째 위치에 차례대로 저장한다.
    addListData(_ArrayList_, 0, 10);
    addListData(_ArrayList_, 1, 20);
    // 자료 30을 배열 리스트의 첫 번째 위치에 저장한다.
    addListData(_ArrayList_, 0, 30);
    // 배열 리스트에서 두 번째 위치에 저장된 자료를 가져온다.
    val = getListData(_ArrayList_, 1);
    printf("pos: %d, val: %d\n", 1, val);
    // 리스트에 저장된 데이터 수량 출력
    val = getListLength(_ArrayList_);
    printf("자료의 개수 %d\n", val);
    // 배열 리스트에서 첫 번째 위치의 자료를 제거한다.
    removeListData(_ArrayList_, 0);
    // 배열 리스트 자체를 삭제한다.
    deleteList(_ArrayList_);

    return 0;
}