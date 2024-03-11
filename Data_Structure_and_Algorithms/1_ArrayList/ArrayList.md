# 배열 리스트
- 기본적인 리스트
- 데이터를 순서대로 저장

## 시나리오
- data add: 새로운 데이터를 자료구조에 저장
- data get: 데이터가 저장된 자료구조에 접근하여 원하는 값을 반환
- data remove: 사용이 끝난 데이터를 자료구조에서 제거
  
### Data Add
**정수 3개 (10, 20, 30)을 입력받아 30-10-20의 순서로 저장한다.**

1. 리스트를 만든다. (배열을 할당한다.)
2. 10을 입력 받아 리스트에 저장한다. (defult 첫번째)
3. 20을 입력 받아 리스트 두 번째 위치에 저장한다.
4. 30을 입력 받아 리스트 첫 번째 위치에 저장한다.

### Data Get
**데이터가 저장된 위치 정보를 이용하여 원하는 데이터를 가리킨다.**

1. 리스트에서 두 번째 위치에 저장된 자료의 값을 가져온다.

### Data Remove
**사용이 끝난 데이터의 위치 정보를 이용해 삭제한 후 다시 정렬한다.**

1. 리스트의 첫 번째 위치에 저장된 자료를 삭제한다.
2. 리스트 자체를 삭제한다.

## 추상 자료형(ADT, abstract data type)
### 데이터와 데이터 타입의 관계
1. **데이터**: 프로그램에서 처리되는 대상 (value)
2. **데이터 타입**: 데이터와 데이터를 처리하기 위한 명령 혹은 연산(operation)을 함꼐 부르는 명칭

### 추상 자료형이란?
1. 새부적이고 복잡한 것을 생략한 데이터 타입
2. 대신 대표적인 것, 중요한 것만 담아 데이터와 연산자로 표현
3. 사용자의 눈에 직접 보이는 것, 추상 자료형에 따라 내부 로직을 구현해야 함

### 리스트의 추상 자료형
| 이름(kr)       |      함수명      |         인자         |           반환 |
| :------------- | :--------------: | :------------------: | -------------: |
| 리스트 생성    |   createList()   |          -           |         리스트 |
| 자료 추가      |  addListData()   | 리스트, 위치, 데이터 | 성공/실패 여부 |
| 자료 반환      |  getListData()   |     리스트, 위치     |         데이터 |
| 자료 개수 반환 | getListLength()  |        리스트        |    데이터 개수 |
| 자료 제거      | removeListData() |     리스트, 위치     | 성공/실패 여부 |
| 모든 자료 제거 |   clearList()    |        리스트        |            N/A |
| 리스트 삭제    |   deleteList()   |        리스트        |            N/A |

## 배열 리스트란?
- c 언어의 배열을 사용하여 구현된 리스트
- 장점:
  - 인덱스 값을 활용한 메모리 참조가 쉬움
- 단점:
  - 초기에 할당한 배열의 크기에서 확장이 어려움

### 배열 리스트의 추상 자료형
- 리스트 생성 외 다른 요소는 이전의 설명과 동일

| 이름(kr)    |    함수명    |    인자     |  반환  |                                             설명 |
| :---------- | :----------: | :---------: | :----: | -----------------------------------------------: |
| 리스트 생성 | createList() | 최대 개수 n | 리스트 | 최대 n 개 데이터를 저장할 수 있는 빈 리스트 생성 |

### 노드(Node)
- 자료를 저장하는 단위
- struct 키워드를 이용해 노드 구조체를 선언
    (실제 저장되는 데이터를 멤버 변수로 가진다.)
- 동시에 여러 개의 자료를 저장하기 쉽기 때문에 이러한 방식을 사용

## 구현
- [ArrayList](Data_Structure_and_Algorithms\ArrayList\ArrayList.c)

### 노드 구성
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

### 리스트 생성: createList()
ArrayList* createList(int count)
{
  ArrayList *pResult = (ArrayList*)malloc(sizeof(ArrayList));     // 리스트 헤더 할당
  if (pResult != NULL)
  {
      pResult->maxCount = count;                             // 리스트 최대 개수
      pResult->currentCount = 0;                             // 리스트 현재 개수
      pResult->pNode = (Node *)malloc(sizeof(Node) * count); // 배열 할당
      if (pResult->pNode != NULL)
      {
          memset(pResult->pNode, 0, sizeof(Node) * count); // 메모리 초기화 함수
          return pResult;
      }
      return NULL;
  }
  return NULL;
}

### 데이터 추가: addListData()
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

### 데이터 삭제: removeListData()
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
/*시나리오
1. 삭제를 원하는 데이터의 인덱스 값을 받는다.
2. 인덱스 값으로 데이터가 저장된 위치를 참조
3. 데이터를 삭제한다.
4. 삭제한 데이터의 인덱스를 기준으로 뒷 인덱스에 데이터가 있으면 한칸씩 앞으로 옮긴다.
삭제 이후의 후처리(post-processing) 필수
*/

### 데이터 반환: getListData()
int getListData(ArrayList* _pList_, int _position_)
{
    // TODO: 데이터가 없는 곳을 참조하려고 할 경우
    return _pList_->pNode[_position_].data;
}

### 리스트 삭제: deleteList()
void deleteList(ArrayList* _pList_)
{
    // TODO: 데이터가 없는 곳을 참조하려고 할 경우
    free(_pList_->pNode);
    free(_pList_);
}

### 리스트 데이터 저장 개수 반환: getListLength()
int getListLength(ArrayList* _ArrayList_)
{
    return _ArrayList_->currentCount;
}

### 함수 활용
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

### 그 외
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