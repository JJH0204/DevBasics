// LinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADERNODE

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
    /* error correction
    LinkedList(89647,0x1dea25000) malloc: *** error for object 0x12a605f28: pointer being freed was not allocated
    LinkedList(89647,0x1dea25000) malloc: *** set a breakpoint in malloc_error_break to debug
    */

    while (pCurrent != NULL)
    {
        pDelete = pCurrent;
        pCurrent = pCurrent->pNext;

        free(pDelete);
    }

    free(_pList_);
    return 0;
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
/*
displayList() 함수에서 실행되는 for문은 리스트에 저장된 데이터의 수에 따라 비례하게 증가한다.O(n)
for문 이후 호출되는 getListData() 또한 리스트의 처음부터 인덱스 위치까지 순차적으로 참조하기에 O(n)의 속도를 가진다.
for문이 n번 실행되면 getListData() 동일하게 n 번 실행되기에 n*n = n^2 = O(n^2)의 시간 효율을 가지게 된다.
따라서, 리스트를 전체를 한번 출력하는 로직 치고는 매우 비효율적인 시간복잡도를 가지는 것을 알 수 있다.
*/

int iterateLinkedList(linkedList* _pList_)
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
/*
displayList() 함수와 달리 리스트를 순회하며 바로바로 데이터를 출력하도록 로직에서 기능을 처리하여 불필요한 반복 계산을 필요 없도록 만들었다.
displayList() 와 같은 추상 자료형을 사용하지만, 내부 구현에 있어 차이가 발생하게 된다. (알고리즘의 차이)
*/

#endif

#ifdef HEADERPOINT
// TODO: 헤더 포인터를 활용한 연결리스트 구현
typedef struct LinkedList
{
    int nCurrentCount;
    node* nodeHeader;
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
    
}

int addListData(linkedList* _pList_, int _nVal_, const int _nIndex_)
{
    
}

int removeListData(linkedList* _pList_, const int _nIndex_)
{
    
}

int deleteList(linkedList* _pList_)
{
    
}

int getListLength(linkedList* _pList_)
{
    
}
#endif

int main(int argc, char* argv[])
{
    int val = 0;
    linkedList* LinkedList = createList();
    addListData(LinkedList, 10, 0);
    addListData(LinkedList, 20, 1);
    addListData(LinkedList, 30, 1);

    val = getListData(LinkedList, 1);
    printf("index: 1, val: %d\n", val);

    iterateLinkedList(LinkedList);

    removeListData(LinkedList, 1);
    deleteList(LinkedList);
    return 0;
}