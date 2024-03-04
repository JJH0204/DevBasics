# LinkedList.md
- 포인터를 이용하여 리스트를 구현
- 데이터를 저장하는 부분과 연결을 위한 포인터로 구성된 노드

## 노드 구조
  - 실제 저장하려는 **데이터**와 다음 데이터의 링크(포인트)를 멤버 변수로 가지는 구조체  
'''
typedef struct LinkedListNodeType
{
    int nData;
    struct LinkedListNodeType* pNext;
} node;
'''

## 연결 리스트의 구조의 특징
**헤더 노드(header node)의 존재**
> 헤더 노드란?  
> 연결 리스트에 구성된 멤버 변수  
> 자료를 저장하는 노드가 아닌 첫번째 노드를 가리키는 포인터 변수  
> 헤더 노드 == NULL = "연결 리스트가 비어있다."  

**할당 과정에서 최대 개수 값이 필요 없다.**  
> 데이터를 추가, 제거하는 과정에서 노드를 별도로 생성, 제거한 후 연결만 하면된다.  
> 배열 리스트와 달리 인덱스를 초과한 데이터 저장이 가능하다.  
'''
typedef struct LinkedList
{
    int nCurrentCount;
    node* pHeader;
} linkedList;
'''  

## 연결 리스트 구현  
### createList()
