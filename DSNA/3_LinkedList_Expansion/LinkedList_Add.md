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
### 리스트 데이터 추가
    int addCircularList(CircularList *_pList_, int _nData_, int _nIndex_)
    {
        int i = 0;
        node *pPrevious = NULL;
        node *pNewNode = NULL;

        if (_pList_ == NULL)
            return -1;
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return -2;

        pNewNode = (node *)malloc(sizeof(node));
        if (pNewNode == NULL)
            return -3;

        pNewNode->nData = _nData_;
        pNewNode->pNext = NULL;

        pPrevious = &(_pList_->sHeader);
        while (i < _nIndex_)
        {
            pPrevious = pPrevious->pNext;
            i++;
        }
        pNewNode->pNext = pPrevious->pNext;
        pPrevious->pNext = pNewNode;

        _pList_->nCurrentCount++;

        if (pNewNode->pNext == NULL)
            pNewNode->pNext = pNewNode;
        
        return 0;
    }

### 리스트 순회
    int circularIterateList(const CircularList *_pList_)
    {
        int nCount = 0;
        node *pCurrent = NULL;
        if (_pList_ == NULL)
            return -1;
        if (_pList_->nCurrentCount <= 0)
        {
            printf("No list data\n");
            return -2;
        }
        pCurrent = _pList_->sHeader.pNext;
        for (; nCount < _pList_->nCurrentCount; nCount++)
        {
            printf("%d [%d]\n", pCurrent->nData, nCount);
            pCurrent = pCurrent->pNext;
        }
        printf("Node's: %d\n", nCount);
        return 0;
    }

### 리스트 데이터 삭제
    int removeCircularListData(CircularList *_pList_, const int _nIndex_)
    {
        int i = 0;
        node *pCurrent = NULL;
        node *pPrevious = NULL;

        if (_pList_ == NULL)
            return -1;
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return -2;
        
        pPrevious = &(_pList_->sHeader);
        for (; i < _nIndex_; i++)
            pPrevious = pPrevious->pNext;
        
        pCurrent = pPrevious->pNext;
        pPrevious->pNext = pCurrent->pNext;
        // TODO: 리스트의 요소가 1개 뿐일 경우 에러 발생
        if (1 == _pList_->nCurrentCount)
            _pList_->sHeader.pNext = NULL;
        
        free(pCurrent);
        _pList_->nCurrentCount--;
        return 0;
    }

### 리스트 삭제
    int deleteCircularList(CircularList * _pList_)
    {
        int i = 0;
        node* pCurrent = NULL;
        node* pDelete = NULL;
        if (_pList_ == NULL)
            return 1;
        
        pCurrent = (_pList_->sHeader).pNext;

        // 무한 루프 방지
        for (; i < _pList_->nCurrentCount; i++)
        {
            pDelete = pCurrent;
            pCurrent = pCurrent->pNext;

            free(pDelete);
        }

        free(_pList_);
        return 0;
    }

### 리스트 연결
    int concatCircularList(CircularList *_pListA_, CircularList *_pListB_)
    {
        
    }

## 이중 연결 리스트(Double linked list)
> **구성 요소의 양방향 순환이 가능한 연결 리스트**

### 노드 구조
    typedef struct DoubleLink
    {
        int nData;
        struct DoubleLink *pLeftLink;
        struct DoubleLink *pRightLink;
    } node;

### 리스트 구조
> 헤더 노드의 이전 노드(left)가 리스트의 마지막 노드를 가리키고,  
> 리스트의 마지막 노드의 다음 노드(right)가 헤더 노드를 가리키는 구조를 갖는다.
    typedef struct DoubleLinkedList
    {
        unsigned int nCurrentCount;
        node sHeader;
    } dList;

### 리스트 생성
    dList *createList (void)
    {
        dList *pResult = (dList*)malloc(sizeof(dList));
        if (pResult == NULL)
            return NULL;
        memset(pResult, 0, sizeof(dList));
        pResult->sHeader.pLeftLink = &(pResult->sHeader);
        pResult->sHeader.pRightLink = &(pResult->sHeader);
        return pResult;
    }

### 데이터 추가
    int addData(dList *_pList_, int _nData_, unsigned int _nIndex_)
    {
        node *pNewNode = NULL;
        node *pCurrentNode = NULL;
        node *pNextNode = NULL;
        int nCount = 0;
        if (_pList_ == NULL)
            return -1;
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return -2;

        pNewNode = (node*)malloc(sizeof(node));
        memset(pNewNode, 0, sizeof(node));
        pNewNode->nData = _nData_;

        pCurrentNode = &(_pList_->sHeader);

        for ( ; nCount < _nIndex_; nCount++)
            pCurrentNode = pCurrentNode->pRightLink;
        
        pNextNode = pCurrentNode->pRightLink;

        pNewNode->pRightLink = pNextNode;
        pNewNode->pLeftLink = pCurrentNode;

        pCurrentNode->pRightLink = pNewNode;
        pNextNode->pLeftLink = pNewNode;

        _pList_->nCurrentCount++;
        return 0;
    }

### 데이터 반환
    int getData(dList *_pList_, int _nIndex_)
    {
        int nBetter = 0;
        int nCount = 0;
        node *pCurrentNode = NULL;

        if (_pList_ == NULL)
            return -1;      // no list
        if (_pList_->nCurrentCount <= 0)
            return -2;      // no data
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return -3;      // error Index
        
        pCurrentNode = &(_pList_->sHeader);
        nBetter = (_pList_->nCurrentCount - 1) - _nIndex_;

        // It is better to move to the right
        if (nBetter >= _nIndex_)
            for ( ; nCount <= _nIndex_; nCount++)
                pCurrentNode = pCurrentNode->pRightLink;
        // It is better to move to the left
        else
            for ( ; nCount <= nBetter; nCount++)
                pCurrentNode = pCurrentNode->pLeftLink;
        
        return pCurrentNode->nData;
    }

### 데이터 삭제
    int removeData(dList *_pList_, int _nIndex_)
    {
        int nCount = 0;
        int nBetter = 0;
        node *pCurrentNode = NULL;
        node *pRemoveNode = NULL;

        if (_pList_ == NULL)
            return -1;
        if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
            return -2;
        
        pRemoveNode = &(_pList_->sHeader);
        nBetter = (_pList_->nCurrentCount - 1) - _nIndex_;

        if (nBetter >= _nIndex_)
            for ( ; nCount <= _nIndex_; nCount++)
                pRemoveNode = pRemoveNode->pRightLink;
        else
            for ( ; nCount <= nBetter; nCount++)
                pRemoveNode = pRemoveNode->pLeftLink;
        
        pRemoveNode->pRightLink->pLeftLink = pRemoveNode->pLeftLink;
        pRemoveNode->pLeftLink->pRightLink = pRemoveNode->pRightLink;

        pRemoveNode->pRightLink = NULL;
        pRemoveNode->pLeftLink = NULL;

        free(pRemoveNode);
        _pList_->nCurrentCount--;
        return 0;
    }

### 기타 함수
    int getLength (dList *_pList_)
    {
        if (_pList_ == NULL)
            return -1;
        
        return _pList_->nCurrentCount;
    }

    int deleteList(dList *_pList_)
    {
        if (_pList_ == NULL)
            return -1;
        
        while (_pList_->nCurrentCount > 0)
            removeData(_pList_, 0);
        
        free(_pList_);
        
        return 0;
    }

    int printList_R(dList *_pList_)
    {
        int nCount = 0;
        node *pPrintNode = NULL;
        if (_pList_ == NULL)
            return -1;
        if (_pList_->nCurrentCount <= 0)
        {
            printf("No data\n");
            return -2;
        }
        printf("Node count: %d\n", _pList_->nCurrentCount);

        pPrintNode = _pList_->sHeader.pRightLink;
        for ( ; nCount < _pList_->nCurrentCount; nCount++)
        {
            printf("[%d]: %d\n", nCount, pPrintNode->nData);
            pPrintNode = pPrintNode->pRightLink;
        }
        return 0;
    }

    int printList_L(dList *_pList_)
    {
        int nCount = 0;
        node *pPrintNode = NULL;
        if (_pList_ == NULL)
            return -1;
        if (_pList_->nCurrentCount <= 0)
        {
            printf("No data\n");
            return -2;
        }
        printf("Node count: %d\n", _pList_->nCurrentCount);

        pPrintNode = _pList_->sHeader.pLeftLink;
        for ( ; nCount < _pList_->nCurrentCount; nCount++)
        {
            printf("[%d]: %d\n", nCount, pPrintNode->nData);
            pPrintNode = pPrintNode->pLeftLink;
        }
        return 0;
    }

    // TODO: concat()
    int concatList(dList *_pListA_, dList *_pListB_)
    {

        return 0;
    }