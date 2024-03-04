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
    ArrayList *pResult = (ArrayList*)malloc(sizeof(ArrayList));     // 리스트 헤더 할당
    pResult->maxCount = count;                                      // 리스트 최대 개수
    pResult->currentCount = 0;                                      // 리스트 현재 개수
    pResult->pNode = (Node*)malloc(sizeof(Node) * count);           // 배열 할당
    memset(pResult->pNode, 0, sizeof(Node) * count);                // 메모리 초기화 함수
    /* void *memset(void *s, int c, size_t n);
    - s는 초기화할 메모리 영역의 시작 주소를 가리키는 포인터입니다.
    - c는 메모리에 채우고자 하는 값입니다.
        ㄴ int 타입이지만, 실제로는 unsigned char로 변환되어 메모리에 채워집니다. (0에서 255 사이의 값이 사용)
    - n은 c 값으로 채울 바이트 수를 나타내는 크기입니다.
    
    memset() 함수는 첫 번째 매개변수 s로 전달된 주소부터 시작하여 n 바이트만큼 c 값으로 채웁니다. 
    함수의 반환 값은 s와 같으며, 초기화된 메모리 영역의 시작 주소를 가리키는 포인터를 반환합니다.
    
    메모리를 특정 값으로 빠르게 초기화할 필요가 있을 때 유용하게 사용됩니다. 
    예를 들어 배열을 초기화하거나, 메모리 할당 후 초기화하는 등의 작업에 활용할 수 있습니다.
    */
   //TODO: 반환이 없는데?
   //TODO: 할당 과정이 무결하다는 보장은?
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

    // TODO: 뭘 믿고 무조건 0을 return 하는 거지?
    return 0;
}

// 데이터 삭제: removeListData()
/*시나리오
1. 삭제를 원하는 데이터의 인덱스 값을 받는다.
2. 인덱스 값으로 데이터가 저장된 위치를 참조
3. 데이터를 삭제한다.
4. 삭제한 데이터의 인덱스를 기준으로 뒷 인덱스에 데이터가 있으면 한칸씩 앞으로 옮긴다.
삭제 이후의 후처리(post-processing) 필수
*/
int removeListData(ArrayList* _pList_, int _position_)
{
    int i = _position_;
    for (; i < _pList_->currentCount - 1; i++)
    {
        _pList_->pNode[i] = _pList_->pNode[i+1];
    }
    _pList_->currentCount--;

    // TODO: 뭘 믿고 무조건 0을 return 하는 거지?
    return 0;
}

// 데이터 반환: getListData()
int getListData(ArrayList* _pList_, int _position_)
{
    // TODO: 데이터가 없는 곳을 참조하려고 할 경우
    return _pList_->pNode[_position_].data;
}

// 리스트 삭제: deleteList()
void deleteList(ArrayList* _pList_)
{
    // TODO: 데이터가 없는 곳을 참조하려고 할 경우
    free(_pList_->pNode);
    free(_pList_);
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
    // 배열 리스트에서 첫 번째 위치의 자료를 제거한다.
    removeListData(_ArrayList_, 0);
    // 배열 리스트 자체를 삭제한다.
    deleteList(_ArrayList_);

    return 0;
}