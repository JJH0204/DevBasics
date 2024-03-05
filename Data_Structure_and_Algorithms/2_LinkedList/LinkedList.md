# LinkedList.md
- 포인터를 이용하여 리스트를 구현
- 데이터를 저장하는 부분과 연결을 위한 포인터로 구성된 노드

## 노드 구조
  - 실제 저장하려는 **데이터**와 다음 데이터의 링크(포인트)를 멤버 변수로 가지는 구조체  

        typedef struct LinkedListNodeType
        {
            int nData;

            struct LinkedListNodeType* pNext; 
        } node;


## 연결 리스트의 구조의 특징
**헤더 노드(header node)의 존재**
> 헤더 노드란?  
> 연결 리스트에 구성된 멤버 변수  
> 자료를 저장하는 노드가 아닌 첫번째 노드를 가리키는 포인터 변수  
> 헤더 노드 == NULL = "연결 리스트가 비어있다."  

**할당 과정에서 최대 개수 값이 필요 없다.**  
> 데이터를 추가, 제거하는 과정에서 노드를 별도로 생성, 제거한 후 연결만 하면된다.  
> 배열 리스트와 달리 인덱스를 초과한 데이터 저장이 가능하다.  

    typedef struct LinkedList
    {
        int nCurrentCount;
        node nodeHeader;
    } linkedList;


## 연결 리스트 구현  
### createList()
    linkedList* createList()
    {
        linkedList* pResult = (linkedList*)malloc(sizeof(linkedList));
        if (pResult == NULL)
            return NULL;
        memset(pResult, 0, sizeof(linkedList));
        return pResult;
    }  

### getListData()  
    int getListData(linkedList* _pList_, const int _nIndex_)
    {
        int i = 0;
        node* pCurrent = NULL;
        if (_pList_ == NULL)
            return 1;
        if (_nIndex_ >= _pList_->nCurrentCount)
            return 2;
        
        pCurrent = &(_pList_->nodeHeader);

        while (i <= _nIndex_)
        {
            pCurrent = pCurrent->pNext;
            i++;
        }
        return pCurrent->nData;
    }

### addListData()  
    int addListData(linkedList* _pList_, int _nVal_, const int _nIndex_)
    {
        int i = 0;
        node* pPrevious = NULL;
        node* pNewNode = NULL;

        if (_pList_ == NULL)
            return 1;
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return 2;
        
        pNewNode = (node*)malloc(sizeof(node));
        pNewNode->nData = _nVal_;
        pNewNode->pNext = NULL;

        pPrevious = &(_pList_->nodeHeader);
        while (i < _nIndex_)
        {
            pPrevious = pPrevious->pNext;
            // pCurrent = pCurrent->pNext;
            i++;
        }
        pNewNode->pNext = pPrevious->pNext;
        pPrevious->pNext = pNewNode;

        (_pList_->nCurrentCount)++;
        return 0;
    }

### removeListData()
    int removeListData(linkedList* _pList_, const int _nIndex_)
    {
        int i = 0;
        node* pCurrent = NULL;
        node* pPrevious = NULL;
        
        if (_pList_ == NULL)
            return 1;
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return 2;
        
        pPrevious = &(_pList_->nodeHeader);

        for (; i < _nIndex_; i++)
            pPrevious = pPrevious->pNext;
        
        pCurrent = pPrevious->pNext;
        pPrevious->pNext = pCurrent->pNext;

        free(pCurrent);

        (_pList_->nCurrentCount)--;
        return 0;
    }

### deleteList()
    int deleteList(linkedList* _pList_)
    {
        node* pCurrent = NULL;
        node* pDelete = NULL;
        if (_pList_ == NULL)
            return 1;
        
        pCurrent = (_pList_->nodeHeader).pNext;
        while (pCurrent != NULL)
        {
            pDelete = pCurrent;
            pCurrent = pCurrent->pNext;

            free(pDelete);
        }

        free(_pList_);
        return 0;
    }

### getListLength()
    int getListLength(linkedList* _pList_)
    {
        if (_pList_ == NULL)
            return 0;
        
        return _pList_->nCurrentCount;
    }

### int displayList(linkedList* _pList_)
    {
        int i = 0;
        if (_pList_ == NULL)
            return 0;
        for (; i < _pList_->nCurrentCount; i++)
            printf("[%d] %d\n", i, getListData(_pList_, i));
        
    }

## 배열 리스트와 연결 리스트 비교  
| 구분 | 구현 방식 | 순차적 저장을 구현한 방식 | 접근 속도 | 구현 난이도 | 제약 사항 |
| :--- | :-------: |:--:|:--:|:--:|--:
배열 리스트|배열|물리적 저장 순서가 순차적|빠름|낮음|최대 저장 개수 필요
연결 리스트|포인터|논리적 저장 순서가 순차적|느림|높음|-  
### 배열리스트 > 연결리스트
- 배열리스트의 접근 속도가 O(1)인 이유는 저장 공간에 물리적으로 연속해 저장되어 있어 인덱스 번호만으로 바로 접근이 가능하기 때문
- 연결리스트의 경우 리스트를 구성하는 데이터의 수가 n개라면 접근 연산은 O(n)이라 배열리스트에 비해 느리다.
- 연결리스트의 경우 메모리 누수(leak)로 인한 오류 가능성으로 인해 구현 난이도가 높다.  
### 연결리스트 > 배열리스트
- 연결리스트의 경우 물리적으로 연속된 메모리 공간을 필요로 하지 않음
- 동적 할당과 해제를 통해 원하는 만큼 메모리를 사용할 수 있어 효율이 좋다.
### 배열리스트 = 연결리스트
- 자료 추가 및 삭제 시 O(n)
- 다만, 배열리스트는 데이터의 복사 연산 자체가 많은 반면, 연결리스트는 적절한 노드 위치를 찾는 연산에 시간을 소요
- 데이터 추가와 삭제가 빈번한 경우 배열리스트 < 연결리스트