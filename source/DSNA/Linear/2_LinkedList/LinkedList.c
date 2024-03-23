// LinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADERPOINT

// node definition
typedef struct LinkedListNodeType
{
    int nData;
    struct LinkedListNodeType* pNext;
} node;

#ifdef HEADERNODE
// 헤더 노드를 활용한 연결리스트 구현
typedef struct LinkedList
{
    int nCurrentCount;
    node nodeHeader;
} linkedList;

linkedList* createList()
{
    linkedList* pResult = (linkedList*)malloc(sizeof(linkedList));
    if (pResult == NULL)
        return NULL;
    
    memset(pResult, 0, sizeof(linkedList));
    return pResult;
}

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
    if (pNewNode == NULL)
        return 3;
    
    pNewNode->nData = _nVal_;
    pNewNode->pNext = NULL;

    pPrevious = &(_pList_->nodeHeader);
    while (i < _nIndex_)
    {
        pPrevious = pPrevious->pNext;
        i++;
    }
    pNewNode->pNext = pPrevious->pNext;
    pPrevious->pNext = pNewNode;

    (_pList_->nCurrentCount)++;
    return 0;
}

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

// 멤버 변수 없이 직접 리스트의 개수를 구해서 반환하는 함수로 변경
int getListCount(linkedList* _pList_)
{
    int nResult = 0;
    node* pCurrent = NULL;
    if (_pList_ == NULL)
        return -1;
    pCurrent = &(_pList_->nodeHeader);

    while (pCurrent->pNext != NULL)
    {
        nResult++;
        pCurrent = pCurrent->pNext;
    }
    
    return nResult;
}

int getListLength(linkedList* _pList_)
{
    if (_pList_ == NULL)
        return 0;
    
    return _pList_->nCurrentCount;
}

// 비효율적인 로직
int displayList(linkedList* _pList_)
{
    int i = 0; 
    if (_pList_ == NULL) 
        return 1;
    for (; i < _pList_->nCurrentCount; i++)  
        printf("[%d] %d\n", i, getListData(_pList_, i));
    return 0;
}

int iterateList(linkedList* _pList_)
{
    int nCount = 0;
    node* pCurrent = NULL;
    if (_pList_ == NULL)
        return 1;

    pCurrent = _pList_->nodeHeader.pNext;
    while (pCurrent != NULL)
    {
        printf("[%d] %d\n", nCount, pCurrent->nData);
        nCount++;
        pCurrent = pCurrent->pNext;
    }
    printf("Node's: %d\n", nCount);

    return 0;
}

// 유효성 n 논리 문제 보완
int concatList(linkedList* _pListA_, linkedList* _pListB_)
{
    node* pCurrent = NULL;
    if ((_pListA_ == NULL) && (_pListB_ == NULL))
        return -1;
    if (_pListB_->nodeHeader.pNext == NULL)
        return 0;
    
    pCurrent = &(_pListA_->nodeHeader);
    while (pCurrent->pNext != NULL)
        pCurrent = pCurrent->pNext;
    pCurrent->pNext = _pListB_->nodeHeader.pNext;
    _pListA_->nCurrentCount = _pListA_->nCurrentCount + _pListB_->nCurrentCount;
    // _pListB_ 포인터는 본 함수에서는 초기화만 진행, 할당해제 여부는 외부에서 결정
    memset(_pListB_, 0, sizeof(linkedList));
    return 0;
}

// 리스트 평균값 구하는 함수
int averageList(linkedList* _pList_)
{
    int nSum = 0;
    int nIndex = 0;
    node* pCurrent = NULL;
    if (_pList_ == NULL)
        return -1;
    
    pCurrent = &(_pList_->nodeHeader);
    while (pCurrent->pNext != NULL)
    {
        pCurrent = pCurrent->pNext;
        nSum = nSum + pCurrent->nData;
        nIndex++;
    }
    return nSum/nIndex;
}

// 리스트 뒤집기
int flipList(linkedList* _pList_)
{
    node* pCurrent = NULL;
    node* pPost = NULL;

    if ((_pList_ == NULL) || (_pList_->nodeHeader.pNext == NULL))
        return -1;
    pCurrent = _pList_->nodeHeader.pNext;
    pPost = pCurrent->pNext;
    pCurrent->pNext = NULL;

    while (pPost != NULL)
    {
        pCurrent = pPost;
        pPost = pCurrent->pNext;
        pCurrent->pNext = _pList_->nodeHeader.pNext;
        _pList_->nodeHeader.pNext = pCurrent;
    }

    return 0;
}
#endif

#ifdef HEADERPOINT
// 헤더 포인터를 활용한 연결리스트 구현
typedef struct LinkedList
{
    int nCurrentCount;
    node* pHead;
} linkedList;

linkedList* createList()
{
    linkedList* pResult = (linkedList*)malloc(sizeof(linkedList));
    if (pResult == NULL)
        return NULL;
    
    memset(pResult, 0, sizeof(linkedList));
    return pResult;
}

int getListData(linkedList* _pList_, const int _nIndex_)
{
    int nCount = 0;
    node* pCurrent = NULL;
    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ >= _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;
    if (_pList_->pHead == NULL)
        return -3;
    pCurrent = _pList_->pHead;
    for (; nCount < _nIndex_; nCount++)
        pCurrent = pCurrent->pNext;
    return pCurrent->nData;
}

int addListData(linkedList* _pList_, const int _nVal_, const int _nIndex_)
{
    int nCount = 0;
    node* pPrevious = NULL;
    node* pNewNode = NULL;

    if (_pList_ == NULL)
        return -1;
    if ((_nIndex_ > _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;
    
    pNewNode = (node*)malloc(sizeof(node));
    if (pNewNode == NULL)
        return -3;
    pNewNode->nData = _nVal_;
    pNewNode->pNext = NULL;

    if (_pList_->pHead == NULL)
    {
        _pList_->pHead = pNewNode;
    }
    else
    {
        pPrevious = _pList_->pHead;                 // head 가 NULL 일때 아래 코드를 실행하면, segmentation fault 발생
        for (; nCount < (_nIndex_ - 1); nCount++)
            pPrevious = pPrevious->pNext;
        pNewNode->pNext = pPrevious->pNext;
        pPrevious->pNext = pNewNode;
    }
    _pList_->nCurrentCount++;
    return 0;
}

int removeListData(linkedList* _pList_, const int _nIndex_)
{
    int nCount = 0;
    node* pCurrent = NULL;
    node* pPrevious = NULL;

    if ((_pList_ == NULL) || (_pList_->pHead == NULL))
        return -1;
    if ((_nIndex_ >= _pList_->nCurrentCount) || (_nIndex_ < 0))
        return -2;
    pPrevious = _pList_->pHead;

    for (nCount = 0; nCount < _nIndex_ - 1; nCount++)
        pPrevious = pPrevious->pNext;
    
    pCurrent = pPrevious->pNext;
    pPrevious->pNext = pCurrent->pNext;

    free(pCurrent);
    _pList_->nCurrentCount--;
    return 0;
}

int deleteList(linkedList* _pList_)
{
    node* pPost = NULL;
    if (_pList_ == NULL)
        return -1;
    while (_pList_->pHead != NULL)
    {
        pPost = _pList_->pHead->pNext;
        free(_pList_->pHead);
        _pList_->pHead = pPost;
    }
    free(_pList_);
    
    return 0;
}

int getListLength(linkedList* _pList_)
{
    if (_pList_ == NULL)
        return -1;
    
    return _pList_->nCurrentCount;
}

int iterateList(linkedList* _pList_)
{
    int nCount = 0;
    node* pCurrent = NULL;

    if (_pList_ == NULL)
        return -1;
    
    pCurrent = _pList_->pHead;
    while (pCurrent != NULL)
    {
        printf("[%d] %d\n", nCount, pCurrent->nData);
        nCount++;
        pCurrent = pCurrent->pNext;
    }
    printf("Node's: %d\n", nCount);
    return 0;
}

int concatList(linkedList* _pListA_, linkedList* _pListB_)
{
    node* pCurrent = NULL;
    if ((_pListA_ == NULL) && (_pListB_ == NULL))
        return -1;
    if (_pListB_->pHead == NULL)
        return -2;

    if (_pListA_->pHead != NULL)
    {
        pCurrent = _pListA_->pHead;
        while (pCurrent->pNext != NULL)
            pCurrent = pCurrent->pNext;
        pCurrent->pNext = _pListB_->pHead;
    }
    else
    {
        _pListA_->pHead = _pListB_->pHead;
    }
    _pListA_->nCurrentCount = _pListA_->nCurrentCount + _pListB_->nCurrentCount;
    // memset(_pListB_, 0, sizeof(linkedList));
    _pListB_->pHead = NULL;
    _pListB_->nCurrentCount = 0;
    return 0;
}

int averageList(linkedList* _pList_)
{
    int nSum = 0;
    int nCount = 0;
    node* pCurrent = NULL;
    if ((_pList_ == NULL) || (_pList_->pHead == NULL))
        return -1;
    pCurrent = _pList_->pHead;
    for (; pCurrent != NULL; pCurrent = pCurrent->pNext)
    {
        nSum = nSum + pCurrent->nData;
        nCount++;
    }
    return nSum/nCount;
}

int flipList(linkedList* _pList_)
{
    node* pCurrent = NULL;
    node* pPost = NULL;

    if ((_pList_ == NULL) || (_pList_->pHead == NULL))
        return -1;
    pCurrent = _pList_->pHead;
    pPost = pCurrent->pNext;
    pCurrent->pNext = NULL;
    
    while (pPost != NULL)
    {
        pCurrent = pPost;
        pPost = pCurrent->pNext;
        pCurrent->pNext = _pList_->pHead;
        _pList_->pHead = pCurrent;
    }
    
    return 0;
}
#endif

int main(int argc, char* argv[])
{
    int val = 0;

    linkedList *pListA = createList();
    linkedList *pListB = createList();

    addListData(pListA, 10, 0);
    addListData(pListA, 20, 1);
    addListData(pListA, 30, 1);

    addListData(pListB, 40, 0);
    addListData(pListB, 50, 1);

    printf("->concat list before<------------\n");
    printf("List A: \n");
    iterateList(pListA);
    printf("List B: \n");
    iterateList(pListB);

    val = getListData(pListA, 1);
    printf("print 'pListA' -> index: 1, val: %d\n", val);
    val = getListLength(pListA);
    printf("data count: %d\n", val);

    concatList(pListA, pListB);
    printf("->concat list after<------------\n");
    printf("List A: \n");
    iterateList(pListA);
    printf("List B: \n");
    iterateList(pListB);

    deleteList(pListB);

    removeListData(pListA, 2);
    printf("ListA index %d data remove: \n", 2);
    iterateList(pListA);
    
    flipList(pListA);
    printf("ListA flip: \n");
    iterateList(pListA);

    val = averageList(pListA);
    printf("List average: %d\n", val);

    deleteList(pListA);

    return 0;
}