# 연결 리스트의 확장
## 연결 리스트의 종류
1. 단순 연결 리스트: 기본이 되는 연결 리스트, 서로의 연결이 단방향
2. 이중 연결 리스트: 서로의 연결이 양방향
   - 되돌리기(undo) 기능을 구현하는데 필요
3. 원형 연결 리스트: 서로의 연결이 단방향, 하지만 끝없이 순회하는 루프(loop)구조
   - 리스트 순회의 지속적인 반복이 필요한 경우 유용하다.

## 원형 연결 리스트(circular linked list)
> **리스트의 마지막 노드가 첫 번째 노드와 연결된 단순 연결 리스트**  

### 노드 정의  
    typedef struct CircularLink
    {
        int nData;
        struct CircularLink *pNext;
    } Node;
### 리스트 정의
    typedef struct CircularLinkedList
    {
        int nCurrentCount;
        Node sHeader;
    } CircularList;

### 리스트 생성
    CircularList *createCircularList()
    {
        CircularList *pResult = (CircularList *)malloc(sizeof(CircularList));
        if (pResult == NULL)
            return NULL;
        memset(pResult, 0, sizeof(CircularList));
        return pResult;
    }

### 리스트 데이터 반환
    int getCircularListData(CircularList* _pList_, int _nIndex_)
    {
        int i = 0;
        Node* pCurrent = NULL;

        if (_pList_ == NULL)
            return -1;
        
        if ((_nIndex_ < 0) || (_nIndex_>_pList_->nCurrentCount))
            return -2;
        
        pCurrent = &(_pList_->sHeader);
        for (; i <= _nIndex_; i++)
            pCurrent = pCurrent->pNext;
        
        return pCurrent->nData;
    }

## 이중 연결 리스트(Double linked list)
> **구성 요소의 양방향 순환이 가능한 연결 리스트**
